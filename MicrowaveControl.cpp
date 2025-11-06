#include "MicrowaveControl.h"
#include <QDebug>

MicrowaveControl::MicrowaveControl(QObject *parent)
	: QObject(parent)
{
	serial = new QSerialPort(this);
	connect(serial, &QSerialPort::readyRead, this, &MicrowaveControl::slotReadData);
}

MicrowaveControl::~MicrowaveControl()
{
	delete serial;
}

/*
Name:connectToPort
Import:
port_name:串口名称
baud_rate:波特率
data_bits:数据位
parity:奇偶校验位
stop_bits:停止位
flow_control:流控
*/
bool MicrowaveControl::connectToPort(QString port_name, int baud_rate, QSerialPort::DataBits data_bits, QSerialPort::Parity parity, QSerialPort::StopBits stop_bits, QSerialPort::FlowControl flow_control)
{
	//设置串口名字
	serial->setPortName(port_name);
	//设置波特率
	serial->setBaudRate(baud_rate);
	//设置数据位
	serial->setDataBits(data_bits);
	//设置奇偶校验位
	serial->setParity(parity);
	//设置停止位
	serial->setStopBits(stop_bits);
	//设置流控
	serial->setFlowControl(flow_control);
	//打开串口
	if (serial->open(QIODevice::ReadWrite))
	{
		return true;
	}
	else 
	{
		return false;
	}
}

//关闭串口
void MicrowaveControl::closePort()
{
	serial->clear();
	serial->close();
}

//复位指令下发
void MicrowaveControl::setReSet()
{
	My_Order msg;
	memset(&msg, 0, sizeof(msg));
	msg.m_Head[0] = 0xAA;
	msg.m_Head[1] = 0xAA;
	msg.m_Long[0] = 0x00;
	msg.m_Long[1] = 0x04;
	msg.m_ID[0] = 0x00;
	msg.m_ID[1] = 0x01;
	msg.m_Type[0] = 0x00;
	msg.m_Type[1] = 0x50;
	msg.m_Data[0] = 0x00;
	msg.m_Data[1] = 0x00;
	msg.m_Data[2] = 0x00;
	msg.m_Data[3] = 0x01;

	serial->write((char*)&msg, sizeof(msg));
}

//心跳检测指令下发
void MicrowaveControl::setHeartbeatDetection()
{
	My_Order msg;
	memset(&msg, 0, sizeof(msg));
	msg.m_Head[0] = 0xAA;
	msg.m_Head[1] = 0xAA;
	msg.m_Long[0] = 0x00;
	msg.m_Long[1] = 0x04;
	msg.m_ID[0] = 0x00;
	msg.m_ID[1] = 0x01;
	msg.m_Type[0] = 0x00;
	msg.m_Type[1] = 0x51;
	msg.m_Data[0] = 0x00;
	msg.m_Data[1] = 0x00;
	msg.m_Data[2] = 0x00;
	msg.m_Data[3] = 0x01;

	serial->write((char*)&msg, sizeof(msg));
}

//扫频参数指令下发
/*
Name:
Import:
start_rate:起始频率
end_rate:终止频率
step_long:步进频率
*/
void MicrowaveControl::setSweepParameters(uint start_rate, uint end_rate, uint step_long)
{
	Scan_Order msg;
	memset(&msg, 0, sizeof(msg));
	msg.m_Head[0] = 0xAA;
	msg.m_Head[1] = 0xAA;
	msg.m_Long[0] = 0x00;
	msg.m_Long[1] = 0x08;
	msg.m_ID[0] = 0x00;
	msg.m_ID[1] = 0x01;
	msg.m_Type[0] = 0x00;
	msg.m_Type[1] = 0x52;

	msg.m_Start_Rate[0] = start_rate >> 24;
	msg.m_Start_Rate[1] = start_rate >> 16;
	msg.m_Start_Rate[2] = start_rate >> 8;
	msg.m_Start_Rate[3] = start_rate;

	msg.m_End_Rate[0] = end_rate >> 24;
	msg.m_End_Rate[1] = end_rate >> 16;
	msg.m_End_Rate[2] = end_rate >> 8;
	msg.m_End_Rate[3] = end_rate;

	msg.m_Step_Long[0] = step_long >> 24;
	msg.m_Step_Long[1] = step_long >> 16;
	msg.m_Step_Long[2] = step_long >> 8;
	msg.m_Step_Long[3] = step_long;


	serial->write((char*)&msg, sizeof(msg));
}

