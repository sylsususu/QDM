#pragma once
#include <QThread>
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include<qmetatype.h>
#include <QThread>
#include <QTimer>
#include <omp.h>
#include <time.h>
using namespace std;
class CtuCamCap :public QThread
{
	Q_OBJECT
public:
	explicit CtuCamCap(QObject* parent = 0);

public:
	void run();
	void stream();
	void pause();
	void stop();
	
private:
	bool pause_status;
	bool quit;
	cv::Mat dst;

signals:
	void camCap(cv::Mat);
	void getfps();
};



