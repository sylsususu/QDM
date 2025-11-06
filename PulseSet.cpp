#include "PulseSet.h"

PulseSet::PulseSet(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	// 设置界面为模态窗口
	this->setWindowModality(Qt::ApplicationModal); // 设置界面为模态窗口

	connect(ui.widget, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(on_MouseMoveCustomplot(QMouseEvent*)));
	connect(ui.pushButton_showPulse, &QPushButton::clicked, this, &PulseSet::showPulse);
	connect(ui.pushButton_readPulse, &QPushButton::clicked, this, &PulseSet::readPulseParam);
	connect(ui.pushButton_savePulse, &QPushButton::clicked, this, &PulseSet::savePusleParam);
	yAxis0 = ui.widget->axisRect(0)->axis(QCPAxis::atLeft, 0);
	graph0 = ui.widget->addGraph(nullptr, yAxis0);//0
	graph1 = ui.widget->addGraph(nullptr, yAxis0);//1
	graph2 = ui.widget->addGraph(nullptr, yAxis0);//2
	init_customplot();
	//// 创建一个整数验证器，限制输入范围为1到100
	QIntValidator* validator1 = new QIntValidator(1, 10000000, ui.lineEdit_cycleTime);
	ui.lineEdit_cycleTime->setValidator(validator1);
	delete validator1;
	QIntValidator* validator2 = new QIntValidator(0, 10000, ui.lineEdit_pulseNumber);
	ui.lineEdit_pulseNumber->setValidator(validator2);
	delete validator2;
	lineeditSetRange();
	QObject::connect(ui.lineEdit_cycleTime, &QLineEdit::textChanged,this,&PulseSet::lineeditSetRange);
	QObject::connect(ui.lineEdit_startTime0_0, &QLineEdit::textChanged, this, &PulseSet::lineeditSetRange);
	QObject::connect(ui.lineEdit_ctuTime0_0, &QLineEdit::textChanged, this, &PulseSet::lineeditSetRange);
	QObject::connect(ui.lineEdit_startTime1_0, &QLineEdit::textChanged, this, &PulseSet::lineeditSetRange);
	QObject::connect(ui.lineEdit_startTime1_1, &QLineEdit::textChanged, this, &PulseSet::lineeditSetRange);
	QObject::connect(ui.lineEdit_ctuTime1_0, &QLineEdit::textChanged, this, &PulseSet::lineeditSetRange);
	QObject::connect(ui.lineEdit_ctuTime1_1, &QLineEdit::textChanged, this, &PulseSet::lineeditSetRange);
	QObject::connect(ui.lineEdit_startTime2_0, &QLineEdit::textChanged, this, &PulseSet::lineeditSetRange);
	QObject::connect(ui.lineEdit_ctuTime2_0, &QLineEdit::textChanged, this, &PulseSet::lineeditSetRange);

	readInitPulseParam();
}

PulseSet::~PulseSet()
{
	
}

