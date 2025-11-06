#include "CurrentSource.h"

uint16_t CurrentSource::calculateCRC16(const uint8_t* data, size_t length)
{
	uint16_t crc = 0xFFFF;

	for (size_t i = 0; i < length; ++i)
	{
		crc ^= data[i];

		for (int j = 0; j < 8; ++j)
		{
			if (crc & 0x0001)
			{
				crc >>= 1;
				crc ^= 0xA001;
			}
			else
			{
				crc >>= 1;
			}
		}
	}

	return crc;
}




CurrentSource::CurrentSource()
{
	port = new QSerialPort();
	timer = new QTimer();

	QByteArray data;
	data.append(char(0x01));//从机01

	data.append(char(0x03));

	data.append(char(0x00));
	data.append(char(0x02));


	data.append(char(0x00));
	data.append(char(0x02));

	const uint8_t* dtr = reinterpret_cast<const uint8_t*>(data.data());
	uint16_t CRC = calculateCRC16(dtr, 6);
	int CRC_high8 = CRC & 0xFF;
	int CRC_low8 = (CRC >> 8) & 0xFF;
	data.append(char(CRC_high8));
	data.append(char(CRC_low8));

	getCurrentAndVoltageData = data;
	
}

CurrentSource::~CurrentSource()
{
	if (port) {
		port->close();
		delete port;
		port = nullptr;
	}
	if (timer) {
		delete timer;
		timer = nullptr;
	}
	
}

bool CurrentSource::currentConnect(const QString & name)
{
	port_name = name;
	port->setPortName(port_name); // 设置串口号
	port->setBaudRate(QSerialPort::Baud9600); // 设置波特率
	port->setDataBits(QSerialPort::Data8); // 设置数据位
	port->setParity(QSerialPort::NoParity); // 设置校验位
	port->setStopBits(QSerialPort::OneStop); // 设置停止位
	port->setFlowControl(QSerialPort::NoFlowControl); // 设置流控制
	if (port->open(QIODevice::ReadWrite))
	{
		
		//握手
		QByteArray data;
		data.append(char(0x01));//从机01

		data.append(char(0x03));

		data.append(char(0x00));
		data.append(char(0x0B));


		data.append(char(0x00));
		data.append(char(0x02));

		const uint8_t* dtr = reinterpret_cast<const uint8_t*>(data.data());
		uint16_t CRC = calculateCRC16(dtr, 6);
		int CRC_high8 = CRC & 0xFF;
		int CRC_low8 = (CRC >> 8) & 0xFF;
		data.append(char(CRC_high8));
		data.append(char(CRC_low8));

		port->write(data);
		port->waitForBytesWritten(3000);
		if (port->waitForReadyRead(10000)) // 等待1000毫秒
		{
			QByteArray data = port->readAll(); // 读取所有可用数据
			if (!data.isEmpty() && (data.at(1) == 0x03))
			{
				char a6 = data.at(6);
				char a7 = data.at(7);
				char a8 = data.at(8);
				if ((data.at(6) == 17)&&(data.at(7) == -113)&& (data.at(8) == 87))
				{
					
					QObject::connect(this->port, &QSerialPort::readyRead, this, &CurrentSource::onReadyRead);
					return true;
				}
			}
				
		}
		else
		{
			QObject::disconnect(this->port, &QSerialPort::readyRead, this, &CurrentSource::onReadyRead);
			return false;
		}
		
	}
	else
	{
		QObject::disconnect(this->port, &QSerialPort::readyRead, this, &CurrentSource::onReadyRead);
		port->close();
		return false;
	}
}

bool CurrentSource::disCurrentConnect()
{
	QObject::disconnect(this->port, &QSerialPort::readyRead, this, &CurrentSource::onReadyRead);
	realTimeReading(false);
	port->close();
	return true;
}

void CurrentSource::realTimeReading(bool isRealTimeReading)
{
	if (isRealTimeReading)
	{
		// 设置触发间隔为1秒
		timer->setInterval(1000);

		// 连接定时器的 timeout 信号到 getCurrent 槽函数
		QObject::connect(timer, &QTimer::timeout, this, &CurrentSource::getCurrentAndVoltage);
		timer->start();
		
	}
	else
	{
		timer->stop();
		QObject::disconnect(timer, &QTimer::timeout, this, &CurrentSource::getCurrentAndVoltage);
	}
	
	return;
}

void CurrentSource::getCurrentAndVoltage()
{
	
	foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
		if (info.portName() == port_name) {
			// 串口仍然可用
			// 继续写数据
			try {
				qint64 bytesWritten = port->write(getCurrentAndVoltageData);
				if (bytesWritten == -1) {

					throw QString("Failed to write to the current source serial port");
				}
				else if (bytesWritten != getCurrentAndVoltageData.size()) {

					throw QString("Only part of the data was written to the current source serial port");
				}
				else if (!port->waitForBytesWritten(3000)) {

					throw QString("Timeout or error while waiting for the current source serial port to write");
				}
				else {
					//qDebug() << "Write to the current source serial port completed";
				}

			}
			catch (QString &e) {
				// 捕获并处理异常
				qDebug() << "Exception:" << e;
				// 在这里进行异常处理，比如关闭串口，重新连接等操作
				timer->stop();
				QObject::disconnect(timer, &QTimer::timeout, this, &CurrentSource::getCurrentAndVoltage);
			}
			break;
		}
		else {
			// 串口已被拔出
			// 关闭串口并采取相应的处理措施
		}
	}
	
	
	
	return;
}

