/********************************************************************************
** Form generated from reading UI file 'PulseGenerator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PULSEGENERATOR_H
#define UI_PULSEGENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_PulseGeneratorClass
{
public:
    QFrame *frame;
    QLabel *label;
    QPushButton *pushButton_Connect;
    QPushButton *pushButton_Import;
    QPushButton *pushButton_Clear;
    QPushButton *pushButton_Save;
    QPushButton *pushButton_CheckPulse;
    QPushButton *pushButton_SendData;
    QFrame *frame_Top;
    QPushButton *pushButton_Max;
    QPushButton *pushButton_Mini;
    QPushButton *pushButton_Close;
    QTableWidget *tableWidget_Loop;
    QTableWidget *tableWidget_RowNote;
    QTableWidget *tableWidget_Main;
    QTableWidget *tableWidget_ColNote;
    QCustomPlot *widget;
    QTableWidget *tableWidget_Seg;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTableWidget *tableWidget_Channel;

    void setupUi(QWidget *PulseGeneratorClass)
    {
        if (PulseGeneratorClass->objectName().isEmpty())
            PulseGeneratorClass->setObjectName(QStringLiteral("PulseGeneratorClass"));
        PulseGeneratorClass->resize(1924, 1040);
        PulseGeneratorClass->setMinimumSize(QSize(1532, 936));
        QIcon icon;
        icon.addFile(QStringLiteral(":/PulseGenerator/Image/PulseLogo.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        PulseGeneratorClass->setWindowIcon(icon);
        PulseGeneratorClass->setStyleSheet(QLatin1String("QWidget#PulseGeneratorClass\n"
"{\n"
"background-color:#F2F2F2 ;\n"
"}"));
        frame = new QFrame(PulseGeneratorClass);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 223, 1040));
        frame->setStyleSheet(QString::fromUtf8("QFrame#frame\n"
"{\n"
"border-image: url(:/PulseImage/\345\267\246\344\276\247\345\212\237\350\203\275.png);\n"
"}\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(58, 117, 101, 23));
        label->setStyleSheet(QString::fromUtf8("QLabel#label\n"
"{\n"
"border-image: url(:/PulseGenerator/Image/\350\277\236\346\216\245\350\256\276\345\244\207.png);\n"
"}"));
        pushButton_Connect = new QPushButton(frame);
        pushButton_Connect->setObjectName(QStringLiteral("pushButton_Connect"));
        pushButton_Connect->setEnabled(true);
        pushButton_Connect->setGeometry(QRect(65, 164, 80, 48));
        pushButton_Connect->setStyleSheet(QLatin1String("QPushButton#pushButton_Connect\n"
"{\n"
" border-image: url(:/PulseImage/switch.png);\n"
"\n"
"}\n"
""));
        pushButton_Import = new QPushButton(frame);
        pushButton_Import->setObjectName(QStringLiteral("pushButton_Import"));
        pushButton_Import->setGeometry(QRect(0, 250, 210, 60));
        pushButton_Import->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_Import\n"
"{\n"
"border-image: url(:/PulseImage/\345\212\240\350\275\275.png);\n"
"}\n"
"\n"
"QPushButton#pushButton_Import::hover\n"
"{\n"
"border-image: url(:/PulseImage/1206\350\241\245\345\205\205\345\210\207\345\233\276-\344\277\235\345\255\230_\345\272\217\345\210\227\351\242\204\350\247\210/\346\202\254\346\265\256\347\202\271\345\207\273\345\212\240\350\275\275.png);\n"
"}"));
        pushButton_Clear = new QPushButton(frame);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));
        pushButton_Clear->setGeometry(QRect(0, 310, 210, 60));
        pushButton_Clear->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_Clear\n"
"{\n"
"border-image: url(:/PulseImage/\346\270\205\351\231\244.png);\n"
"}\n"
"\n"
"QPushButton#pushButton_Clear::hover\n"
"\n"
"{\n"
"border-image: url(:/PulseImage/1206\350\241\245\345\205\205\345\210\207\345\233\276-\344\277\235\345\255\230_\345\272\217\345\210\227\351\242\204\350\247\210/\346\202\254\346\265\256\347\202\271\345\207\273\346\270\205\351\231\244.png);\n"
"}"));
        pushButton_Save = new QPushButton(frame);
        pushButton_Save->setObjectName(QStringLiteral("pushButton_Save"));
        pushButton_Save->setGeometry(QRect(0, 370, 210, 60));
        pushButton_Save->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_Save\n"
"\n"
"{\n"
"border-image: url(:/PulseImage/1206\350\241\245\345\205\205\345\210\207\345\233\276-\344\277\235\345\255\230_\345\272\217\345\210\227\351\242\204\350\247\210/\344\277\235\345\255\230.png);\n"
"}\n"
"QPushButton#pushButton_Save::hover\n"
"{\n"
"\n"
"\n"
"border-image: url(:/PulseImage/1206\350\241\245\345\205\205\345\210\207\345\233\276-\344\277\235\345\255\230_\345\272\217\345\210\227\351\242\204\350\247\210/\346\202\254\346\265\256\347\202\271\345\207\273\344\277\235\345\255\230.png);\n"
"\n"
"}"));
        pushButton_CheckPulse = new QPushButton(frame);
        pushButton_CheckPulse->setObjectName(QStringLiteral("pushButton_CheckPulse"));
        pushButton_CheckPulse->setGeometry(QRect(0, 430, 210, 60));
        pushButton_CheckPulse->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_CheckPulse\n"
"{\n"
"border-image: url(:/PulseImage/1206\350\241\245\345\205\205\345\210\207\345\233\276-\344\277\235\345\255\230_\345\272\217\345\210\227\351\242\204\350\247\210/\345\272\217\345\210\227\351\242\204\350\247\210.png);\n"
"}\n"
"\n"
"QPushButton#pushButton_CheckPulse::hover\n"
"{\n"
"border-image: url(:/PulseImage/1206\350\241\245\345\205\205\345\210\207\345\233\276-\344\277\235\345\255\230_\345\272\217\345\210\227\351\242\204\350\247\210/\346\202\254\346\265\256\347\202\271\345\207\273\345\272\217\345\210\227\351\242\204\350\247\210.png);\n"
"}"));
        pushButton_SendData = new QPushButton(frame);
        pushButton_SendData->setObjectName(QStringLiteral("pushButton_SendData"));
        pushButton_SendData->setGeometry(QRect(0, 490, 210, 60));
        pushButton_SendData->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_SendData\n"
"{\n"
"border-image: url(:/PulseImage/\345\272\217\345\210\227\347\203\247\345\275\225.png);\n"
"}\n"
"QPushButton#pushButton_SendData::hover\n"
"{\n"
"border-image: url(:/PulseImage/1206\350\241\245\345\205\205\345\210\207\345\233\276-\344\277\235\345\255\230_\345\272\217\345\210\227\351\242\204\350\247\210/\346\202\254\346\265\256\347\202\271\345\207\273\345\272\217\345\210\227\347\203\247\345\275\225.png);\n"
"}"));
        frame_Top = new QFrame(PulseGeneratorClass);
        frame_Top->setObjectName(QStringLiteral("frame_Top"));
        frame_Top->setGeometry(QRect(190, 0, 1731, 76));
        frame_Top->setStyleSheet(QString::fromUtf8("QFrame#frame_Top\n"
"{\n"
"border-image: url(:/PulseImage/\347\237\251\345\275\242.png);\n"
"}"));
        frame_Top->setFrameShape(QFrame::StyledPanel);
        frame_Top->setFrameShadow(QFrame::Raised);
        pushButton_Max = new QPushButton(frame_Top);
        pushButton_Max->setObjectName(QStringLiteral("pushButton_Max"));
        pushButton_Max->setGeometry(QRect(1610, 10, 40, 40));
        pushButton_Max->setMinimumSize(QSize(40, 40));
        pushButton_Max->setMaximumSize(QSize(40, 40));
        pushButton_Max->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_Max\n"
"{\n"
"border-image: url(:/PulseImage/btn_\346\234\200\345\244\247\345\214\226_nor.PNG);\n"
"}\n"
"\n"
"QPushButton#pushButton_Max::hover\n"
"{\n"
"background-color:#E5E5E5;\n"
"}"));
        pushButton_Mini = new QPushButton(frame_Top);
        pushButton_Mini->setObjectName(QStringLiteral("pushButton_Mini"));
        pushButton_Mini->setGeometry(QRect(1550, 10, 40, 40));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_Mini->sizePolicy().hasHeightForWidth());
        pushButton_Mini->setSizePolicy(sizePolicy);
        pushButton_Mini->setMinimumSize(QSize(40, 40));
        pushButton_Mini->setMaximumSize(QSize(40, 40));
        pushButton_Mini->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_Mini\n"
"{\n"
"border-image: url(:/PulseImage/btn_\346\234\200\345\260\217\345\214\226_nor.PNG);\n"
"}\n"
"\n"
"QPushButton#pushButton_Mini::hover\n"
"{\n"
"background-color:#E5E5E5;\n"
"}"));
        pushButton_Close = new QPushButton(frame_Top);
        pushButton_Close->setObjectName(QStringLiteral("pushButton_Close"));
        pushButton_Close->setGeometry(QRect(1670, 10, 40, 40));
        pushButton_Close->setMinimumSize(QSize(40, 40));
        pushButton_Close->setMaximumSize(QSize(40, 40));
        pushButton_Close->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_Close\n"
"{\n"
"border-image: url(:/PulseImage/btn_\345\205\263\351\227\255_nor.PNG);\n"
"}\n"
"QPushButton#pushButton_Close::hover\n"
"{\n"
"background-color:#E5E5E5;\n"
"}"));
        tableWidget_Loop = new QTableWidget(PulseGeneratorClass);
        if (tableWidget_Loop->columnCount() < 100)
            tableWidget_Loop->setColumnCount(100);
        if (tableWidget_Loop->rowCount() < 2)
            tableWidget_Loop->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Loop->setVerticalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Loop->setVerticalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_Loop->setObjectName(QStringLiteral("tableWidget_Loop"));
        tableWidget_Loop->setGeometry(QRect(315, 100, 1601, 81));
        tableWidget_Loop->setStyleSheet(QString::fromUtf8("\n"
"QTableWidget::cell:selected,QTableView::cell:selected {				    /*\350\256\276\347\275\256\351\200\211\344\270\255\347\232\204\350\247\206\345\233\276\351\241\271*/\n"
"        background: rgb(0\357\274\214255\357\274\2140);\n"
"        \n"
"}\n"
"\n"
"QHeaderView::section{\n"
"border:0px;\n"
"border-radius:0px;\n"
"padding:2px 4px;\n"
"background-color:#f2f2f2;\n"
"color:#000000;\n"
"width:40;\n"
"height:32;\n"
"align:Center;\n"
"font-size:20px;\n"
"font-family: PingFangSC-Regular;\n"
"font-weight:500\n"
"}\n"
"\n"
"QTableWidget\n"
"{\n"
"alternate-background-color:#F7F7F7 ;\n"
"background: #FFFFFF;\n"
"gridline-color:#438AFF;\n"
"text-align:center;\n"
"font-size:10px;\n"
"font-weight:490;\n"
"gridline-width:1px;\n"
"\n"
"}\n"
"\n"
"QTableWidget::item\n"
"{border:1px solid #438AFF;\n"
"border-bottom:1px solid #438AFF;\n"
"border-top:1px solid #438AFF;\n"
"}\n"
"\n"
"QTableWidget::item::selected\n"
"{\n"
"background-color:rgb(0,255,0);\n"
"}\n"
"\n"
"QTableWidget QTableCornerButton::section {\n"
"    backg"
                        "round-color: #438AFF;\n"