//内外触发切换指令指令下发
/*
Name:
Import:
i=true:设置内触发
i=false:设置外触发
*/
void MicrowaveControl::setTriggerSelection(bool i)
{
	if (i)
	{
		//内触发
		My_Order msg;
		memset(&msg, 0, sizeof(msg));
		msg.m_Head[0] = 0xAA;
		msg.m_Head[1] = 0xAA;
		msg.m_Long[0] = 0x00;
		msg.m_Long[1] = 0x04;
		msg.m_ID[0] = 0x00;
		msg.m_ID[1] = 0x01;
		msg.m_Type[0] = 0x00;
		msg.m_Type[1] = 0x53;
		msg.m_Data[0] = 0x00;
		msg.m_Data[1] = 0x00;
		msg.m_Data[2] = 0x00;
		msg.m_Data[3] = 0x00;

		serial->write((char*)&msg, sizeof(msg));
	}
	else
	{
		//外触发
		My_Order msg;
		memset(&msg, 0, sizeof(msg));
		msg.m_Head[0] = 0xAA;
		msg.m_Head[1] = 0xAA;
		msg.m_Long[0] = 0x00;
		msg.m_Long[1] = 0x04;
		msg.m_ID[0] = 0x00;
		msg.m_ID[1] = 0x01;
		msg.m_Type[0] = 0x00;
		msg.m_Type[1] = 0x53;
		msg.m_Data[0] = 0x00;
		msg.m_Data[1] = 0x00;
		msg.m_Data[2] = 0x00;
		msg.m_Data[3] = 0x01;

		serial->write((char*)&msg, sizeof(msg));
	}

}

//微波、放大器开关控制
/*
Name:
Import:
i=true:打开微波、放大器
i=false:关闭微波、放大器
*/
void MicrowaveControl::setMicrowavAmplifierSwitch(bool i)
{
	if (i)
	{
		//打开
		My_Order msg;
		memset(&msg, 0, sizeof(msg));
		msg.m_Head[0] = 0xAA;
		msg.m_Head[1] = 0xAA;
		msg.m_Long[0] = 0x00;
		msg.m_Long[1] = 0x04;
		msg.m_ID[0] = 0x00;
		msg.m_ID[1] = 0x01;
		msg.m_Type[0] = 0x00;
		msg.m_Type[1] = 0x54;
		msg.m_Data[0] = 0x00;
		msg.m_Data[1] = 0x00;
		msg.m_Data[2] = 0x00;
		msg.m_Data[3] = 0x01;

		serial->write((char*)&msg, sizeof(msg));
	} 
	else
	{
		//关闭
		My_Order msg;
		memset(&msg, 0, sizeof(msg));
		msg.m_Head[0] = 0xAA;
		msg.m_Head[1] = 0xAA;
		msg.m_Long[0] = 0x00;
		msg.m_Long[1] = 0x04;
		msg.m_ID[0] = 0x00;
		msg.m_ID[1] = 0x01;
		msg.m_Type[0] = 0x00;
		msg.m_Type[1] = 0x54;
		msg.m_Data[0] = 0x00;
		msg.m_Data[1] = 0x00;
		msg.m_Data[2] = 0x00;
		msg.m_Data[3] = 0x00;

		serial->write((char*)&msg, sizeof(msg));
	}
	
}

//开始
void MicrowaveControl::startOut()
{
	My_Order msg;
	memset(&msg, 0, sizeof(msg));
	msg.m_Head[0] = 0xAA;
	msg.m_Head[1] = 0xAA;
	msg.m_Long[0] = 0x00;
	msg.m_Long[1] = 0x04;
	msg.m_ID[0] = 0x00;
	msg.m_ID[1] = 0x01;
	msg.m_Type[0] = 0x00;
	msg.m_Type[1] = 0x55;
	msg.m_Data[0] = 0x00;
	msg.m_Data[1] = 0x00;
	msg.m_Data[2] = 0x00;
	msg.m_Data[3] = 0x01;

	serial->write((char*)&msg, sizeof(msg));
}

