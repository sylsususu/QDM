#include "MVCameraFix.h"
#include <windows.h>

extern int g_hCamera;                    //相机设备句柄
extern unsigned char* g_pRawBuffer;     //raw数据
extern unsigned char* g_pRgbBuffer;     //处理后数据缓存区
extern unsigned char* g_readBuf;        //画板显示数据区
extern tSdkFrameHead           g_tFrameHead;       //图像帧头信息
extern tSdkCameraCapbility     g_tCapability;      //设备描述信息
extern tSdkCameraDevInfo       tCameraEnumList[4];   //相机列表

extern int g_Width;
extern int g_Height;
extern double g_SweepFreStart;
extern double g_SweepFreEnd;
extern double g_SweepFreStep;
extern bool  isAutoSave;
extern int g_uiPicWidth;
extern int g_uiPicHeigth;
extern bool g_is_Binning;
extern int g_bin;
extern int g_IterationTime;
extern bool isLockIn ;


MVCameraFix::MVCameraFix(QObject* parent) :
	QThread(parent)
{
	pause_status = true;
	quit = false;
	
	qRegisterMetaType<cv::Mat>("cv::Mat");
}

void MVCameraFix::run()
{
	quit = false;

	picNum = 0;
	iterTime = 0;
	count = 0;


	forever
	{
		if (!pause_status)
		{

			if (quit)
			{
				emit stopFixMeasure();
				break;
			}
			if (isLockIn == false)
			{
				if ((picNum + 1) >= g_IterationTime * 2)
				{
					emit stopFixMeasure();
					break;
				}
			}
			else
			{
				if ((picNum) >= g_IterationTime * 4)
				{
					emit stopFixMeasure();
					break;
				}
			}
#pragma omp parallel for num_threads(32) 
			for (int i = 0; i < g_Width* g_Height ; ++i)
			{
				int a = i + i * i;
			}

			if (CameraGetImageBuffer(g_hCamera, &g_tFrameHead, &g_pRawBuffer, 2000) == CAMERA_STATUS_SUCCESS)
			{
				CameraDataProcess::rawChangetoMat(g_pRawBuffer, g_Width, g_Height, dst);
				CameraReleaseImageBuffer(g_hCamera, g_pRawBuffer);
				//丢帧检测
				uint uid;
				CameraGetFrameID(g_hCamera, &uid);
				qDebug() << "uid:" << uid;
				if (0 == count)
				{
					count = uid;
				}
				//if (count>65535)
				//{
				//	count = 1;

				//}
				if (count != uid)
				{
					emit lostPic();
					emit stopFixMeasure();
					break;
				}
				emit GetFixMat(picNum,dst);
				picNum++;
				count++;
	
			}
			else
			{
				printf("Grab the hardware trigger frame failure, ret  is %lf\r\n", g_SweepFreStart);
			}


		}
		else
		{
			usleep(1000);
		}

	}//end forever
}

void MVCameraFix::stream()
{
	pause_status = false;
}

void MVCameraFix::pause()
{
	pause_status = true;
}

void MVCameraFix::stop()
{
	pause_status = false;
	quit = true;
}
