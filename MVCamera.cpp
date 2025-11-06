#include "MVCamera.h"

extern int g_hCamera;                    //相机设备句柄
extern unsigned char* g_pRawBuffer;     //raw数据
extern unsigned char* g_pRgbBuffer;     //处理后数据缓存区
extern unsigned char* g_readBuf;        //画板显示数据区
extern tSdkFrameHead           g_tFrameHead;       //图像帧头信息
extern tSdkCameraCapbility     g_tCapability;      //设备描述信息
extern tSdkCameraDevInfo       tCameraEnumList[4];   //相机列表

extern int g_Width;
extern int g_Height;

MVCamera::MVCamera()
{
	for (int i = 0; i < 256; i++)
	{
		grayColourTable.append(qRgb(i, i, i));
	}
}

MVCamera::~MVCamera()
{
}

bool MVCamera::initCamera()
{
	int iCameraCounts = 4;
	int iStatus = -1;
	//初始化  0 English 1中文
	iStatus=CameraSdkInit(1);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}
	//枚举设备，并建立设备列表
	iStatus=CameraEnumerateDevice(tCameraEnumList, &iCameraCounts);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}
	//没有连接设备
	if (iCameraCounts == 0)
	{
		return false;
	}

	iStatus = CameraInit(&tCameraEnumList[0], -1, -1, &g_hCamera);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{
		
		return false;
	}
	
	return true;
}

bool MVCamera::uninitCamera()
{
	int iStatus = CameraUnInit(g_hCamera);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}

	return true;
}

bool MVCamera::openCamera(UINT uiIdx)
{
	CameraSetFrameSpeed(g_hCamera, 2);
	CameraSetMediaType(g_hCamera, 1);//设置12bit输出
	CameraSetMirror(g_hCamera, 1, false);//禁用垂直翻转
	//获得相机的特性描述结构体。该结构体中包含了相机可设置的各种参数的范围信息。决定了相关函数的参数
	CameraGetCapability(g_hCamera, &g_tCapability);

	g_pRgbBuffer = (unsigned char*)malloc(g_tCapability.sResolutionRange.iHeightMax*g_tCapability.sResolutionRange.iWidthMax * 3);
	g_readBuf = (unsigned char*)malloc(g_tCapability.sResolutionRange.iHeightMax*g_tCapability.sResolutionRange.iWidthMax * 3);
	int iStatus = CameraPlay(g_hCamera);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}

	return true;
}

bool MVCamera::closeCamera()
{
	
	int iStatus = CameraStop(g_hCamera);
	free(g_pRgbBuffer);
	free(g_readBuf);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}

	return true;
}

bool MVCamera::getCameraExpTime(double & exposureTime)
{
	int iStatus = CameraGetExposureTime(g_hCamera, &exposureTime);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}

	return true;
}

bool MVCamera::getCameraRoi(int & X, int & Y, int & W, int & H)
{
	tSdkImageResolution sRoiResolution = { 0 };
	//预览的分辨率。
	int iStatus = CameraGetImageResolution(g_hCamera, &sRoiResolution);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}
	// 宽度
	W=sRoiResolution.iWidth;
	// 高度
	H=sRoiResolution.iHeight ;
	// 视场偏移
	X=sRoiResolution.iHOffsetFOV;

	Y=sRoiResolution.iVOffsetFOV;
	return true;
}

bool MVCamera::setCameraRoi(int X, int Y, int W, int H)
{
	tSdkImageResolution sRoiResolution = { 0 };

	// 设置成 0xff 表示自定义分辨率，设置成 0 到 N 表示选择预设分辨率
	sRoiResolution.iIndex = 0xff;
	// 宽度
	sRoiResolution.iWidth = W;
	sRoiResolution.iWidthFOV = W;
	// 高度
	sRoiResolution.iHeight = H;
	sRoiResolution.iHeightFOV = H;

	// 视场偏移
	sRoiResolution.iHOffsetFOV = X;

	sRoiResolution.iVOffsetFOV = Y;

	// 软件缩放宽高，都为 0 则表示不缩放
	sRoiResolution.iWidthZoomSw = 0;
	sRoiResolution.iHeightZoomSw = 0;

	//设置预览的分辨率。
	int iStatus = CameraSetImageResolution(g_hCamera, &sRoiResolution);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}

	return true;
}