void CurrentSource::setCurrent(float current)
{

	_current = current;
	
	QByteArray data;
	data.append(char(0x01));//从机01
	
	data.append(char(0x06));
	data.append(char(0x00));
	data.append(char(0x51));


	uint16_t c_tmp = (int)(current * 100);
	int c_tmp_low8 = c_tmp & 0xFF;
	int c_tmp_high8 = (c_tmp >> 8) & 0xFF;
	data.append(char(c_tmp_high8));
	data.append(char(c_tmp_low8));

	const uint8_t* dtr = reinterpret_cast<const uint8_t*>(data.data());
	uint16_t CRC = calculateCRC16(dtr, 6);
	int CRC_high8 = CRC & 0xFF;
	int CRC_low8 = (CRC >> 8) & 0xFF;
	data.append(char(CRC_high8));
	data.append(char(CRC_low8));

	setCurrentData = data;
	timer->stop();
	try {

		qint64 bytesWritten = port->write(data);
		if (bytesWritten == -1) {
			throw QString("Failed to write to the current source serial port");
		}
		else if (bytesWritten != data.size()) {
			throw QString("Only part of the data was written to the current source serial port");
		}
		else if (!port->waitForBytesWritten(-1)) {
			throw QString("Timeout or error while waiting for the current source serial port to write");
		}
		else {
			//qDebug() << "Write to the current source serial port completed";
		}
	}
	catch (QString &e) {
		// 捕获并处理异常
		qDebug() << "Exception:" << e;
		// 在这里进行异常处理，比如关闭串口，重新连接等操作
		
		
	}
	timer->start();

}

void CurrentSource::setVoltage(float voltage)
{
	

	_voltage = voltage;

	QByteArray data;
	data.append(char(0x01));//从机01
	

	data.append(char(0x06));

	data.append(char(0x00));
	data.append(char(0x00));

	uint16_t v_tmp = (int)(voltage * 100);
	int v_tmp_low8 = v_tmp & 0xFF;
	int v_tmp_high8 = (v_tmp >> 8) & 0xFF;
	data.append(char(v_tmp_high8));
	data.append(char(v_tmp_low8));

	const uint8_t* dtr = reinterpret_cast<const uint8_t*>(data.data());
	uint16_t CRC=calculateCRC16(dtr, 6);
	int CRC_high8 = CRC & 0xFF;
	int CRC_low8 = (CRC >> 8) & 0xFF;
	data.append(char(CRC_high8));
	data.append(char(CRC_low8));

	
	setVoltageData = data;
	timer->stop();
	try {
		qint64 bytesWritten = port->write(data);
		if (bytesWritten == -1) {
			throw QString("Failed to write to the current source serial port");
		}
		else if (bytesWritten != data.size()) {
			throw QString("Only part of the data was written to the current source serial port");
		}
		else if (!port->waitForBytesWritten(-1)) {
			throw QString("Timeout or error while waiting for the current source serial port to write");
		}
		else {
			//qDebug() << "Write to the current source serial port completed";
		}
	}
	catch (QString &e) {
		// 捕获并处理异常
		qDebug() << "Exception:" << e;
		// 在这里进行异常处理，比如关闭串口，重新连接等操作
		
		
	}
	timer->start();
	
}

void CurrentSource::setCurrentAndVoltage(float current, float voltage)
{
	
	
	_voltage = voltage;
	_current = current;

	QByteArray data;
	data.append(char(0x01));//从机01
	

	data.append(char(0x10));

	data.append(char(0x00));
	data.append(char(0x00));

	data.append(char(0x00));
	data.append(char(0x02));

	data.append(char(0x04));

	uint16_t v_tmp = (int)(voltage * 100);
	int v_tmp_low8 = v_tmp & 0xFF;
	int v_tmp_high8 = (v_tmp >> 8) & 0xFF;
	data.append(char(v_tmp_high8));
	data.append(char(v_tmp_low8));

	uint16_t c_tmp = (int)(current * 100);
	int c_tmp_low8 = c_tmp & 0xFF;
	int c_tmp_high8 = (c_tmp >> 8) & 0xFF;
	data.append(char(c_tmp_high8));
	data.append(char(c_tmp_low8));

	

	const uint8_t* dtr = reinterpret_cast<const uint8_t*>(data.data());
	uint16_t CRC = calculateCRC16(dtr, 11);
	int CRC_high8 = CRC & 0xFF;
	int CRC_low8 = (CRC >> 8) & 0xFF;
	data.append(char(CRC_high8));
	data.append(char(CRC_low8));

	
	setCurrentAndVoltageData = data;
	timer->stop();
	try {
		qint64 bytesWritten = port->write(data);
		if (bytesWritten == -1) {
			throw QString("Failed to write to the current source serial port");
		}
		else if (bytesWritten != data.size()) {
			throw QString("Only part of the data was written to the current source serial port");
		}
		else if (!port->waitForBytesWritten(-1)) {
			throw QString("Timeout or error while waiting for the current source serial port to write");
		}
		else {
			//qDebug() << "Write to the current source serial port completed";
		}
	}
	catch (QString &e) {
		// 捕获并处理异常
		qDebug() << "Exception:" << e;
		// 在这里进行异常处理，比如关闭串口，重新连接等操作
		
		
	}
	timer->start();
	

}

