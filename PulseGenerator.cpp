#include "PulseGenerator.h"
#include<qpen.h>
#include<windowsx.h>
#include<qt_windows.h>


const int g_nBorder = 10; //设置鼠标拖动调整边框时，鼠标和边框的距离
const int origin_Width = 1924;//主窗口的初始宽度
const int origin_Height = 1040;//主窗口的初始高度

extern PulseUDPCom* sendUdp;
extern UdpReceiveThread* receiver;
extern QList<ChannelData*> listChannel;

PulseGenerator::PulseGenerator(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    //设置窗口模式
    //setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	setWindowFlags(Qt::FramelessWindowHint);
	//子类窗口采用setStyleSheet 设置背景色无效,需要加上setAttribute(Qt::WA_StyledBackground);目的是脱离父窗口的样式。
	setAttribute(Qt::WA_StyledBackground);
	setAutoFillBackground(true);   		
    //设置坐标图样式
    ui.widget->xAxis->setVisible(true);
    ui.widget->yAxis->setVisible(true);
    QBrush brush(QColor(67, 138, 255, 255));
    ui.widget->xAxis->setBasePen(QPen(brush, 3));//设置x轴颜色
    ui.widget->yAxis->setBasePen(QPen(brush, 3));//设置y轴颜色
	ui.widget->setBackground(QBrush(QColor("#f7f7f7")));
    ui.widget->yAxis->setTickLabels(false);
	ui.widget->setInteractions(QCP::iRangeZoom | QCP::Interaction::iRangeDrag | QCP::iSelectPlottables | QCP::iMultiSelect);
	ui.widget->axisRect()->setRangeZoom(Qt::Orientation::Horizontal);//只能水平缩放
	ui.widget->axisRect()->setRangeDrag(Qt::Horizontal);//只能水平拖动
	connect(ui.widget->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(setAxisRangeXPositive(QCPRange)));//控制X轴不能向负方向平移、缩放
	ui.pushButton_SendData->setVisible(false);
	//坐标图右键菜单
	ui.widget->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
	menu = new QMenu(ui.widget);
	QAction* action1 = new QAction(QStringLiteral("还原视图"));
	menu->addAction(action1);
	connect(ui.widget, &QCustomPlot::customContextMenuRequested, this, &PulseGenerator::showMenu); //绘图区添加右键菜单-显示还原视图
	connect(action1, &QAction::triggered, this, &PulseGenerator::RestoreView);
    //设置坐标图控制方式
    ui.widget->setInteractions(QCP::iRangeZoom | QCP::Interaction::iRangeDrag | QCP::iSelectPlottables | QCP::iMultiSelect);
    ui.widget->setMultiSelectModifier(Qt::KeyboardModifier::ControlModifier);   
    ui.widget->axisRect()->setRangeZoom(Qt::Orientation::Horizontal);//只能水平缩放
    ui.widget->axisRect()->setRangeDrag(Qt::Horizontal);//只能水平拖动

    //设置tablewidget_Main
    ui.tableWidget_Main ->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui.tableWidget_Main->verticalHeader()->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui.tableWidget_Main->setFocusPolicy(Qt::NoFocus);
    ui.tableWidget_Main->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
    ui.tableWidget_Main->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);
    ui.tableWidget_Main->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);   
    connect(ui.tableWidget_Main->horizontalScrollBar(), &QScrollBar::valueChanged, this, &PulseGenerator::on_scorllBarChanged);//滚动条同步滚动
    ui.tableWidget_Main->viewport()->installEventFilter(this);

    //设置tablewidget_Channel
    ui.tableWidget_Channel->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
    ui.tableWidget_Channel->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
    ui.tableWidget_Channel->viewport()->installEventFilter(this);
    for (int i = 0; i < 16; i++)
    {
        QComboBox* box = new QComboBox(this);
        for (int j = 1; j < 17; j++)
        {
            box->addItem(QString::number(j));            
        }
        box->setCurrentIndex(i);
        box->setStyleSheet("QComboBox {background-color:#438AFF; color:#ffffff;font-size:18px;font-weight:600;}"
            "QComboBox QAbstractItemView {color: #d34b4b;"
            "background-color: #FFFFFF; selection-color: #3377FF;selection-background-color:#438AFF}"
            "QComboBox::down-arrow {width:15px;}"
            "QComboBox::drop-down {width:10px;backround-color:#ffffff}"
        );
       ui.tableWidget_Channel->setCellWidget(i, 0, box);       
    }                                                                                                                              
    //设置tablewidget_Seg
    ui.tableWidget_Seg->verticalHeader()->setDefaultAlignment(Qt::AlignRight);
    ui.tableWidget_Seg->setFocusPolicy(Qt::NoFocus);
    ui.tableWidget_Seg->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);    
	ui.tableWidget_Seg->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);
    ui.tableWidget_Seg->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectItems);
    connect(ui.tableWidget_Seg, &QTableWidget::cellClicked, this, &PulseGenerator::on_CellClicked);
	
    //设置tablewidget_Loop
    ui.tableWidget_Loop->verticalHeader()->setDefaultAlignment(Qt::AlignRight);
    ui.tableWidget_Loop->setFocusPolicy(Qt::NoFocus);
    ui.tableWidget_Loop->setEditTriggers(QAbstractItemView::EditTrigger::DoubleClicked);
    ui.tableWidget_Loop->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
    connect(ui.tableWidget_Loop->horizontalScrollBar(), &QScrollBar::valueChanged, this, &PulseGenerator::on_scorllBarChanged);//滚动条同步滚动
	connect(ui.tableWidget_Loop, &QTableWidget::itemChanged, this, &PulseGenerator::on_tableWidget_Loop_ItemChanged);
	ui.tableWidget_Loop->setMouseTracking(true);//开启鼠标跟踪
	connect(ui.tableWidget_Loop, &QTableWidget::entered, this, &PulseGenerator::slot_tooltip);//鼠标悬浮显示单元格内容
	//ui.tableWidget_Loop->viewport()->installEventFilter(this);//通过鼠标事件实现拖放复制Length数据
	//设置tablewidget_RowNote
    ui.tableWidget_RowNote->verticalHeader()->setDefaultAlignment(Qt::AlignRight);
    ui.tableWidget_RowNote->setFocusPolicy(Qt::NoFocus);
    ui.tableWidget_RowNote->setEditTriggers(QAbstractItemView::EditTrigger::DoubleClicked);
    ui.tableWidget_RowNote->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
	ui.tableWidget_RowNote->setMouseTracking(true);//开启鼠标跟踪
	connect(ui.tableWidget_RowNote, &QTableWidget::entered, this, &PulseGenerator::slot_tooltip);//鼠标悬浮显示单元格内容
    //设置tablewidget_ColNote
    ui.tableWidget_ColNote->setFocusPolicy(Qt::NoFocus);
    ui.tableWidget_ColNote->setEditTriggers(QAbstractItemView::EditTrigger::DoubleClicked);
    ui.tableWidget_ColNote->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
    ui.tableWidget_ColNote->viewport()->installEventFilter(this);
	ui.tableWidget_ColNote->setMouseTracking(true);//开启鼠标跟踪
	connect(ui.tableWidget_ColNote, &QTableWidget::entered, this, &PulseGenerator::slot_tooltip);//鼠标悬浮显示单元格内容
    //初始化所有tableWidget的内容为""
	///改为封装成函数，方便清除功能clear函数调用
	InitTableItems();
    /////所有TableWidget初始化完成/////////////
    connect(ui.pushButton_Close, &QPushButton::clicked, this, &QWidget::close);
    connect(ui.pushButton_Mini, &QPushButton::clicked, this, &PulseGenerator::on_Mini_Clicked);
    connect(ui.pushButton_Max, &QPushButton::clicked, this, &PulseGenerator::on_Max_Clicked);
    connect(ui.pushButton_CheckPulse, &QPushButton::clicked, this, &PulseGenerator::on_CheckPulse_Clicked);
	connect(ui.pushButton_SendData, &QPushButton::clicked, this, &PulseGenerator::on_SendData_Clicked);
	connect(ui.pushButton_Save, &QPushButton::clicked, this, &PulseGenerator::on_Save_Clicked);
	connect(ui.pushButton_Import, &QPushButton::clicked, this, &PulseGenerator::on_Import_Clicked);
	connect(ui.pushButton_Clear, &QPushButton::clicked, this, &PulseGenerator::on_Clear_Clicked);
	connect(ui.pushButton_Connect, &QPushButton::clicked, this, &PulseGenerator::on_Connect_Clicked);
	//初始化发送UDP
	//sendUdp = new PulseUDPCom(QHostAddress("192.168.100.221"), 4000, QHostAddress("192.168.100.14"), 4040);//下位机的IP及端口

	///判断界面所有表格内容有没有变化，如果有，重置isSaved和isChecked状态，要求重新保存和预览
	connect(ui.tableWidget_Seg, &QTableWidget::itemChanged, this, &PulseGenerator::itemChangeSaved);
	connect(ui.tableWidget_RowNote, &QTableWidget::itemChanged, this, &PulseGenerator::itemChangeSaved);
	connect(ui.tableWidget_ColNote, &QTableWidget::itemChanged, this, &PulseGenerator::itemChangeSaved);
	connect(ui.tableWidget_Main, &QTableWidget::itemSelectionChanged, this, &PulseGenerator::selectionChangeSaved);
	connect(ui.tableWidget_Channel, &QTableWidget::itemChanged, this, &PulseGenerator::itemChangeSaved);
	///开启定时查询连接状态
	isConnected = false;
	//connection_Timer = new QTimer();
	//connection_Timer->setInterval(2000);
	//receiver = new UdpReceiveThread(sendUdp->m_socket);
	//m_thread = new QThread();
	//receiver->moveToThread(m_thread);
	//m_thread->start();
	connect(receiver, &UdpReceiveThread::connectionStatusChanged, this, &PulseGenerator::changeConnectionStatus);
	//connect(connection_Timer, &QTimer::timeout, receiver, &UdpReceiveThread::ReceiveData,Qt::QueuedConnection);
	//connection_Timer->start();
	///序列保存状态设置
	isSaved = true; //初始界面没有序列，不需要保存
	isChecked = false; //初始没有预览检查
	/// 调整窗口大小，所有控件一起改变大小
	m_objectList = this->children();
	//把父窗口不是主UI的控件也加入到变化列表
	m_objectList.append(ui.pushButton_Max); 
	m_objectList.append(ui.pushButton_Mini);
	m_objectList.append(ui.pushButton_Close);
	m_objectList.append(ui.label);
	m_objectList.append(ui.pushButton_Connect);
	m_objectList.append(ui.pushButton_Import);
	m_objectList.append(ui.pushButton_Clear);
	m_objectList.append(ui.pushButton_Save);
	m_objectList.append(ui.pushButton_CheckPulse);
	m_objectList.append(ui.pushButton_SendData);

	foreach(QObject * obj, m_objectList)
	{
		m_objMap.insert(obj, obj->property("geometry").toRect());
	}
}

