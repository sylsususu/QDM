#pragma once
#include<qudpsocket.h>

class PulseUDPCom
{
private:
	
	QHostAddress remoteAddress;
	qint16 remotePort;
public:
	QUdpSocket* m_socket;
public:
	PulseUDPCom( QHostAddress localAddress, qint16 localPort , QHostAddress remoteAddress, qint16 remotePort);
	~PulseUDPCom();

	/// <summary>
	/// 构建除功能码不同，其他相同的包头
	/// </summary>
	/// <param name="code">代表功能码 </param>
	/// <returns></returns>
	QByteArray constructHeader(char code);

	/// <summary>
	/// QString到16进制字符串
	/// </summary>
	/// <param name="str">输入字符串</param>
	/// <param name="byteData">输出16进制数</param>
	void convertStringToHex(const QString& str, QByteArray& byteData);	
	char convertCharToHex(char ch);

	/// <summary>
	/// 发送脉宽设置命令
	/// </summary>
	/// <param name="channel">通道号</param>
	/// <param name="loopNo">loop编号</param>
	/// <param name="pulseEdgeNo">脉冲沿编号</param>
	/// <param name="pulseEdgeTime">脉冲沿时间</param>
	void sendPulseWidth(char channel, int loopNo, int pulseEdgeNo, int pulseEdgeTime);

	/// <summary>
	/// 发送循环时长设置指令
	/// </summary>
	/// <param name="channel">通道号</param>
	/// <param name="loopNo">loop编号</param>
	/// <param name="loopTime">循环时长</param>
	void sendLoopTime(char channel, int loopNo,int loopTime);

	/// <summary>
	///  发送通道循环次数指令
	/// </summary>
	/// <param name="channel">通道号</param>
	/// <param name="loopNo">loop编号</param>
	/// <param name="loopNumber">循环次数</param>
	void sendLoopCycleNumber(char channel, int loopNo, int loopNumber);

	/// <summary>
	/// 发送设置处理模式命令
	/// </summary>
	/// <param name="channel">通道号</param>
	/// <param name="loopNo">loop编号</param>
	/// <param name="strModeBinary">处理模式，32位二进制字符串，从右边开始第一位</param>
	void sendProcessMode(char channel, int loopNo, QString strModeBinary);

	/// <summary>
	/// 发送启动输出指令
	/// </summary>
	void sendStartOut();

	/// <summary>
	/// 发送设置当前通道有多少个LOOP指令
	/// </summary>
	/// <param name="channel">通道号</param>
	/// <param name="loopNumber">LOOP的总数量</param>
	void sendLoopNumber(char channel, qint8 loopNumber);

	/// <summary>
	/// 发送设置LOOP个数设置生效指令
	/// </summary>
	void sendLoopNumberValidate();

	/// <summary>
	/// 发送心跳检测
	/// </summary>
	void sendHeartDetection();

	/// <summary>
	/// 清除某个通道内的波形
	/// </summary>
	/// <param name="channel">通道号</param>
	void sendClearChannel(char channel);
	
};