"    border: 0px solid #fffff8;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"/*background:#438AFF; */\n"
"padding-top:20px; \n"
"padding-bottom:20px; \n"
"padding-left:0px; \n"
"padding-right:0px;\n"
"border-left:1px solid #d7d7d7;\n"
"}"));
        tableWidget_Loop->setFrameShape(QFrame::NoFrame);
        tableWidget_Loop->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_Loop->setProperty("showDropIndicator", QVariant(true));
        tableWidget_Loop->setDragEnabled(true);
        tableWidget_Loop->setDragDropOverwriteMode(true);
        tableWidget_Loop->setDragDropMode(QAbstractItemView::DragDrop);
        tableWidget_Loop->setAlternatingRowColors(true);
        tableWidget_Loop->setShowGrid(true);
        tableWidget_Loop->setRowCount(2);
        tableWidget_Loop->setColumnCount(100);
        tableWidget_Loop->horizontalHeader()->setVisible(false);
        tableWidget_Loop->horizontalHeader()->setDefaultSectionSize(40);
        tableWidget_Loop->horizontalHeader()->setMinimumSectionSize(40);
        tableWidget_Loop->verticalHeader()->setVisible(false);
        tableWidget_Loop->verticalHeader()->setDefaultSectionSize(32);
        tableWidget_Loop->verticalHeader()->setMinimumSectionSize(32);
        tableWidget_RowNote = new QTableWidget(PulseGeneratorClass);
        if (tableWidget_RowNote->columnCount() < 100)
            tableWidget_RowNote->setColumnCount(100);
        if (tableWidget_RowNote->rowCount() < 1)
            tableWidget_RowNote->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_RowNote->setVerticalHeaderItem(0, __qtablewidgetitem2);
        tableWidget_RowNote->setObjectName(QStringLiteral("tableWidget_RowNote"));
        tableWidget_RowNote->setGeometry(QRect(315, 190, 1601, 35));
        tableWidget_RowNote->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QTableWidget::cell:selected,QTableView::cell:selected {				    /*\350\256\276\347\275\256\351\200\211\344\270\255\347\232\204\350\247\206\345\233\276\351\241\271*/\n"
"        background: rgb(0\357\274\214255\357\274\2140);\n"
"        \n"
"}\n"
"\n"
"QHeaderView::section{\n"
"border:0px;\n"
"border-radius:0px;\n"
"padding:2px 4px;\n"
"background-color:#f2f2f2;\n"
"color:#000000;\n"
"width:100;\n"
"height:32;\n"
"align:Center;\n"
"font-size:20px;\n"
"font-family:SourceHanSansSC-Medium;\n"
"font-weight:500\n"
"}\n"
"\n"
"QTableWidget\n"
"{\n"
"alternate-background-color:#F7F7F7 ;\n"
"background: #FFFFFF;\n"
"gridline-color:#438AFF;\n"
"text-align:center;\n"
"font-size:10px;\n"
"font-weight:480;\n"
"gridline-width:2px;\n"
"\n"
"}\n"
"\n"
"QTableWidget::item\n"
"{\n"
"border:2px solid #438AFF;\n"
"\n"
"margin-left:1px;\n"
"margin-right:1px;\n"
"\n"
"\n"
"}\n"
"\n"
"QTableWidget::item::selected\n"
"{\n"
"background-color:rgb(0,255,0);\n"
"}\n"
"\n"
"QTableWidget QTableCornerButton::section {\n"
"    back"
                        "ground-color: #438AFF;\n"
"    border: 0px solid #fffff8;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"/*background:#438AFF; */\n"
"padding-top:20px; \n"
"padding-bottom:20px; \n"
"padding-left:0px; \n"
"padding-right:0px;\n"
"border-left:1px solid #d7d7d7;\n"
"}"));
        tableWidget_RowNote->setFrameShape(QFrame::NoFrame);
        tableWidget_RowNote->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_RowNote->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_RowNote->setShowGrid(false);
        tableWidget_RowNote->setRowCount(1);
        tableWidget_RowNote->setColumnCount(100);
        tableWidget_RowNote->horizontalHeader()->setVisible(false);
        tableWidget_RowNote->horizontalHeader()->setDefaultSectionSize(40);
        tableWidget_RowNote->horizontalHeader()->setMinimumSectionSize(40);
        tableWidget_RowNote->verticalHeader()->setVisible(false);
        tableWidget_RowNote->verticalHeader()->setDefaultSectionSize(32);
        tableWidget_RowNote->verticalHeader()->setMinimumSectionSize(32);
        tableWidget_Main = new QTableWidget(PulseGeneratorClass);
        if (tableWidget_Main->columnCount() < 100)
            tableWidget_Main->setColumnCount(100);
        if (tableWidget_Main->rowCount() < 16)
            tableWidget_Main->setRowCount(16);
        tableWidget_Main->setObjectName(QStringLiteral("tableWidget_Main"));
        tableWidget_Main->setEnabled(true);
        tableWidget_Main->setGeometry(QRect(315, 230, 1601, 481));
        tableWidget_Main->setStyleSheet(QString::fromUtf8("/*\n"
"QTableWidget::cell:selected {		\n"
"background: rgb(0\357\274\214255\357\274\2140);\n"
"} \n"
"*/\n"
"QHeaderView::section{\n"
"border:0px solid;\n"
"border-radius:0px;\n"
"padding:2px 4px;\n"
"background-color:#438AFF;\n"
"color:#ffffff;\n"
"width:40;\n"
"height:40;\n"
"text-align:Center;\n"
"font-size:20px;\n"
"}\n"
"\n"
"QTableWidget#tableWidget_Main\n"
"{\n"
"alternate-background-color:#F7F7F7 ;\n"
"background: #FFFFFF;\n"
"gridline-color:#438AFF;\n"
"text-align:center;\n"
"gridline-width: 1px;\n"
"\n"
"}\n"
"\n"
"QTableWidget::item\n"
"{border:1px solid #438AFF;\n"
"border-bottom:1px solid #438AFF;\n"
"border-top:1px solid #438AFF;\n"
"border-left:1px solid #438AFF;\n"
"\n"
"}\n"
"\n"
"QTableWidget::item::selected\n"
"{\n"
"background-color:rgb(0,255,0);\n"
"}\n"
"\n"
"QTableWidget QTableCornerButton::section {\n"
"    background-color: #438AFF;\n"
"    border: 0px solid #fffff8;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"/*background:#438AFF; */\n"
"padding-top:20px; \n"
"padding-botto"
                        "m:20px; \n"
"padding-left:0px; \n"
"padding-right:0px;\n"
"border-left:1px solid #d7d7d7;\n"
"}"));
        tableWidget_Main->setFrameShape(QFrame::NoFrame);
        tableWidget_Main->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_Main->setAlternatingRowColors(true);
        tableWidget_Main->setRowCount(16);
        tableWidget_Main->setColumnCount(100);
        tableWidget_Main->horizontalHeader()->setDefaultSectionSize(40);
        tableWidget_Main->horizontalHeader()->setMinimumSectionSize(40);
        tableWidget_Main->verticalHeader()->setVisible(false);
        tableWidget_Main->verticalHeader()->setDefaultSectionSize(40);
        tableWidget_Main->verticalHeader()->setMinimumSectionSize(40);
        tableWidget_ColNote = new QTableWidget(PulseGeneratorClass);
        if (tableWidget_ColNote->columnCount() < 1)
            tableWidget_ColNote->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_ColNote->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        if (tableWidget_ColNote->rowCount() < 16)
            tableWidget_ColNote->setRowCount(16);
        tableWidget_ColNote->setObjectName(QStringLiteral("tableWidget_ColNote"));
        tableWidget_ColNote->setGeometry(QRect(224, 230, 45, 461));
        tableWidget_ColNote->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QTableWidget::cell:selected,QTableView::cell:selected {				    /*\350\256\276\347\275\256\351\200\211\344\270\255\347\232\204\350\247\206\345\233\276\351\241\271*/\n"
"        background: rgb(0\357\274\214255\357\274\2140);\n"
"        \n"
"}\n"
"\n"
"QHeaderView::section{\n"
"border:0px;\n"
"border-radius:0px;\n"
"padding:2px 4px;\n"
"background-color:#438AFF;\n"
"color:#000000;\n"
"width:50;\n"
"height:40;\n"
"align:Center;\n"
"font-size:20px;\n"
"font-family: PingFangSC-Regular;\n"
"font-weight:500\n"
"}\n"
"\n"
"QTableWidget\n"
"{\n"
"alternate-background-color:#F7F7F7 ;\n"
"background: #FFFFFF;\n"
"gridline-color:#438AFF;\n"
"text-align:center;\n"
"font-size:10px;\n"
"font-weight:480;\n"
"gridline-width:1px;\n"
"\n"
"}\n"
"\n"
"QTableWidget::item\n"
"{\n"
"border:2px solid #438AFF;\n"
"\n"
"margin-top:1px;\n"
"margin-buttom:1px;\n"
"margin-left:0px;\n"
"margin-right:5px;\n"
"\n"
"\n"
"}\n"
"\n"
"QTableWidget::item::selected\n"
"{\n"
"background-color:rgb(0,255,0);\n"
"}\n"
"\n"
"QTableWidget QTa"
                        "bleCornerButton::section {\n"
"    background-color: #438AFF;\n"
"    border: 0px solid #fffff8;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"/*background:#438AFF; */\n"
"padding-top:20px; \n"
"padding-bottom:20px; \n"
"padding-left:0px; \n"
"padding-right:0px;\n"
"border-left:1px solid #d7d7d7;\n"
"}"));
        tableWidget_ColNote->setFrameShape(QFrame::NoFrame);
        tableWidget_ColNote->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_ColNote->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_ColNote->setShowGrid(false);
        tableWidget_ColNote->setRowCount(16);
        tableWidget_ColNote->setColumnCount(1);
        tableWidget_ColNote->horizontalHeader()->setVisible(true);
        tableWidget_ColNote->horizontalHeader()->setDefaultSectionSize(47);
        tableWidget_ColNote->horizontalHeader()->setMinimumSectionSize(47);
        tableWidget_ColNote->verticalHeader()->setVisible(false);
        tableWidget_ColNote->verticalHeader()->setDefaultSectionSize(40);
        tableWidget_ColNote->verticalHeader()->setMinimumSectionSize(40);
        widget = new QCustomPlot(PulseGeneratorClass);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(220, 710, 1691, 321));
        widget->setStyleSheet(QLatin1String("QWidget#widget\n"
"{\n"
"border:3px solid #438AFF;\n"
"}"));
        tableWidget_Seg = new QTableWidget(PulseGeneratorClass);
        if (tableWidget_Seg->columnCount() < 100)
            tableWidget_Seg->setColumnCount(100);
        if (tableWidget_Seg->rowCount() < 1)
            tableWidget_Seg->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Seg->setVerticalHeaderItem(0, __qtablewidgetitem4);
        tableWidget_Seg->setObjectName(QStringLiteral("tableWidget_Seg"));
        tableWidget_Seg->setGeometry(QRect(315, 70, 1601, 31));
        tableWidget_Seg->setStyleSheet(QString::fromUtf8("\n"
"QTableWidget::cell:selected,QTableView::cell:selected {				    /*\350\256\276\347\275\256\351\200\211\344\270\255\347\232\204\350\247\206\345\233\276\351\241\271*/\n"
"        background: rgb(0\357\274\214255\357\274\2140);\n"
"        \n"
"}\n"
"\n"
"QHeaderView::section{\n"
"border:0px;\n"
"border-radius:0px;\n"
"padding:2px 4px;\n"
"background-color:#f2f2f2;\n"
"color:#000000;\n"
"width:40;\n"
"height:32;\n"
"align:Center;\n"
"font-size:16px;\n"
"font-family: PingFangSC-Regular;\n"
"font-weight:600\n"
"}\n"
"\n"
"QTableWidget\n"
"{\n"
"alternate-background-color:#F7F7F7 ;\n"
"background: #FFFFFF;\n"
"gridline-color:#438AFF;\n"
"text-align:center;\n"
"font-size:8px;\n"
"font-weight:500;\n"
"gridline-width:1px;\n"
"\n"
"}\n"
"\n"
"QTableWidget::item\n"
"{border:1px solid #438AFF;\n"
"border-bottom:3px solid #438AFF;\n"
"border-top:3px solid #438AFF;\n"
"}\n"
"\n"
"QTableWidget::item::selected\n"
"{\n"
"background-color:rgb(0,255,0);\n"
"}\n"
"\n"
"QTableWidget QTableCornerButton::section {\n"
"    backgr"
                        "ound-color: #438AFF;\n"
"    border: 0px solid #fffff8;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"/*background:#438AFF; */\n"
"padding-top:20px; \n"
"padding-bottom:20px; \n"
"padding-left:0px; \n"
"padding-right:0px;\n"
"border-left:1px solid #d7d7d7;\n"
"}"));
        tableWidget_Seg->setFrameShape(QFrame::NoFrame);
        tableWidget_Seg->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_Seg->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_Seg->setRowCount(1);
        tableWidget_Seg->setColumnCount(100);
        tableWidget_Seg->horizontalHeader()->setVisible(false);
        tableWidget_Seg->horizontalHeader()->setDefaultSectionSize(40);
        tableWidget_Seg->horizontalHeader()->setMinimumSectionSize(40);
        tableWidget_Seg->verticalHeader()->setVisible(false);
        tableWidget_Seg->verticalHeader()->setDefaultSectionSize(32);
        tableWidget_Seg->verticalHeader()->setMinimumSectionSize(32);
        label_2 = new QLabel(PulseGeneratorClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(235, 80, 74, 18));
        label_2->setStyleSheet(QString::fromUtf8("QLabel#label_2\n"
"{\n"
"border-image: url(:/PulseImage/Segment\345\244\207\344\273\275.png);\n"
"}"));
        label_3 = new QLabel(PulseGeneratorClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(267, 109, 41, 17));
        label_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"border-image: url(:/PulseImage/Loop\345\244\207\344\273\275.png);\n"
