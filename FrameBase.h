/*****************************************
Copyright(C):国盛量子
Version:v1.0
Author:杨万阳
Date:2023/03/27
Description:数据帧基类
*****************************************/
#pragma once

#include <QObject>

class FrameBase 
{
public:
	FrameBase();
	~FrameBase();

	/// <summary>
	/// 设置帧数据-帧解析(反序列化)
	/// </summary>
	/// <param name="frame">帧数据</param>
	/// <returns>void</returns>
	void setFrameBuffer(QByteArray frame);

	/// <summary>
	/// 获取帧数据字节数组-帧组装(序列化)
	/// </summary>
	/// <param name="isFrameLengthCheck">是否需要帧长度校验，默认false</param>
	/// <returns>QByteArray</returns>
	QByteArray getFrameBuffer(bool isFrameLengthCheck = false);

	/// <summary>
	/// 设置消息属性
	/// </summary>
	/// <param name="msgId1">消息标识1，16进制</param>
	/// <param name="msgId2">消息标识2，16进制</param>
	/// <param name="msgId3">消息标识3，16进制</param>
	/// <param name="exMode">扩展模式，16进制</param>
	/// <param name="msgExId">扩展标识，16进制</param>
	/// <returns>void</returns>
	void setFrameMsgAttr(char msgId1, char msgId2 = 0x0, char msgId3 = 0x0, char exMode = 0x0, char msgExId = 0x0);
	char getFrameMsgAttrMsgId1();
	char getFrameMsgAttrMsgId2();
	char getFrameMsgAttrMsgId3();

	/// <summary>
	/// 设置消息属性
	/// </summary>
	/// <param name="frameMsgAttr">消息属性</param>
	/// <returns>void</returns>
	void setFrameMsgAttr(QByteArray frameMsgAttr);

	/// <summary>
	/// 设置消息
	/// </summary>
	/// <param name="data">消息</param>
	/// <returns>void</returns>
	void setFrameMsgData(QByteArray data);
	QByteArray getFrameMsgData();

	/// <summary>
	/// 设置消息类型 
	/// </summary>
	/// <param name="msgType">消息类型</param>
	/// <returns>void</returns>
	void setFrameMsgType(char msgType);
	char getFrameMsgType();

	/// <summary>
	/// 设置消息地址
	/// </summary>
	/// <param name="sourceAddress">源地址</param>
	/// <param name="destinationAddress">目的地址</param>
	/// <returns>void</returns>
	void setFrameMsgAddress(char sourceAddress, char destinationAddress);
	void getFrameMsgAddress(char& sourceAddress, char& destinationAddress);

	/// <summary>
	/// 设置帧序号
	/// </summary>
	/// <param name="sn">帧序号</param>
	/// <returns>void</returns>
	void setMsgSN(quint16 sn);
	quint16 getMsgSN();

	/// <summary>
	/// 帧长度校验 
	/// </summary>
	/// <returns>bool</returns>
	bool frameLengthCheck();

	/// <summary>
	/// 帧校验
	/// </summary>
	/// <returns>bool</returns>
	bool frameCheck();

	/// <summary>
	/// 获取帧长度 
	/// </summary>
	/// <returns>int(单位：字，1字=2字节)</returns>
	int getFrameLength();

private:
	QByteArray m_Frame;			//帧
	QByteArray m_FrameLength;	//帧长度
	QByteArray m_FrameMsgID;	//消息标识
	QByteArray m_FrameMsgSN;	//消息序号
	QByteArray m_FrameMsgAttr;	//消息属性
	QByteArray m_FrameMsg;		//消息

	unsigned short int m_MsgSN = 0;//消息序号

	char m_MsgType = 0x00;		//消息类型
	char m_MsgAddress = 0x12;   //消息地址（高4位：源地址，低4位：目的地址）

	//消息属性子内容
	char m_FrameMsgAttrMsgId1;
	char m_FrameMsgAttrMsgId2;
	char m_FrameMsgAttrMsgId3;
	

	friend class FrameHeartbeat;
	friend class FrameReset;
	friend class FrameCommand;
	friend class FrameData;
	friend class FrameParam;
	friend class FrameQuery;
	friend class FrameInformationTransmission;
};


//心跳帧
class FrameHeartbeat : public FrameBase
{
public:
	FrameHeartbeat();
	QByteArray getFrameBuffer(bool isFrameLengthCheck = false);

private:
	unsigned short int m_HeartbeatSN = 0;
};

//复位帧
class FrameReset : public FrameBase
{
public:
	FrameReset();
};

//命令帧
class FrameCommand : public FrameBase
{
public:
	FrameCommand();
};

//数据帧
class FrameData : public FrameBase
{
public:
	FrameData();
};

//参数帧
class FrameParam : public FrameBase
{
public:
	FrameParam();
};

//查询帧
class FrameQuery : public FrameBase
{
public:
	FrameQuery();
};

//信息传输帧
class FrameInformationTransmission : public FrameBase
{
public:
	FrameInformationTransmission();
};