#include "CtuCamCap.h"
#include <windows.h>
#include<QtConcurrent/qtconcurrentrun.h>

//FLcamerasdk
#include "./camerasdk/inc/TUCamApi.h"                         // 导入SDK头文件
#ifdef _WIN64
#pragma comment(lib, "./camerasdk/lib/x64/TUCam.lib")
#else
#pragma comment(lib, "./camerasdk/lib/x86/TUCam.lib")
#endif
#include <vector>
typedef std::vector<unsigned char *> BUFFERS;
extern TUCAM_INIT m_itApi;       // SDK API initialized object
extern TUCAM_OPEN m_opCam;       // Open camera object
extern TUCAM_FRAME m_frame;      // The frame object
extern TUCAM_TRIGGER_ATTR m_tgr; // The trigger object
static BUFFERS m_buffers;
extern int g_uiPicWidth;
extern int g_uiPicHeigth;
extern int g_Width;
extern int g_Height;
extern bool g_is_Binning;
extern int g_bin;


CtuCamCap::CtuCamCap(QObject* parent) :
	QThread(parent)
{
	pause_status = true;
	quit = false;
	qRegisterMetaType<cv::Mat>("cv::Mat");
}



void destroyBuffers()
{
	int size = (int)m_buffers.size();

	for (int i = 0; i < size; ++i)
	{
		if (NULL != m_buffers[i])
		{
			delete[] m_buffers[i];
			m_buffers[i] = NULL;
		}
	}

	m_buffers.clear();
}

/* Create some custom buffers */
int createBuffers(int numBuffers, PTUCAM_FRAME pFrame)
{
	destroyBuffers();

	int bufferSize = pFrame->usHeader + pFrame->uiImgSize + pFrame->uiHstSize;

	for (int i = 0; i < numBuffers; ++i)
	{
		unsigned char *buffer = new unsigned char[bufferSize];

		// init header info
		memcpy(buffer, pFrame, sizeof(TUCAM_IMG_HEADER));

		PTUCAM_IMG_HEADER pImg = (PTUCAM_IMG_HEADER)(buffer);
		pImg->pImgData = buffer + pFrame->usHeader;
		pImg->pImgHist = (unsigned int*)(buffer + pFrame->usHeader + pFrame->uiImgSize);

		m_buffers.push_back(buffer);
	}

	return bufferSize;
}
void CtuCamCap::run()
{
	

	quit = false;
	forever
	{
		
		int nBuffers = 10;

		m_frame.pBuffer = NULL;
		m_frame.ucFormatGet = TUFRM_FMT_USUAl;
		m_frame.uiRsdSize = 1;
		TUCAM_Buf_Alloc(m_opCam.hIdxTUCam, &m_frame);
		int buffferSize = createBuffers(nBuffers, &m_frame);

		
		if (!pause_status)
		{
			
			if (TUCAMRET_SUCCESS == TUCAM_Cap_Start(m_opCam.hIdxTUCam, (UINT32)TUCCM_SEQUENCE))
			{
				int index = 0;
				int numBuffers = (int)m_buffers.size();

				unsigned char *pAttch = NULL;

				while(1)
				{
					if (quit)
					{

						break;
					}
					if (index < numBuffers)
					{
						// use custom buffer
						// after called TUCAM_Buf_Alloc
						TUCAM_Buf_Attach(m_opCam.hIdxTUCam, m_buffers[index], buffferSize);
						index++;
					}
					else
					{
						// restore internal buffer
						// before called TUCAM_Buf_Release
						TUCAM_Buf_Detach(m_opCam.hIdxTUCam);
					}

					
					if (TUCAMRET_SUCCESS == TUCAM_Buf_WaitForFrame(m_opCam.hIdxTUCam, &m_frame))
					{
						emit getfps();
						int type = CV_MAKETYPE(m_frame.ucDepth, m_frame.ucChannels);
						uchar *data = m_frame.pBuffer + m_frame.usHeader;
						dst = cv::Mat(m_frame.usHeight, m_frame.usWidth, type, data);
						cv::Mat resizedImage;
						//调用resizeImage函数
						if (g_is_Binning)
						{
							cv::resize(dst, resizedImage, cv::Size(g_Width/g_bin, g_Height/g_bin));
							emit camCap(resizedImage);
						}
						else
						{
							
							emit camCap(dst);
						}
						


						
						
					}
					else
					{
						printf("Grab the frame failure, index number is x\r\n");
					}
					
					
				}

				TUCAM_Buf_AbortWait(m_opCam.hIdxTUCam);
				TUCAM_Cap_Stop(m_opCam.hIdxTUCam);
			}

			TUCAM_Buf_Release(m_opCam.hIdxTUCam);
			destroyBuffers();
			if (quit)
			{

				break;
			}
		}
		

	}
	
	
	
	
}

void CtuCamCap::stream()
{
	pause_status = false;
}

void CtuCamCap::pause()
{
	pause_status = true;
}

void CtuCamCap::stop()
{
	

	pause_status = false;
	quit = true;
}