void  PulseGenerator::InitTableItems()
{
	for (int i = 0; i < ui.tableWidget_Main->rowCount(); i++)
	{
		for (int j = 0; j < ui.tableWidget_Main->columnCount(); j++)
		{
			QTableWidgetItem* item = new QTableWidgetItem;
			item->setText("");
			ui.tableWidget_Main->setItem(i, j, item);


			QTableWidgetItem* item_1 = new QTableWidgetItem;
			item_1->setText("");
			ui.tableWidget_Loop->setItem(i, j, item_1);

			QTableWidgetItem* item_2 = new QTableWidgetItem;
			item_2->setText("");
			ui.tableWidget_Seg->setItem(i, j, item_2);

			QTableWidgetItem* item_3 = new QTableWidgetItem;
			item_3->setText("");
			ui.tableWidget_RowNote->setItem(i, j, item_3);
		}
	}
	for (int i = 0; i < 16; i++)
	{
		QTableWidgetItem* item = new QTableWidgetItem;
		item->setText("");
		ui.tableWidget_Channel->setItem(i, 0, item);

		QTableWidgetItem* item_1 = new QTableWidgetItem;
		item_1->setText("");
		ui.tableWidget_ColNote->setItem(i, 0, item_1);
	}
}

bool PulseGenerator::eventFilter(QObject* object, QEvent* event)
{
	if (object == ui.tableWidget_Main->viewport() || object == ui.tableWidget_ColNote->viewport() || object == ui.tableWidget_Channel->viewport())
	{

		if (event->type() == QEvent::Wheel)
		{
			QWheelEvent* wheelEvent = static_cast<QWheelEvent*>(event);
			int degress = wheelEvent->angleDelta().ry() * 0.01;
			if (wheelEvent->orientation() == Qt::Vertical)
			{
				ui.tableWidget_Main->verticalScrollBar()->setValue(ui.tableWidget_Main->verticalScrollBar()->value() - degress);
				ui.tableWidget_ColNote->verticalScrollBar()->setValue(ui.tableWidget_Main->verticalScrollBar()->value() - degress);
				ui.tableWidget_Channel->verticalScrollBar()->setValue(ui.tableWidget_Main->verticalScrollBar()->value() - degress);
			}
			wheelEvent->accept();
			return true;
		}
	}
	else if (object == ui.tableWidget_Loop->viewport())
	{
		if (event->type() == QEvent::Drop)
		{
			const QMimeData* mime = ((QDropEvent*)event)->mimeData();
			QByteArray encodedata = mime->data("application/x-qabstractitemmodeldatalist");
			if (encodedata.isEmpty())
				return false;

			QDataStream stream(&encodedata, QIODevice::ReadOnly);
			while (!stream.atEnd())
			{
				int row, col;
				QMap<int, QVariant> roleDataMap;
				//拖动的row和col
				stream >> row >> col >> roleDataMap;

				QTableWidgetItem* pDropItem = ui.tableWidget_Loop->itemAt(((QDropEvent*)event)->pos());
				if (!pDropItem)
					return true;

				//放下的row和col
				if (pDropItem->row() == row)
				{
					QMessageBox::information(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("不能跨列复制!"));
					return true;
				}

				if (pDropItem->column() != col)
				{
					QMessageBox::information(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("不能跨列复制!"));
					return true;
				}

				QString sn1 = ui.tableWidget_Loop->item(row, col)->data(Qt::DisplayRole).toString();
				QString sn2 = ui.tableWidget_Loop->item(pDropItem->row(), pDropItem->column())->data(Qt::DisplayRole).toString();

				if (sn1.isEmpty() || sn2.isEmpty())
				{
					QMessageBox::information(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("空数据不能复制!"));
					return true;
				}

				//自己的实现TODO:
				ui.tableWidget_Loop->item(row, col)->setData(Qt::DisplayRole, sn2);
				ui.tableWidget_Loop->item(pDropItem->row(), pDropItem->column())->setData(Qt::DisplayRole, sn1);

				QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("复制成功!"));

				return true;    //不要交给系统处理，否则他会给你新增一行
			}
		}
		
	}
    else
    {
        return QWidget::eventFilter(object, event);
    }
	return QWidget::eventFilter(object, event);
}

