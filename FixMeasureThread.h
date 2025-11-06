#pragma once
#include <QThread>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include<qmetatype.h>

using namespace std;
class FixMeasureThread :public QThread
{
    Q_OBJECT
public:
    explicit FixMeasureThread(QObject* parent = 0);

public:
    void run();
    void stream();
    void pause();
    void stop();
	void initPicNum() {
		picNum = 0;
	}
private:
    bool pause_status;
    bool quit;

    cv::Mat onMat, offMat;
	cv::Mat dst;
    int picNum;
    int iterTime;
	int count;
	
signals:
    void GetMat(cv::Mat ,cv::Mat);
    void stopFixMeasure();
	void lostPic();

};

