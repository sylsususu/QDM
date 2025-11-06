#include "FixMeasureThread.h"
#include <windows.h>
#include<QtConcurrent/qtconcurrentrun.h>



extern int g_Width;
extern int g_Height;
extern double g_SweepFreStart;
extern double g_SweepFreEnd;
extern double g_SweepFreStep;
extern double g_FixedFre;
extern int g_IterationTime;
extern bool isAutoSave;
extern int g_uiPicWidth;
extern int g_uiPicHeigth;
extern bool g_is_Binning;
extern int g_bin;


//FLcamerasdk
#include "./camerasdk/inc/TUCamApi.h"                         // 导入SDK头文件
#ifdef _WIN64
#pragma comment(lib, "./camerasdk/lib/x64/TUCam.lib")
#else
#pragma comment(lib, "./camerasdk/lib/x86/TUCam.lib")
#endif

extern TUCAM_INIT m_itApi;       // SDK API initialized object
extern TUCAM_OPEN m_opCam;       // Open camera object
extern TUCAM_FRAME m_frame;      // The frame object
extern TUCAM_TRIGGER_ATTR m_tgr; // The trigger object



FixMeasureThread::FixMeasureThread(QObject* parent) :
    QThread(parent)
{

    pause_status = true;
    quit = false;
	picNum = 0;
    iterTime = 0;
    qRegisterMetaType<cv::Mat>("cv::Mat");
}

void FixMeasureThread::run()
{

	
	quit = false;

    iterTime = 0;
	count = 0;
    forever
    {

		if (!pause_status)
		{

			m_frame.pBuffer = NULL;
			m_frame.ucFormatGet = TUFRM_FMT_USUAl;
			m_frame.uiRsdSize = 1;
			TUCAM_Buf_Alloc(m_opCam.hIdxTUCam, &m_frame);


			if (TUCAMRET_SUCCESS == TUCAM_Cap_Start(m_opCam.hIdxTUCam, (UINT32)TUCCM_TRIGGER_STANDARD))
			{
				while (1)
				{
					if (quit)
					{
						break;
					}
					if (iterTime >= g_IterationTime)
					{

						break;
					}
					
					if (TUCAMRET_SUCCESS == TUCAM_Buf_WaitForFrame(m_opCam.hIdxTUCam, &m_frame))
					{

						int type = CV_MAKETYPE(m_frame.ucDepth, m_frame.ucChannels);
						uchar *data = m_frame.pBuffer + m_frame.usHeader;
						dst = cv::Mat(m_frame.usHeight, m_frame.usWidth, type, data);
						//丢帧判断
						TUCAM_IMG_HEADER ImgHeader;
						memcpy(&ImgHeader, m_frame.pBuffer, sizeof(TUCAM_IMG_HEADER));
						if (0==iterTime)
						{
							count = ImgHeader.uiIndex;
						}
						else
						{
							if (count>255)
							{
								count = 0;
							}
							if (count != ImgHeader.uiIndex)
							{
								//TODO:增加信号，发送到主线程，报告丢帧问题
								emit lostPic();
								break;
							}
						}
						
						//binning算法
						if (g_is_Binning)
						{

							cv::resize(dst, dst, cv::Size(g_Width/g_bin, g_Height/g_bin));

						}				

						if (picNum == 0)
						{
							onMat = dst.clone();	
							picNum = 1;
							count++;
							
							//qDebug() << "index:" << ImgHeader.uiIndex;
						}
						else
						{
							offMat = dst.clone();
							picNum = 0;
							count++;
							emit GetMat(onMat, offMat);
							//qDebug() <<  "index:" << ImgHeader.uiIndex;
							
							iterTime++;
							

						}
					}
					else
					{
						printf("Grab the hardware trigger frame failure, ret is %d\r\n", count);
					}




				}

				TUCAM_Buf_AbortWait(m_opCam.hIdxTUCam);
				TUCAM_Cap_Stop(m_opCam.hIdxTUCam);
			}

			TUCAM_Buf_Release(m_opCam.hIdxTUCam);
			emit stopFixMeasure();
			break;
			
        }
        else
            usleep(1000);
		
    }
}

void FixMeasureThread::stream()
{
    pause_status = false;
}

void FixMeasureThread::pause()
{
    pause_status = true;
}

void FixMeasureThread::stop()
{
    pause_status = false;
    quit = true;
}
