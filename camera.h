#pragma once
//FLCamera SDK
#include "./camerasdk/inc/TUCamApi.h"                        
#include <conio.h> 
#ifdef _WIN64
#pragma comment(lib, "./camerasdk/lib/x64/TUCam.lib")
#else
#pragma comment(lib, "./camerasdk/lib/x86/TUCam.lib")
#endif
#include <QRect>
#include <opencv2/opencv.hpp>
#include<qdebug.h>
#include<omp.h>
class camera
{
public:
	~camera();

public:
	// 初始化相机
	bool initCamera();

	// 反初始化相机
	bool uninitCamera();

	// 打开相机
	bool openCamera(UINT uiIdx);

	// 关闭相机
	bool closeCamera();

	// 获取相机曝光时间
	bool getCameraExpTime(double &exposureTime);

	// 设置相机感兴趣区域
	bool setCameraRoi(int X, int Y, int W, int H);

	// 设置相机曝光模式
	bool setCameraExpMode(bool isAutoExpo);

	// 设置相机曝光时间
	bool setCameraExpTime(double exposureTime);

	// 设置相机触发模式
	bool setCameraTriggerMode(int TriggerMode);

	// 设置相机图像模式（0:标准模式16bit 1:低噪声模式14bit 2:低噪声模式16bit）
	bool setCameraImgMode(int imgMode);

	//设置相机增益(0.1.2.3)
	bool setCameraGain(int Gain);

	// 一次软件触发相机并获取图像
	cv::Mat cameraSoftTriggerOnce();

	//设置相机对比度0-255 默认值128
	bool setCameraContrast(int Contrast);

	//设置相机gamma1-255 默认值100
	bool setCameraGamma(int Gamma);

	//读取相机对比度
	bool getCameraContrast(double &Contrast);

	//读取相机gamma
	bool getCameraGamma(double &Gamma);
};

