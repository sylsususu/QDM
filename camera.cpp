#include "camera.h"

extern TUCAM_INIT m_itApi;       // SDK API initialized object
extern TUCAM_OPEN m_opCam;       // Open camera object
extern TUCAM_FRAME m_frame;      // The frame object
extern TUCAM_TRIGGER_ATTR m_tgr; // The trigger object



camera::~camera()
{
	uninitCamera();
	
}

bool camera::initCamera()
{
	m_itApi.uiCamCount = 0;
	m_itApi.pstrConfigPath = const_cast<PCHAR>("./");


	TUCAM_Api_Init(&m_itApi);
	printf("Connect %d camera\r\n", m_itApi.uiCamCount);
	if (0 == m_itApi.uiCamCount)
	{
		//没有相机
		return false;
	}

	return true;
}

bool camera::uninitCamera()
{
	TUCAM_Api_Uninit();
	return true;
}

bool camera::openCamera(UINT uiIdx)
{
	
	if (uiIdx >= m_itApi.uiCamCount)
	{
		return false;
	}
	m_opCam.hIdxTUCam = 0;
	m_opCam.uiIdxOpen = uiIdx;

	if (TUCAMRET_SUCCESS == TUCAM_Dev_Open(&m_opCam))
	{
		
		
		return true;
	}
	return false;
}

bool camera::closeCamera()
{
	if (NULL != m_opCam.hIdxTUCam)
	{
		TUCAM_Dev_Close(m_opCam.hIdxTUCam);
	}
	printf("Close the camera success\r\n");
	return true;
}

bool camera::getCameraExpTime(double & exposureTime)
{
	if (TUCAMRET_SUCCESS == TUCAM_Prop_GetValue(m_opCam.hIdxTUCam, TUIDP_EXPOSURETM, &exposureTime))
	{
		return true;//ms
	}

	return false;
	
}

bool camera::setCameraRoi(int X, int Y, int W, int H)
{
	TUCAM_ROI_ATTR camRoi;
	camRoi.bEnable = true;
	camRoi.nHOffset = X;
	camRoi.nVOffset =Y;
	camRoi.nWidth = W;
	camRoi.nHeight = H;
	if (TUCAMRET_SUCCESS == TUCAM_Cap_SetROI(m_opCam.hIdxTUCam, camRoi))
	{
		return true;
	}

	return false;
	
}

bool camera::setCameraExpMode(bool isAutoExpo)
{
	if (isAutoExpo)
	{
		if (TUCAMRET_SUCCESS==TUCAM_Capa_SetValue(m_opCam.hIdxTUCam, TUIDC_ATEXPOSURE, 1))
		{
			return true;
		}
		return false;
		
	}
	else
	{
		if (TUCAMRET_SUCCESS == TUCAM_Capa_SetValue(m_opCam.hIdxTUCam, TUIDC_ATEXPOSURE, 0))
		{
			return true;
		}
		return false;
		
	}
	
}

bool camera::setCameraExpTime(double exposureTime)
{
	if (TUCAMRET_SUCCESS== TUCAM_Prop_SetValue(m_opCam.hIdxTUCam, TUIDP_EXPOSURETM, exposureTime))
	{
		return true;
	}
	return false;
}

bool camera::setCameraTriggerMode(int TriggerMode)
{
	if (TriggerMode==0)
	{
		TUCAM_TRIGGER_ATTR tgrAttr;
		tgrAttr.nTgrMode = TUCCM_SEQUENCE; // 序列模式
		if (TUCAMRET_SUCCESS==TUCAM_Cap_SetTrigger(m_opCam.hIdxTUCam, tgrAttr))
		{
			return true;
		}
		
		

		
	}
	else if (TriggerMode==1)
	{
		
		TUCAM_Cap_GetTrigger(m_opCam.hIdxTUCam, &m_tgr);
		m_tgr.nTgrMode = (INT32)TUCCM_TRIGGER_SOFTWARE;
		m_tgr.nFrames = 1;
		if (TUCAMRET_SUCCESS==TUCAM_Cap_SetTrigger(m_opCam.hIdxTUCam, m_tgr))
		{
			return true;
		}
		
	}
	else
	{
		
		//
		TUCAM_Cap_GetTrigger(m_opCam.hIdxTUCam, &m_tgr);
		m_tgr.nTgrMode = TUCCM_TRIGGER_STANDARD; // 标准触发模式
		m_tgr.nExpMode = TUCTE_EXPTM; // 曝光模式
		m_tgr.nEdgeMode = TUCTD_RISING; // 激发上升沿
		m_tgr.nFrames = 1; // 触发 1 帧
		m_tgr.nDelayTm = 0; // 延时 0 ms
		if (TUCAMRET_SUCCESS== TUCAM_Cap_SetTrigger(m_opCam.hIdxTUCam, m_tgr))
		{
			return true;
		}
		


	}
	return false;
}