void PulseGenerator::on_tableWidget_Loop_ItemChanged(QTableWidgetItem* item)
{
	if (item->row() == 1)
	{
		QRegExp  reg(QString("^\\d{1,}"));

		//3.获取修改的新的单元格内容
		QString str = item->text();

		//完全匹配
		if (!reg.exactMatch(str))
		{
			item->setText("");
		}
		else if (str.toInt() < 12 )
		{
			item->setText("12");
		}
	}
	if (item->row() == 0)
	{
		QRegExp  reg(QString("^\\d{1,}"));

		//3.获取修改的新的单元格内容
		QString str = item->text();

		//完全匹配
		if (!reg.exactMatch(str))
		{
			item->setText("");
		}
		else if (str.toInt() < 1 )
		{
			item->setText("1");
		}
	}
	isSaved = false;
	isChecked = false;
}

void PulseGenerator::on_CellClicked(int r, int c)
{
   /* if (r == 0)
    {
        if (ui.tableWidget_Seg->item(r, c)->text() == "")
        {
            ui.tableWidget_Seg->item(r, c)->setText("LOOP End");
        }
        else
        {
            ui.tableWidget_Seg->item(r, c)->setText("");
        }
    }*/
	if (ui.tableWidget_Seg->item(r, c)->isSelected())
	{
		ui.tableWidget_Seg->item(r, c)->setText("LOOP End");
	}
	else
	{
		ui.tableWidget_Seg->item(r, c)->setText("");
	}
}

void PulseGenerator::setAxisRangeXPositive(QCPRange range)
{
	/*if (range.lower < 0)
	{
		ui.widget->xAxis->setRangeLower(0);
	}*/
}

void PulseGenerator::on_Connect_Clicked()
{
	sendUdp->sendHeartDetection();
	ui.pushButton_Connect->setStyleSheet("border-image: url(:/PulseGenerator/Image/on.png);");
}


void PulseGenerator::on_Max_Clicked()
{
	if (this->isMaximized())
	{
		this->showNormal();
	}
	else
	{
		this->showMaximized();
		this->showFullScreen();

	}
}

void PulseGenerator::on_Mini_Clicked()
{
	this->setWindowState(Qt::WindowMinimized);
}



void PulseGenerator::on_Clear_Clicked()
{
	QTableWidgetItem* item_1 = new QTableWidgetItem;
	item_1->setText("");
	
	if (isSaved == false&& ui.tableWidget_Main->selectedItems().isEmpty()==false)
	{
		switch (QMessageBox::question(this, QStringLiteral("保存提示"), QStringLiteral("当前脉冲序列尚未保存，是否立即清除当前脉冲序列！"),
			QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok))
		{
		case QMessageBox::Ok:
			ui.tableWidget_Main->clear();
			ui.tableWidget_Loop->clear();
			ui.tableWidget_Seg->clear();
			ui.tableWidget_RowNote->clear();
			ui.tableWidget_ColNote->clear();
			
			ui.tableWidget_ColNote->setHorizontalHeaderItem(0,item_1);
			for (int i = 0; i < 16; i++)
			{
				QWidget* m_widget = ui.tableWidget_Channel->cellWidget(i, 0);
				((QComboBox*)m_widget)->setCurrentIndex(i);
			}
			InitTableItems();
			ui.widget->clearGraphs();
			ui.widget->replot();
			break;
		case QMessageBox::Cancel:
			return;
		default:
			break;
		}
	}
	else
	{	
		ui.tableWidget_Main->clear();
		ui.tableWidget_Loop->clear();
		ui.tableWidget_Seg->clear();
		ui.tableWidget_RowNote->clear();
		ui.tableWidget_ColNote->clear();
		ui.tableWidget_ColNote->setHorizontalHeaderItem(0, item_1);
		for (int i = 0; i < 16; i++)
		{
			QWidget* m_widget = ui.tableWidget_Channel->cellWidget(i, 0);
			((QComboBox*)m_widget)->setCurrentIndex(i);
		}
		InitTableItems();

		ui.widget->clearGraphs();
		//注意 QCustomPlot 调用各种clear之后只是清空数据，绘图区不会立刻刷新
		//需要刷新绘图区，需要调用replot()方法
		ui.widget->replot();
	}
}

