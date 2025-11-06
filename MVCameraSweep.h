#pragma once
#include<qimage.h>
#include <QThread>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include<omp.h>
#include "MVCamera.h"
#include"CameraDataProcess.h"
#include <QElapsedTimer>
using namespace std;

class MVCameraSweep : public QThread
{
	Q_OBJECT
public:
	explicit MVCameraSweep(QObject* parent = 0);

public:
	void run();
	void stream();
	void pause();
	void stop();

	void setPicNums(int nums) {
		picNums = nums;
	}
signals:
	void GetSweepData(double value, cv::Mat on, cv::Mat off);

	void GetPic(cv::Mat showMat);

	void stopSweepMeasure();

	void lostPic();

	void plusEnd(int s);

	void GetSweepData2(double Frevalue, int itemTime, unsigned char*);
private:
	int switchNum; //切换微波开关标志
	bool pause_status;
	int picNums;//频率抓图次数

	int count = 0;
	int countOn;//数量
	int countOff;//数量
	cv::Mat onMat, offMat;
	cv::Mat dst;
	bool quit;
	int iterTime;
};

