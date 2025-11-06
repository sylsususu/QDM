#pragma once
#include <QTimer>
#include <QThread>
#include <QtWidgets/QApplication>
#include<qudpsocket.h>
#include<qdebug.h>
class UdpReceiveThread:public QObject
{
	Q_OBJECT;
private:
	QTimer* m_timer;
	QUdpSocket* receiveSocket;
public slots:
	void ReceiveData();
signals:
	void connectionStatusChanged(bool);
public:
	explicit UdpReceiveThread(QUdpSocket* m_socket, QObject* parent = nullptr);
	~UdpReceiveThread();

	

};