//停止
void MicrowaveControl::stopOut()
{
	My_Order msg;
	memset(&msg, 0, sizeof(msg));
	msg.m_Head[0] = 0xAA;
	msg.m_Head[1] = 0xAA;
	msg.m_Long[0] = 0x00;
	msg.m_Long[1] = 0x04;
	msg.m_ID[0] = 0x00;
	msg.m_ID[1] = 0x01;
	msg.m_Type[0] = 0x00;
	msg.m_Type[1] = 0x56;
	msg.m_Data[0] = 0x00;
	msg.m_Data[1] = 0x00;
	msg.m_Data[2] = 0x00;
	msg.m_Data[3] = 0x00;

	serial->write((char*)&msg, sizeof(msg));
}

//内触发频率参数设置
/*
Name:
Import:
freq:内触发频率参数
*/
void MicrowaveControl::setInternalTriggerFrequencyParameters(uint freq)
{
	My_Order msg;
	memset(&msg, 0, sizeof(msg));
	msg.m_Head[0] = 0xAA;
	msg.m_Head[1] = 0xAA;
	msg.m_Long[0] = 0x00;
	msg.m_Long[1] = 0x04;
	msg.m_ID[0] = 0x00;
	msg.m_ID[1] = 0x01;
	msg.m_Type[0] = 0x00;
	msg.m_Type[1] = 0x57;

	msg.m_Data[0] = freq >> 24;
	msg.m_Data[1] = freq >> 16;
	msg.m_Data[2] = freq >> 8;
	msg.m_Data[3] = freq;

	serial->write((char*)&msg, sizeof(msg));
}

//点频参数设置
/*
Name:
Import:
freq:点频参数
*/
void MicrowaveControl::setPointFrequencyParameters(uint freq)
{
	My_Order msg;
	memset(&msg, 0, sizeof(msg));
	msg.m_Head[0] = 0xAA;
	msg.m_Head[1] = 0xAA;
	msg.m_Long[0] = 0x00;
	msg.m_Long[1] = 0x04;
	msg.m_ID[0] = 0x00;
	msg.m_ID[1] = 0x01;
	msg.m_Type[0] = 0x00;
	msg.m_Type[1] = 0x58;

	msg.m_Data[0] = freq >> 24;
	msg.m_Data[1] = freq >> 16;
	msg.m_Data[2] = freq >> 8;
	msg.m_Data[3] = freq;

	serial->write((char*)&msg, sizeof(msg));
}

//开启点频或扫频
/*
Name:
Import:
i=0:设置点频模式
i=1:设置扫频模式
*/
void MicrowaveControl::setPointOrScanOn(int j)
{
	if (j == 0)
	{
		//点频
		My_Order msg;
		memset(&msg, 0, sizeof(msg));
		msg.m_Head[0] = 0xAA;
		msg.m_Head[1] = 0xAA;
		msg.m_Long[0] = 0x00;
		msg.m_Long[1] = 0x04;
		msg.m_ID[0] = 0x00;
		msg.m_ID[1] = 0x01;
		msg.m_Type[0] = 0x00;
		msg.m_Type[1] = 0x59;
		msg.m_Data[0] = 0x00;
		msg.m_Data[1] = 0x00;
		msg.m_Data[2] = 0x00;
		msg.m_Data[3] = 0x00;

		serial->write((char*)&msg, sizeof(msg));
	}
	else if(j == 1)
	{
		//扫频
		My_Order msg;
		memset(&msg, 0, sizeof(msg));
		msg.m_Head[0] = 0xAA;
		msg.m_Head[1] = 0xAA;
		msg.m_Long[0] = 0x00;
		msg.m_Long[1] = 0x04;
		msg.m_ID[0] = 0x00;
		msg.m_ID[1] = 0x01;
		msg.m_Type[0] = 0x00;
		msg.m_Type[1] = 0x59;
		msg.m_Data[0] = 0x00;
		msg.m_Data[1] = 0x00;
		msg.m_Data[2] = 0x00;
		msg.m_Data[3] = 0x01;

		serial->write((char*)&msg, sizeof(msg));
	}
}

