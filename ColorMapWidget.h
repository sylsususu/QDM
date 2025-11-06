#pragma once

#include <QWidget>
#include "ui_ColorMapWidget.h"
#include<qgraphicsitem.h>
#include<qfile.h>
#include <QMouseEvent> 
#include<qdebug.h>
#include <QToolTip> 
#include <QFileDialog>
#include<opencv2/opencv.hpp>
using namespace std;


// ColorMapWidget类，继承自QWidget
class ColorMapWidget : public QWidget
{
	Q_OBJECT

public:
	// 构造函数，接受四个矢量和一个维度参数
	ColorMapWidget(std::vector<double> magValueVec, std::vector<double> magValueVec_x,
		std::vector<double> magValueVec_y, std::vector<double> magValueVec_z, int dimension, QWidget *parent = nullptr);
	// 析构函数
	~ColorMapWidget();

	void setRawMagValue(std::vector<double> magValueVec, std::vector<double> magValueVec_x,
		std::vector<double> magValueVec_y, std::vector<double> magValueVec_z);

	void ChangeBToMat();

	void readTiff();

	void transImg();

	string QStr2Str(const QString qStr)
	{
		QByteArray data = qStr.toLocal8Bit();
		return string(data);
	}
	void setHW(int h, int w);

private:
	Ui::ColorMapWidgetClass ui; // UI对象

private:
	QGraphicsScene *m_scene_1, *m_scene_2, *m_scene_3, *m_scene_4; // 四个图形场景
	QGraphicsPixmapItem  *m_image_item_1, *m_image_item_2, *m_image_item_3, *m_image_item_4; // 四个图形场景中的图像项
	int dataDimension; // 数据维度
	int height, width; // 高度和宽度

	//归一化数据-显示
	vector<double> magValueVec; // 综合磁场标量结果
	vector<double> magValueVec_x; // 磁场X分量矢量
	vector<double> magValueVec_y; // 磁场Y分量矢量
	vector<double> magValueVec_z; // 磁场Z分量矢量


	//原始数据
	vector<double> magValueVec_raw; // 综合磁场标量结果
	vector<double> magValueVec_x_raw; // 磁场X分量矢量
	vector<double> magValueVec_y_raw; // 磁场Y分量矢量
	vector<double> magValueVec_z_raw; // 磁场Z分量矢量

	//伪彩图
	QImage imgBx;
	QImage imgBy;
	QImage imgBz;
	QImage imgB;

	float scalex = 1.0;
	float scaley = 1.0;
protected:
	// 事件过滤器
	bool eventFilter(QObject* obj, QEvent* event);

public slots:
	// 绘制色图的槽函数
	void drawColorMap();
	// 导入数据的槽函数
	void importData();


};
