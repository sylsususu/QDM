#include "PulseUDPCom.h"

PulseUDPCom::PulseUDPCom(QHostAddress localAddress, qint16 localPort, QHostAddress remoteAddress, qint16 remotePort)
{
    m_socket = new QUdpSocket();
    m_socket->bind(localAddress, localPort);
    this->remoteAddress = remoteAddress;
    this->remotePort = remotePort;
    m_socket->setReadBufferSize(10240);
}
PulseUDPCom::~PulseUDPCom()
{
    m_socket->abort();
    delete m_socket;
}
/// <summary>
/// 构建除功能码不同，其他相同的包头
/// </summary>
/// <param name="code">功能码</param>
QByteArray PulseUDPCom::constructHeader(char code)
{
    QByteArray baHead, head1, head2;
    convertStringToHex("55aa0000", head1);
    convertStringToHex("10000000dd00", head2);
    baHead.append(head1);
    baHead.append(code);
    baHead.append(head2);
    return baHead;
    
}
/// <summary>
/// QString转成16进制数字字符串
/// </summary>
/// <param name="str"></param>
/// <param name="byteData"></param>
void PulseUDPCom::convertStringToHex(const QString& str, QByteArray& byteData)
{
    int hexdata, lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    byteData.resize(len / 2);
    char lstr, hstr;
    for (int i = 0; i < len; )
    {
        //char lstr,
        hstr = str[i].toLatin1();
        if (hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if (i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = convertCharToHex(hstr);
        lowhexdata = convertCharToHex(lstr);
        if ((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata * 16 + lowhexdata;
        i++;
        byteData[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    byteData.resize(hexdatalen);
}

char PulseUDPCom::convertCharToHex(char ch)
{
    if ((ch >= '0') && (ch <= '9'))
        return ch - 0x30;
    else if ((ch >= 'A') && (ch <= 'F'))
        return ch - 'A' + 10;
    else if ((ch >= 'a') && (ch <= 'f'))
        return ch - 'a' + 10;
    else return (-1);
}
/// <summary>
/// 发送脉宽设置命令
/// </summary>
/// <param name="channel"></param>
/// <param name="loopNo"></param>
/// <param name="pulseEdgeNo"></param>
/// <param name="pulseEdgeTime"></param>
void PulseUDPCom::sendPulseWidth(char channel, int loopNo, int pulseEdgeNo, int pulseEdgeTime)
{
    QByteArray baMessage;
    
    //1.将两段bit合并计算得到十进制int
    //2.再把10进制int格式化表示成固定位数的十六进制字符串
    //3.最后把十六进制字符串转成字节数组
    QByteArray baNo,baTime;
    QString strNo =  QString("%1").arg(loopNo * 16 + pulseEdgeNo, 4, 16, QLatin1Char('0'));
    convertStringToHex(strNo, baNo);
    int time = floor(pulseEdgeTime / 4);
    QString strTime= QString("%1").arg(time, 8, 16, QLatin1Char('0'));
    convertStringToHex(strTime, baTime);

    baMessage.append(constructHeader(0x0b));
    baMessage.append(channel);
    baMessage.append(baNo);
    baMessage.append(baTime);

    m_socket->writeDatagram(baMessage, remoteAddress, remotePort);
    
}
/// <summary>
/// 发送循环时长设置指令
/// </summary>
/// <param name="channel"></param>
/// <param name="loopNo"></param>
/// <param name="loopTime"></param>
void PulseUDPCom::sendLoopTime(char channel, int loopNo, int loopTime)
{
    QByteArray baMessage;
    QByteArray baNo, baTime;    
    QString strNo = QString("%1").arg(loopNo * 16 + 12, 4, 16, QLatin1Char('0'));
    convertStringToHex(strNo, baNo);
    int time = floor(loopTime / 4);
    QString strTime = QString("%1").arg(time, 8, 16, QLatin1Char('0'));
    convertStringToHex(strTime, baTime);

    baMessage.append(constructHeader(0x0b));
    baMessage.append(channel);
    baMessage.append(baNo);
    baMessage.append(baTime);

    m_socket->writeDatagram(baMessage, remoteAddress, remotePort);
}
/// <summary>
/// 发送通道循环次数指令
/// </summary>
/// <param name="channel"></param>
/// <param name="loopNo"></param>
/// <param name="loopNumber"></param>
void PulseUDPCom::sendLoopCycleNumber(char channel, int loopNo, int loopNumber)
{
    QByteArray baMessage;

    QByteArray baNo, baLoopNumber;
    QString strNo = QString("%1").arg(loopNo * 16 + 13, 4, 16, QLatin1Char('0'));
    convertStringToHex(strNo, baNo);
    QString strLoopNumber = QString("%1").arg(loopNumber, 8, 16, QLatin1Char('0'));
    convertStringToHex(strLoopNumber, baLoopNumber);

    baMessage.append(constructHeader(0x0b));
    baMessage.append(channel);
    baMessage.append(baNo);
    baMessage.append(baLoopNumber);

    m_socket->writeDatagram(baMessage, remoteAddress, remotePort);
}
/// <summary>
/// 发送设置处理模式命令
/// </summary>
/// <param name="channel"></param>
/// <param name="loopNo"></param>
void PulseUDPCom::sendProcessMode(char channel, int loopNo,QString strModeBinary)
{
    QByteArray baMessage;

    QByteArray baNo, baMode;
    QString strNo = QString("%1").arg(loopNo * 16 + 14, 4, 16, QLatin1Char('0'));
    convertStringToHex(strNo, baNo);
    bool ok;
    int intMode = strModeBinary.toInt(&ok, 2);
    QString strMode= QString("%1").arg(intMode, 8, 16, QLatin1Char('0'));
    convertStringToHex(strMode, baMode);

    baMessage.append(constructHeader(0x0b));
    baMessage.append(channel);
    baMessage.append(baNo);
    baMessage.append(baMode);

    m_socket->writeDatagram(baMessage, remoteAddress, remotePort);

}
/// <summary>
/// 发送启动输出指令
/// </summary>
void PulseUDPCom::sendStartOut()
{
    QByteArray baMessage, baPara;
    convertStringToHex("00000000000000", baPara);
    baMessage.append(constructHeader(0x0c));
    baMessage.append(baPara);

    m_socket->writeDatagram(baMessage, remoteAddress, remotePort);
}
/// <summary>
/// 发送设置当前通道有多少个LOOP指令
/// </summary>
/// <param name="channel"></param>
/// <param name="loopNumber"></param>
void PulseUDPCom::sendLoopNumber(char channel, qint8 loopNumber)
{
    QByteArray baMessage, baPara;

    convertStringToHex("0000000000", baPara);
    baMessage.append(constructHeader(0x0a));
    baMessage.append(channel+240);
    baMessage.append(loopNumber);
    baMessage.append(baPara);
    m_socket->writeDatagram(baMessage, remoteAddress, remotePort);
}
/// <summary>
/// 发送设置LOOP个数设置生效指令
/// </summary>
void PulseUDPCom::sendLoopNumberValidate()
{
    QByteArray baMessage, baPara;

    convertStringToHex("00000000000000", baPara);
    baMessage.append(constructHeader(0x0d));
    baMessage.append(baPara);

    m_socket->writeDatagram(baMessage, remoteAddress, remotePort);
}
/// <summary>
/// 发送心跳检测
/// </summary>
void PulseUDPCom::sendHeartDetection()
{
    m_socket->writeDatagram(QByteArray(0x00), remoteAddress, remotePort);
}

/// <summary>
/// 清除某个通道内的波形
/// </summary>
/// <param name="channel">通道号</param>
void PulseUDPCom::sendClearChannel(char channel)
{
    QByteArray baMessage = QByteArrayLiteral("\x55\xaa\x00\x00\x08\x10\x00\x00\x00\xdd\x00\x00\x00\x00\x00");
    if ((0 <= channel) && (channel <= 7))
    {
        baMessage.append(QByteArrayLiteral("\x00"));
        baMessage.append(channel);
    }
    else
    {
        baMessage.append(QByteArrayLiteral("\x01"));
        baMessage.append(channel - 8);
    }
    
    baMessage.append(QByteArrayLiteral("\x00"));
    m_socket->writeDatagram(baMessage, remoteAddress, remotePort);
}