void PulseSet::showPulse()
{
	//总周期
	cycleTime = ui.lineEdit_cycleTime->text().toInt();
	//脉冲次数
	pulseNumbers = ui.lineEdit_pulseNumber->text().toInt();
	
	//脉冲起点
	startTime0_0 = ui.lineEdit_startTime0_0->text().toInt();
	//脉冲持续
	ctuTime0_0 = ui.lineEdit_ctuTime0_0->text().toInt();
	//相机起点0
	startTime1_0 = ui.lineEdit_startTime1_0->text().toInt();
	//相机起点1
	startTime1_1 = ui.lineEdit_startTime1_1->text().toInt();
	//相机持续0
	ctuTime1_0 = ui.lineEdit_ctuTime1_0->text().toInt();
	//相机持续1
	ctuTime1_1 = ui.lineEdit_ctuTime1_1->text().toInt();
	//微波开关起点
	startTime2_0 = ui.lineEdit_startTime2_0->text().toInt();
	//微波开关持续
	ctuTime2_0 = ui.lineEdit_ctuTime2_0->text().toInt();
	saveInitPulseParam();
	emit GetPulseTimesParam(startTime0_0, ctuTime0_0, startTime1_0, ctuTime1_0, startTime1_1, ctuTime1_1, startTime2_0, ctuTime2_0);
	//预览
	QVector<float>keys,A0, A1, A2;
	keys.resize(cycleTime);
	A0.resize(cycleTime);
	A1.resize(cycleTime);
	A2.resize(cycleTime);
	for (int i = 0; i < cycleTime; i++)
	{
		keys[i]=i;
		if ((i >= startTime0_0) && (i < startTime0_0 + ctuTime0_0))
		{
			A0[i] = (float)highLevel0;
		}
		else
		{
			A0[i] = 0.0;
		}
		bool a = (i >= startTime1_0) && (i < startTime1_0 + ctuTime1_0);
		bool b = (i >= startTime1_1) && (i < startTime1_1 + ctuTime1_1);
		if (a || b)
		{
			A1[i] = (float)highLevel1;
		}
		else
		{
			A1[i] = 0.0;
		}


		if ((i >= startTime2_0) && (i < startTime2_0 + ctuTime2_0))
		{
			A2[i] = (float)highLevel2;
		}
		else
		{
			A2[i] = 0.0;
		}
	}
	
	QVector<double>x_all, y_wave, y_camerawave, y_openclosewave;
	x_all.resize(cycleTime);
	y_wave.resize(cycleTime);
	y_camerawave.resize(cycleTime);
	y_openclosewave.resize(cycleTime);
	for (int i = 0; i < cycleTime; i++)
	{
		x_all[i] = keys[i];
		y_wave[i] = A0[i] / 5 + 5;
		y_camerawave[i] = A1[i] / 5 + 3;
		y_openclosewave[i] = A2[i] / 5 + 1;
	}
	
	init_customplot();
	ui.widget->axisRect(0)->axis(QCPAxis::atLeft, 0)->setRange(0,8);
	ui.widget->xAxis->setRange(0, cycleTime);
	ui.widget->graph(0)->setData(x_all, y_wave,true);
	ui.widget->graph(1)->setData(x_all, y_camerawave, true);
	ui.widget->graph(2)->setData(x_all, y_openclosewave, true);
	ui.widget->replot();

	//发送数据
	emit GetPulseParam(cycleTime, pulseNumbers, A0, A1, A2);
	
	
}

void PulseSet::init_customplot()
{
	
	
	QList<QCPAxis*> horizontal;
	QList<QCPAxis*> vertical;
	horizontal << ui.widget->axisRect(0)->axis(QCPAxis::atBottom, 0);
	vertical << yAxis0;
		
	ui.widget->axisRect(0)->setRangeZoomAxes(horizontal, vertical);//需要缩放的轴
	ui.widget->axisRect(0)->setRangeDragAxes(horizontal, vertical);//需要拖动的轴
	ui.widget->setInteraction(QCP::iRangeDrag, true);//开启拖动
	ui.widget->setInteraction(QCP::iRangeZoom, true);//开启缩放

	QBrush brush(QColor(6, 111, 217));
	ui.widget->xAxis->setBasePen(QPen(brush, 2));//设置x轴颜色
	yAxis0->setBasePen(QPen(brush, 2));//设置y轴颜色
	ui.widget->setBackground(QBrush(QColor(0, 0, 0)));
	yAxis0->setTickLabels(false);//隐藏刻度
	//设置坐标轴终端箭头样式
	ui.widget->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
	yAxis0->setUpperEnding(QCPLineEnding::esSpikeArrow);
	//设置小刻度和箭头颜色
	ui.widget->xAxis->setSubTickPen(QPen(brush, 2));
	ui.widget->yAxis->setSubTickPen(QPen(brush, 2));
	//设置坐标轴标签字体和颜色
	QFont f;
	f.setPixelSize(18);
	f.setFamily("SimHei");
	ui.widget->xAxis->setLabelFont(f);
	ui.widget->xAxis->setLabelColor(QColor(Qt::white));
	yAxis0->setLabelFont(f);
	yAxis0->setLabelColor(QColor(Qt::white));
	//设置坐标轴线字体
	QFont f_Tick;
	f_Tick.setPixelSize(14);
	f_Tick.setFamily("SimHei");
	ui.widget->xAxis->setTickLabelColor(Qt::white);
	ui.widget->yAxis->setTickLabelColor(Qt::white);
	ui.widget->xAxis->setTickLabelFont(f_Tick);
	yAxis0->setTickLabelFont(f_Tick);

	ui.widget->xAxis->setLabel("脉冲时间/ms");
	
	
	
	
	ui.widget->legend->setBrush(QBrush(QColor(255, 255, 255, 0))); // 设置图例颜色为白色半透明

	ui.widget->legend->setTextColor(QColor(255, 255, 255, 155)); // 设置图例文本颜色为红色
	graph0->setName("脉冲切频");// 设置图例名称
	graph1->setName("相机触发");// 设置图例名称
	graph2->setName("微波开关");// 设置图例名称
	
	ui.widget->legend->setFillOrder(QCPLayoutGrid::foColumnsFirst);
	ui.widget->graph(0)->setPen(QPen(QColor(255, 0, 0, 255), 2));
	ui.widget->graph(1)->setPen(QPen(QColor(50, 205, 50, 255), 2));
	ui.widget->graph(2)->setPen(QPen(QColor(0, 0, 255, 255), 2));

	
	ui.widget->graph(0)->setLineStyle(QCPGraph::LineStyle::lsStepLeft);
	ui.widget->graph(1)->setLineStyle(QCPGraph::LineStyle::lsStepLeft);
	ui.widget->graph(2)->setLineStyle(QCPGraph::LineStyle::lsStepLeft);
	ui.widget->legend->setVisible(true); // 显示图例
	// 将图例布局设置为水平布局
	ui.widget->setInteractions(QCP::iRangeZoom | QCP::Interaction::iRangeDrag | QCP::iSelectPlottables | QCP::iMultiSelect);
}