void CurrentSource::setOut(bool isOut)
{
	
	if (isOut)
	{
		QByteArray data;
		data.append(char(0x01));//从机01
		

		data.append(char(0x06));

		data.append(char(0x00));
		data.append(char(0x09));

		data.append(char(0x00));
		data.append(char(0x01));

		const uint8_t* dtr = reinterpret_cast<const uint8_t*>(data.data());
		uint16_t CRC = calculateCRC16(dtr, 6);
		int CRC_high8 = CRC & 0xFF;
		int CRC_low8 = (CRC >> 8) & 0xFF;
		data.append(char(CRC_high8));
		data.append(char(CRC_low8));

		setOutData = data;
		timer->stop();
		try {
			qint64 bytesWritten = port->write(data);
			if (bytesWritten == -1) {
				throw QString("Failed to write to the current source serial port");
			}
			else if (bytesWritten != data.size()) {
				throw QString("Only part of the data was written to the current source serial port");
			}
			else if (!port->waitForBytesWritten(-1)) {
				throw QString("Timeout or error while waiting for the current source serial port to write");
			}
			else {
				//qDebug() << "Write to the current source serial port completed";
			}
		}
		catch (QString &e) {
			// 捕获并处理异常
			qDebug() << "Exception:" << e;
			// 在这里进行异常处理，比如关闭串口，重新连接等操作
			
			
		}
		timer->start();
	}
	else
	{
		QByteArray data;
		data.append(char(0x01));//从机01
		

		data.append(char(0x06));

		data.append(char(0x00));
		data.append(char(0x09));

		data.append(char(0x00));
		data.append(char(0x00));

		const uint8_t* dtr = reinterpret_cast<const uint8_t*>(data.data());
		uint16_t CRC = calculateCRC16(dtr, 6);
		int CRC_high8 = CRC & 0xFF;
		int CRC_low8 = (CRC >> 8) & 0xFF;
		data.append(char(CRC_high8));
		data.append(char(CRC_low8));

		setOutData = data;
		timer->stop();
		try {
			qint64 bytesWritten = port->write(data);
			if (bytesWritten == -1) {
				throw QString("Failed to write to the current source serial port");
			}
			else if (bytesWritten != data.size()) {
				throw QString("Only part of the data was written to the current source serial port");
			}
			else if (!port->waitForBytesWritten(-1)) {
				throw QString("Timeout or error while waiting for the current source serial port to write");
			}
			else {
				//qDebug() << "Write to the current source serial port completed";
			}
		}
		catch (QString &e) {
			// 捕获并处理异常
			qDebug() << "Exception:" << e;
			// 在这里进行异常处理，比如关闭串口，重新连接等操作
			
			
		}
		timer->start();
	}


}

void CurrentSource::setInitVal(float current, float voltage, bool isOut)
{
	setCurrent(current);
	setVoltage(voltage);
	setOut(isOut);
}



void CurrentSource::onReadyRead()
{
	QByteArray data = port->readAll(); // 读取所有可用数据
	
	//解析，只处理输出电流值报文
	if (!data.isEmpty() && (data.at(1) == 0x03))
	{
		QByteArray subData = data.mid(3, 2);
		int v = subData.toHex().toInt(nullptr, 16);
		_voltage = v / 100.0;

		QByteArray subData2 = data.mid(5, 2);
		int a = subData2.toHex().toInt(nullptr, 16);
		_current = a / 100.0;

		emit GetCurrentAndVoltage(_current, _voltage);
		
		
	}
	else if (!data.isEmpty() && (data== setCurrentData))
	{
		//设置电流成功
		emit setCurrentOK();
	}
	else if (!data.isEmpty() && (data == setVoltageData))
	{
		//设置电压成功
		emit setVoltageOK();
	}
	else if (!data.isEmpty() && (data == setOutData))
	{
		//设置开关成功
		emit setOutOK();
	}
	else if (!data.isEmpty()&& (data.at(1) == 0x10))
	{
		//设置电流电压成功
		emit setCurrentAndVoltageOK();
	}
	

	return;
}
