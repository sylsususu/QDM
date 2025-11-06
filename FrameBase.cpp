#include "FrameBase.h"
#include <QByteArray>
#include <QBitArray>

#include "Utils.h"

FrameBase::FrameBase()
{
	m_FrameMsgID.resize(2);
	m_FrameMsgSN.resize(2);
	m_FrameMsgAttr.resize(2);
	m_FrameMsgAttr = QByteArrayLiteral("\x00\x00");
    
}

FrameBase::~FrameBase()
{}

void FrameBase::setFrameMsgAttr(char msgId1, char msgId2, char msgId3, char exMode, char msgExId)
{
	QByteArray frameMsgAttr;
	QBitArray bitArrayMsgAttr;
	bitArrayMsgAttr.resize(16);
	bitArrayMsgAttr.fill(false);
	//  00     00      0000    0000  0000
	//[15:14] [13:12] [11:8]  [7:4]  [3:0]
	//[11:8] msgId1
	bitArrayMsgAttr[4] = msgId1 >> 3 & 1;
	bitArrayMsgAttr[5] = msgId1 >> 2 & 1;
	bitArrayMsgAttr[6] = msgId1 >> 1 & 1;
	bitArrayMsgAttr[7] = msgId1 >> 0 & 1;
	//[7:4]  msgId2
	bitArrayMsgAttr[8]  = msgId2 >> 3 & 1;
	bitArrayMsgAttr[9]  = msgId2 >> 2 & 1;
	bitArrayMsgAttr[10] = msgId2 >> 1 & 1;
	bitArrayMsgAttr[11] = msgId2 >> 0 & 1;
	//[3:0]  msgId3
	bitArrayMsgAttr[12] = msgId3 >> 3 & 1;
	bitArrayMsgAttr[13] = msgId3 >> 2 & 1;
	bitArrayMsgAttr[14] = msgId3 >> 1 & 1;
	bitArrayMsgAttr[15] = msgId3 >> 0 & 1;
	//[15:14]  exMode
	bitArrayMsgAttr[0] = exMode >> 1 & 1;
	bitArrayMsgAttr[1] = exMode >> 0 & 1;
	//[13:12]  msgExId
	bitArrayMsgAttr[2] = msgExId >> 1 & 1;
	bitArrayMsgAttr[3] = msgExId >> 0 & 1;

	frameMsgAttr = Utils::bitsToBytes(bitArrayMsgAttr);
	setFrameMsgAttr(frameMsgAttr);
}

void FrameBase::setFrameMsgAttr(QByteArray frameMsgAttr)
{
	m_FrameMsgAttr = frameMsgAttr;
}

void FrameBase::setFrameMsgData(QByteArray data)
{
	m_FrameMsg = data;
}
QByteArray FrameBase::getFrameMsgData()
{
	return m_FrameMsg;
}


QByteArray FrameBase::getFrameBuffer(bool isFrameLengthCheck)
{
	//帧单位：字（1字=2字节）
	QByteArray frame;

	//计算帧长度（消息标识+消息序号+消息属性+消息）
	int length = 3 + m_FrameMsg.length()/2;
	QByteArray binLengthBytes = QByteArray::number(length, 2);
	QBitArray binLengthBits = Utils::intTo16Bits(length);
	if (isFrameLengthCheck)
	{
		//帧长度校验
		binLengthBits[0] = true;
		binLengthBits[1] = binLengthBits[4] ^ binLengthBits[5] ^ binLengthBits[6] ^ binLengthBits[7];
		binLengthBits[2] = binLengthBits[8] ^ binLengthBits[9] ^ binLengthBits[10] ^ binLengthBits[11];
		binLengthBits[3] = binLengthBits[12] ^ binLengthBits[13] ^ binLengthBits[14] ^ binLengthBits[15];
	}
	m_FrameLength = Utils::bitsToBytes(binLengthBits);
	//写入帧长度
	frame.append(m_FrameLength);

	//写入消息标识
	m_FrameMsgID[0] = m_MsgAddress;
	m_FrameMsgID[1] = m_MsgType;
	frame.append(m_FrameMsgID);

	//写入消息序号（消息序号自增长，自动归0）
	m_FrameMsgSN = Utils::intToDoubleBytes(m_MsgSN);
	frame.append(m_FrameMsgSN);
	m_MsgSN++;

	//写入消息属性
	frame.append(m_FrameMsgAttr);

	//写入消息
	frame.append(m_FrameMsg);

	//计算帧校验
	unsigned short int frameCheckSum = 0;   //帧校验和
	for (int i = 0; i < frame.length(); i=i+2)
	{
		QByteArray temp;
		temp.append(frame[i]);
		temp.append(frame[i+1]);
		unsigned short int num = temp.toHex().toUInt(NULL, 16);
		frameCheckSum += num;
	}
	QByteArray frameCheck = Utils::intToDoubleBytes(frameCheckSum);

	//写入校验位
	frame.append(frameCheck);

	//写入帧头(帧校验不包括帧头，所以帧头放在最后写入)
	for (int i = 0; i < 4; i++)
	{
		frame.insert(0, 0xAA);
	}

	return frame;
}