void PulseSet::readPulseParam()
{
	QString filePath = QFileDialog::getOpenFileName(nullptr, "Open JSON File", ".", "JSON Files (*.json)");

	// 检查用户是否选择了文件
	if (!filePath.isEmpty()) {
		lodaPulseParam(filePath);
	}
	
}

void PulseSet::savePusleParam()
{
	// 创建一个JSON对象
	QJsonObject jsonData;

	// 添加参数到JSON对象
	jsonData["cycleTime"] = cycleTime;
	jsonData["pulseNumbers"] = pulseNumbers;
	jsonData["highLevel0"] = highLevel0;
	jsonData["highLevel1"] = highLevel1;
	jsonData["highLevel2"] = highLevel2;
	jsonData["startTime0_0"] = startTime0_0;
	jsonData["ctuTime0_0"] = ctuTime0_0;
	jsonData["startTime1_0"] = startTime1_0;
	jsonData["ctuTime1_0"] = ctuTime1_0;
	jsonData["startTime1_1"] = startTime1_1;
	jsonData["ctuTime1_1"] = ctuTime1_1;
	jsonData["startTime2_0"] = startTime2_0;
	jsonData["ctuTime2_0"] = ctuTime2_0;

	// 创建一个JSON文档
	QJsonDocument jsonDoc(jsonData);

	// 将JSON文档转换为字符串
	QString jsonString = jsonDoc.toJson();


	QString filePath = QFileDialog::getSaveFileName(nullptr, "Save JSON File", ".", "JSON Files (*.json)");

	// 检查用户是否选择了文件路径
	if (!filePath.isEmpty()) {
		// 执行保存JSON文件的操作
		// 将字符串写入文件
		QFile file(filePath);
		if (file.open(QIODevice::WriteOnly)) {
			QTextStream stream(&file);
			stream << jsonString;
			file.close();
		}
	}

	
	
}