void PulseGenerator::on_scorllBarChanged(int value)
{
    QScrollBar* scrollBar = qobject_cast<QScrollBar*>(sender());
    if (scrollBar == ui.tableWidget_Main->horizontalScrollBar())
    {
        ui.tableWidget_Loop->horizontalScrollBar()->setValue(value);
        ui.tableWidget_Seg->horizontalScrollBar()->setValue(value);
        ui.tableWidget_RowNote->horizontalScrollBar()->setValue(value);
    }

    if (scrollBar == ui.tableWidget_Loop->horizontalScrollBar())
    {
        ui.tableWidget_Main->horizontalScrollBar()->setValue(value);
        ui.tableWidget_Seg->horizontalScrollBar()->setValue(value);
        ui.tableWidget_RowNote->horizontalScrollBar()->setValue(value);
    }

    if (value == ui.tableWidget_Main->horizontalScrollBar()->maximum())
    {
        ui.tableWidget_Main->insertColumn(ui.tableWidget_Main->columnCount());
        ui.tableWidget_Seg->insertColumn(ui.tableWidget_Seg->columnCount());
        ui.tableWidget_Loop->insertColumn(ui.tableWidget_Loop->columnCount());
        ui.tableWidget_RowNote->insertColumn(ui.tableWidget_RowNote->columnCount());


        for (int i = 0; i < 16; i++)
        {            
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setText("");
            ui.tableWidget_Main->setItem(i, ui.tableWidget_Main->columnCount() - 1, item);
        }
        for (int i = 0; i < 2; i++)
        {
            QTableWidgetItem* item = new QTableWidgetItem;            
            item->setText("");
            ui.tableWidget_Loop->setItem(i, ui.tableWidget_Loop->columnCount() - 1, item);
        }
        for (int i = 0; i < 1; i++)
        {
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setText("");
            ui.tableWidget_Seg->setItem(i, ui.tableWidget_Loop->columnCount() - 1, item);

            QTableWidgetItem* item_1 = new QTableWidgetItem;
            item_1->setText("");
            ui.tableWidget_RowNote->setItem(i, ui.tableWidget_Loop->columnCount() - 1, item);
        }
    }
}
//bool PulseGenerator::winEvent(MSG* message, long* result)
//{
//	switch (message->message)
//	{
//	case WM_NCHITTEST:
//		int xPos = GET_X_LPARAM(message->lParam) - this->frameGeometry().x();
//		int yPos = GET_Y_LPARAM(message->lParam) - this->frameGeometry().y();
//		if (this->childAt(xPos, yPos) == 0)
//		{
//			*result = HTCAPTION;
//		}
//		else {
//			return false;
//		}
//		if ( xPos < 15)
//			*result = HTLEFT;
//		if (xPos > (this->width() - 15))
//			*result = HTRIGHT;
//		if ( yPos < 15)
//			*result = HTTOP;
//		if (yPos > (this->height() - 15) )
//			*result = HTBOTTOM;
//		if ( xPos < 15 &&yPos <15)
//			*result = HTTOPLEFT;
//		if (xPos > (this->width() - 15)  && yPos < 15)
//			*result = HTTOPRIGHT;
//		if (xPos < 15 && yPos >(this->height() - 15) )
//			*result = HTBOTTOMLEFT;
//		if (xPos > (this->width() - 15) && yPos >(this->height() - 15) )
//			*result = HTBOTTOMRIGHT;
//
//		return true;
//	}
//	return false;
//}

void PulseGenerator::mousePressEvent(QMouseEvent* event)
{
    this->windowPos = this->pos();       // 获得部件当前位置
    this->mousePos = event->globalPos(); // 获得鼠标位置
    this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}

void PulseGenerator::mouseMoveEvent(QMouseEvent* event)
{
    this->move(event->globalPos() - this->dPos);
}

