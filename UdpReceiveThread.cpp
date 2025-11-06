#include "UdpReceiveThread.h"
#include <QtGui/qregion.h>

UdpReceiveThread::UdpReceiveThread(QUdpSocket* m_socket, QObject* parent)
{
    this->receiveSocket = m_socket;
    int result=receiveSocket->writeDatagram(QByteArray(0x00), QHostAddress("192.168.100.14"), 4040);
    
}



void UdpReceiveThread::ReceiveData()
{
    QByteArray datagram;   
    if (receiveSocket->hasPendingDatagrams())
    {
        emit connectionStatusChanged(true);
        while (receiveSocket->hasPendingDatagrams())
        {
            receiveSocket->readDatagram(datagram.data(),datagram.size());
        }
    }
    else
    {
        emit connectionStatusChanged(false);
    }

}

UdpReceiveThread::~UdpReceiveThread()
{
}