void PulseSet::lodaPulseParam(QString str)
{
	// 打开JSON文件
	QFile file(str);
	if (!file.open(QIODevice::ReadOnly)) {
		// 文件打开失败
		return ;
	}

	// 读取JSON数据
	QByteArray jsonData = file.readAll();

	// 关闭文件
	file.close();

	// 将JSON数据解析为JSON文档
	QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

	// 将JSON文档转换为JSON对象
	QJsonObject jsonObj = jsonDoc.object();

	// 从JSON对象中获取参数值
	cycleTime = jsonObj["cycleTime"].toInt();
	pulseNumbers = jsonObj["pulseNumbers"].toInt();
	highLevel0 = jsonObj["highLevel0"].toInt();
	highLevel1 = jsonObj["highLevel1"].toInt();
	highLevel2 = jsonObj["highLevel2"].toInt();
	startTime0_0 = jsonObj["startTime0_0"].toInt();
	ctuTime0_0 = jsonObj["ctuTime0_0"].toInt();
	startTime1_0 = jsonObj["startTime1_0"].toInt();
	ctuTime1_0 = jsonObj["ctuTime1_0"].toInt();
	startTime1_1 = jsonObj["startTime1_1"].toInt();
	ctuTime1_1 = jsonObj["ctuTime1_1"].toInt();
	startTime2_0 = jsonObj["startTime2_0"].toInt();
	ctuTime2_0 = jsonObj["ctuTime2_0"].toInt();


	//设置界面显示值一致
	ui.lineEdit_cycleTime->setText(QString::number(cycleTime));
	ui.lineEdit_pulseNumber->setText(QString::number(pulseNumbers));
	ui.lineEdit_startTime0_0->setText(QString::number(startTime0_0));
	ui.lineEdit_ctuTime0_0->setText(QString::number(ctuTime0_0));
	ui.lineEdit_startTime1_0->setText(QString::number(startTime1_0));
	ui.lineEdit_ctuTime1_0->setText(QString::number(ctuTime1_0));
	ui.lineEdit_startTime1_1->setText(QString::number(startTime1_1));
	ui.lineEdit_ctuTime1_1->setText(QString::number(ctuTime1_1));
	ui.lineEdit_startTime2_0->setText(QString::number(startTime2_0));
	ui.lineEdit_ctuTime2_0->setText(QString::number(ctuTime2_0));

	//预览
	QVector<float>keys, A0, A1, A2;
	keys.resize(cycleTime);
	A0.resize(cycleTime);
	A1.resize(cycleTime);
	A2.resize(cycleTime);
	for (int i = 0; i < cycleTime; i++)
	{
		keys[i] = i;
		if ((i >= startTime0_0) && (i < startTime0_0 + ctuTime0_0))
		{
			A0[i] = (float)highLevel0;
		}
		else
		{
			A0[i] = 0.0;
		}
		bool a = (i >= startTime1_0) && (i < startTime1_0 + ctuTime1_0);
		bool b = (i >= startTime1_1) && (i < startTime1_1 + ctuTime1_1);
		if (a || b)
		{
			A1[i] = (float)highLevel1;
		}
		else
		{
			A1[i] = 0.0;
		}


		if ((i >= startTime2_0) && (i < startTime2_0 + ctuTime2_0))
		{
			A2[i] = (float)highLevel2;
		}
		else
		{
			A2[i] = 0.0;
		}
	}
	QVector<double>x_all, y_wave, y_camerawave, y_openclosewave;
	x_all.resize(cycleTime);
	y_wave.resize(cycleTime);
	y_camerawave.resize(cycleTime);
	y_openclosewave.resize(cycleTime);
	for (int i = 0; i < cycleTime; i++)
	{
		x_all[i] = keys[i];
		y_wave[i] = A0[i] / highLevel0 + 5;
		y_camerawave[i] = A1[i] / highLevel1 + 3;
		y_openclosewave[i] = A2[i] / highLevel2 + 1;
	}

	init_customplot();
	ui.widget->axisRect(0)->axis(QCPAxis::atLeft, 0)->setRange(0, 8);
	ui.widget->xAxis->setRange(0, cycleTime);
	ui.widget->graph(0)->setData(x_all, y_wave, true);
	ui.widget->graph(1)->setData(x_all, y_camerawave, true);
	ui.widget->graph(2)->setData(x_all, y_openclosewave, true);
	ui.widget->replot();
	//发送数据
	emit GetPulseParam(cycleTime, pulseNumbers, A0, A1, A2);

	return;
}

