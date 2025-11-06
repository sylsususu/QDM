#pragma once
#include <QSerialPort>
#include <QDebug>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <QObject>
#include <QThread>
#include <QTimer>
#include <windows.h>
#include <QElapsedTimer>
#include<qserialport.h>
#include<qserialportinfo.h>


class CurrentSource : public QObject
{

	Q_OBJECT

private:
	float _current; // 电流值
	float _voltage; // 电压值
	QSerialPort* port; // 串口对象
	QString port_name; // 串口号

	// CRC校验
	uint16_t calculateCRC16(const uint8_t* data, size_t length);

	QByteArray getCurrentAndVoltageData;
	// 浮点数转为QByteArray
	QByteArray setCurrentData;
	QByteArray setVoltageData;
	QByteArray setOutData;
	QByteArray setCurrentAndVoltageData;
	QTimer* timer;

public:
	// 构造函数
	CurrentSource();
	// 析构函数
	~CurrentSource();

	// 连接电流源
	bool currentConnect(const QString& name);

	bool CurrentSource::disCurrentConnect();

	// 实时读取电压电流
	void  realTimeReading(bool isRealTimeReading);

	// 设置电流值
	void setCurrent(float current);

	// 设置电压值
	void setVoltage(float voltage);

	// 设置电流和电压
	void setCurrentAndVoltage(float current, float voltage);

	// 设置开关
	void setOut(bool isOut);

	// 设置上电初始值
	void setInitVal(float current, float voltage, bool isOut);

public slots:
	// 获取电流值和电压值
	void getCurrentAndVoltage();

	// 读取从机回报
	void onReadyRead();

signals:
	// 发送电流值和电压值
	void GetCurrentAndVoltage(float _current, float voltage);
	// 发送电流设置完成信号
	void setCurrentOK();
	// 发送电压设置完成信号
	void setVoltageOK();
	// 发送开关设置完成信号
	void setOutOK();
	// 发送电流和电压设置完成信号
	void setCurrentAndVoltageOK();
	
};