bool camera::setCameraImgMode(int imgMode)
{
	//0:标准模式16bit 1:低噪声模式14bit 2:低噪声模式16bit
	if (TUCAMRET_SUCCESS== TUCAM_Capa_SetValue(m_opCam.hIdxTUCam, TUIDC_IMGMODESELECT, imgMode))
	{
		return true;
	}
	
	return false;
}

bool camera::setCameraGain(int Gain)
{
	//0:标准模式14bit 1:低噪声模式14bit 2:低噪声模式16bit
	if (TUCAMRET_SUCCESS == TUCAM_Prop_SetValue(m_opCam.hIdxTUCam, TUIDP_GLOBALGAIN, Gain))
	{
		return true;
	}

	return false;
	
}

cv::Mat camera::cameraSoftTriggerOnce()
{
	cv::Mat dst;
	int nTimes = 1;

	m_frame.pBuffer = NULL;
	m_frame.ucFormatGet = TUFRM_FMT_USUAl;
	m_frame.uiRsdSize = 1;

	TUCAM_Cap_GetTrigger(m_opCam.hIdxTUCam, &m_tgr);
	m_tgr.nTgrMode = (INT32)TUCCM_TRIGGER_SOFTWARE;
	m_tgr.nFrames = 1;
	TUCAM_Cap_SetTrigger(m_opCam.hIdxTUCam, m_tgr);

	TUCAM_Buf_Alloc(m_opCam.hIdxTUCam, &m_frame);

	long lRet = (long)TUCAMRET_NOT_SUPPORT;

	if (TUCAMRET_SUCCESS == TUCAM_Cap_Start(m_opCam.hIdxTUCam, (UINT32)TUCCM_TRIGGER_SOFTWARE))
	{
		for (int i = 0; i < nTimes; ++i)
		{
			/* Send software trigger signal */
			lRet = (long)TUCAM_Cap_DoSoftwareTrigger(m_opCam.hIdxTUCam);

			if ((long)TUCAMRET_SUCCESS == lRet)
			{
				if (TUCAMRET_SUCCESS == TUCAM_Buf_WaitForFrame(m_opCam.hIdxTUCam, &m_frame))
				{
					printf("Grab the software trigger frame success, index number is %d, width:%d, height:%d, channel:%d, depth:%d, image size:%d\r\n", i, m_frame.usWidth, m_frame.usHeight, m_frame.ucChannels, (2 == m_frame.ucElemBytes) ? 16 : 8, m_frame.uiImgSize);
					int type = CV_MAKETYPE(m_frame.ucDepth, m_frame.ucChannels);//CV_16U
					uchar *data = m_frame.pBuffer + m_frame.usHeader;
					dst = cv::Mat(m_frame.usHeight, m_frame.usWidth, type, data);
					TUCAM_IMG_HEADER ImgHeader;
					memcpy(&ImgHeader, m_frame.pBuffer, sizeof(TUCAM_IMG_HEADER));
					qDebug() << "index:" << ImgHeader.uiIndex;
				
#pragma omp parallel for num_threads(64)
					for (int i = 0; i < dst.rows; i++) {
						ushort* ptr = dst.ptr<ushort>(i);
						for (int j = 0; j < dst.cols; j++) {
							ptr[j] /= 64;
						}
					}

					dst.convertTo(dst, CV_8U);
					
					
					
				}
				else
				{
					printf("Grab the software trigger frame failure, index number is %d\r\n", i);
				}
			}
			else if ((long)TUCAMRET_NOT_SUPPORT == lRet)
			{
				printf("This camera cannot support software trigger\r\n");
				break;
			}
			else
			{
				printf("Send the software trigger signal failure\r\n");
			}
		}

		TUCAM_Buf_AbortWait(m_opCam.hIdxTUCam);
		TUCAM_Cap_Stop(m_opCam.hIdxTUCam);
	}

	TUCAM_Buf_Release(m_opCam.hIdxTUCam);
	return dst;
}

bool camera::setCameraContrast(int Contrast)
{
	if (TUCAMRET_SUCCESS == TUCAM_Prop_SetValue(m_opCam.hIdxTUCam, TUIDP_CONTRAST, Contrast))
	{
		return true;
	}
	
	return false;
}

bool camera::setCameraGamma(int Gamma)
{
	if (TUCAMRET_SUCCESS == TUCAM_Prop_SetValue(m_opCam.hIdxTUCam, TUIDP_GAMMA, Gamma))
	{
		return true;
	}
	return false;
}

bool camera::getCameraContrast(double & Contrast)
{
	
	if (TUCAMRET_SUCCESS == TUCAM_Prop_GetValue(m_opCam.hIdxTUCam, TUIDP_CONTRAST, &Contrast))
	{
		return true;
	}
	return false;
}

bool camera::getCameraGamma(double & Gamma)
{
	if (TUCAMRET_SUCCESS == TUCAM_Prop_GetValue(m_opCam.hIdxTUCam, TUIDP_GAMMA, &Gamma))
	{
		return true;
	}
	return false;
}