void PulseSet::lineeditSetRange()
{
	

	int maxA = ui.lineEdit_cycleTime->text().toInt();
	QIntValidator* validator1 = new QIntValidator(0, maxA-1, ui.lineEdit_startTime0_0);
	ui.lineEdit_startTime0_0->setValidator(validator1);
	delete validator1;
	QIntValidator* validator2 = new QIntValidator(0, maxA - 1, ui.lineEdit_startTime1_0);
	ui.lineEdit_startTime1_0->setValidator(validator2);
	delete validator2;
	QIntValidator* validator3 = new QIntValidator(0, maxA - 1, ui.lineEdit_startTime1_1);
	ui.lineEdit_startTime1_1->setValidator(validator3);
	delete validator3;
	QIntValidator* validator4 = new QIntValidator(0, maxA - 1, ui.lineEdit_startTime2_0);
	ui.lineEdit_startTime2_0->setValidator(validator4);
	delete validator4;


	QIntValidator* validator5 = new QIntValidator(0, maxA - 1- ui.lineEdit_startTime0_0->text().toInt(), ui.lineEdit_ctuTime0_0);
	ui.lineEdit_ctuTime0_0->setValidator(validator5);
	delete validator5;
	QIntValidator* validator6 = new QIntValidator(0, maxA - 1- ui.lineEdit_startTime1_0->text().toInt(), ui.lineEdit_ctuTime1_0);
	ui.lineEdit_ctuTime1_0->setValidator(validator6);
	delete validator6;
	QIntValidator* validator7 = new QIntValidator(0, maxA - 1- ui.lineEdit_startTime1_1->text().toInt(), ui.lineEdit_ctuTime1_1);
	ui.lineEdit_ctuTime1_1->setValidator(validator7);
	delete validator7;
	QIntValidator* validator8 = new QIntValidator(0, maxA - 1- ui.lineEdit_startTime2_0->text().toInt(), ui.lineEdit_ctuTime2_0);
	ui.lineEdit_ctuTime2_0->setValidator(validator8);
	delete validator8;
}

void PulseSet::readInitPulseParam()
{
	QString filePath = "./initPulse.json";

	// 检查用户是否选择了文件
	if (!filePath.isEmpty()) {
		lodaPulseParam(filePath);
	}
}

void PulseSet::saveInitPulseParam()
{
	// 创建一个JSON对象
	QJsonObject jsonData;

	// 添加参数到JSON对象
	jsonData["cycleTime"] = cycleTime;
	jsonData["pulseNumbers"] = pulseNumbers;
	jsonData["highLevel0"] = highLevel0;
	jsonData["highLevel1"] = highLevel1;
	jsonData["highLevel2"] = highLevel2;
	jsonData["startTime0_0"] = startTime0_0;
	jsonData["ctuTime0_0"] = ctuTime0_0;
	jsonData["startTime1_0"] = startTime1_0;
	jsonData["ctuTime1_0"] = ctuTime1_0;
	jsonData["startTime1_1"] = startTime1_1;
	jsonData["ctuTime1_1"] = ctuTime1_1;
	jsonData["startTime2_0"] = startTime2_0;
	jsonData["ctuTime2_0"] = ctuTime2_0;

	// 创建一个JSON文档
	QJsonDocument jsonDoc(jsonData);

	// 将JSON文档转换为字符串
	QString jsonString = jsonDoc.toJson();

	QString filePath = "./initPulse.json";


	// 检查用户是否选择了文件路径
	if (!filePath.isEmpty()) {
		// 执行保存JSON文件的操作
		// 将字符串写入文件
		QFile file(filePath);
		if (file.open(QIODevice::WriteOnly)) {
			QTextStream stream(&file);
			stream << jsonString;
			file.close();
		}
	}
}






void PulseSet::on_MouseMoveCustomplot(QMouseEvent* event)
{
	QPointF CPoint = event->pos();

	//鼠标点击的后屏幕位置转换到下坐标轴对应坐标
	int cur_x = ui.widget->xAxis->pixelToCoord(CPoint.x());
	int index = ui.widget->graph(0)->findBegin(cur_x, false);
	if (index == ui.widget->graph()->data().data()->size() || index == 0)
		return;
	float cur_y = ui.widget->graph()->data().data()->at(index)->value;
	QToolTip::showText(event->globalPos(), tr(
		
		"<table>"
		"<tr>"
		"<td><h5>X: %2</h5></td>" 
		"</tr>"
		"</table>").arg(QString::number(cur_x)), this, this->rect());
	//m_cur_Label_temp->setText(QString("x = %1, y = %2").arg(cur_x).arg(cur_y));//设置游标说明内容
	//注意：这里使用的是QToolTip，没有使用CustomPlot里面的游标，所以不需要调用replot函数
	//ui.widget->replot();//绘制器一定要重绘，否则看不到游标位置更新情况
}