bool MVCamera::setCameraExpMode(bool isAutoExpo)
{
	//TRUE:自动曝光；FALSE:手动曝光。
	int iStatus = CameraSetAeState(g_hCamera, isAutoExpo);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}

	return true;
}

bool MVCamera::setCameraExpTime(double exposureTime)
{
	int iStatus = CameraSetExposureTime(g_hCamera, exposureTime);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}

	return true;
}

bool MVCamera::setCameraTriggerMode(int TriggerMode)
{
	//模式选择索引号。0: 连续采集；1: 软件触发；2: 硬件触发（线阵为帧触发）；3: 行触发（编码器触发）（仅线阵）；4: 条件行触发（仅线阵）；
	CameraSetExtTrigSignalType(g_hCamera, 0);//上升沿
	CameraSetExtTrigDelayTime(g_hCamera, 0);
	CameraSetExtTrigJitterTime(g_hCamera, 0);
	int iStatus = CameraSetTriggerMode(g_hCamera, TriggerMode);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}

	return true;
}

bool MVCamera::setCameraGain(int Gain)
{
	/*
		设置相机的图像模拟增益值。该值乘以CameraGetCapability获得
		的相机属性结构体中sExposeDesc.fAnalogGainStep=0.1，就
		得到实际的图像信号放大倍数。
	*/
	int iStatus = CameraSetAnalogGain(g_hCamera, Gain);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}

	return true;
}

bool MVCamera::getCameraGain(int & Gain)
{
	int iStatus = CameraGetAnalogGain(g_hCamera, &Gain);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}

	return true;
}

QImage MVCamera::cameraSoftTriggerOnce()
{
	
	int gama, contrust;
	CameraGetGamma(g_hCamera, &gama);
	CameraGetSaturation(g_hCamera, &contrust);
	CameraClearBuffer(g_hCamera);
	CameraSoftTrigger(g_hCamera);
	CameraGetImageBuffer(g_hCamera, &g_tFrameHead, &g_pRawBuffer, 2000);
	//在设置时集中反转了
	//CameraFlipFrameBuffer(g_pRawBuffer, &g_tFrameHead, 1);
	CameraImageProcess(g_hCamera, g_pRawBuffer, g_pRgbBuffer, &g_tFrameHead);
	CameraReleaseImageBuffer(g_hCamera, g_pRawBuffer);
	QImage image(g_pRgbBuffer, g_Width, g_Height, QImage::Format_RGB888);


	return image;
}

bool MVCamera::setCameraContrast(int Contrast)
{
	/*
	   设定LUT动态生成模式下的对比度值。设定的值会
	   马上保存在SDK内部，但是只有当相机处于动态
	   参数生成的LUT模式时，才会生效。
   */
	
	int iStatus = CameraSetContrast(g_hCamera, Contrast);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}

	return true;
}

bool MVCamera::setCameraGamma(int Gamma)
{
	
	int iStatus = CameraSetGamma(g_hCamera, Gamma);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}

	return true;
}

bool MVCamera::getCameraContrast(double & Contrast)
{
	
	//获得LUT动态生成模式下的Gamma值。
	int tmp_contrast = -1;
	int iStatus = CameraGetGamma(g_hCamera, &tmp_contrast);
	
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}
	Contrast = (double)tmp_contrast;
	return true;

}

bool MVCamera::getCameraGamma(double & Gamma)
{
	//获得LUT动态生成模式下的对比度值
	int tmp_gamma = -1;
	int iStatus = CameraGetContrast(g_hCamera, &tmp_gamma);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}
	Gamma = (double)tmp_gamma;
	return true;
}

bool MVCamera::clearCameraBuffer()
{
	int iStatus = CameraClearBuffer(g_hCamera);
	if (iStatus != CAMERA_STATUS_SUCCESS)
	{

		return false;
	}
	return true;
}


