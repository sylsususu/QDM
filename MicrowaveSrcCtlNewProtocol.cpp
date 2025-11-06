#include "MicrowaveSrcCtlNewProtocol.h"
#include "Utils.h"
#include <QDebug>
#include <QBitArray>
#include <QDebug>


MicrowaveSrcCtlNewProtocol::MicrowaveSrcCtlNewProtocol(QObject *parent)
	: QObject(parent)
{
	isSeril = false;
	isTcp = false;
	m_Reset = new FrameReset;
	m_Heartbeat = new FrameHeartbeat;
	m_Command = new FrameCommand;
	m_Param = new FrameParam;
	m_Query = new FrameQuery;
	//test
	m_socket = new QTcpSocket(this);
}


MicrowaveSrcCtlNewProtocol::~MicrowaveSrcCtlNewProtocol()
{
	if (isTcp)
	{
		m_socket->disconnectFromHost();
		delete m_socket;
	}
	if (isSeril)
	{
		m_serial->close();
		delete m_serial;
	}
	delete m_Reset;
	delete m_Heartbeat;
	delete m_Command;
	delete m_Param;
	delete m_Query;
}

//连接
bool MicrowaveSrcCtlNewProtocol::b_Connected(QString IP, int port)
{
	/*m_socket = new QTcpSocket(this);*/
	m_socket->abort();
	m_socket->connectToHost(IP, port);
	//等待连接成功
	if (!m_socket->waitForConnected(2000))
	{
		isTcp = false;
		return false;
	}
	if (isSeril)
	{
		m_serial->close();
		delete m_serial;
	}
	isTcp = true;
	isSeril = false;
	connect(m_socket, &QTcpSocket::readyRead, this, &MicrowaveSrcCtlNewProtocol::slotReadData);
	return true;
}

//断开链接
void MicrowaveSrcCtlNewProtocol::disConnect()
{
	m_socket->abort();
	m_socket->disconnectFromHost();
	/*delete m_socket;*/
	isTcp = false;
}

//打开串口
bool MicrowaveSrcCtlNewProtocol::connectToPort(QString port_name, int baud_rate, QSerialPort::DataBits data_bits, QSerialPort::Parity parity, QSerialPort::StopBits stop_bits, QSerialPort::FlowControl flow_control)
{
	m_serial = new QSerialPort(this);
	//设置串口名字
	m_serial->setPortName(port_name);
	//设置波特率
	m_serial->setBaudRate(baud_rate);
	//设置数据位
	m_serial->setDataBits(data_bits);
	//设置奇偶校验位
	m_serial->setParity(parity);
	//设置停止位
	m_serial->setStopBits(stop_bits);
	//设置流控
	m_serial->setFlowControl(flow_control);
	//打开串口
	if (m_serial->open(QIODevice::ReadWrite))
	{
		if (isTcp && m_socket->state() == QAbstractSocket::ConnectedState)
		{
			m_socket->disconnectFromHost();
			delete m_socket;
		}
		isSeril = true;
		isTcp = false;
		connect(m_serial, &QSerialPort::readyRead, this, &MicrowaveSrcCtlNewProtocol::slotReadData);
		return true;
	}
	return false;
	isSeril = false;
}

//关闭串口
void MicrowaveSrcCtlNewProtocol::closePort()
{
	m_serial->clear();
	m_serial->close();
	delete m_serial;
	isSeril = false;
}

//复位指令下发
void MicrowaveSrcCtlNewProtocol::setReSet()
{
	QByteArray arr = QByteArrayLiteral("\x00\x00");
	m_Reset->setFrameMsgData(arr);
	if (isTcp)
	{
		m_socket->write(m_Reset->getFrameBuffer());
	} 
	else
	{
		m_serial->write(m_Reset->getFrameBuffer());
	}
}

//心跳检测指令下发
void MicrowaveSrcCtlNewProtocol::setHeartbeatDetection()
{
	if (isTcp)
	{
		m_socket->write(m_Heartbeat->getFrameBuffer());
	} 
	else
	{
		m_serial->write(m_Heartbeat->getFrameBuffer());
	}
	
}

//工作模式
void MicrowaveSrcCtlNewProtocol::setWorkMode(int freq_mode, int trigger_mode, int scan_seq, int scan_mode, int mw_sw_en , int Select_Clk, int Set_Clk_Out)
{
	QBitArray a;
	a.resize(16);
	a.fill(0);
	a[15] = freq_mode;
	a[14] = trigger_mode;
	a[13] = scan_seq;
	a[12] = scan_mode;
	a[11] = mw_sw_en;
	a[10] = Select_Clk;
	a[9] = Set_Clk_Out;
	QByteArray arr = Utils::bitsToBytes(a);
	m_Param->setFrameMsgData(arr);
	arr = QByteArrayLiteral("\x00\x10");
	m_Param->setFrameMsgAttr(arr);
	if (isTcp)
	{
		m_socket->write(m_Param->getFrameBuffer());
	} 
	else
	{
		m_serial->write(m_Param->getFrameBuffer());
	}
}