void MicrowaveControl::checkState()
{
	//查询状态
	My_Order msg;
	memset(&msg, 0, sizeof(msg));
	msg.m_Head[0] = 0xAA;
	msg.m_Head[1] = 0xAA;
	msg.m_Long[0] = 0x00;
	msg.m_Long[1] = 0x04;
	msg.m_ID[0] = 0x00;
	msg.m_ID[1] = 0x02;
	msg.m_Type[0] = 0x00;
	msg.m_Type[1] = 0x70;
	msg.m_Data[0] = 0x00;
	msg.m_Data[1] = 0x00;
	msg.m_Data[2] = 0x00;
	msg.m_Data[3] = 0x00;

	serial->write((char*)&msg, sizeof(msg));
}
/*
Name:
Output:(int)
0:复位成功
1:复位失败
10:心跳正常
20:扫频参数配置成功
21:扫频参数配置失败
30:内/外部触发选择成功
31:内/外部触发选择成失败
40:微波开关/放大器开关控制成功
41:微波开关/放大器开关控制失败
50:启动成功
51:启动失败
60:停止成功
61:停止失败
70:内触发频率设置成功
71:内触发频率设置失败
80:设置点频参数成功
81:设置点频参数失败
90:点频/扫频选择成功
91:点频/扫频选择失败

Other：请以信号槽方式监听
*/
void MicrowaveControl::slotReadData()
{
	QByteArray buf = serial->readAll().toHex().data();
	
	
	if (buf.left(16) == ("aaaa000401000050"))
	{
		if (buf.mid(16,8) == ("00000000"))
		{
			emit getRecSignals(0);
		} 
		else
		{
			emit getRecSignals(1);
		}
	}
	else if (buf.left(16) == ("aaaa000401000051"))
	{
		if (buf.mid(16, 8) == ("00000001"))
		{
			emit getRecSignals(10);
		}
		
	}
	else if (buf.left(16) == ("aaaa000401000052"))
	{
		if (buf.mid(16, 8) == ("00000000"))
		{
			emit getRecSignals(20);
		}
		else
		{
			emit getRecSignals(21);
		} 
	}
	else if (buf.left(16) == ("aaaa000401000053"))
	{
		if (buf.mid(16, 8) == ("00000000"))
		{
			emit getRecSignals(30);
		}
		else
		{
			emit getRecSignals(31);
		}
	}
	else if (buf.left(16) == ("aaaa000401000054"))
	{
		if (buf.mid(16, 8) == ("00000000"))
		{
			emit getRecSignals(40);
		}
		else
		{
			emit getRecSignals(41);
		}
	}
	else if (buf.left(16) == ("aaaa000401000055"))
	{
		if (buf.mid(16, 8) == ("00000000"))
		{
			emit getRecSignals(50);
		}
		else
		{
			emit getRecSignals(51);
		}
	}
	else if (buf.left(16) == ("aaaa000401000056"))
	{
		if (buf.mid(16, 8) == ("00000000"))
		{
			emit getRecSignals(60);
		}
		else
		{
			emit getRecSignals(61);
		}
	}
	else if (buf.left(16) == ("aaaa000401000057"))
	{
		if (buf.mid(16, 8) == ("00000000"))
		{
			emit getRecSignals(70);
		}
		else
		{
			emit getRecSignals(71);
		}
	}
	else if (buf.left(16) == ("aaaa000401000058"))
	{
		if (buf.mid(16, 8) == ("00000000"))
		{
			emit getRecSignals(80);
		}
		else
		{
			emit getRecSignals(81);
		}
	}
	else if (buf.left(16) == ("aaaa000401000059"))
	{
		if (buf.mid(16, 8) == ("00000000"))
		{
			emit getRecSignals(90);
		}
		else
		{
			emit getRecSignals(91);
		}
	}
	else if (buf.left(16) == ("aaaa000402000070"))
	{
		if (buf.mid(16, 8) == ("00000001"))
		{
			emit getRecSignals(100);
		}
		else if (buf.mid(16, 8) == ("00000000"))
		{
			emit getRecSignals(101);
		}
	}
}