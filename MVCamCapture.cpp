#include "MVCamCapture.h"
#include <QDebug>

#include <windows.h>
#include "CameraApi.h"

//SDK使用
extern int                  g_hCamera;          //设备句柄
extern unsigned char        * g_pRawBuffer;     //raw数据
extern unsigned char        * g_pRgbBuffer;     //处理后数据缓存区
extern tSdkFrameHead        g_tFrameHead;       //图像帧头信息
extern tSdkCameraCapbility  g_tCapability;      //设备描述信息


extern int g_uiPicWidth;
extern int g_uiPicHeigth;
extern int g_Width;
extern int g_Height;
extern bool g_is_Binning;
extern int g_bin;



MVCamCapture::MVCamCapture(QObject *parent) :
	QThread(parent)
{
	pause_status = true;
	quit = false;
	qRegisterMetaType<cv::Mat>("cv::Mat");
}

void MVCamCapture::run()
{
	quit = false;
	ts = clock();
	forever
	{
		if (!pause_status)
		{
			if (quit) break;
			if (CameraGetImageBuffer(g_hCamera,&g_tFrameHead,&g_pRawBuffer,2000) == CAMERA_STATUS_SUCCESS)
			{
				//emit getfps();
				time_t end = clock();
				double duration = (double)(end - ts) / CLOCKS_PER_SEC;
				ts = clock();
				emit getCapTime(duration);
			
				CameraDataProcess::rawChangetoMat(g_pRawBuffer, g_Width, g_Height, dst);
				CameraReleaseImageBuffer(g_hCamera, g_pRawBuffer);
				
				if (g_is_Binning)
				{
					cv::Mat resizedImage;
					cv::resize(dst, resizedImage, cv::Size(g_Width / g_bin, g_Height / g_bin));
					emit camCap(resizedImage);
					
				}
				else
				{

					emit camCap(dst);
					
				}
				
			}
			else {
				printf("timeout \n");
				usleep(1000);
			}
		}
		else usleep(1000);
		if (quit) break;
	}
}

void MVCamCapture::stream()
{
	pause_status = false;
}

void MVCamCapture::pause()
{
	pause_status = true;
}

void MVCamCapture::stop()
{
	pause_status = false;
	quit = true;
}

