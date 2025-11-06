#include "SweepMeasureThread.h"
#include <windows.h>
#include<QtConcurrent/qtconcurrentrun.h>




extern int g_Width;
extern int g_Height;
extern double g_SweepFreStart ;
extern double g_SweepFreEnd ;
extern double g_SweepFreStep ;
extern bool  isAutoSave;
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



SweepMeasureThread::SweepMeasureThread(QObject* parent) :
    QThread(parent)
{
    pause_status = true;
    quit = false;
	qRegisterMetaType<cv::Mat>("cv::Mat");

}



//除法
void SweepMeasureThread::run()
{
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
			m_frame.pBuffer = NULL;
			m_frame.ucFormatGet = TUFRM_FMT_USUAl;
			m_frame.uiRsdSize = 1;
			TUCAM_Buf_Alloc(m_opCam.hIdxTUCam, &m_frame);

			if (TUCAMRET_SUCCESS == TUCAM_Cap_Start(m_opCam.hIdxTUCam, (UINT32)TUCCM_TRIGGER_STANDARD))
			{
				while(1)
				{
					if (quit)
					{
						break;
					}
					if ((g_SweepFreStart - g_SweepFreEnd) >= g_SweepFreStep-0.00005)
					{

						break;
					}
					
					if (TUCAMRET_SUCCESS == TUCAM_Buf_WaitForFrame(m_opCam.hIdxTUCam, &m_frame))
					{

						int type = CV_MAKETYPE(m_frame.ucDepth, m_frame.ucChannels);
						uchar *data = m_frame.pBuffer + m_frame.usHeader;
						dst = cv::Mat(m_frame.usHeight, m_frame.usWidth, type, data);
						//qDebug() << count;
						//qDebug() << "freq:"<<g_SweepFreStart ;
						//丢帧判断
						TUCAM_IMG_HEADER ImgHeader;
						memcpy(&ImgHeader, m_frame.pBuffer, sizeof(TUCAM_IMG_HEADER));
						if (0 == count)
						{
							count = ImgHeader.uiIndex;
						}
						else
						{
							if (count > 255)
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
							cv::resize(dst, dst, cv::Size(g_Width/ g_bin, g_Height/ g_bin));
						}

						//根据频率抓图次数分情况
						if (1==picNums)//cv_16u
						{
							if (0==switchNum)
							{
								onMat = dst.clone();
								switchNum = 1;
								count++;
								emit GetPic(onMat);
								
							}
							else 
							{
								offMat = dst.clone();
								switchNum = 0;
								count++;
								emit GetPic(offMat);
								emit GetSweepData(g_SweepFreStart, onMat, offMat);
								g_SweepFreStart += g_SweepFreStep;
							
							}
						}
						else//cv_32f
						{
							if (0==switchNum)
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
								count++;
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
								count++;
								switchNum = 0;
								qDebug() << "g_SweepFreStart:" << g_SweepFreStart << "__count:" << countOff;
								if (countOff!= picNums)
								{
									emit plusEnd(0);
									//qDebug() << "plus0";
								}
								if (countOff == picNums)
								{
									emit GetPic(offMat);
									countOff = 0;

									emit GetSweepData(g_SweepFreStart, onMat, offMat);
									g_SweepFreStart += g_SweepFreStep;

									onMat.release();
									offMat.release();
									emit plusEnd(1);
									//qDebug() << "plus1";

								}
							}

						}
						
	

					}
					else
					{
						printf("Grab the hardware trigger frame failure, ret  is %lf\r\n", g_SweepFreStart);
					}
					
					
				}
				TUCAM_Buf_AbortWait(m_opCam.hIdxTUCam);
				TUCAM_Cap_Stop(m_opCam.hIdxTUCam);
				
			}
			TUCAM_Buf_Release(m_opCam.hIdxTUCam);
			emit stopSweepMeasure();
			break;
			

		}
		else
			usleep(1000);
		
		
	
	}
}


void SweepMeasureThread::stream()
{
    pause_status = false;
}

void SweepMeasureThread::pause()
{
    pause_status = true;
}

void SweepMeasureThread::stop()
{
    pause_status = false;
    quit = true;
}