//扫频参数指令下发
void MicrowaveSrcCtlNewProtocol::setSweepParameters(uint start_rate, uint end_rate, uint step_long)
{
	QBitArray start;
	start = Utils::intToBits(start_rate,32);

	QBitArray end;
	end = Utils::intToBits(end_rate, 32);

	QBitArray step;
	step = Utils::intToBits(step_long, 32);

	QByteArray arr;
	arr.append(Utils::bitsToBytes(start));
	arr.append(Utils::bitsToBytes(end));
	arr.append(Utils::bitsToBytes(step));

	m_Param->setFrameMsgAttr(QByteArrayLiteral("\x00\x30"));
	m_Param->setFrameMsgData(arr);
	if (isTcp)
	{
		m_socket->write(m_Param->getFrameBuffer());
	} 
	else
	{
		m_serial->write(m_Param->getFrameBuffer());
	}
}


//开始
void MicrowaveSrcCtlNewProtocol::startOut()
{
	QByteArray arr = QByteArrayLiteral("\x00\x10");
	m_Command->setFrameMsgAttr(arr);
	arr = QByteArrayLiteral("\x00\x01");
	m_Command->setFrameMsgData(arr);
	if (isTcp)
	{
		m_socket->write(m_Command->getFrameBuffer());
	} 
	else
	{
		m_serial->write(m_Command->getFrameBuffer());
	}
}

//停止
void MicrowaveSrcCtlNewProtocol::stopOut()
{
	QByteArray arr = QByteArrayLiteral("\x00\x20");
	m_Command->setFrameMsgAttr(arr);
	arr = QByteArrayLiteral("\x00\x01");
	m_Command->setFrameMsgData(arr);
	if (isTcp)
	{
		m_socket->write(m_Command->getFrameBuffer());
	}
	else
	{
		m_serial->write(m_Command->getFrameBuffer());
	}
}

//内触发频率参数设置
void MicrowaveSrcCtlNewProtocol::setInternalTriggerFrequencyParameters(uint freq)
{
	QBitArray f;
	f = Utils::intToBits(freq, 32);

	QByteArray arr = Utils::bitsToBytes(f);

	m_Param->setFrameMsgAttr(QByteArrayLiteral("\x00\x40"));
	m_Param->setFrameMsgData(arr);
	if (isTcp)
	{
		m_socket->write(m_Param->getFrameBuffer());
	}
	else
	{
		m_serial->write(m_Param->getFrameBuffer());
	}
}

//点频参数设置
void MicrowaveSrcCtlNewProtocol::setPointFrequencyParameters(uint freq)
{
	QBitArray f;
	f = Utils::intToBits(freq, 32);

	QByteArray arr = Utils::bitsToBytes(f);

	m_Param->setFrameMsgAttr(QByteArrayLiteral("\x00\x20"));
	m_Param->setFrameMsgData(arr);
	if (isTcp)
	{
		m_socket->write(m_Param->getFrameBuffer());
	} 
	else
	{
		m_serial->write(m_Param->getFrameBuffer());
	}
}

//扫频次数下发
void MicrowaveSrcCtlNewProtocol::setScanNum(uint scan_num)
{
	QBitArray f;
	f = Utils::intToBits(scan_num, 32);
	QByteArray arr = Utils::bitsToBytes(f);
	m_Param->setFrameMsgAttr(QByteArrayLiteral("\x00\x50"));
	m_Param->setFrameMsgData(arr);
	if (isTcp)
	{
		m_socket->write(m_Param->getFrameBuffer());
	} 
	else
	{
		m_serial->write(m_Param->getFrameBuffer());
	}
}

//工作状态检查
void MicrowaveSrcCtlNewProtocol::checkState()
{
	m_Query->setFrameMsgAttr(QByteArrayLiteral("\x00\x40"));
	m_Query->setFrameMsgData(QByteArrayLiteral("\x00\x00"));
	if (isTcp)
	{
		m_socket->write(m_Query->getFrameBuffer());
	} 
	else
	{
		m_serial->write(m_Query->getFrameBuffer());
	}
}

