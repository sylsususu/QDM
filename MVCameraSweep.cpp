#include "MVCameraSweep.h"
#include <windows.h>

QElapsedTimer timer2;


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


MVCameraSweep::MVCameraSweep(QObject* parent) :
	QThread(parent)
{
	pause_status = true;
	quit = false;
	qRegisterMetaType<cv::Mat>("cv::Mat");
	
}

void MVCameraSweep::run()
{
	//timer2.start();
	quit = false;
	count = 0;
	countOn = 0;
	countOff = 0;
	switchNum = 0;
	onMat.release();
	offMat.release();
	forever
	{
		if (!pause_status)
		{
			
			if (quit)
			{
				emit stopSweepMeasure();
				break;
			}
			if ((g_SweepFreStart - g_SweepFreEnd) >= g_SweepFreStep - 0.00005)
			{
				emit stopSweepMeasure();
				break;
			}

#pragma omp parallel for num_threads(32) 
			for (int i = 0; i < g_Width* g_Height; ++i)
			{
				int a = i + i * i;
			}
			int iii = CameraGetImageBuffer(g_hCamera, &g_tFrameHead, &g_pRawBuffer, 3000);
			if (iii == CAMERA_STATUS_SUCCESS)
			{
				
				/*unsigned char* rawBuffer;
				rawBuffer = (unsigned char*)malloc(g_Width*g_Height*1.5);
				memcpy(rawBuffer, g_pRawBuffer, g_Width*g_Height*1.5 );
				CameraReleaseImageBuffer(g_hCamera, g_pRawBuffer);*/
				CameraDataProcess::rawChangetoMat(g_pRawBuffer, g_Width, g_Height, dst);
				CameraReleaseImageBuffer(g_hCamera, g_pRawBuffer); 
				//丢帧检测
				//tSdkFrameStatistic    psFrameStatistic;
				//CameraGetFrameStatistic(g_hCamera, &psFrameStatistic);
				////qDebug() << "thread index:" << count;
				//qDebug() << "camera index:" << psFrameStatistic.iCapture;
				//if (0 == count)
				//{
				//	count = psFrameStatistic.iCapture;
				//}
				//if (count!= psFrameStatistic.iCapture)
				//{
				//	

				//	emit lostPic();
				//	emit stopSweepMeasure();
				//	break;
				//}
				//丢帧检测2
				uint uid;
				CameraGetFrameID(g_hCamera, &uid);
				qDebug() << "uid:" << uid;
				if (0 == count)
				{
					count = uid;
				}
				//if (count > 65535)
				//{
				//	count = 1;

				//}
				if (count != uid)
				{
					emit lostPic();
					emit stopSweepMeasure();
					break;
				}

				//根据频率抓图次数分情况
				if (1 == picNums)//cv_16u
				{
					if (0 == switchNum)
					{
						
						onMat = dst.clone();
						switchNum = 1;
						count++;
						
						
					}
					else
					{
						
						offMat = dst.clone();
						switchNum = 0;
						count++;
				
						emit GetSweepData(g_SweepFreStart, onMat, offMat);
						g_SweepFreStart += g_SweepFreStep;
						onMat.release();
						offMat.release();


					}
				}
				else//cv_32f
				{
					if (0 == switchNum)
					{
						
						if (onMat.empty()) {
							dst.convertTo(dst, CV_32FC1);
							onMat = dst.clone();
						}
						else {
							dst.convertTo(dst, CV_32FC1);
							onMat += dst;
						}
						countOn++;
						count+=1;
						switchNum = 1;
						if (countOn == picNums)
						{
							emit GetPic(onMat);
							countOn = 0;

						}

					}
					else
					{
						
						if (offMat.empty()) {
							dst.convertTo(dst, CV_32FC1);
							offMat = dst.clone();
						}
						else {
							dst.convertTo(dst, CV_32FC1);
							offMat += dst;
						}
						countOff++;
						count+=1;
						switchNum = 0;

						if (countOff!=picNums)
						{
							emit plusEnd(0);
							
						}

						if (countOff == picNums)
						{
							emit GetPic(offMat);
							countOff = 0;

							emit GetSweepData(g_SweepFreStart, onMat, offMat);
							

							g_SweepFreStart += g_SweepFreStep;
							qDebug() << g_SweepFreStart;
							onMat.release();
							offMat.release();

							emit plusEnd(1);
							

						}
					}

				}
				/*free(rawBuffer);
				rawBuffer = NULL;*/

			}
			else
			{
				qDebug() << "Grab the hardware trigger frame failure" << g_SweepFreStart;
				qDebug() << iii;
			}
			

		}
		else
		{
			usleep(1000);
		}
			
	}//end forever
}

void MVCameraSweep::stream()
{
	pause_status = false;
}

void MVCameraSweep::pause()
{
	pause_status = true;
}

void MVCameraSweep::stop()
{
	pause_status = false;
	quit = true;
}
