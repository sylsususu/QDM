#pragma once
#include<qlist.h>
#include<qpoint.h>
class LoopData
{
public:
	int channel;//通道号
	int loopNo;//循环编号
	QList<int> selectedCell;//loop包含的选中单元格
	QList<int> pulseRise;//脉冲上升单元格编号
	QList<int> pulseFall;//脉冲下降单元格编号
	QList<int> pulseTotal; //总的脉冲沿集合
	QList<int> pulseTime; // 脉冲延时间
	int high_Index, low_Index;//loop的起始单元格
	int pulseNo;//脉冲沿数量		 
	int totalTime; //LOOP总时间
	int cicleTime; //当前LOOP循环次数
	QString processMode;//处理模式

};

class ChannelData
{

public:
	QList<int> selectedCell;//通道中选中的单元格
	int high_Index, low_Index;//通道的起始单元格
	int channelNo; //通道号
	QList<LoopData*> loopDataList;//通道Loop数据组成的list
	int loopNum;//通道包含的Loop数量	
	QList<QPoint> channelPointlist; //每个通道绘图点


};


