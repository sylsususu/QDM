#pragma once

#include <QTcpSocket>
#include <QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "FrameBase.h"

class MicrowaveSrcCtlNewProtocol : public QObject
{
	Q_OBJECT
public:
	MicrowaveSrcCtlNewProtocol(QObject *parent = 0);
	~MicrowaveSrcCtlNewProtocol();

	QTcpSocket *m_socket;
	QSerialPort *m_serial;
	QByteArray buf;
	bool isTcp;
	bool isSeril;

	/// <summary>
	/// 复位帧
	/// </summary>
	FrameReset *m_Reset;

	/// <summary>
	/// 心跳检测帧
	/// </summary>
	FrameHeartbeat *m_Heartbeat;

	/// <summary>
	/// 命令帧
	/// </summary>
	FrameCommand *m_Command;

	/// <summary>
	/// 参数帧
	/// </summary>
	FrameParam *m_Param;

	/// <summary>
	/// 查询帧
	/// </summary>
	FrameQuery *m_Query;

	/// <summary>
	/// 连接
	/// </summary>
	/// <param name="QString">IP地址</param>
	/// <param name="int">Port端口</param>
	/// <returns></returns>
	bool b_Connected(QString, int);

	/// <summary>
	/// 打开串口
	/// </summary>
	/// <param name="">串口名</param>
	/// <param name="">波特率</param>
	/// <param name="">数据位</param>
	/// <param name="">奇偶校验位</param>
	/// <param name="">停止位</param>
	/// <param name="">流控</param>
	/// <returns></returns>
	bool connectToPort(QString, int, QSerialPort::DataBits, QSerialPort::Parity, QSerialPort::StopBits, QSerialPort::FlowControl);

	/// <summary>
	/// 断开链接
	/// </summary>
	void disConnect();

	/// <summary>
	/// 关闭串口
	/// </summary>
	void closePort();

	/// <summary>
	/// 复位
	/// </summary>
	void setReSet();

	/// <summary>
	/// 心跳检测
	/// </summary>
	void setHeartbeatDetection();

	/// <summary>
	/// 设置工作模式
	/// </summary>
	/// <param name="freq_mode">点频：0 扫频：1</param>
	/// <param name="trigger_mode">内触发：0 外触发：1</param>
	/// <param name="scan_seq">工作顺序：正序：0 逆序：1</param>
	/// <param name="scan_mode">工作次数：有限次：0 无限次：1</param>
	/// <param name="mw_sw_en">微波开：1 微波关：0</param>
	/// <param name="Select_Clk">内参考：0  外参考：1</param>
	/// <param name="Set_Clk_Out">晶振输出：1  晶振不输出：0</param>
	void setWorkMode(int freq_mode, int trigger_mode, int scan_seq, int scan_mode, int mw_sw_en, int Select_Clk, int Set_Clk_Out);

	/// <summary>
	/// 扫频参数配置
	/// </summary>
	/// <param name="">起始频率</param>
	/// <param name="">终止频率</param>
	/// <param name="">步进长度</param>
	void setSweepParameters(uint, uint, uint);
	
	/// <summary>
	/// 启动
	/// </summary>
	void startOut();

	/// <summary>
	/// 停止
	/// </summary>
	void stopOut();

	/// <summary>
	/// 内触发频率设置
	/// </summary>
	/// <param name="">内触发频率</param>
	void setInternalTriggerFrequencyParameters(uint);

	/// <summary>
	/// 扫频次数配置
	/// </summary>
	/// <param name="">扫频次数</param>
	void setScanNum(uint);
	
	/// <summary>
	/// 点频参数配置
	/// </summary>
	/// <param name="">点频频率</param>
	void setPointFrequencyParameters(uint);
	
	/// <summary>
	/// 工作状态查询
	/// </summary>
	void checkState();

private slots:

	/// <summary>
	/// tcp解包
	/// </summary>
	void slotReadData();

signals:

	/// <summary>
	/// 
	 /*
	 Name :
	 Output:(int)
		 0 : 复位成功
		 1 : 复位失败
		 10 : 心跳正常
		 20 : 启动成功
		 21 : 启动失败
		 30 : 停止成功
		 31 : 停止失败
		 40 : 工作模式配置成功
		 41 : 工作模式配置失败
		 50 : 点频参数配置成功
		 51 : 点频参数配置失败
		 60 : 扫频参数配置成功
		 61 : 扫频参数配置失败
		 70 : 内触发频率设置成功
		 71 : 内触发频率设置失败
		 80 : 扫频次数配置成功
		 81 : 扫频次数配置失败
		 90 : 扫频中
		 91 : 扫频完成
		 0000 : 未知消息接收

		 Other：请以信号槽方式监听
	 */
	/// </summary>
	void getRecSignals(int);
};