"}"));
        label_4 = new QLabel(PulseGeneratorClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(221, 140, 87, 19));
        label_4->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"border-image: url(:/PulseImage/Length(ns).png);\n"
"}"));
        label_5 = new QLabel(PulseGeneratorClass);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(227, 198, 80, 20));
        label_5->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"border-image: url(:/PulseImage/\346\223\215\344\275\234\345\244\207\346\263\250.png);\n"
"}"));
        tableWidget_Channel = new QTableWidget(PulseGeneratorClass);
        if (tableWidget_Channel->columnCount() < 1)
            tableWidget_Channel->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Channel->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        if (tableWidget_Channel->rowCount() < 16)
            tableWidget_Channel->setRowCount(16);
        tableWidget_Channel->setObjectName(QStringLiteral("tableWidget_Channel"));
        tableWidget_Channel->setGeometry(QRect(267, 230, 50, 461));
        tableWidget_Channel->setStyleSheet(QString::fromUtf8("\n"
"\n"
"/*QTableWidget::cell:selected,QTableView::cell:selected {				   \n"
"        background: rgb(0\357\274\214255\357\274\2140);\n"
"        \n"
"}*/\n"
"\n"
"QHeaderView::section{\n"
"border:0px;\n"
"border-radius:0px;\n"
"padding:2px 4px;\n"
"background-color:#438AFF;\n"
"color:#ffffff;\n"
"width:50;\n"
"height:40;\n"
"align:Center;\n"
"font-size:16px;\n"
"/*font-family: PingFangSC-Regular;*/\n"
"font-weight:600\n"
"}\n"
"\n"
"QTableWidget\n"
"{\n"
"alternate-background-color:#F7F7F7 ;\n"
"background: #FFFFFF;\n"
"gridline-color:#438AFF;\n"
"text-align:center;\n"
"font-size:11px;\n"
"font-weight:480;\n"
"gridline-width:1px;\n"
"border-right:3px;\n"
"\n"
"}\n"
"\n"
"QTableWidget::item\n"
"{border:1px solid #438AFF;\n"
"border-bottom:1px solid #438AFF;\n"
"border-top:1px solid #438AFF;\n"
"border-right:2px solid #438AFF;\n"
"}\n"
"\n"
"QTableWidget::item::selected\n"
"{\n"
"background-color:rgb(0,255,0);\n"
"}\n"
"\n"
"QTableWidget QTableCornerButton::section {\n"
"    background-color: #438AFF;\n"
"    "
                        "border: 0px solid #fffff8;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"/*background:#438AFF; */\n"
"padding-top:20px; \n"
"padding-bottom:20px; \n"
"padding-left:0px; \n"
"padding-right:0px;\n"
"border-left:1px solid #d7d7d7;\n"
"}"));
        tableWidget_Channel->setFrameShape(QFrame::NoFrame);
        tableWidget_Channel->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_Channel->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_Channel->setShowGrid(true);
        tableWidget_Channel->setRowCount(16);
        tableWidget_Channel->setColumnCount(1);
        tableWidget_Channel->horizontalHeader()->setVisible(true);
        tableWidget_Channel->horizontalHeader()->setDefaultSectionSize(50);
        tableWidget_Channel->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_Channel->verticalHeader()->setVisible(false);
        tableWidget_Channel->verticalHeader()->setDefaultSectionSize(40);
        tableWidget_Channel->verticalHeader()->setMinimumSectionSize(40);
        frame_Top->raise();
        label_3->raise();
        tableWidget_RowNote->raise();
        tableWidget_Loop->raise();
        tableWidget_ColNote->raise();
        tableWidget_Main->raise();
        widget->raise();
        tableWidget_Seg->raise();
        label_2->raise();
        label_4->raise();
        label_5->raise();
        frame->raise();
        tableWidget_Channel->raise();

        retranslateUi(PulseGeneratorClass);

        QMetaObject::connectSlotsByName(PulseGeneratorClass);
    } // setupUi

    void retranslateUi(QWidget *PulseGeneratorClass)
    {
        PulseGeneratorClass->setWindowTitle(QApplication::translate("PulseGeneratorClass", "PulseGenerator", Q_NULLPTR));
        label->setText(QString());
        pushButton_Connect->setText(QString());
        pushButton_Import->setText(QString());
        pushButton_Clear->setText(QString());
        pushButton_Save->setText(QString());
        pushButton_CheckPulse->setText(QString());
        pushButton_SendData->setText(QString());
        pushButton_Max->setText(QString());
        pushButton_Mini->setText(QString());
        pushButton_Close->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Loop->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PulseGeneratorClass", "Loop", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Loop->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PulseGeneratorClass", "Length", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_RowNote->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("PulseGeneratorClass", "\346\223\215\344\275\234\345\244\207\346\263\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Seg->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("PulseGeneratorClass", "Segment", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Channel->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("PulseGeneratorClass", "\351\200\232\351\201\223", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PulseGeneratorClass: public Ui_PulseGeneratorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PULSEGENERATOR_H
