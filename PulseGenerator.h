#pragma once

#include <QtWidgets/QWidget>
#include "ui_PulseGenerator.h"
#include"PulseUDPCom.h"
#include<qdebug.h>

#include"ChannelData.h"
#include<qheaderview.h>
#include<qglobal.h>
#include<qmenu.h>
#include<qevent.h>
#include"UdpReceiveThread.h"
//#include<qcustomplot.h>
class PulseGenerator : public QWidget
{
    Q_OBJECT

public:
    PulseGenerator(QWidget *parent = nullptr);
    ~PulseGenerator();

private:
    Ui::PulseGeneratorClass ui;
   
   //记录鼠标窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;

    QList<int> lengthList; //步长网格数据
   /* QList<ChannelData*> listChannel;*/
    bool isSaved; //清除前数据是否保存
    //PulseUDPCom* sendUdp;
    QTimer* connection_Timer;//定时查询连接状态
    QThread* m_thread;//udp接受后台线程
    //UdpReceiveThread* receiver;
    bool isConnected;//设备连接状态
    bool isChecked;  //当前序列有没有经过预览检查
    //窗口大小变化时，控件一起变化相关变量
    QList<QObject*> m_objectList;
    QMap<QObject*, QRect> m_objMap;
    
    QMenu* menu; //曲线图右键菜单
    double xValueUpper;

private:

    //定义鼠标事件，实现拖动无边框窗体
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);


    bool eventFilter(QObject* object, QEvent* event);
    void Sleep(int msec);
    void InitTableItems();
    bool CheckForLegal();
private slots:
    void on_scorllBarChanged(int);
    void on_CellClicked(int r, int c);
    void setAxisRangeXPositive(QCPRange);
    void on_tableWidget_Loop_ItemChanged(QTableWidgetItem* item);//对LOOP的输入进行检查

    void on_Max_Clicked(); //最大化按钮
    void on_Mini_Clicked(); //最小化按钮
    //void on_Connect_Clicked(); //连接按钮
    void on_Clear_Clicked();  //清除按钮
    void on_SendData_Clicked(); //下发设置，播放序列
    void on_CheckPulse_Clicked();//序列预览兼检查
    void on_Save_Clicked();//保存序列
    void on_Import_Clicked();//导入序列
    void on_Connect_Clicked();//连接

    void selectionChangeSaved();//改变保存状态
    void itemChangeSaved(QTableWidgetItem *item);//改变保存状态的重载
    
    void changeConnectionStatus(bool); //改变连接按钮的状态
    void slot_tooltip(QModelIndex);//鼠标悬停显示单元格内容  
    void showMenu(const QPoint);
    void RestoreView();
protected:
    virtual bool nativeEvent(const QByteArray& eventType, void* message, long* result);//实现鼠标在窗口边缘时变化形状，并且拖动改变窗口大小
    virtual void resizeEvent(QResizeEvent* event) override; //窗口大小改变时，改变控件大小
};

//class CheckBoxHeaderView : public QHeaderView
//{
//    Q_OBJECT
//public:
//    CheckBoxHeaderView(int Index, 
//        Qt::Orientation orientation,
//        QWidget* parent = 0) :
//        QHeaderView(orientation, parent)
//    {
//        // 默认ComboBox;
//        m_Index = Index;
//        for (int i = 0; i < 16; i++)
//        {
//            m_comboBox = new QComboBox(this);
//            /*m_comboBox->setFixedWidth(40);
//            m_comboBox->setFixedHeight(40);*/
//            for (int j = 1; j < 17; j++)
//            {
//                m_comboBox->addItem(QString::number(j));
//            }
//            comboBox_List.append(m_comboBox);
//        }      
//
//
//    }
//
//    // 获取当前comboBox文字;
//    QString getCurrentComboBoxText(int i)
//    {
//        QComboBox *cb = new QComboBox();
//        cb = comboBox_List.at(i);
//        return cb->currentText();
//    }
//
//    // 设置自定义ComboBox;
//    void setComboBoxObject(QComboBox* object)
//    {
//        m_comboBox = object;
//        m_comboBox->setParent(this);
//    }
//
//protected:
//    void paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const
//    {
//        /*if (logicalIndex == m_Index)
//        {
//            m_comboBox->setGeometry(rect);            
//        }
//        else
//        {
//            QHeaderView::paintSection(painter, rect, logicalIndex);
//        }*/ 
//       
//        //m_comboBox->setGeometry(rect);
//        comboBox_List[logicalIndex]->setGeometry(rect);
//    }
//
//private:
//    QComboBox* m_comboBox;
//    int m_Index;
//public:
//    QList<QComboBox*> comboBox_List;
//};
