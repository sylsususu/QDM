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

class MVCameraFix : public QThread
{
	Q_OBJECT
public:
	explicit MVCameraFix(QObject* parent = 0);
public:
	void run();
	void stream();
	void pause();
	void stop();

private:
	bool pause_status;
	bool quit;

	cv::Mat onMat, offMat;
	cv::Mat dst;
	int picNum;
	int iterTime;
	uint count;

signals:
	void GetMat(cv::Mat, cv::Mat);
	void GetFixMat(int index,cv::Mat);
	void stopFixMeasure();

	void lostPic();
};