//数据解包
void MicrowaveSrcCtlNewProtocol::slotReadData()
{
	bool ok;
	if (isTcp)
	{
		buf.append(m_socket->readAll());
	} 
	else
	{
		buf.append(m_serial->readAll());
	}
	if (buf.size()<6)
	{
		return;
	}
	int firstLocate = buf.indexOf(QByteArrayLiteral("\xaa\xaa\xaa\xaa"));
	QByteArray arr = buf.toHex();
	if (firstLocate == -1)
	{
		buf.clear();
		return;
	}
	int packLong = (buf.toHex().mid(firstLocate + 8, 4).toInt(&ok, 16) + 3)*2;

	if (buf.size() - firstLocate < packLong)
	{
		return;
	}
	QByteArray oneFram = buf.mid(firstLocate, packLong);
	buf.remove(firstLocate, packLong);
	FrameBase fram;
	fram.setFrameBuffer(oneFram);
	//bool isCheck = fram.frameCheck();
	////校验不正确退出
	//if (!isCheck)
	//{
	//	return;
	//}
	char a, b;
	fram.getFrameMsgAddress(a, b);
	//地址不正确退出
	if (!(a == 0x2 && b == 0x1))
	{
		return;
	}
	char msgType = fram.getFrameMsgType();
	QByteArray Msgdata;
	char Id1;
	char Id2;
	char Id3;
	switch (msgType)
	{
	   //复位响应帧
	   case 0x1F:
		   Msgdata = fram.getFrameMsgData();
		   if (Msgdata == QByteArrayLiteral("\x00\x00"))
		   {
			   //复位正常
			   emit getRecSignals(0);
			   break;
		   }
		   //复位失败
		   emit getRecSignals(1);
		   break;

	   //心跳响应帧
	   case 0x1E:
			emit getRecSignals(10);
			break;

		//命令响应帧	  
	   case 0x11:
		   Msgdata = fram.getFrameMsgData();
		   Id2 = fram.getFrameMsgAttrMsgId2();
		   //启动命令响应
		   if (Id2 == 0x1)
		   {
			   if (Msgdata == QByteArrayLiteral("\x00\x00"))
			   {
				   //启动成功
				   emit getRecSignals(20);
				   break;
			   }
			   //启动失败
			   emit getRecSignals(21);
			   break;
		   }
		   //停止命令响应
		   else if (Id2 == 0x2)
		   {
			   if (Msgdata == QByteArrayLiteral("\x00\x00"))
			   {
				   //停止成功
				   emit getRecSignals(30);
				   break;
			   }
			   //停止失败
			   emit getRecSignals(31);
			   break;
		   }
		   break;
	   //参数配置响应帧
	   case 0x13:
		   Msgdata = fram.getFrameMsgData();
		   Id2 = fram.getFrameMsgAttrMsgId2();
		   //工作模式响应
		   if (Id2 == 0x1)
		   {
			   if (Msgdata == QByteArrayLiteral("\x00\x00"))
			   {
				   //工作模式设置成功
				   emit getRecSignals(40);
				   break;
			   }
			   //工作模式设置失败
			   emit getRecSignals(41);
			   break;
		   }
		   //点频参数配置响应帧
		   else if (Id2 == 0x2)
		   {
			   if (Msgdata == QByteArrayLiteral("\x00\x00"))
			   {
				   //点频参数设置成功
				   emit getRecSignals(50);
				   break;
			   }
			   //点频参数设置失败
			   emit getRecSignals(51);
			   break;
		   }
		   //扫频参数响应帧
		   else if (Id2 == 0x3)
		   {
			   if (Msgdata == QByteArrayLiteral("\x00\x00"))
			   {
				   //扫频参数设置成功
				   emit getRecSignals(60);
				   break;
			   }
			   //扫频参数设置失败
			   emit getRecSignals(61);
			   break;
		   }
		   //内触发频率参数配置响应帧
		   else if (Id2 == 0x4)
		   {
			   if (Msgdata == QByteArrayLiteral("\x00\x00"))
			   {
				   //内触发频率参数设置成功
				   emit getRecSignals(70);
				   break;
			   }
			   //内触发频率参数设置失败
			   emit getRecSignals(71);
			   break;
		   }
		   //扫频扫描次数参数配置响应帧
		   else if (Id2 == 0x5)
		   {
			   if (Msgdata == QByteArrayLiteral("\x00\x00"))
			   {
				   //扫频扫描次数参数设置成功
				   emit getRecSignals(80);
				   break;
			   }
			   //扫频扫描次数参数设置失败
			   emit getRecSignals(81);
			   break;
		   }
		   break;
       //查询帧
	   case 0x14:
		   Msgdata = fram.getFrameMsgData();
		   Id2 = fram.getFrameMsgAttrMsgId2();
		   //扫频状态查询帧
		   if (Id2 == 0x4)
		   {
			   if (Msgdata == QByteArrayLiteral("\x00\x01"))
			   {
				   //扫频中
				   emit getRecSignals(90);
				   break;
			   }
			   //扫频完成
			   emit getRecSignals(91);
			   break;
		   }
		   break;
		
	   default:
		   //错误类型接收
		   emit getRecSignals(0000);
		   break;
	}

}