void FrameBase::setFrameBuffer(QByteArray frame)
{	
	m_Frame = frame;

	//帧长度
	m_FrameLength = frame.mid(4, 2);

	//消息标识
	m_FrameMsgID = frame.mid(6, 2);
	m_MsgAddress = m_FrameMsgID.at(0);
	m_MsgType = m_FrameMsgID.at(1);

	//消息序号
	m_FrameMsgSN = frame.mid(8, 2);
	m_MsgSN = m_FrameMsgSN.toHex().toUInt(nullptr, 16);

	//消息属性
	m_FrameMsgAttr = frame.mid(10, 2);
	//消息
	m_FrameMsg = frame.mid(12, frame.length() - 12);

	//0000 0000 0000 0000
	QBitArray bitArrayMsgAttr = Utils::bytesToBits(m_FrameMsgAttr);
	m_FrameMsgAttrMsgId1 = (bitArrayMsgAttr[7]  << 0) | (bitArrayMsgAttr[6]  << 1) | (bitArrayMsgAttr[5]  << 2) | (bitArrayMsgAttr[4]  << 3);
	m_FrameMsgAttrMsgId2 = (bitArrayMsgAttr[11] << 0) | (bitArrayMsgAttr[10] << 1) | (bitArrayMsgAttr[9]  << 2) | (bitArrayMsgAttr[8]  << 3);
	m_FrameMsgAttrMsgId3 = (bitArrayMsgAttr[15] << 0) | (bitArrayMsgAttr[14] << 1) | (bitArrayMsgAttr[13] << 2) | (bitArrayMsgAttr[12] << 3);
}
char FrameBase::getFrameMsgAttrMsgId1()
{
	return m_FrameMsgAttrMsgId1;
}
char FrameBase::getFrameMsgAttrMsgId2()
{
	return m_FrameMsgAttrMsgId2;
}
char FrameBase::getFrameMsgAttrMsgId3()
{
	return m_FrameMsgAttrMsgId3;
}

void FrameBase::setFrameMsgType(char msgType)
{
	m_MsgType = msgType;
}

char FrameBase::getFrameMsgType()
{
	return m_MsgType;
}

void FrameBase::setFrameMsgAddress(char sourceAddress, char destinationAddress)
{
	QBitArray bitArrayAddress;
	bitArrayAddress.resize(8);
	bitArrayAddress.fill(false);
	bitArrayAddress[0] = (sourceAddress >> 3) & 1;
	bitArrayAddress[1] = (sourceAddress >> 2) & 1;
	bitArrayAddress[2] = (sourceAddress >> 1) & 1;
	bitArrayAddress[3] = (sourceAddress >> 0) & 1;
	bitArrayAddress[4] = (destinationAddress >> 3) & 1;
	bitArrayAddress[5] = (destinationAddress >> 2) & 1;
	bitArrayAddress[6] = (destinationAddress >> 1) & 1;
	bitArrayAddress[7] = (destinationAddress >> 0) & 1;
	m_MsgAddress = Utils::bitsToBytes(bitArrayAddress).at(0);
}

void FrameBase::getFrameMsgAddress(char & sourceAddress, char & destinationAddress)
{
	char temp = 0 | (m_MsgAddress << 4);
	sourceAddress = m_MsgAddress >> 4;
	destinationAddress = temp >> 4;
}

void FrameBase::setMsgSN(quint16 sn)
{
	m_MsgSN = sn;
}
quint16 FrameBase::getMsgSN()
{
	return m_MsgSN;
}

