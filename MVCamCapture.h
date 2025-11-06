#pragma once
#include <QThread>
#include <QImage>
#include <opencv2/opencv.hpp>
#include "CameraDataProcess.h"
class MVCamCapture : public QThread
{
	Q_OBJECT
public:
	explicit MVCamCapture(QObject *parent = 0);

public:
	void run();
	void stream();
	void pause();
	void stop();

	bool quit;


signals:
	void camCap(cv::Mat);

	void getfps();
	void getCapTime(double t);
private:
	bool pause_status;
	cv::Mat dst;
	time_t ts;
};
