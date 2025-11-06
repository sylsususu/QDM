#pragma once
#include <windows.h>
#include "CameraApi.h"
#include <opencv2/opencv.hpp>
#include<omp.h>
#include <QImage>
#include "CameraDataProcess.h"
class MVCamera
{
public:
	MVCamera();
	~MVCamera();
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
	bool getCameraRoi(int &X, int &Y, int &W, int &H);

	// 设置相机感兴趣区域
	bool setCameraRoi(int X,int Y,int W,int H);

	// 设置相机曝光模式
	bool setCameraExpMode(bool isAutoExpo);

	// 设置相机曝光时间
	bool setCameraExpTime(double exposureTime);

	// 设置相机触发模式
	bool setCameraTriggerMode(int TriggerMode);
	
	//独有
	//设置相机增益
	bool setCameraGain(int Gain);

	//独有
	//读取相机Gain
	bool getCameraGain(int &Gain);

	// 一次软件触发相机并获取图像
	QImage cameraSoftTriggerOnce();

	//设置相机对比度0-200 默认值100
	bool setCameraContrast(int Contrast);

	//设置相机gamma1-250 默认值100
	bool setCameraGamma(int Gamma);

	//读取相机对比度
	bool getCameraContrast(double &Contrast);

	//读取相机gamma
	bool getCameraGamma(double &Gamma);

	//独有
	//清空相机缓存
	bool clearCameraBuffer();

	

private:
	QVector<QRgb> grayColourTable;

};