bool FrameBase::frameLengthCheck()
{
	QBitArray bitArrayFrameLength = Utils::bytesToBits(m_FrameLength);
	//[15] 帧长度校验使能
	bool isFrameLengthEnable = bitArrayFrameLength[0];

	//[14:12] 帧长度校验
	//frm_len_ck[0] = ^frm_len[3:0]
	//frm_len_ck[1] = ^frm_len[7:4]
	//frm_len_ck[2] = ^frm_len[11:8]
	bool isFrameLengthOK = true;
	if (isFrameLengthEnable)
	{
		//需要对帧长度校验
		QBitArray bitArrayFrameLengthCkeck(3);
		bitArrayFrameLengthCkeck.fill(false);
		bitArrayFrameLengthCkeck[0] = bitArrayFrameLength[15] ^ bitArrayFrameLength[14] ^ bitArrayFrameLength[13] ^ bitArrayFrameLength[12];
		bitArrayFrameLengthCkeck[1] = bitArrayFrameLength[11] ^ bitArrayFrameLength[10] ^ bitArrayFrameLength[9] ^ bitArrayFrameLength[8];
		bitArrayFrameLengthCkeck[2] = bitArrayFrameLength[7] ^ bitArrayFrameLength[6] ^ bitArrayFrameLength[5] ^ bitArrayFrameLength[4];
		if (bitArrayFrameLength[3] == bitArrayFrameLengthCkeck[0]
			&& bitArrayFrameLength[2] == bitArrayFrameLengthCkeck[1]
			&& bitArrayFrameLength[1] == bitArrayFrameLengthCkeck[2])
		{
			//帧长度正确
		}
		else
		{
			isFrameLengthOK = false;
		}
	}
	return isFrameLengthOK;
}

int FrameBase::getFrameLength()
{
	QBitArray bitArrayFrameLength = Utils::bytesToBits(m_FrameLength);

	//[11:0] 帧长度
	QByteArray byteArrayLength;
	QBitArray bitArrayFrameLengthTemp(16);
	bitArrayFrameLengthTemp.fill(false);
	for (int i = 0; i < 12; i++)
	{
		bitArrayFrameLengthTemp[15 - i] = bitArrayFrameLength[15 - i];
	}
	byteArrayLength = Utils::bitsToBytes(bitArrayFrameLengthTemp);
	int frameLength = byteArrayLength.toHex().toInt(nullptr, 16);
	return frameLength;
}

bool FrameBase::frameCheck()
{
	QByteArray bytesFrameCheck = m_Frame.right(2);
	unsigned short int frameCheckSum = 0;   //帧校验和(帧长度、消息标识、消息序号、消息属性、消息)
	for (int i = 4; i < m_Frame.length() - 2; i = i + 2)
	{
		QByteArray temp;
		temp.append(m_Frame[i]);
		temp.append(m_Frame[i + 1]);
		unsigned short int num = temp.toHex().toUInt(NULL, 16);
		frameCheckSum += num;
	}
	unsigned short int check = m_Frame.right(2).toHex().toUInt(nullptr, 16);
	if (check == frameCheckSum)
	{
		return true;
	}
	else
	{
		return false;
	}
}










//心跳帧/////////////////////////////////////////////////////////////////
FrameHeartbeat::FrameHeartbeat()
{
	m_MsgType = 0x0E;//心跳监测帧
}

QByteArray FrameHeartbeat::getFrameBuffer(bool isFrameLengthCheck)
{
	QByteArray frameHeartbeatSN = Utils::intToDoubleBytes(m_HeartbeatSN);
	m_HeartbeatSN++;
	m_FrameMsg = frameHeartbeatSN;
	return FrameBase::getFrameBuffer(isFrameLengthCheck);
}


//复位帧/////////////////////////////////////////////////////////////////
FrameReset::FrameReset()
{
	m_MsgType = 0x0F;//复位帧

	//消息
	QBitArray bitArrayMsg;
	bitArrayMsg.resize(16);
	bitArrayMsg.fill(false);
	bitArrayMsg[0] = true;
	QByteArray byteArrayMsg = Utils::bitsToBytes(bitArrayMsg);
	m_FrameMsg = byteArrayMsg;
}


//命令帧/////////////////////////////////////////////////////////////////
FrameCommand::FrameCommand()
{
	m_MsgType = 0x01;//命令帧
}


//数据帧/////////////////////////////////////////////////////////////////
FrameData::FrameData()
{
	m_MsgType = 0x02;//数据帧
}


//参数帧/////////////////////////////////////////////////////////////////
FrameParam::FrameParam()
{
	m_MsgType = 0x03;//参数帧
}

//查询帧/////////////////////////////////////////////////////////////////
FrameQuery::FrameQuery()
{
	m_MsgType = 0x04;//查询帧
}


//信息传输帧/////////////////////////////////////////////////////////////
FrameInformationTransmission::FrameInformationTransmission()
{
	m_MsgType = 0x05;//信息传输帧
}