void PulseGenerator::on_CheckPulse_Clicked()
{
	listChannel.clear();
	lengthList.clear();
	/*for (int i = 0; i < ui.widget->graphCount(); i++)
	{
		ui.widget->removeGraph(i);
	}*/
	ui.widget->clearGraphs();
	QList<LoopData> loopList;
	QModelIndexList list = ui.tableWidget_Main->selectionModel()->selectedIndexes();
	if (list.isEmpty())
	{
		QMessageBox::warning(this, QStringLiteral("设置出错"), QStringLiteral("通道序列为空"));
		return;
	}
	/// <summary>
	/// sort排序后，list先按行排列，再按列排列
	/// </summary>
	qSort(list.begin(), list.end());
	QModelIndex index;
	int channelNum = list.back().row() + 1;
	///剔除空的行
	/*for (int i = 0; i < channelNum; i++)
	{
		foreach(QModelIndex modelIndex, list)
		{
			if (modelIndex.row() == i)
				break;
			if (modelIndex == list.back())
				channelNum--;
		}
	}*/

	//////////////////////tablewidget1完成///////////////////////////////	
	int lastIndex = 0;
	QList<int> posIndex, circleTimeList;
	for (int i = 0; i < ui.tableWidget_Seg->columnCount(); i++)
	{
		//QColor test = ui.tableWidget_2->itemAt(0, i)->backgroundColor();
		int test1 = ui.tableWidget_Seg->columnCount();
		if (ui.tableWidget_Seg->item(0, i)->isSelected() == true)
		{
			if (ui.tableWidget_Loop->item(0, i)->text() == "")
			{
				QMessageBox::warning(this, QStringLiteral("设置出错"), QStringLiteral("第%1列Seg未设置循环次数").arg(i+1));
				return;
			}
			lastIndex = i + 1;
		}
	}
	if (lastIndex == 0)
	{
		QMessageBox::warning(this, QStringLiteral("设置出错"), QStringLiteral("Seg行没有选择项"));
		return;
	}
	for (int i = 0; i < lastIndex; i++)
	{
		if (ui.tableWidget_Loop->item(1, i)->text() == "")
		{
			QMessageBox::warning(this, QStringLiteral("设置出错"), QStringLiteral("Length的第%1项为空").arg(i+1));
			return;
		}
		lengthList.append(ui.tableWidget_Loop->item(1, i)->text().toInt());
		if (ui.tableWidget_Seg->item(0, i)->isSelected() == true)
		{
			posIndex.append(i);
			circleTimeList.append(ui.tableWidget_Loop->item(0, i)->text().toInt());
		}
	}
	int totalLength = 0;
	for (int i = 0; i < lengthList.count(); i++)
	{
		totalLength += lengthList[0];
	}


	//qDebug() << posIndex;
	///////////////////////widget2完成
	//定义改到头文件中
	//QList<ChannelData*> listChannel;
	/*for (int i = 0; i < channelNum; i++)
	{

		ChannelData* data = new ChannelData();
		listChannel.append(data);
	}*/
	/*foreach(index, list)
	{
		listChannel[index.row()]->selectedCell.append(index.column());
		listChannel[index.row()]->channelNo = index.row();
	}	*/
	///对空的行进行判断，channnelNo值改为实际的行数
	///不再按之前的顺序排列
	for (int i = 0; i < list.count(); i++)
	{
		ChannelData* data;
		if (i == 0)
		{
			data = new ChannelData();
			QWidget *m_widget = ui.tableWidget_Channel->cellWidget(list[0].row(), 0);			
			data->channelNo = ((QComboBox*)m_widget)->currentText().toInt();
			data->selectedCell.append(list[0].column());
			listChannel.append(data);
		}
		else
		{
			if (list[i].row() == list[i - 1].row())
			{

				data->selectedCell.append(list[i].column());
			}
			else
			{
				data = new ChannelData();
				QWidget* m_widget = ui.tableWidget_Channel->cellWidget(list[i].row(), 0);
				data->channelNo = ((QComboBox*)m_widget)->currentText().toInt();
				data->selectedCell.append(list[i].column());
				listChannel.append(data);
			}
		}
	}
	channelNum = listChannel.count();
	for (int i = 0; i < channelNum; i++)
	{
		int startPoint = 0;//计算坐标点，每个通道坐标点的起始
		//考虑到有空的行，行号不等于索引
		//listChannel[i]->channelNo = i;
		listChannel[i]->high_Index = 0;
		listChannel[i]->low_Index = lastIndex - 1;
		listChannel[i]->loopNum = posIndex.count();
		for (int j = 0; j < listChannel[i]->loopNum; j++)
		{
			LoopData* loopData = new LoopData();
			loopData->channel = listChannel[i]->channelNo;
			loopData->loopNo = j;
			if (j == 0)
			{
				loopData->high_Index = 0;
			}
			else
			{
				loopData->high_Index = posIndex[j - 1] + 1;
			}
			loopData->low_Index = posIndex[j];

			/*if (j == posIndex.count() - 1)
			{
				loopData->low_Index = lastIndex - 1;
			}
			else
			{
				loopData->low_Index = posIndex[j + 1] - 1;
			}*/
			loopData->totalTime = 0;
			for (int k = loopData->high_Index; k <= loopData->low_Index; k++)
			{
				loopData->totalTime += lengthList[k];
			}
			loopData->cicleTime = circleTimeList[j];
			foreach(int value, listChannel[i]->selectedCell)
			{
				if ((value >= loopData->high_Index) && (value <= loopData->low_Index))
				{
					loopData->selectedCell.append(value);
				}
			}
			///添加对空LOOP的处理----------------------------------
			if (loopData->selectedCell.isEmpty())
			{
				loopData->pulseNo = 2;
				loopData->pulseTotal.append(0);
				loopData->pulseTotal.append(1);
				loopData->pulseRise.append(0);
				loopData->pulseFall.append(1);
				loopData->pulseTime.append(0);
				loopData->pulseTime.append(0);
				QString str = "00";
				loopData->processMode = str.rightJustified(32, '0');
				startPoint = startPoint + loopData->totalTime * loopData->cicleTime;
				listChannel[i]->channelPointlist.append(QPoint(startPoint, 0));
				listChannel[i]->loopDataList.append(loopData);
			}
			else
			{

				////--------------------------------------------------
				loopData->pulseNo = 1;
				int startInt = loopData->selectedCell[0];
				//第一个必定是上升脉冲
				loopData->pulseRise.append(startInt);
				for (int k = 1; k < loopData->selectedCell.count(); k++)
				{
					if (loopData->selectedCell[k] - startInt > 1)
					{
						loopData->pulseNo = loopData->pulseNo + 2;

						loopData->pulseRise.append(loopData->selectedCell[k]);
						loopData->pulseFall.append(startInt);
					}
					startInt = loopData->selectedCell[k];

				}
				//最后一个必定是下降脉冲
				loopData->pulseFall.append(loopData->selectedCell.last());
				loopData->pulseNo++;

				loopData->pulseTotal = loopData->pulseRise + loopData->pulseFall;
				qSort(loopData->pulseTotal);
				//计算坐标图上的点，坐标图上的点需要叠加时间，包括叠加循环时间
				//每个LOOP和每个循环脉冲沿时间画到横坐标上时间要叠加			
				////////////////////////////////////////////////////////////////
				for (int n = 0; n < loopData->cicleTime; n++)
				{
					//int seriesPointTime = startPoint;
					for (int k = 0; k < loopData->pulseTotal.count(); k++)
					{

						int seriesPointTime = startPoint;
						if (k % 2 == 0)
						{
							for (int m = loopData->high_Index; m < loopData->pulseTotal[k]; m++)
							{
								seriesPointTime += lengthList[m];

							}
							listChannel[i]->channelPointlist.append(QPoint(seriesPointTime, 1));
						}

						else
						{
							for (int m = loopData->high_Index; m <= loopData->pulseTotal[k]; m++)
							{
								seriesPointTime += lengthList[m];

							}
							listChannel[i]->channelPointlist.append(QPoint(seriesPointTime, 0));
						}
					}
					startPoint = startPoint + loopData->totalTime;
				}
				//添加第一个点
				listChannel[i]->channelPointlist.append(QPoint(0, 0));
				//当执行完最后一个LOOP的最后一个循环时，startpoint指向了通道数据的结尾
				if (j == listChannel[i]->loopNum - 1)
				{
					listChannel[i]->channelPointlist.append(QPoint(startPoint, 0));
				}

				/*int startTime, endTime;
				startTime = endTime = 0;
				for (int k = 0; k < loopData->high_Index; k++)
				{
					startTime += lengthList[k];
				}
				for (int k = 0; k < loopData->low_Index; k++)
				{
					endTime += lengthList[k];
				}
				listChannel[i]->channelPointlist.append(QPoint(startTime, 0));
				listChannel[i]->channelPointlist.append(QPoint(endTime, 0));*/
				/////////////////////////////////////////////////////

				//计算脉冲沿时间，脉冲沿时间和脉冲沿编号对每个LOOP及每个循环是单独计算的
				//每个LOOP和每个循环脉冲沿时间都是从0开始
				//统计脉冲延时间从每个脉冲的high_index算起

				for (int k = 0; k < loopData->pulseTotal.count(); k++)
				{
					int time = 0;
					if (k % 2 == 0)
					{
						for (int m = loopData->high_Index; m < loopData->pulseTotal[k]; m++)
						{
							time += lengthList[m];
						}
					}
					else
					{
						for (int m = loopData->high_Index; m <= loopData->pulseTotal[k]; m++)
						{
							time += lengthList[m];
						}
					}
					loopData->pulseTime.append(time);
				}
				///计算处理模式
				//从右向左添加 ，补足4个字节2进制，共32位
				QString str = "";
				foreach(int processTime, loopData->pulseTime)
				{
					if (processTime % 4 == 0)
					{
						str.prepend('0');
					}
					else
					{
						str.prepend('1');
					}
				}
				loopData->processMode = str.rightJustified(32, '0');
				listChannel[i]->loopDataList.append(loopData);
			}
		}
		ui.widget->addGraph();

		foreach(QPoint point, listChannel[i]->channelPointlist)
		{
			ui.widget->graph(i)->addData(point.x(), point.y()+ 2*(15-i));

			//ui.widget->graph(i)->addData(point.x(), point.y() + 2 * (15 - listChannel[i]->channelNo));
		}
		ui.widget->graph(i)->setLineStyle(QCPGraph::LineStyle::lsStepLeft);
		//ui.widget->xAxis->setRange(0, totalLength);
		ui.widget->graph(i)->rescaleAxes(true);
		ui.widget->graph(i)->setPen(QPen(QColor(255,115,45,255),2));
	}
	//
	///数据模型添加完成，检查图形规则
	///规则：1.LOOP首尾至少一个空格 2.脉冲边沿数量<=12  3.loop周期>=360
	if (!CheckForLegal())
	{
		return;
	}
	ui.widget->yAxis->setRange(32 - listChannel.size()* 2, 32);

	ui.widget->replot();
	xValueUpper = ui.widget->xAxis->range().upper;
}

