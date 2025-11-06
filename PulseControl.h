#pragma once
#include "./pulseSdk/USB3000.h"
#include <QVector>
#include <QCoreApplication>
#include <QMessageBox>
#include <windows.h>
#include <QTimer>
#include<qDebug>
class PulseControl
{
private:
	~PulseControl();
	
public:
	
	bool pulseConnect();
	bool pulseDisConect();
	
	void clearPulse();
	void startPulse(int cycleTime, int pulseNumbers,  QVector<float> A0, QVector<float> A1, QVector<float> A2,unsigned int ms);
	void startPulse_LockIn(int cycleTime, int pulseNumbers, QVector<float> A0, QVector<float> A1, QVector<float> A2, unsigned int ms);
	void Sleep(int msec)
	{
		QEventLoop loop;//定义一个新的事件循环
		QTimer::singleShot(msec, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
		loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
	}

};

