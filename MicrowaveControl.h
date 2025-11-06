#pragma once
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class MicrowaveControl : public QObject

{
	Q_OBJECT
public:
	MicrowaveControl(QObject *parent = 0);
	~MicrowaveControl();

	QSerialPort *serial;

	
	bool connectToPort(QString, int, QSerialPort::DataBits , QSerialPort::Parity , QSerialPort::StopBits , QSerialPort::FlowControl );
	void closePort();


	void setReSet();
	void setHeartbeatDetection();

	
	void setSweepParameters(uint, uint, uint);
	void setTriggerSelection(bool);
	void setMicrowavAmplifierSwitch(bool);
	void startOut();
	void stopOut();

	void setInternalTriggerFrequencyParameters(uint);
	void setPointFrequencyParameters(uint);
	void setPointOrScanOn(int);

	void checkState();

private slots:

	void slotReadData();

signals:
	
	void getRecSignals(int);
};

typedef struct  My_Order
{
	char m_Head[2];
	char m_Long[2];
	char m_ID[2];
	char m_Type[2];
	char m_Data[4];
};

typedef struct  Scan_Order
{
	char m_Head[2];
	char m_Long[2];
	char m_ID[2];
	char m_Type[2];
	char m_Start_Rate[4];
	char m_End_Rate[4];
	char m_Step_Long[4];
};