bool PulseGenerator::CheckForLegal()
{
	QString info = "";
	QList<int> m_channelList;
	
	for (int i = 0; i < listChannel.count(); i++)
	{
		m_channelList.append(listChannel[i]->channelNo);
		for (int j = 0; j < listChannel[i]->loopDataList.count(); j++)
		{
			if (listChannel[i]->loopDataList[j]->totalTime < 360)
			{
				info += QStringLiteral("通道%1 Loop%2 周期小于360\n").arg(listChannel[i]->channelNo).arg(j + 1);
			}
			if (listChannel[i]->loopDataList[j]->pulseTotal.count() > 12)
			{
				info += QStringLiteral("通道%1 Loop%2 脉冲边沿数量大于12\n").arg(listChannel[i]->channelNo).arg(j + 1);
			}
			if (listChannel[i]->loopDataList[j]->selectedCell.contains(listChannel[i]->loopDataList[j]->high_Index) ||
				listChannel[i]->loopDataList[j]->selectedCell.contains(listChannel[i]->loopDataList[j]->low_Index))
			{
				info += QStringLiteral("通道%1 Loop%2 开始和停止处不能为脉冲沿\n").arg(listChannel[i]->channelNo).arg(j + 1);
			}
			///检查脉宽不超过283ms///
			for (int k = 0; k < listChannel[i]->loopDataList[j]->pulseRise.count(); k++)
			{
				int lowerIndex = listChannel[i]->loopDataList[j]->pulseRise[k];
				int upperIndex= listChannel[i]->loopDataList[j]->pulseFall[k];
				int total = 0;
				for (int m = lowerIndex; m <= upperIndex; m++)
				{
					total += lengthList[m];
				}
				if (total > 283000000)
				{
					info += QStringLiteral("通道%1 Loop%2 第%3个脉冲长度大于283ms\n").arg(listChannel[i]->channelNo).arg(j + 1).arg(k);
				}
			}
		}
	}
	qSort(m_channelList);
	
	if (m_channelList.count() > 1)
	{
		for (int i = 1; i < m_channelList.count(); i++)
		{
			if (m_channelList[i] == m_channelList[i - 1])
			{
				info += QStringLiteral("通道名称包含重复项\n");
				break;
			}
		}
	}
	if (info != "")
	{
		QMessageBox::warning(this, QStringLiteral("设置出错"), info);
		return false;
	}
	else
	{
		isChecked = true;
		return true;
	}
}

void PulseGenerator::on_SendData_Clicked()
{
	
	if (!isConnected)
	{
		QMessageBox::warning(this, QStringLiteral("操作错误"), QStringLiteral("设备未连接，无法下发参数"));
		return;
	}
	if (!isChecked)
	{
		QMessageBox::warning(this, QStringLiteral("操作错误"), QStringLiteral("请先进行序列预览检查"));
		return;
	}
	for (int i = 0; i < listChannel.count(); i++)
	{
		//下位机协议中通道从0开始，上位机界面中通道组合框从1开始
		//channelNo存的是上位机中组合框选中项的值
		//所以发送到下位机时，要把channelNo减去1，得到下位机协议中的通道号
		int channel = listChannel[i]->channelNo-1;
		for (int j = 0; j < listChannel[i]->loopDataList.count(); j++)
		{
			LoopData* m_LoopData = listChannel[i]->loopDataList[j];
			//对每个通道使用的LOOP手动清零，方法是对每个使用的通道，将通道中的6个脉冲12个脉冲边沿时间置为0
			for (int k = 0; k < 12; k++)
			{
				sendUdp->sendPulseWidth(channel, m_LoopData->loopNo, k, 0);
				Sleep(50);
			}
			///////////////////////////////////////////////////////////////////////////////////////////////

			sendUdp->sendLoopTime(channel, j, m_LoopData->totalTime);
			Sleep(50);
			sendUdp->sendLoopCycleNumber(channel, j, m_LoopData->cicleTime);
			Sleep(50);
			sendUdp->sendProcessMode(channel, j, m_LoopData->processMode);
			Sleep(50);
			for (int k = 0; k < m_LoopData->pulseNo; k++)
			{
				sendUdp->sendPulseWidth(channel, m_LoopData->loopNo, k, m_LoopData->pulseTime[k]);
				Sleep(50);
			}
		}
		sendUdp->sendLoopNumber(channel, listChannel[i]->loopNum);
		Sleep(50);
	}	
	/*sendUdp->sendLoopNumberValidate();
	Sleep(500);*/
	/*sendUdp->sendStartOut();
	Sleep(50);*/
	/// 把不使用的通道输出置为0
	///清除通道波形指令08必须在启动输出之后
	/*QList<int> allChannel;
	for (int i = 0; i < 16; i++)
	{
		allChannel.append(i);
	}
	for (int i = 0; i < listChannel.count(); i++)
	{
		allChannel.removeOne(listChannel[i]->channelNo-1);
	}
	for (int i = 0; i < allChannel.count(); i++)
	{
		sendUdp->sendClearChannel(allChannel[i]);
		Sleep(50);
	}*/
}
void PulseGenerator::Sleep(int msec)
{
	QEventLoop loop;//定义一个新的事件循环
	QTimer::singleShot(msec, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
	loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出

}
void PulseGenerator::on_Save_Clicked()
{
	QJsonObject GraphObj;
	QJsonArray channelArray;

	for (int i = 0; i < listChannel.count(); i++)
	{
		QJsonObject channelDataJson;
		channelDataJson.insert("high_Index", listChannel[i]->high_Index);
		channelDataJson.insert("low_Index", listChannel[i]->low_Index);
		channelDataJson.insert("channelNo", listChannel[i]->channelNo);
		channelDataJson.insert("loopNum", listChannel[i]->loopNum);

		QJsonArray seriesPointarray;
		for (int j = 0; j < listChannel[i]->channelPointlist.count(); j++)
		{
			QJsonArray seriesPoin;
			seriesPoin.append(listChannel[i]->channelPointlist[j].x());
			seriesPoin.append(listChannel[i]->channelPointlist[j].y());
			seriesPointarray.append(seriesPoin);
		}
		channelDataJson.insert("channelPointlist", seriesPointarray);

		QJsonArray selectedCellarray;
		for (int j = 0; j < listChannel[i]->selectedCell.count(); j++)
		{
			selectedCellarray.append(listChannel[i]->selectedCell[j]);
		}
		channelDataJson.insert("selectedCell", selectedCellarray);
		QJsonArray loopDataArray;
		for (int j = 0; j < listChannel[i]->loopDataList.count(); j++)
		{
			LoopData* m_Loopdata = listChannel[i]->loopDataList[j];
			QJsonObject loopDataJson;
			loopDataJson.insert("channel", m_Loopdata->channel);
			loopDataJson.insert("loop_No", m_Loopdata->loopNo);
			loopDataJson.insert("high_Index", m_Loopdata->high_Index);
			loopDataJson.insert("low_Index", m_Loopdata->low_Index);
			loopDataJson.insert("pulseNo", m_Loopdata->pulseNo);
			loopDataJson.insert("totalTime", m_Loopdata->totalTime);
			loopDataJson.insert("circleTime", m_Loopdata->cicleTime);
			QJsonArray loopSelectedcellArray, pulseRiseArray, pulseFallArray, pulseTotalArray, pulseTimeArray;
			if (m_Loopdata->selectedCell.isEmpty())
			{
				loopDataJson.insert("selectedCell", "");
			}
			else
			{
				for (int k = 0; k < m_Loopdata->selectedCell.count(); k++)
				{
					loopSelectedcellArray.append(m_Loopdata->selectedCell[k]);
				}
				loopDataJson.insert("selectedCell", loopSelectedcellArray);
			}
			for (int k = 0; k < m_Loopdata->pulseRise.count(); k++)
			{
				pulseRiseArray.append(m_Loopdata->pulseRise[k]);
			}
			for (int k = 0; k < m_Loopdata->pulseFall.count(); k++)
			{
				pulseFallArray.append(m_Loopdata->pulseFall[k]);
			}
			for (int k = 0; k < m_Loopdata->pulseTotal.count(); k++)
			{
				pulseTotalArray.append(m_Loopdata->pulseTotal[k]);
				pulseTimeArray.append(m_Loopdata->pulseTime[k]);
			}

			loopDataJson.insert("pulseRise", pulseRiseArray);
			loopDataJson.insert("pulseFall", pulseFallArray);
			loopDataJson.insert("pulseTotal", pulseTotalArray);
			loopDataJson.insert("pulseTime", pulseTimeArray);

			loopDataArray.append(loopDataJson);
		}
		channelDataJson.insert("loopData", loopDataArray);
		channelArray.append(channelDataJson);
	}
	QJsonArray lengthDataArray;
	for (int i = 0; i < lengthList.count(); i++)
	{
		lengthDataArray.append(lengthList[i]);
	}
	QJsonArray rowNoteArray, columnNoteArray;
	for (int i = 0; i < ui.tableWidget_RowNote->columnCount(); i++)
	{
		rowNoteArray.append(ui.tableWidget_RowNote->item(0, i)->text());
	}
	for (int i = 0; i < ui.tableWidget_ColNote->rowCount(); i++)
	{
		columnNoteArray.append(ui.tableWidget_ColNote->item(i,0)->text());
	}

	GraphObj.insert("channelData", channelArray);
	GraphObj.insert("lengthData", lengthDataArray);
	GraphObj.insert("rowNote", rowNoteArray);
	GraphObj.insert("columnNote", columnNoteArray);
	QString fileName = QFileDialog::getSaveFileName(this, tr("Json Config"), "", tr("Json Files (*.json)"));
	if (!fileName.isNull())
	{
		QFile file(fileName);
		file.open(QIODevice::WriteOnly);
		QJsonDocument jsonDoc;
		jsonDoc.setObject(GraphObj);

		file.write(jsonDoc.toJson(QJsonDocument::Indented));

		//file.write(jsonDoc.toJson(QJsonDocument::Compact));
		file.close();
		isSaved = true;
	}	
}

void PulseGenerator::on_Import_Clicked()
{
	/// //////////////////////////////////

	QList<int> m_selectedChannelCell;
	QList<int> m_lengthList;
	QList<QString> rowNoteList, columnNoteList;
	QList<QList<QPoint>> m_ChannelPointList;
	QList<QPoint> m_PointList;
	QMap<int, int> circleTimeMap;
	int channelSize = 0;

	QString filename = QFileDialog::getOpenFileName(this, tr("Choose Jason File"), "", tr("Json Files (*.json)"));
	if (filename == "")
	{
		return;
	}
	ui.tableWidget_Main->clear();
	ui.tableWidget_Loop->clear();
	ui.tableWidget_Seg->clear();
	ui.tableWidget_RowNote->clear();
	ui.tableWidget_ColNote->clear();
	QTableWidgetItem* item_1 = new QTableWidgetItem();
	item_1->setText("");
	ui.tableWidget_ColNote->setHorizontalHeaderItem(0, item_1);
	for (int i = 0; i < 16; i++)
	{
		QWidget* m_widget = ui.tableWidget_Channel->cellWidget(i, 0);
		((QComboBox*)m_widget)->setCurrentIndex(i);
	}
	InitTableItems();
	ui.widget->clearGraphs();
	ui.widget->replot();

	QFile jsonFile(filename);
	if (!jsonFile.open(QIODevice::ReadOnly))
	{
		qDebug() << "could't open projects json";
		return;
	}

	QByteArray byteArray = jsonFile.readAll();
	jsonFile.close();

	QJsonParseError jsonError;
	QJsonDocument document = QJsonDocument::fromJson(byteArray, &jsonError);  // 转化为 JSON 文档
	if (!document.isNull() && (jsonError.error == QJsonParseError::NoError))
	{
		// 解析未发生错误
		if (document.isObject())
		{
			QJsonArray channelArr = document.object().value("channelData").toArray();
			channelSize = channelArr.size();
			for (int i = 0; i < channelSize; i++)
			{
				QJsonArray selectedCellArray = channelArr.at(i).toObject().value("selectedCell").toArray();
				/// 设置channel表格中的复选框						
				int channelNo = channelArr.at(i).toObject().value("channelNo").toInt();
				QWidget* m_widget = ui.tableWidget_Channel->cellWidget(i, 0);
				((QComboBox*)m_widget)->setCurrentIndex(channelNo-1);
				for (int j = 0; j < selectedCellArray.size(); j++)
				{
					m_selectedChannelCell.append(selectedCellArray.at(j).toInt());
				}
				for (int j = 0; j < m_selectedChannelCell.count(); j++)
				{
					QTableWidgetItem* item = ui.tableWidget_Main->item(i, m_selectedChannelCell[j]);
					ui.tableWidget_Main->setItemSelected(item, true);
				}
				m_selectedChannelCell.clear();


				QJsonArray seriesPointArr = channelArr.at(i).toObject().value("channelPointlist").toArray();
				for (int j = 0; j < seriesPointArr.size(); j++)
				{
					QJsonArray seriesPoint = seriesPointArr.at(j).toArray();
					m_PointList.append(QPoint(seriesPoint.at(0).toInt(), seriesPoint.at(1).toInt()));
				}
				m_ChannelPointList.append(m_PointList);
				m_PointList.clear();
				/// 循环次数及LOOP分段点对于每个通道都一样，所以这里只判断第一个通道							
				if (i == 0)
				{
					QJsonArray loopDataArr = channelArr.at(i).toObject().value("loopData").toArray();
					for (int j = 0; j < loopDataArr.size(); j++)
					{
						int key = loopDataArr.at(j).toObject().value("low_Index").toInt();
						int value = loopDataArr.at(j).toObject().value("circleTime").toInt();
						circleTimeMap.insert(key, value);
					}
				}
			}
			QJsonArray lengthArr = document.object().value("lengthData").toArray();
			for (int i = 0; i < lengthArr.size(); i++)
			{
				m_lengthList.append(lengthArr.at(i).toInt());
			}

			///新增加对rowNote和columnNote的读取
			QJsonArray rowNoteArr = document.object().value("rowNote").toArray();
			QJsonArray columnNoteArr = document.object().value("columnNote").toArray();
			for (int i = 0; i < rowNoteArr.size(); i++)
			{
				rowNoteList.append(rowNoteArr.at(i).toString());
			}
			for (int i = 0; i < columnNoteArr.size(); i++)
			{
				columnNoteList.append(columnNoteArr.at(i).toString());
			}

		}
	}
	for (int i = 0; i < circleTimeMap.count(); i++)
	{
		QMap<int, int>::const_iterator it = circleTimeMap.constBegin();
		while (it != circleTimeMap.constEnd())
		{
			QTableWidgetItem* item = ui.tableWidget_Seg->item(0, it.key());
			ui.tableWidget_Seg->item(0, it.key())->setText("LOOP End");
			ui.tableWidget_Seg->setItemSelected(item, true);
			ui.tableWidget_Loop->item(0, it.key())->setText(QString::number(it.value()));
			it++;
		}
	}
	for (int i = 0; i < m_lengthList.count(); i++)
	{
		ui.tableWidget_Loop->item(1, i)->setText(QString::number(m_lengthList[i]));
	}
	///新增加对rowNote和columnNote的单元格显示
	for (int i = 0; i < rowNoteList.count(); i++)
	{
		ui.tableWidget_RowNote->item(0, i)->setText(rowNoteList[i]);
	}
	for (int i = 0; i < columnNoteList.count(); i++)
	{
		ui.tableWidget_ColNote->item(i, 0)->setText(columnNoteList[i]);
	}

	/*for (int i = 0; i < m_ChannelPointList.count(); i++)
	{
		ui.widget->addGraph();
		for (int j = 0; j < m_ChannelPointList[i].count(); j++)
		{
			ui.widget->graph(i)->addData(m_ChannelPointList[i][j].x(), m_ChannelPointList[i][j].y() + 2 * (15 - i));
		}
		ui.widget->graph(i)->setLineStyle(QCPGraph::LineStyle::lsStepLeft);
		ui.widget->yAxis->setRange(32 - channelSize * 2, 32);
		ui.widget->graph(i)->rescaleAxes(true);
		ui.widget->graph(i)->setPen(QPen(QColor(255, 115, 45, 255), 2));
	}

	ui.widget->replot();*/
	isSaved = true;
}

bool PulseGenerator::nativeEvent(const QByteArray& eventType, void* message, long* result)
{
	MSG* pMsg = (MSG*)message;
	switch (pMsg->message)
	{
		case WM_NCHITTEST:
		{
			QPoint pos = mapFromGlobal(QPoint(LOWORD(pMsg->lParam), HIWORD(pMsg->lParam)));
			/*qDebug() << pos.x() << "  " << pos.y();*/
			bool bHorLeft = pos.x() < g_nBorder;
			bool bHorRight = pos.x() > width() - g_nBorder;
			bool bVertTop = pos.y() < g_nBorder;
			bool bVertBottom = pos.y() > height() - g_nBorder;
			if (bHorLeft && bVertTop)
			{
				*result = HTTOPLEFT;
			}
			else if (bHorLeft && bVertBottom)
			{
				*result = HTBOTTOMLEFT;
			}
			else if (bHorRight && bVertTop)
			{
				*result = HTTOPRIGHT;
			}
			else if (bHorRight && bVertBottom)
			{
				*result = HTBOTTOMRIGHT;
			}
			else if (bHorLeft)
			{
				*result = HTLEFT;
			}
			else if (bHorRight)
			{
				*result = HTRIGHT;
			}
			else if (bVertTop)
			{
				*result = HTTOP;
			}
			else if (bVertBottom)
			{
				*result = HTBOTTOM;
			}
			else
			{
				return false;
			}
			return true;
		}
		break;
		default:
			break;
	}
	return QWidget::nativeEvent(eventType, message, result);
}

void PulseGenerator::resizeEvent(QResizeEvent* event)
{	
	/*int x = this->frameGeometry().width(); 
	int y = this->frameGeometry().height();	
	ui.frame->setFixedHeight(y);
	ui.tableWidget_Main->setFixedHeight(ui.tableWidget_Main->height() + y - origin_Height);*/

	double d_scale_x = this->width() * 1.0 / origin_Width;
	double d_scale_y = this->height() * 1.0 / origin_Height;
	QMap<QObject*, QRect> ::iterator iter;
	for (iter = m_objMap.begin(); iter != m_objMap.end(); iter++)
	{
		iter.key()->setProperty("geometry", QRect(iter.value().x() * d_scale_x, iter.value().y() * d_scale_y,
			iter.value().width() * d_scale_x, iter.value().height() * d_scale_y));
	}
}

void PulseGenerator::selectionChangeSaved()
{
	isSaved = false;
	isChecked = false;
}

void PulseGenerator::itemChangeSaved(QTableWidgetItem *item)
{
	isSaved = false;
	isChecked = false;
}

void PulseGenerator::changeConnectionStatus(bool isConnection)
{
	if (isConnection)
	{
		ui.pushButton_Connect->setStyleSheet("QPushButton#pushButton_Connect{border-image: url(:/PulseImage/on.png);}");
		isConnected = true;
	}
	else
	{
		ui.pushButton_Connect->setStyleSheet("QPushButton#pushButton_Connect{border-image: url(:/PulseImage/switch.png);}");
		isConnected = false;
	}
}

void PulseGenerator::slot_tooltip(QModelIndex index)

{
	QToolTip::showText(QCursor::pos(), index.data().toString());

	return;

}

void PulseGenerator::showMenu(const QPoint)
{
	menu->exec(QCursor::pos());
}

void PulseGenerator::RestoreView()
{	
	if (ui.widget->graphCount() != 0)
	{				
		ui.widget->xAxis->setRange(0,xValueUpper);
		ui.widget->replot();
	}
}

PulseGenerator::~PulseGenerator()
{}
