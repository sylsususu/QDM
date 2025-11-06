/********************************************************************************
** Form generated from reading UI file 'QDM_Interface.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDM_INTERFACE_H
#define UI_QDM_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "MyGraphicsView.h"
#include "qcustomplot.h"
#include "radiusprogressbar.h"

QT_BEGIN_NAMESPACE

class Ui_QDM_InterfaceClass
{
public:
    QTreeWidget *treeWidget;
    QLabel *label_2;
    QCustomPlot *widget;
    QLabel *label_ColorCard;
    MyGraphicsView *graphicsView;
    QFrame *frame_3;
    QPushButton *pushButton_StartFixFreMeasure;
    QLabel *label;
    QLineEdit *lineEdit_IterationTime;
    QLabel *label_8;
    QPushButton *pushButton_StopFixFreMeasure;
    QPushButton *pushButton_StartFixFreMeasureAllPoint;
    QCheckBox *checkBox_IsLockIn;
    QFrame *frame;
    QPushButton *pushButton_StartSweepMeasure;
    QLabel *label_28;
    QPushButton *pushButton_StartAllOut;
    QLabel *label_29;
    QLineEdit *lineEdit_PicNums;
    QRadioButton *radioButton_Mag;
    QRadioButton *radioButton_NoMag;
    QPushButton *pushButton_StopSweepMeasure;
    QFrame *frame_2;
    QPushButton *pushButton_OpenColorMapPage;
    QLineEdit *lineEdit_DataDimension;
    QPushButton *pushButton_StartAnalysisNoMag;
    QPushButton *pushButton_StartAnalysisWithMag;
    QRadioButton *radioButton_AnalysisSelf;
    QRadioButton *radioButton_AnalysisAll;
    QLabel *label_9;
    QPushButton *pushButton_StartAllAnalysis;
    QLabel *label_30;
    QLabel *label_10;
    QLabel *label_12;
    QPushButton *pushButton_ImportPicNoMag;
    QPushButton *pushButton_ImportPicWithMag;
    QPushButton *pushButton_ImportParaNoMag;
    QPushButton *pushButton_ImportParaWithMag;
    QPushButton *pushButton_AverODMRNoMag;
    QPushButton *pushButton_AverODMRWithMag;
    QPushButton *pushButton_GetInitParaNoMag;
    QPushButton *pushButton_GetInitParaWithMag;
    QTableWidget *tableWidget_ParaNoMag;
    QTableWidget *tableWidget_ParaWithMag;
    RadiusProgressBar *progressBar;
    QPushButton *pushButton_AnalysisRoi;
    QPushButton *pushButton_SaveParaNoMag;
    QPushButton *pushButton_SaveParaWithMag;
    QPushButton *pushButton_loadNoMagData;
    QFrame *frame_4;
    QPushButton *pushButton_OpenRoiAnalysePage;
    QLabel *label_15;
    QToolButton *minimizeButton;
    QToolButton *closeButton;
    QGroupBox *groupBox_MT;
    QPushButton *pushButton_FindZero;
    QPushButton *pushButton_WriteLoadPos;
    QPushButton *pushButton_WriteUnloadPos;
    QPushButton *pushButton_MotorStop;
    QPushButton *pushButton_LoadPos;
    QPushButton *pushButton_UnlodPos;
    QLineEdit *lineEdit_RelativeDistance;
    QLabel *label_7;
    QPushButton *pushButton_Left;
    QPushButton *pushButton_Forward;
    QPushButton *pushButton_Right;
    QPushButton *pushButton_Up;
    QPushButton *pushButton_Backward;
    QPushButton *pushButton_Down;
    QLabel *label_MotorPos;
    QRadioButton *radioButton_Standard;
    QRadioButton *radioButton_FineTuning;
    QGroupBox *groupBox_camera;
    QGroupBox *groupBox_ExposureSetting;
    QRadioButton *radioButton_AutoExpo;
    QRadioButton *radioButton_MannualExpo;
    QPushButton *pushButton_autoFindExpTime;
    QLabel *label_6;
    QLineEdit *lineEdit_ExposureTime;
    QLabel *label_36;
    QLabel *label_37;
    QGroupBox *groupBox_TriggerSetting;
    QRadioButton *radioButton_ContTrigger;
    QRadioButton *radioButton_SoftTrigger;
    QRadioButton *radioButton_HardTrigger;
    QPushButton *pushButton_SoftTriggerOnce;
    QLabel *label_38;
    QGroupBox *groupBox_RoiSetting;
    QLabel *label_5;
    QLineEdit *lineEdit_CameraX;
    QLabel *label_18;
    QLineEdit *lineEdit_CameraY;
    QLabel *label_20;
    QLineEdit *lineEdit_CameraW;
    QLabel *label_21;
    QLineEdit *lineEdit_CameraH;
    QPushButton *pushButton_SetROI;
    QLabel *label_39;
    QPushButton *pushButton_zaoshengfenxi;
    QCheckBox *checkBox_AutoSave;
    QPushButton *pushButton_ChooseSavePath;
    QLineEdit *lineEdit_SavePath;
    QLabel *label_19;
    QPushButton *pushButton_SavePic;
    QLabel *label_16;
    QLineEdit *lineEdit_Binning;
    QGroupBox *groupBox;
    QLabel *label_52;
    QRadioButton *radioButton_Stander;
    QRadioButton *radioButton_LowNoise14;
    QRadioButton *radioButton_LowNoise16;
    QGroupBox *groupBox_2;
    QLabel *label_53;
    QRadioButton *radioButton_Gain0;
    QRadioButton *radioButton_Gain1;
    QRadioButton *radioButton_Gain2;
    QRadioButton *radioButton_Gain3;
    QSlider *contrastSlider;
    QSlider *GammaSlider;
    QLabel *label_69;
    QLabel *label_70;
    QLineEdit *lineEdit_ConTrast;
    QLineEdit *lineEdit_Gamma;
    QLabel *label_73;
    QLineEdit *lineEdit_Gain;
    QSlider *GainSlider;
    QGroupBox *groupBox_Connect;
    QPushButton *pushButton_ConnectCamera;
    QLabel *label_3;
    QComboBox *comboBox_serialPort;
    QPushButton *pushButton_ConnectWave;
    QLabel *label_31;
    QComboBox *comboBox_Current;
    QPushButton *pushButton_ConnectCurrent;
    QPushButton *pushButton_ConnectPulse;
    QPushButton *pushButton_ConnectMotor;
    QPushButton *pushButton_ConnectCoilXYZ;
    QPushButton *pushButton_OpenLaser;
    QPushButton *pushButton_OpenLED;
    QLabel *label_4;
    QGroupBox *groupBox_Gs;
    QLabel *label_AV;
    QLineEdit *lineEdit_V;
    QLabel *label_32;
    QLineEdit *lineEdit_A;
    QLabel *label_34;
    QPushButton *pushButton_CurrentSet;
    QPushButton *pushButton_CurrentOut;
    QLabel *label_14;
    QLabel *label_22;
    QLabel *label_35;
    QGroupBox *groupBox_wave;
    QGroupBox *groupBox_FreMode;
    QRadioButton *radioButton_SweepFreMode;
    QRadioButton *radioButton_FixFreMode;
    QPushButton *pushButton_SendWaveMode;
    QLabel *label_40;
    QGroupBox *groupBox_SweepFre;
    QLabel *label_24;
    QLineEdit *lineEdit_StartFre;
    QLabel *label_25;
    QLabel *label_13;
    QLineEdit *lineEdit_EndFre;
    QLabel *label_23;
    QLabel *label_26;
    QLineEdit *lineEdit_StepFre;
    QLabel *label_27;
    QLabel *label_33;
    QLineEdit *lineEdit_SweepTimes;
    QPushButton *pushButton_SendSweepFre;
    QLabel *label_41;
    QGroupBox *groupBox_FixFre;
    QLabel *label_11;
    QLineEdit *lineEdit_FixFre;
    QLabel *label_17;
    QPushButton *pushButton_SendFixFre;
    QLabel *label_42;
    QPushButton *pushButton_StartWave;
    QPushButton *pushButton_ResetWave;
    QGroupBox *groupBox_pusle;
    QPushButton *pushButton_OpenPulseSettingPage;
    QPushButton *pushButton_ClearPulseManual;
    QLabel *label_43;
    QLabel *label_44;
    QFrame *frame_7;
    QTextEdit *textEdit_Log;
    QPushButton *pushButton_ClearLog;
    QLabel *label_45;
    QGroupBox *groupBox_coil;
    QLabel *label_46;
    QLineEdit *lineEdit_CoilX_V;
    QLabel *label_48;
    QLineEdit *lineEdit_CoilX_A;
    QPushButton *pushButton_CoilXSet;
    QPushButton *pushButton_CoilXOut;
    QPushButton *pushButton_CoilYSet;
    QLineEdit *lineEdit_CoilY_V;
    QLineEdit *lineEdit_CoilY_A;
    QPushButton *pushButton_CoilYOut;
    QLabel *label_49;
    QLabel *label_47;
    QPushButton *pushButton_CoilZSet;
    QLineEdit *lineEdit_CoilZ_V;
    QLineEdit *lineEdit_CoilZ_A;
    QPushButton *pushButton_CoilZOut;
    QLabel *label_50;
    QLabel *label_51;
    QLabel *label_XAV;
    QLabel *label_YAV;
    QLabel *label_ZAV;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_CamFps_2;
    QLabel *label_CamFps;
    QGroupBox *groupBox_Sensitivity;
    QLabel *label_54;
    QLabel *label_55;
    QLabel *label_56;
    QLabel *label_57;
    QPushButton *pushButton_CalSensitivity;
    QLabel *label_58;
    QLabel *label_59;
    QLineEdit *lineEdit_Std;
    QLineEdit *lineEdit_K;
    QLabel *label_60;
    QPushButton *pushButton_CalParams;
    QLabel *label_61;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_F0;
    QLabel *label_62;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_F1;
    QLabel *label_63;
    QWidget *layoutWidget_4;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_KStart;
    QLabel *label_64;
    QWidget *layoutWidget_5;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_KEnd;
    QLabel *label_65;
    QWidget *layoutWidget_6;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEdit_Exp;
    QLabel *label_66;
    QLabel *label_67;
    QLineEdit *lineEdit_OffWaveValue;
    QWidget *layoutWidget_7;
    QGridLayout *gridLayout_6;
    QLineEdit *lineEdit_Sensitivity;
    QLabel *label_68;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_7;
    QLabel *label_71;
    QLineEdit *lineEdit_StartY;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_8;
    QLabel *label_72;
    QLineEdit *lineEdit_EndY;
    QLabel *label_Point_1;
    QLabel *label_Point;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Point_2;
    QLabel *label_GrayValue;

    void setupUi(QDialog *QDM_InterfaceClass)
    {
        if (QDM_InterfaceClass->objectName().isEmpty())
            QDM_InterfaceClass->setObjectName(QStringLiteral("QDM_InterfaceClass"));
        QDM_InterfaceClass->setWindowModality(Qt::WindowModal);
        QDM_InterfaceClass->resize(1920, 1040);
        QDM_InterfaceClass->setStyleSheet(QLatin1String("QDialog{background: #060606;}\n"
""));
        treeWidget = new QTreeWidget(QDM_InterfaceClass);
        treeWidget->headerItem()->setText(0, QString());
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI Light"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem1->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem2->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem3->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem4->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem5->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem6->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem7->setFont(0, font);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(1540, 97, 376, 931));
        treeWidget->setStyleSheet(QString::fromUtf8("QHeaderView::section { \n"
"    height:25px;  /* \350\256\276\347\275\256section\347\232\204\351\253\230\345\272\246 */\n"
"    color:white;  /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    background: #191919;  /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"   \n"
"}\n"
"\n"
"QTreeWidget {\n"
"    border:none;  /* \347\247\273\351\231\244\350\276\271\346\241\206 */\n"
"    background: #060606;  /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    show-decoration-selected: 0;  /* \346\230\276\347\244\272\351\200\211\344\270\255\351\241\271\347\232\204\350\243\205\351\245\260 */\n"
"	\n"
"}\n"
"\n"
"\n"
"QTreeWidget::item {\n"
"   \n"
"	margin-bottom: 10px;  /* \350\256\276\347\275\256\344\270\213\350\276\271\350\267\235 */\n"
"    border: none;  /* \347\247\273\351\231\244\350\276\271\346\241\206 */\n"
"    height: 56px;  /* \350\256\276\347\275\256\351\253\230\345\272\246 */\n"
"    color: white;  /* \350"
                        "\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    background: #191919;  /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"	\n"
"	background-image:url(:/Image/treeclose.png); background-repeat: no-repeat; \n"
"background-position: right ; \n"
"	\n"
"}\n"
"\n"
"QTreeWidget::item:hover {\n"
"    border: none;  /* \347\247\273\351\231\244\350\276\271\346\241\206 */\n"
"    background: #3B3B3B;  /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QTreeWidget::item:selected{\n"
"    border: none;  /* \347\247\273\351\231\244\350\276\271\346\241\206 */\n"
"    background: #3B3B3B;  /* \350\256\276\347\275\256\351\200\211\344\270\255\351\241\271\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"\n"
"\n"
"QTreeWidget::branch {\n"
"	\n"
"    border: none;  /* \347\247\273\351\231\244\350\276\271\346\241\206 */\n"
"    "
                        "background:  #060606;  /* \350\256\276\347\275\256\345\261\225\345\274\200/\346\212\230\345\217\240\346\216\247\344\273\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QTreeWidget::item:closed {background-image: url(:/Image/treeclose.png); background-repeat: no-repeat; \n"
"background-position: right ; \n"
" }\n"
"QTreeWidget::item:open { background-image: url(:./Image/treeopen.png); background-repeat: no-repeat; \n"
"background-position: right ; \n"
" }\n"
"\n"
"QTreeWidget::branch:hover {\n"
"    border: none;  /* \347\247\273\351\231\244\350\276\271\346\241\206 */\n"
"    background: #060606;  /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QTreeWidget::branch:selected {\n"
"    border: none;  /* \347\247\273\351\231\244\350\276\271\346\241\206 */\n"
"    background: #060606;  /* \350\256\276\347\275\256\351\200\211\344\270\255\351\241\271\347\232\204\350\203"
                        "\214\346\231\257\351\242\234\350\211\262 */\n"
"	\n"
"}\n"
""));
        treeWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        treeWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        treeWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        treeWidget->setAutoScroll(false);
        treeWidget->setEditTriggers(QAbstractItemView::SelectedClicked);
        treeWidget->setAutoExpandDelay(-1);
        treeWidget->setIndentation(100);
        treeWidget->setRootIsDecorated(false);
        treeWidget->setUniformRowHeights(false);
        treeWidget->setItemsExpandable(true);
        treeWidget->setSortingEnabled(false);
        treeWidget->setHeaderHidden(true);
        treeWidget->setExpandsOnDoubleClick(false);
        treeWidget->header()->setStretchLastSection(true);
        label_2 = new QLabel(QDM_InterfaceClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(400, 610, 120, 22));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei UI Light"));
        font1.setBold(true);
        font1.setWeight(62);
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("width: 114px;\n"
"height: 22px;\n"
"font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 500;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        widget = new QCustomPlot(QDM_InterfaceClass);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 874, 580));
        widget->setStyleSheet(QLatin1String("border: 1px solid #E6E6E6;\n"
""));
        label_ColorCard = new QLabel(QDM_InterfaceClass);
        label_ColorCard->setObjectName(QStringLiteral("label_ColorCard"));
        label_ColorCard->setGeometry(QRect(1910, 1050, 20, 21));
        graphicsView = new MyGraphicsView(QDM_InterfaceClass);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(924, 20, 580, 580));
        graphicsView->setStyleSheet(QLatin1String("\n"
"background: rgb(150,150,150);"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        frame_3 = new QFrame(QDM_InterfaceClass);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(20, 870, 359, 162));
        frame_3->setStyleSheet(QLatin1String("width: 359px;\n"
"height: 156px;\n"
"background: #252525;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        pushButton_StartFixFreMeasure = new QPushButton(frame_3);
        pushButton_StartFixFreMeasure->setObjectName(QStringLiteral("pushButton_StartFixFreMeasure"));
        pushButton_StartFixFreMeasure->setGeometry(QRect(30, 90, 140, 32));
        pushButton_StartFixFreMeasure->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}"));
        label = new QLabel(frame_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(51, 50, 128, 22));
        label->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"\n"
"\n"
"\n"
""));
        lineEdit_IterationTime = new QLineEdit(frame_3);
        lineEdit_IterationTime->setObjectName(QStringLiteral("lineEdit_IterationTime"));
        lineEdit_IterationTime->setGeometry(QRect(189, 50, 120, 32));
        lineEdit_IterationTime->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        lineEdit_IterationTime->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(16, 12, 120, 22));
        label_8->setFont(font1);
        label_8->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 500;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        pushButton_StopFixFreMeasure = new QPushButton(frame_3);
        pushButton_StopFixFreMeasure->setObjectName(QStringLiteral("pushButton_StopFixFreMeasure"));
        pushButton_StopFixFreMeasure->setEnabled(false);
        pushButton_StopFixFreMeasure->setGeometry(QRect(190, 90, 140, 32));
        pushButton_StopFixFreMeasure->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}"));
        pushButton_StartFixFreMeasureAllPoint = new QPushButton(frame_3);
        pushButton_StartFixFreMeasureAllPoint->setObjectName(QStringLiteral("pushButton_StartFixFreMeasureAllPoint"));
        pushButton_StartFixFreMeasureAllPoint->setGeometry(QRect(170, 10, 111, 16));
        pushButton_StartFixFreMeasureAllPoint->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}"));
        checkBox_IsLockIn = new QCheckBox(frame_3);
        checkBox_IsLockIn->setObjectName(QStringLiteral("checkBox_IsLockIn"));
        checkBox_IsLockIn->setGeometry(QRect(40, 130, 101, 21));
        checkBox_IsLockIn->setStyleSheet(QLatin1String("width: 114px;\n"
"height: 22px;\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 500;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        frame = new QFrame(QDM_InterfaceClass);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 642, 360, 218));
        frame->setStyleSheet(QLatin1String("width: 359px;\n"
"height: 196px;\n"
"background: #252525;\n"
"\n"
"\n"
"\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_StartSweepMeasure = new QPushButton(frame);
        pushButton_StartSweepMeasure->setObjectName(QStringLiteral("pushButton_StartSweepMeasure"));
        pushButton_StartSweepMeasure->setGeometry(QRect(30, 164, 140, 32));
        pushButton_StartSweepMeasure->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}"));
        label_28 = new QLabel(frame);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(16, 12, 91, 22));
        label_28->setFont(font1);
        label_28->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 500;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        pushButton_StartAllOut = new QPushButton(frame);
        pushButton_StartAllOut->setObjectName(QStringLiteral("pushButton_StartAllOut"));
        pushButton_StartAllOut->setEnabled(true);
        pushButton_StartAllOut->setGeometry(QRect(110, 52, 140, 32));
        pushButton_StartAllOut->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}"));
        label_29 = new QLabel(frame);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(51, 113, 96, 22));
        label_29->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_PicNums = new QLineEdit(frame);
        lineEdit_PicNums->setObjectName(QStringLiteral("lineEdit_PicNums"));
        lineEdit_PicNums->setGeometry(QRect(157, 108, 152, 32));
        lineEdit_PicNums->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        lineEdit_PicNums->setAlignment(Qt::AlignCenter);
        radioButton_Mag = new QRadioButton(frame);
        radioButton_Mag->setObjectName(QStringLiteral("radioButton_Mag"));
        radioButton_Mag->setGeometry(QRect(10, 50, 81, 22));
        radioButton_Mag->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}"));
        radioButton_Mag->setChecked(false);
        radioButton_NoMag = new QRadioButton(frame);
        radioButton_NoMag->setObjectName(QStringLiteral("radioButton_NoMag"));
        radioButton_NoMag->setGeometry(QRect(10, 80, 91, 22));
        radioButton_NoMag->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}"));
        radioButton_NoMag->setChecked(true);
        pushButton_StopSweepMeasure = new QPushButton(frame);
        pushButton_StopSweepMeasure->setObjectName(QStringLiteral("pushButton_StopSweepMeasure"));
        pushButton_StopSweepMeasure->setEnabled(false);
        pushButton_StopSweepMeasure->setGeometry(QRect(200, 164, 140, 32));
        pushButton_StopSweepMeasure->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}"));
        frame_2 = new QFrame(QDM_InterfaceClass);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(390, 642, 770, 390));
        frame_2->setStyleSheet(QLatin1String("background-color: rgb(42, 41, 41); \n"
"QWidget { color: white; }"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        pushButton_OpenColorMapPage = new QPushButton(frame_2);
        pushButton_OpenColorMapPage->setObjectName(QStringLiteral("pushButton_OpenColorMapPage"));
        pushButton_OpenColorMapPage->setGeometry(QRect(690, 54, 52, 71));
        pushButton_OpenColorMapPage->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        lineEdit_DataDimension = new QLineEdit(frame_2);
        lineEdit_DataDimension->setObjectName(QStringLiteral("lineEdit_DataDimension"));
        lineEdit_DataDimension->setGeometry(QRect(470, 14, 51, 32));
        lineEdit_DataDimension->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        lineEdit_DataDimension->setAlignment(Qt::AlignCenter);
        pushButton_StartAnalysisNoMag = new QPushButton(frame_2);
        pushButton_StartAnalysisNoMag->setObjectName(QStringLiteral("pushButton_StartAnalysisNoMag"));
        pushButton_StartAnalysisNoMag->setGeometry(QRect(512, 54, 118, 32));
        pushButton_StartAnalysisNoMag->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_StartAnalysisWithMag = new QPushButton(frame_2);
        pushButton_StartAnalysisWithMag->setObjectName(QStringLiteral("pushButton_StartAnalysisWithMag"));
        pushButton_StartAnalysisWithMag->setGeometry(QRect(512, 93, 118, 32));
        pushButton_StartAnalysisWithMag->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        radioButton_AnalysisSelf = new QRadioButton(frame_2);
        radioButton_AnalysisSelf->setObjectName(QStringLiteral("radioButton_AnalysisSelf"));
        radioButton_AnalysisSelf->setGeometry(QRect(210, 19, 81, 22));
        radioButton_AnalysisSelf->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}"));
        radioButton_AnalysisAll = new QRadioButton(frame_2);
        radioButton_AnalysisAll->setObjectName(QStringLiteral("radioButton_AnalysisAll"));
        radioButton_AnalysisAll->setGeometry(QRect(120, 19, 81, 22));
        radioButton_AnalysisAll->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}"));
        radioButton_AnalysisAll->setChecked(true);
        radioButton_AnalysisAll->setAutoRepeat(false);
        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(398, 18, 71, 22));
        label_9->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        pushButton_StartAllAnalysis = new QPushButton(frame_2);
        pushButton_StartAllAnalysis->setObjectName(QStringLiteral("pushButton_StartAllAnalysis"));
        pushButton_StartAllAnalysis->setGeometry(QRect(636, 54, 48, 71));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_StartAllAnalysis->sizePolicy().hasHeightForWidth());
        pushButton_StartAllAnalysis->setSizePolicy(sizePolicy);
        pushButton_StartAllAnalysis->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        label_30 = new QLabel(frame_2);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(10, 10, 102, 22));
        label_30->setFont(font1);
        label_30->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 500;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 59, 81, 22));
        label_10->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 99, 71, 22));
        label_12->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        pushButton_ImportPicNoMag = new QPushButton(frame_2);
        pushButton_ImportPicNoMag->setObjectName(QStringLiteral("pushButton_ImportPicNoMag"));
        pushButton_ImportPicNoMag->setGeometry(QRect(82, 54, 118, 32));
        pushButton_ImportPicNoMag->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}"));
        pushButton_ImportPicWithMag = new QPushButton(frame_2);
        pushButton_ImportPicWithMag->setObjectName(QStringLiteral("pushButton_ImportPicWithMag"));
        pushButton_ImportPicWithMag->setGeometry(QRect(82, 93, 118, 32));
        pushButton_ImportPicWithMag->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_ImportParaNoMag = new QPushButton(frame_2);
        pushButton_ImportParaNoMag->setObjectName(QStringLiteral("pushButton_ImportParaNoMag"));
        pushButton_ImportParaNoMag->setGeometry(QRect(320, 54, 92, 32));
        pushButton_ImportParaNoMag->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_ImportParaWithMag = new QPushButton(frame_2);
        pushButton_ImportParaWithMag->setObjectName(QStringLiteral("pushButton_ImportParaWithMag"));
        pushButton_ImportParaWithMag->setGeometry(QRect(320, 93, 92, 32));
        pushButton_ImportParaWithMag->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_AverODMRNoMag = new QPushButton(frame_2);
        pushButton_AverODMRNoMag->setObjectName(QStringLiteral("pushButton_AverODMRNoMag"));
        pushButton_AverODMRNoMag->setGeometry(QRect(210, 54, 106, 32));
        pushButton_AverODMRNoMag->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_AverODMRWithMag = new QPushButton(frame_2);
        pushButton_AverODMRWithMag->setObjectName(QStringLiteral("pushButton_AverODMRWithMag"));
        pushButton_AverODMRWithMag->setGeometry(QRect(210, 93, 106, 32));
        pushButton_AverODMRWithMag->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_GetInitParaNoMag = new QPushButton(frame_2);
        pushButton_GetInitParaNoMag->setObjectName(QStringLiteral("pushButton_GetInitParaNoMag"));
        pushButton_GetInitParaNoMag->setGeometry(QRect(416, 54, 90, 32));
        pushButton_GetInitParaNoMag->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_GetInitParaWithMag = new QPushButton(frame_2);
        pushButton_GetInitParaWithMag->setObjectName(QStringLiteral("pushButton_GetInitParaWithMag"));
        pushButton_GetInitParaWithMag->setGeometry(QRect(416, 93, 90, 32));
        pushButton_GetInitParaWithMag->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        tableWidget_ParaNoMag = new QTableWidget(frame_2);
        if (tableWidget_ParaNoMag->columnCount() < 3)
            tableWidget_ParaNoMag->setColumnCount(3);
        if (tableWidget_ParaNoMag->rowCount() < 8)
            tableWidget_ParaNoMag->setRowCount(8);
        tableWidget_ParaNoMag->setObjectName(QStringLiteral("tableWidget_ParaNoMag"));
        tableWidget_ParaNoMag->setGeometry(QRect(10, 133, 349, 264));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget_ParaNoMag->sizePolicy().hasHeightForWidth());
        tableWidget_ParaNoMag->setSizePolicy(sizePolicy1);
        tableWidget_ParaNoMag->setMinimumSize(QSize(250, 0));
        tableWidget_ParaNoMag->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
"   border: 0px ;  /* \350\256\276\347\275\256\350\276\271\346\241\206\346\240\267\345\274\217 */\n"
"    background-color: #1E1E1E;  /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    selection-background-color: #FF0000;  /* \350\256\276\347\275\256\351\200\211\344\270\255\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    selection-color: #FFFFFF;  /* \350\256\276\347\275\256\351\200\211\344\270\255\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    alternate-background-color: #1E1E1E;  /* \350\256\276\347\275\256\344\272\244\346\233\277\350\241\214\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"\n"
"\n"
"QTableWidget::item:hover { \n"
"    background-color: #333333;  /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: #FFFFFF;  /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227"
                        "\266\347\232\204\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QTableWidget::item:selected { \n"
"    background-color: #333333;  /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: #FFFFFF;  /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #1E1E1E;  /* \350\256\276\347\275\256\350\241\250\345\244\264\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white;  /* \350\256\276\347\275\256\350\241\250\345\244\264\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    border: 0px solid;  /* \350\256\276\347\275\256\350\276\271\346\241\206\344\270\272\346\227\240 */\n"
"    border-radius: 0px;  /* \350\256\276\347\275\256\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204"
                        "\344\270\2720 */\n"
"    padding: 2px 4px;  /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    width: 20;  /* \350\256\276\347\275\256\345\256\275\345\272\246 */\n"
"    height: 20;  /* \350\256\276\347\275\256\351\253\230\345\272\246\344\270\27215px */\n"
"    text-align: Center;  /* \350\256\276\347\275\256\346\226\207\346\234\254\345\261\205\344\270\255\345\257\271\351\275\220 */\n"
"    font-size: 15px;  /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    color: white;  /* \350\256\276\347\275\256\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    border: 1px solid #979797;  /* \350\256\276\347\275\256\350\276\271\346\241\206\346\240\267\345\274\217 */\n"
"    border-bottom: 1px solid #979797;  /* \350\256\276\347\275\256\345\272\225\351\203\250\350\276\271\346\241\206\346\240\267\345\274\217 */\n"
"    border-top: 1px solid #979797;  /* \350\256\276\347\275\256\351\241\266\351\203\250\350\276\271\346\241"
                        "\206\346\240\267\345\274\217 */\n"
"    border-left: 1px solid #979797;  /* \350\256\276\347\275\256\345\267\246\344\276\247\350\276\271\346\241\206\346\240\267\345\274\217 */\n"
"    text-align: Center;  /* \350\256\276\347\275\256\346\226\207\346\234\254\345\261\205\344\270\255\345\257\271\351\275\220 */\n"
"	\n"
"}\n"
"QTableCornerButton:section{\n"
"	background: #1E1E1E;/* \350\256\276\347\275\256\350\241\250\345\244\264\344\272\244\345\217\211\351\203\250\345\210\206\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"\n"
"}\n"
"QTableWidget QLineEdit { color: white; }\n"
""));
        tableWidget_ParaNoMag->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_ParaNoMag->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_ParaNoMag->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget_ParaNoMag->setAutoScroll(false);
        tableWidget_ParaNoMag->setShowGrid(true);
        tableWidget_ParaNoMag->setGridStyle(Qt::SolidLine);
        tableWidget_ParaNoMag->setRowCount(8);
        tableWidget_ParaNoMag->setColumnCount(3);
        tableWidget_ParaNoMag->horizontalHeader()->setDefaultSectionSize(107);
        tableWidget_ParaNoMag->horizontalHeader()->setMinimumSectionSize(107);
        tableWidget_ParaNoMag->verticalHeader()->setDefaultSectionSize(29);
        tableWidget_ParaNoMag->verticalHeader()->setMinimumSectionSize(35);
        tableWidget_ParaWithMag = new QTableWidget(frame_2);
        if (tableWidget_ParaWithMag->columnCount() < 3)
            tableWidget_ParaWithMag->setColumnCount(3);
        if (tableWidget_ParaWithMag->rowCount() < 8)
            tableWidget_ParaWithMag->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_ParaWithMag->setItem(0, 0, __qtablewidgetitem);
        tableWidget_ParaWithMag->setObjectName(QStringLiteral("tableWidget_ParaWithMag"));
        tableWidget_ParaWithMag->setEnabled(true);
        tableWidget_ParaWithMag->setGeometry(QRect(390, 133, 349, 264));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableWidget_ParaWithMag->sizePolicy().hasHeightForWidth());
        tableWidget_ParaWithMag->setSizePolicy(sizePolicy2);
        tableWidget_ParaWithMag->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
"   border: 0px ;  /* \350\256\276\347\275\256\350\276\271\346\241\206\346\240\267\345\274\217 */\n"
"    background-color: #1E1E1E;  /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    selection-background-color: #FF0000;  /* \350\256\276\347\275\256\351\200\211\344\270\255\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    selection-color: #FFFFFF;  /* \350\256\276\347\275\256\351\200\211\344\270\255\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    alternate-background-color: #1E1E1E;  /* \350\256\276\347\275\256\344\272\244\346\233\277\350\241\214\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"\n"
"\n"
"QTableWidget::item:hover { \n"
"    background-color: #333333;  /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: #FFFFFF;  /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227"
                        "\266\347\232\204\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #1E1E1E;  /* \350\256\276\347\275\256\350\241\250\345\244\264\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white;  /* \350\256\276\347\275\256\350\241\250\345\244\264\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    border: 0px solid;  /* \350\256\276\347\275\256\350\276\271\346\241\206\344\270\272\346\227\240 */\n"
"    border-radius: 0px;  /* \350\256\276\347\275\256\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2720 */\n"
"    padding: 2px 4px;  /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    width: 20;  /* \350\256\276\347\275\256\345\256\275\345\272\246 */\n"
"    height: 20;  /* \350\256\276\347\275\256\351\253\230\345\272\246\344\270\27215px */\n"
"    text-align: Center;  /* \350\256\276\347\275\256\346\226\207\346\234\254\345\261\205\344\270\255\345\257\271\351\275\220 "
                        "*/\n"
"    font-size: 15px;  /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    color: white;  /* \350\256\276\347\275\256\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    border: 1px solid #979797;  /* \350\256\276\347\275\256\350\276\271\346\241\206\346\240\267\345\274\217 */\n"
"    border-bottom: 1px solid #979797;  /* \350\256\276\347\275\256\345\272\225\351\203\250\350\276\271\346\241\206\346\240\267\345\274\217 */\n"
"    border-top: 1px solid #979797;  /* \350\256\276\347\275\256\351\241\266\351\203\250\350\276\271\346\241\206\346\240\267\345\274\217 */\n"
"    border-left: 1px solid #979797;  /* \350\256\276\347\275\256\345\267\246\344\276\247\350\276\271\346\241\206\346\240\267\345\274\217 */\n"
"    text-align: Center;  /* \350\256\276\347\275\256\346\226\207\346\234\254\345\261\205\344\270\255\345\257\271\351\275\220 */\n"
"	\n"
"}\n"
"QTableCornerButton:section{\n"
"	background: #1E1E1E;/* \350\256\276\347\275\256\350"
                        "\241\250\345\244\264\344\272\244\345\217\211\351\203\250\345\210\206\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"\n"
"}\n"
"QTableWidget QLineEdit { color: white; }"));
        tableWidget_ParaWithMag->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_ParaWithMag->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_ParaWithMag->setAutoScroll(false);
        tableWidget_ParaWithMag->setAutoScrollMargin(10);
        tableWidget_ParaWithMag->setRowCount(8);
        tableWidget_ParaWithMag->setColumnCount(3);
        tableWidget_ParaWithMag->horizontalHeader()->setVisible(true);
        tableWidget_ParaWithMag->horizontalHeader()->setDefaultSectionSize(107);
        tableWidget_ParaWithMag->horizontalHeader()->setHighlightSections(true);
        tableWidget_ParaWithMag->horizontalHeader()->setMinimumSectionSize(107);
        tableWidget_ParaWithMag->verticalHeader()->setVisible(true);
        tableWidget_ParaWithMag->verticalHeader()->setDefaultSectionSize(29);
        tableWidget_ParaWithMag->verticalHeader()->setHighlightSections(true);
        tableWidget_ParaWithMag->verticalHeader()->setMinimumSectionSize(35);
        tableWidget_ParaWithMag->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        progressBar = new RadiusProgressBar(frame_2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(640, 10, 120, 40));
        progressBar->setStyleSheet(QStringLiteral("image:url(:/resource/radius_back.png)"));
        pushButton_AnalysisRoi = new QPushButton(frame_2);
        pushButton_AnalysisRoi->setObjectName(QStringLiteral("pushButton_AnalysisRoi"));
        pushButton_AnalysisRoi->setGeometry(QRect(530, 14, 101, 32));
        pushButton_AnalysisRoi->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_SaveParaNoMag = new QPushButton(frame_2);
        pushButton_SaveParaNoMag->setObjectName(QStringLiteral("pushButton_SaveParaNoMag"));
        pushButton_SaveParaNoMag->setGeometry(QRect(360, 355, 30, 32));
        pushButton_SaveParaNoMag->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_SaveParaWithMag = new QPushButton(frame_2);
        pushButton_SaveParaWithMag->setObjectName(QStringLiteral("pushButton_SaveParaWithMag"));
        pushButton_SaveParaWithMag->setGeometry(QRect(740, 355, 30, 32));
        pushButton_SaveParaWithMag->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_loadNoMagData = new QPushButton(frame_2);
        pushButton_loadNoMagData->setObjectName(QStringLiteral("pushButton_loadNoMagData"));
        pushButton_loadNoMagData->setGeometry(QRect(300, 14, 91, 32));
        pushButton_loadNoMagData->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        frame_4 = new QFrame(QDM_InterfaceClass);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(1170, 642, 354, 110));
        frame_4->setStyleSheet(QStringLiteral("background-color: rgb(42, 41, 41);  "));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        pushButton_OpenRoiAnalysePage = new QPushButton(frame_4);
        pushButton_OpenRoiAnalysePage->setObjectName(QStringLiteral("pushButton_OpenRoiAnalysePage"));
        pushButton_OpenRoiAnalysePage->setGeometry(QRect(44, 52, 118, 32));
        pushButton_OpenRoiAnalysePage->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        label_15 = new QLabel(frame_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(25, 12, 68, 22));
        label_15->setFont(font1);
        label_15->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 500;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        minimizeButton = new QToolButton(QDM_InterfaceClass);
        minimizeButton->setObjectName(QStringLiteral("minimizeButton"));
        minimizeButton->setGeometry(QRect(1812, 15, 30, 30));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        minimizeButton->setFont(font2);
        minimizeButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: gray;\n"
"    border-radius: 15px;\n"
"    border: none;\n"
"    background-color: transparent;\n"
"    background-image: url(:/Image/\346\234\200\345\260\217\345\214\226.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-origin: content;\n"
"    background-clip: content;\n"
"    color: white;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: #1E1E1E;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"    background-color: #999999;\n"
"}"));
        closeButton = new QToolButton(QDM_InterfaceClass);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(1866, 15, 30, 30));
        closeButton->setFont(font2);
        closeButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: gray;\n"
"    border-radius: 15px;\n"
"    border: none;\n"
"    background-color: transparent;\n"
"    background-image: url(:/Image/\345\205\263\351\227\255.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-origin: content;\n"
"    background-clip: content;\n"
"    color: white;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: red;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"    background-color: #999999;\n"
"}"));
        groupBox_MT = new QGroupBox(QDM_InterfaceClass);
        groupBox_MT->setObjectName(QStringLiteral("groupBox_MT"));
        groupBox_MT->setGeometry(QRect(1530, 100, 376, 431));
        groupBox_MT->setStyleSheet(QLatin1String("border: none;\n"
"background-color: rgb(42, 41, 41); "));
        pushButton_FindZero = new QPushButton(groupBox_MT);
        pushButton_FindZero->setObjectName(QStringLiteral("pushButton_FindZero"));
        pushButton_FindZero->setGeometry(QRect(0, 0, 114, 32));
        pushButton_FindZero->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_WriteLoadPos = new QPushButton(groupBox_MT);
        pushButton_WriteLoadPos->setObjectName(QStringLiteral("pushButton_WriteLoadPos"));
        pushButton_WriteLoadPos->setGeometry(QRect(0, 48, 114, 32));
        pushButton_WriteLoadPos->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_WriteUnloadPos = new QPushButton(groupBox_MT);
        pushButton_WriteUnloadPos->setObjectName(QStringLiteral("pushButton_WriteUnloadPos"));
        pushButton_WriteUnloadPos->setGeometry(QRect(133, 48, 130, 32));
        pushButton_WriteUnloadPos->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_MotorStop = new QPushButton(groupBox_MT);
        pushButton_MotorStop->setObjectName(QStringLiteral("pushButton_MotorStop"));
        pushButton_MotorStop->setGeometry(QRect(296, 45, 70, 70));
        pushButton_MotorStop->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"             border-image: url(:/Image/stop.png);\n"
"}\n"
"\n"
"QPushButton:Hover\n"
"{	\n"
" 			border-image:url(:/Image/stop-hover.png);\n"
"	\n"
"}\n"
"\n"
"\n"
"\n"
""));
        pushButton_LoadPos = new QPushButton(groupBox_MT);
        pushButton_LoadPos->setObjectName(QStringLiteral("pushButton_LoadPos"));
        pushButton_LoadPos->setGeometry(QRect(0, 96, 114, 32));
        pushButton_LoadPos->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_UnlodPos = new QPushButton(groupBox_MT);
        pushButton_UnlodPos->setObjectName(QStringLiteral("pushButton_UnlodPos"));
        pushButton_UnlodPos->setGeometry(QRect(133, 96, 130, 32));
        pushButton_UnlodPos->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        lineEdit_RelativeDistance = new QLineEdit(groupBox_MT);
        lineEdit_RelativeDistance->setObjectName(QStringLiteral("lineEdit_RelativeDistance"));
        lineEdit_RelativeDistance->setGeometry(QRect(0, 152, 89, 32));
        lineEdit_RelativeDistance->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        label_7 = new QLabel(groupBox_MT);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(93, 160, 35, 17));
        label_7->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        pushButton_Left = new QPushButton(groupBox_MT);
        pushButton_Left->setObjectName(QStringLiteral("pushButton_Left"));
        pushButton_Left->setGeometry(QRect(8, 271, 50, 50));
        pushButton_Left->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"             border-image: url(:/Image/\345\267\246.png);\n"
"}\n"
"\n"
"QPushButton:Hover\n"
"{	\n"
" 			border-image:url(:/Image/\345\267\246-hover.png);\n"
"	\n"
"}\n"
"\n"
"\n"
"\n"
""));
        pushButton_Forward = new QPushButton(groupBox_MT);
        pushButton_Forward->setObjectName(QStringLiteral("pushButton_Forward"));
        pushButton_Forward->setGeometry(QRect(69, 231, 50, 50));
        pushButton_Forward->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"             border-image: url(:/Image/\345\211\215.png);\n"
"}\n"
"\n"
"QPushButton:Hover\n"
"{	\n"
" 			border-image:url(:/Image/\345\211\215-hover.png);\n"
"	\n"
"}\n"
"\n"
""));
        pushButton_Right = new QPushButton(groupBox_MT);
        pushButton_Right->setObjectName(QStringLiteral("pushButton_Right"));
        pushButton_Right->setGeometry(QRect(124, 271, 50, 50));
        pushButton_Right->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"             border-image: url(:/Image/\345\217\263.png);\n"
"}\n"
"\n"
"QPushButton:Hover\n"
"{	\n"
" 			border-image:url(:/Image/\345\217\263-hover.png);\n"
"	\n"
"}\n"
"\n"
"\n"
"\n"
""));
        pushButton_Up = new QPushButton(groupBox_MT);
        pushButton_Up->setObjectName(QStringLiteral("pushButton_Up"));
        pushButton_Up->setGeometry(QRect(289, 228, 63, 87));
        pushButton_Up->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"             border-image: url(:/Image/\344\270\212\345\215\207.png);\n"
"}\n"
"\n"
"QPushButton:Hover\n"
"{	\n"
" 			border-image:url(:/Image/\344\270\212\345\215\207-hover.png);\n"
"	\n"
"}\n"
"\n"
"\n"
"\n"
""));
        pushButton_Backward = new QPushButton(groupBox_MT);
        pushButton_Backward->setObjectName(QStringLiteral("pushButton_Backward"));
        pushButton_Backward->setGeometry(QRect(66, 311, 50, 50));
        pushButton_Backward->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"             border-image: url(:/Image/\345\220\216.png);\n"
"}\n"
"\n"
"QPushButton:Hover\n"
"{	\n"
" 			border-image:url(:/Image/\345\220\216-hover.png);\n"
"	\n"
"}\n"
"\n"
"\n"
"\n"
""));
        pushButton_Down = new QPushButton(groupBox_MT);
        pushButton_Down->setObjectName(QStringLiteral("pushButton_Down"));
        pushButton_Down->setGeometry(QRect(225, 287, 63, 87));
        pushButton_Down->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"             border-image: url(:/Image/\344\270\213\351\231\215.png);\n"
"}\n"
"\n"
"QPushButton:Hover\n"
"{	\n"
" 			border-image:url(:/Image/\344\270\213\351\231\215-hover.png);\n"
"	\n"
"}\n"
"\n"
"\n"
"\n"
""));
        label_MotorPos = new QLabel(groupBox_MT);
        label_MotorPos->setObjectName(QStringLiteral("label_MotorPos"));
        label_MotorPos->setGeometry(QRect(10, 390, 360, 28));
        label_MotorPos->setStyleSheet(QLatin1String("QLabel { color: white; }\n"
"border: 1px solid #979797;"));
        radioButton_Standard = new QRadioButton(groupBox_MT);
        radioButton_Standard->setObjectName(QStringLiteral("radioButton_Standard"));
        radioButton_Standard->setGeometry(QRect(140, 160, 51, 22));
        radioButton_Standard->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}"));
        radioButton_Standard->setChecked(true);
        radioButton_Standard->setAutoRepeat(false);
        radioButton_FineTuning = new QRadioButton(groupBox_MT);
        radioButton_FineTuning->setObjectName(QStringLiteral("radioButton_FineTuning"));
        radioButton_FineTuning->setGeometry(QRect(210, 160, 51, 22));
        radioButton_FineTuning->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}"));
        radioButton_FineTuning->setChecked(false);
        radioButton_FineTuning->setAutoRepeat(false);
        groupBox_camera = new QGroupBox(QDM_InterfaceClass);
        groupBox_camera->setObjectName(QStringLiteral("groupBox_camera"));
        groupBox_camera->setGeometry(QRect(1540, 100, 376, 911));
        groupBox_camera->setStyleSheet(QStringLiteral("border: none;background-color: rgb(42, 41, 41); "));
        groupBox_ExposureSetting = new QGroupBox(groupBox_camera);
        groupBox_ExposureSetting->setObjectName(QStringLiteral("groupBox_ExposureSetting"));
        groupBox_ExposureSetting->setEnabled(false);
        groupBox_ExposureSetting->setGeometry(QRect(0, 100, 376, 141));
        groupBox_ExposureSetting->setStyleSheet(QLatin1String("border: none;\n"
"background-color: rgb(42, 41, 41); color:white;"));
        radioButton_AutoExpo = new QRadioButton(groupBox_ExposureSetting);
        radioButton_AutoExpo->setObjectName(QStringLiteral("radioButton_AutoExpo"));
        radioButton_AutoExpo->setGeometry(QRect(16, 54, 51, 22));
        radioButton_AutoExpo->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
"QRadioButton:disabled {\n"
"    background-color: black; /* \347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}"));
        radioButton_AutoExpo->setChecked(true);
        radioButton_MannualExpo = new QRadioButton(groupBox_ExposureSetting);
        radioButton_MannualExpo->setObjectName(QStringLiteral("radioButton_MannualExpo"));
        radioButton_MannualExpo->setGeometry(QRect(90, 54, 51, 22));
        radioButton_MannualExpo->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
"QRadioButton:disabled {\n"
"    background-color: black; /* \347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}"));
        pushButton_autoFindExpTime = new QPushButton(groupBox_ExposureSetting);
        pushButton_autoFindExpTime->setObjectName(QStringLiteral("pushButton_autoFindExpTime"));
        pushButton_autoFindExpTime->setGeometry(QRect(183, 50, 118, 32));
        pushButton_autoFindExpTime->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        label_6 = new QLabel(groupBox_ExposureSetting);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(16, 103, 71, 22));
        label_6->setStyleSheet(QLatin1String("\n"
"font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_ExposureTime = new QLineEdit(groupBox_ExposureSetting);
        lineEdit_ExposureTime->setObjectName(QStringLiteral("lineEdit_ExposureTime"));
        lineEdit_ExposureTime->setEnabled(false);
        lineEdit_ExposureTime->setGeometry(QRect(86, 98, 90, 32));
        lineEdit_ExposureTime->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        label_36 = new QLabel(groupBox_ExposureSetting);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(180, 103, 48, 16));
        label_36->setStyleSheet(QLatin1String("\n"
"font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_37 = new QLabel(groupBox_ExposureSetting);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(16, 12, 71, 22));
        QFont font3;
        font3.setFamily(QStringLiteral("Microsoft YaHei UI Light"));
        font3.setBold(false);
        font3.setWeight(50);
        label_37->setFont(font3);
        label_37->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        groupBox_TriggerSetting = new QGroupBox(groupBox_camera);
        groupBox_TriggerSetting->setObjectName(QStringLiteral("groupBox_TriggerSetting"));
        groupBox_TriggerSetting->setEnabled(false);
        groupBox_TriggerSetting->setGeometry(QRect(0, 310, 376, 140));
        groupBox_TriggerSetting->setStyleSheet(QStringLiteral("border: none;background-color: rgb(42, 41, 41); color:white;"));
        radioButton_ContTrigger = new QRadioButton(groupBox_TriggerSetting);
        radioButton_ContTrigger->setObjectName(QStringLiteral("radioButton_ContTrigger"));
        radioButton_ContTrigger->setGeometry(QRect(14, 50, 79, 22));
        radioButton_ContTrigger->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
"QRadioButton:disabled {\n"
"    background-color: black; /* \347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}"));
        radioButton_ContTrigger->setChecked(false);
        radioButton_SoftTrigger = new QRadioButton(groupBox_TriggerSetting);
        radioButton_SoftTrigger->setObjectName(QStringLiteral("radioButton_SoftTrigger"));
        radioButton_SoftTrigger->setGeometry(QRect(110, 50, 65, 22));
        radioButton_SoftTrigger->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
"QRadioButton:disabled {\n"
"    background-color: black; /* \347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}"));
        radioButton_SoftTrigger->setChecked(false);
        radioButton_HardTrigger = new QRadioButton(groupBox_TriggerSetting);
        radioButton_HardTrigger->setObjectName(QStringLiteral("radioButton_HardTrigger"));
        radioButton_HardTrigger->setGeometry(QRect(192, 50, 65, 22));
        radioButton_HardTrigger->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
"QRadioButton:disabled {\n"
"    background-color: black; /* \347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}"));
        radioButton_HardTrigger->setChecked(true);
        pushButton_SoftTriggerOnce = new QPushButton(groupBox_TriggerSetting);
        pushButton_SoftTriggerOnce->setObjectName(QStringLiteral("pushButton_SoftTriggerOnce"));
        pushButton_SoftTriggerOnce->setEnabled(false);
        pushButton_SoftTriggerOnce->setGeometry(QRect(14, 88, 114, 32));
        pushButton_SoftTriggerOnce->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        label_38 = new QLabel(groupBox_TriggerSetting);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(16, 12, 71, 22));
        label_38->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        groupBox_RoiSetting = new QGroupBox(groupBox_camera);
        groupBox_RoiSetting->setObjectName(QStringLiteral("groupBox_RoiSetting"));
        groupBox_RoiSetting->setEnabled(false);
        groupBox_RoiSetting->setGeometry(QRect(0, 450, 376, 150));
        groupBox_RoiSetting->setStyleSheet(QStringLiteral("border: none;background-color: rgb(42, 41, 41); color:white;"));
        groupBox_RoiSetting->setCheckable(false);
        label_5 = new QLabel(groupBox_RoiSetting);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(16, 55, 16, 16));
        label_5->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_CameraX = new QLineEdit(groupBox_RoiSetting);
        lineEdit_CameraX->setObjectName(QStringLiteral("lineEdit_CameraX"));
        lineEdit_CameraX->setGeometry(QRect(33, 50, 80, 32));
        lineEdit_CameraX->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        label_18 = new QLabel(groupBox_RoiSetting);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(123, 55, 16, 16));
        label_18->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_CameraY = new QLineEdit(groupBox_RoiSetting);
        lineEdit_CameraY->setObjectName(QStringLiteral("lineEdit_CameraY"));
        lineEdit_CameraY->setGeometry(QRect(140, 50, 80, 32));
        lineEdit_CameraY->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        label_20 = new QLabel(groupBox_RoiSetting);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(16, 103, 16, 16));
        label_20->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_CameraW = new QLineEdit(groupBox_RoiSetting);
        lineEdit_CameraW->setObjectName(QStringLiteral("lineEdit_CameraW"));
        lineEdit_CameraW->setGeometry(QRect(33, 98, 80, 32));
        lineEdit_CameraW->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        label_21 = new QLabel(groupBox_RoiSetting);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(123, 103, 16, 16));
        label_21->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_CameraH = new QLineEdit(groupBox_RoiSetting);
        lineEdit_CameraH->setObjectName(QStringLiteral("lineEdit_CameraH"));
        lineEdit_CameraH->setGeometry(QRect(140, 98, 80, 32));
        lineEdit_CameraH->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        pushButton_SetROI = new QPushButton(groupBox_RoiSetting);
        pushButton_SetROI->setObjectName(QStringLiteral("pushButton_SetROI"));
        pushButton_SetROI->setGeometry(QRect(242, 66, 56, 48));
        pushButton_SetROI->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        label_39 = new QLabel(groupBox_RoiSetting);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(16, 12, 71, 22));
        label_39->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        pushButton_zaoshengfenxi = new QPushButton(groupBox_camera);
        pushButton_zaoshengfenxi->setObjectName(QStringLiteral("pushButton_zaoshengfenxi"));
        pushButton_zaoshengfenxi->setGeometry(QRect(20, 0, 114, 32));
        pushButton_zaoshengfenxi->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        checkBox_AutoSave = new QCheckBox(groupBox_camera);
        checkBox_AutoSave->setObjectName(QStringLiteral("checkBox_AutoSave"));
        checkBox_AutoSave->setGeometry(QRect(150, 8, 81, 21));
        checkBox_AutoSave->setStyleSheet(QLatin1String("font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: rgba(255,255,255,0.65);\n"
"line-height: 22px;\n"
"QCheckBox::indicator:checked { background-color: white;}"));
        checkBox_AutoSave->setChecked(false);
        checkBox_AutoSave->setTristate(false);
        pushButton_ChooseSavePath = new QPushButton(groupBox_camera);
        pushButton_ChooseSavePath->setObjectName(QStringLiteral("pushButton_ChooseSavePath"));
        pushButton_ChooseSavePath->setGeometry(QRect(196, 48, 24, 32));
        pushButton_ChooseSavePath->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"border: 1px solid #979797;"));
        lineEdit_SavePath = new QLineEdit(groupBox_camera);
        lineEdit_SavePath->setObjectName(QStringLiteral("lineEdit_SavePath"));
        lineEdit_SavePath->setGeometry(QRect(94, 48, 92, 32));
        lineEdit_SavePath->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        label_19 = new QLabel(groupBox_camera);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(20, 53, 71, 22));
        label_19->setFont(font3);
        label_19->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        pushButton_SavePic = new QPushButton(groupBox_camera);
        pushButton_SavePic->setObjectName(QStringLiteral("pushButton_SavePic"));
        pushButton_SavePic->setEnabled(true);
        pushButton_SavePic->setGeometry(QRect(244, 48, 114, 32));
        pushButton_SavePic->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        label_16 = new QLabel(groupBox_camera);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(16, 605, 71, 22));
        label_16->setStyleSheet(QLatin1String("\n"
"font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_Binning = new QLineEdit(groupBox_camera);
        lineEdit_Binning->setObjectName(QStringLiteral("lineEdit_Binning"));
        lineEdit_Binning->setEnabled(false);
        lineEdit_Binning->setGeometry(QRect(90, 600, 51, 32));
        lineEdit_Binning->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        groupBox = new QGroupBox(groupBox_camera);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(355, 279, 21, 71));
        groupBox->setStyleSheet(QStringLiteral("border: none;background-color: rgb(42, 41, 41); color:white;"));
        label_52 = new QLabel(groupBox);
        label_52->setObjectName(QStringLiteral("label_52"));
        label_52->setGeometry(QRect(16, 12, 71, 20));
        label_52->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        radioButton_Stander = new QRadioButton(groupBox);
        radioButton_Stander->setObjectName(QStringLiteral("radioButton_Stander"));
        radioButton_Stander->setGeometry(QRect(10, 40, 91, 22));
        radioButton_Stander->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
"QRadioButton:disabled {\n"
"    background-color: black; /* \347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}"));
        radioButton_Stander->setChecked(true);
        radioButton_LowNoise14 = new QRadioButton(groupBox);
        radioButton_LowNoise14->setObjectName(QStringLiteral("radioButton_LowNoise14"));
        radioButton_LowNoise14->setGeometry(QRect(120, 40, 101, 22));
        radioButton_LowNoise14->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
"QRadioButton:disabled {\n"
"    background-color: black; /* \347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}"));
        radioButton_LowNoise14->setChecked(false);
        radioButton_LowNoise16 = new QRadioButton(groupBox);
        radioButton_LowNoise16->setObjectName(QStringLiteral("radioButton_LowNoise16"));
        radioButton_LowNoise16->setGeometry(QRect(240, 40, 101, 22));
        radioButton_LowNoise16->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
"QRadioButton:disabled {\n"
"    background-color: black; /* \347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}"));
        radioButton_LowNoise16->setChecked(false);
        groupBox_2 = new QGroupBox(groupBox_camera);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(355, 380, 21, 91));
        groupBox_2->setStyleSheet(QStringLiteral("border: none;background-color: rgb(42, 41, 41); color:white;"));
        label_53 = new QLabel(groupBox_2);
        label_53->setObjectName(QStringLiteral("label_53"));
        label_53->setGeometry(QRect(16, 12, 71, 20));
        label_53->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        radioButton_Gain0 = new QRadioButton(groupBox_2);
        radioButton_Gain0->setObjectName(QStringLiteral("radioButton_Gain0"));
        radioButton_Gain0->setGeometry(QRect(10, 40, 101, 22));
        radioButton_Gain0->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
"QRadioButton:disabled {\n"
"    background-color: black; /* \347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}"));
        radioButton_Gain0->setChecked(false);
        radioButton_Gain1 = new QRadioButton(groupBox_2);
        radioButton_Gain1->setObjectName(QStringLiteral("radioButton_Gain1"));
        radioButton_Gain1->setGeometry(QRect(180, 40, 101, 22));
        radioButton_Gain1->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
"QRadioButton:disabled {\n"
"    background-color: black; /* \347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}"));
        radioButton_Gain1->setChecked(true);
        radioButton_Gain2 = new QRadioButton(groupBox_2);
        radioButton_Gain2->setObjectName(QStringLiteral("radioButton_Gain2"));
        radioButton_Gain2->setGeometry(QRect(10, 70, 101, 22));
        radioButton_Gain2->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
"QRadioButton:disabled {\n"
"    background-color: black; /* \347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}"));
        radioButton_Gain2->setChecked(false);
        radioButton_Gain3 = new QRadioButton(groupBox_2);
        radioButton_Gain3->setObjectName(QStringLiteral("radioButton_Gain3"));
        radioButton_Gain3->setGeometry(QRect(180, 70, 101, 22));
        radioButton_Gain3->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
"QRadioButton:disabled {\n"
"    background-color: black; /* \347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}"));
        radioButton_Gain3->setChecked(false);
        contrastSlider = new QSlider(groupBox_camera);
        contrastSlider->setObjectName(QStringLiteral("contrastSlider"));
        contrastSlider->setEnabled(false);
        contrastSlider->setGeometry(QRect(90, 650, 131, 22));
        contrastSlider->setToolTipDuration(-1);
        contrastSlider->setMaximum(255);
        contrastSlider->setSingleStep(0);
        contrastSlider->setPageStep(0);
        contrastSlider->setValue(128);
        contrastSlider->setOrientation(Qt::Horizontal);
        GammaSlider = new QSlider(groupBox_camera);
        GammaSlider->setObjectName(QStringLiteral("GammaSlider"));
        GammaSlider->setEnabled(false);
        GammaSlider->setGeometry(QRect(90, 690, 131, 22));
        GammaSlider->setMaximum(255);
        GammaSlider->setPageStep(0);
        GammaSlider->setValue(100);
        GammaSlider->setOrientation(Qt::Horizontal);
        label_69 = new QLabel(groupBox_camera);
        label_69->setObjectName(QStringLiteral("label_69"));
        label_69->setGeometry(QRect(10, 650, 71, 22));
        label_69->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_70 = new QLabel(groupBox_camera);
        label_70->setObjectName(QStringLiteral("label_70"));
        label_70->setGeometry(QRect(10, 690, 71, 22));
        label_70->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_ConTrast = new QLineEdit(groupBox_camera);
        lineEdit_ConTrast->setObjectName(QStringLiteral("lineEdit_ConTrast"));
        lineEdit_ConTrast->setEnabled(false);
        lineEdit_ConTrast->setGeometry(QRect(240, 640, 90, 32));
        lineEdit_ConTrast->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        lineEdit_Gamma = new QLineEdit(groupBox_camera);
        lineEdit_Gamma->setObjectName(QStringLiteral("lineEdit_Gamma"));
        lineEdit_Gamma->setEnabled(false);
        lineEdit_Gamma->setGeometry(QRect(240, 690, 90, 32));
        lineEdit_Gamma->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        label_73 = new QLabel(groupBox_camera);
        label_73->setObjectName(QStringLiteral("label_73"));
        label_73->setGeometry(QRect(10, 260, 71, 22));
        label_73->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_Gain = new QLineEdit(groupBox_camera);
        lineEdit_Gain->setObjectName(QStringLiteral("lineEdit_Gain"));
        lineEdit_Gain->setEnabled(false);
        lineEdit_Gain->setGeometry(QRect(240, 250, 90, 32));
        lineEdit_Gain->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        GainSlider = new QSlider(groupBox_camera);
        GainSlider->setObjectName(QStringLiteral("GainSlider"));
        GainSlider->setEnabled(false);
        GainSlider->setGeometry(QRect(90, 260, 131, 22));
        GainSlider->setToolTipDuration(-1);
        GainSlider->setMinimum(1);
        GainSlider->setMaximum(250);
        GainSlider->setSingleStep(0);
        GainSlider->setPageStep(0);
        GainSlider->setValue(1);
        GainSlider->setOrientation(Qt::Horizontal);
        groupBox_Connect = new QGroupBox(QDM_InterfaceClass);
        groupBox_Connect->setObjectName(QStringLiteral("groupBox_Connect"));
        groupBox_Connect->setGeometry(QRect(1520, 100, 376, 271));
        groupBox_Connect->setStyleSheet(QStringLiteral("border: none;background-color: rgb(42, 41, 41); "));
        pushButton_ConnectCamera = new QPushButton(groupBox_Connect);
        pushButton_ConnectCamera->setObjectName(QStringLiteral("pushButton_ConnectCamera"));
        pushButton_ConnectCamera->setGeometry(QRect(0, 0, 114, 32));
        pushButton_ConnectCamera->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"border: 1px solid #07C160;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #07C160;\n"
"border-radius: 2px;\n"
"}"));
        label_3 = new QLabel(groupBox_Connect);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 103, 64, 22));
        label_3->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        comboBox_serialPort = new QComboBox(groupBox_Connect);
        comboBox_serialPort->setObjectName(QStringLiteral("comboBox_serialPort"));
        comboBox_serialPort->setGeometry(QRect(74, 98, 178, 32));
        comboBox_serialPort->setStyleSheet(QLatin1String(".QComboBox {\n"
"  border-radius: 2px;\n"
"  border: 1px solid #979797;\n"
"font-size: 12px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"color: #FFFFFF;\n"
"\n"
"}\n"
"\n"
".QComboBox:checked {\n"
"  border-radius: 2px;\n"
"  border: 2px solid rgba(60,154,232,0.2);\n"
"\n"
"font-size: 12px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"color: #FFFFFF;\n"
"\n"
"}"));
        pushButton_ConnectWave = new QPushButton(groupBox_Connect);
        pushButton_ConnectWave->setObjectName(QStringLiteral("pushButton_ConnectWave"));
        pushButton_ConnectWave->setGeometry(QRect(262, 98, 114, 32));
        pushButton_ConnectWave->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"border: 1px solid #07C160;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #07C160;\n"
"border-radius: 2px;\n"
"}"));
        label_31 = new QLabel(groupBox_Connect);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(0, 155, 64, 22));
        label_31->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        comboBox_Current = new QComboBox(groupBox_Connect);
        comboBox_Current->setObjectName(QStringLiteral("comboBox_Current"));
        comboBox_Current->setGeometry(QRect(74, 150, 178, 32));
        comboBox_Current->setStyleSheet(QLatin1String(".QComboBox {\n"
"  border-radius: 2px;\n"
"  border: 1px solid #979797;\n"
"font-size: 12px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"color: #FFFFFF;\n"
"\n"
"}\n"
"\n"
".QComboBox:checked {\n"
"  border-radius: 2px;\n"
"  border: 2px solid rgba(60,154,232,0.2);\n"
"\n"
"font-size: 12px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"color: #FFFFFF;\n"
"\n"
"}"));
        pushButton_ConnectCurrent = new QPushButton(groupBox_Connect);
        pushButton_ConnectCurrent->setObjectName(QStringLiteral("pushButton_ConnectCurrent"));
        pushButton_ConnectCurrent->setGeometry(QRect(262, 150, 114, 32));
        pushButton_ConnectCurrent->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"border: 1px solid #07C160;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #07C160;\n"
"border-radius: 2px;\n"
"}"));
        pushButton_ConnectPulse = new QPushButton(groupBox_Connect);
        pushButton_ConnectPulse->setObjectName(QStringLiteral("pushButton_ConnectPulse"));
        pushButton_ConnectPulse->setGeometry(QRect(150, 0, 128, 32));
        pushButton_ConnectPulse->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"border: 1px solid #07C160;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #07C160;\n"
"border-radius: 2px;\n"
"}"));
        pushButton_ConnectMotor = new QPushButton(groupBox_Connect);
        pushButton_ConnectMotor->setObjectName(QStringLiteral("pushButton_ConnectMotor"));
        pushButton_ConnectMotor->setGeometry(QRect(0, 50, 114, 32));
        pushButton_ConnectMotor->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"border: 1px solid #07C160;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #07C160;\n"
"border-radius: 2px;\n"
"}"));
        pushButton_ConnectCoilXYZ = new QPushButton(groupBox_Connect);
        pushButton_ConnectCoilXYZ->setObjectName(QStringLiteral("pushButton_ConnectCoilXYZ"));
        pushButton_ConnectCoilXYZ->setGeometry(QRect(150, 50, 130, 32));
        pushButton_ConnectCoilXYZ->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"border: 1px solid #07C160;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #07C160;\n"
"border-radius: 2px;\n"
"}"));
        pushButton_OpenLaser = new QPushButton(groupBox_Connect);
        pushButton_OpenLaser->setObjectName(QStringLiteral("pushButton_OpenLaser"));
        pushButton_OpenLaser->setGeometry(QRect(0, 210, 111, 31));
        pushButton_OpenLaser->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"border: 1px solid #07C160;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #07C160;\n"
"border-radius: 2px;\n"
"}"));
        pushButton_OpenLED = new QPushButton(groupBox_Connect);
        pushButton_OpenLED->setObjectName(QStringLiteral("pushButton_OpenLED"));
        pushButton_OpenLED->setGeometry(QRect(150, 210, 111, 31));
        pushButton_OpenLED->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"border: 1px solid #07C160;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #07C160;\n"
"border-radius: 2px;\n"
"}"));
        label_4 = new QLabel(QDM_InterfaceClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1520, 20, 261, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("Microsoft YaHei"));
        font4.setPointSize(26);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setUnderline(false);
        font4.setWeight(75);
        label_4->setFont(font4);
        label_4->setStyleSheet(QLatin1String("\n"
"color: #FFFFFF;\n"
""));
        groupBox_Gs = new QGroupBox(QDM_InterfaceClass);
        groupBox_Gs->setObjectName(QStringLiteral("groupBox_Gs"));
        groupBox_Gs->setGeometry(QRect(1520, 100, 360, 170));
        groupBox_Gs->setStyleSheet(QStringLiteral("border: none;background-color: rgb(42, 41, 41); "));
        label_AV = new QLabel(groupBox_Gs);
        label_AV->setObjectName(QStringLiteral("label_AV"));
        label_AV->setGeometry(QRect(90, 0, 121, 25));
        label_AV->setStyleSheet(QLatin1String("font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_V = new QLineEdit(groupBox_Gs);
        lineEdit_V->setObjectName(QStringLiteral("lineEdit_V"));
        lineEdit_V->setGeometry(QRect(80, 40, 90, 28));
        lineEdit_V->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        label_32 = new QLabel(groupBox_Gs);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(180, 45, 16, 16));
        label_32->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_A = new QLineEdit(groupBox_Gs);
        lineEdit_A->setObjectName(QStringLiteral("lineEdit_A"));
        lineEdit_A->setGeometry(QRect(80, 75, 90, 28));
        lineEdit_A->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        lineEdit_A->setMaxLength(10);
        lineEdit_A->setFrame(false);
        label_34 = new QLabel(groupBox_Gs);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(180, 80, 16, 16));
        label_34->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        pushButton_CurrentSet = new QPushButton(groupBox_Gs);
        pushButton_CurrentSet->setObjectName(QStringLiteral("pushButton_CurrentSet"));
        pushButton_CurrentSet->setGeometry(QRect(10, 120, 130, 32));
        pushButton_CurrentSet->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_CurrentOut = new QPushButton(groupBox_Gs);
        pushButton_CurrentOut->setObjectName(QStringLiteral("pushButton_CurrentOut"));
        pushButton_CurrentOut->setGeometry(QRect(180, 120, 130, 32));
        pushButton_CurrentOut->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        label_14 = new QLabel(groupBox_Gs);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(0, 0, 80, 22));
        label_14->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_22 = new QLabel(groupBox_Gs);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(0, 40, 80, 22));
        label_22->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_35 = new QLabel(groupBox_Gs);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(0, 80, 80, 22));
        label_35->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        groupBox_wave = new QGroupBox(QDM_InterfaceClass);
        groupBox_wave->setObjectName(QStringLiteral("groupBox_wave"));
        groupBox_wave->setGeometry(QRect(1520, 100, 376, 571));
        groupBox_wave->setStyleSheet(QStringLiteral("border: none;background-color: rgb(42, 41, 41); "));
        groupBox_FreMode = new QGroupBox(groupBox_wave);
        groupBox_FreMode->setObjectName(QStringLiteral("groupBox_FreMode"));
        groupBox_FreMode->setEnabled(false);
        groupBox_FreMode->setGeometry(QRect(0, 0, 376, 128));
        groupBox_FreMode->setStyleSheet(QStringLiteral("border: none;background-color: rgb(42, 41, 41); "));
        radioButton_SweepFreMode = new QRadioButton(groupBox_FreMode);
        radioButton_SweepFreMode->setObjectName(QStringLiteral("radioButton_SweepFreMode"));
        radioButton_SweepFreMode->setGeometry(QRect(14, 44, 79, 22));
        radioButton_SweepFreMode->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
"QRadioButton:disabled {\n"
"    background-color: black; /* \347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}"));
        radioButton_SweepFreMode->setChecked(true);
        radioButton_FixFreMode = new QRadioButton(groupBox_FreMode);
        radioButton_FixFreMode->setObjectName(QStringLiteral("radioButton_FixFreMode"));
        radioButton_FixFreMode->setGeometry(QRect(120, 44, 79, 22));
        radioButton_FixFreMode->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font-size: 14px;\n"
"	font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"	color: rgba(255,255,255);\n"
"    background-color: #808080; /* \346\234\252\351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"    border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QRadioButton:checked {\n"
"    background-color: #FFA500; /* \351\200\211\344\270\255\346\227\266\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
"QRadioButton:disabled {\n"
"    background-color: black; /* \347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}"));
        pushButton_SendWaveMode = new QPushButton(groupBox_FreMode);
        pushButton_SendWaveMode->setObjectName(QStringLiteral("pushButton_SendWaveMode"));
        pushButton_SendWaveMode->setEnabled(false);
        pushButton_SendWaveMode->setGeometry(QRect(19, 76, 160, 32));
        pushButton_SendWaveMode->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        label_40 = new QLabel(groupBox_FreMode);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(16, 12, 101, 22));
        label_40->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        groupBox_SweepFre = new QGroupBox(groupBox_wave);
        groupBox_SweepFre->setObjectName(QStringLiteral("groupBox_SweepFre"));
        groupBox_SweepFre->setEnabled(false);
        groupBox_SweepFre->setGeometry(QRect(0, 138, 376, 261));
        groupBox_SweepFre->setStyleSheet(QStringLiteral("border: none;background-color: rgb(42, 41, 41); "));
        label_24 = new QLabel(groupBox_SweepFre);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(16, 49, 75, 20));
        label_24->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_StartFre = new QLineEdit(groupBox_SweepFre);
        lineEdit_StartFre->setObjectName(QStringLiteral("lineEdit_StartFre"));
        lineEdit_StartFre->setGeometry(QRect(86, 46, 90, 28));
        lineEdit_StartFre->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        label_25 = new QLabel(groupBox_SweepFre);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(182, 49, 32, 22));
        label_25->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_13 = new QLabel(groupBox_SweepFre);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(16, 87, 75, 20));
        label_13->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_EndFre = new QLineEdit(groupBox_SweepFre);
        lineEdit_EndFre->setObjectName(QStringLiteral("lineEdit_EndFre"));
        lineEdit_EndFre->setGeometry(QRect(86, 84, 90, 28));
        lineEdit_EndFre->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        label_23 = new QLabel(groupBox_SweepFre);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(182, 87, 32, 22));
        label_23->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_26 = new QLabel(groupBox_SweepFre);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(16, 125, 75, 20));
        label_26->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_StepFre = new QLineEdit(groupBox_SweepFre);
        lineEdit_StepFre->setObjectName(QStringLiteral("lineEdit_StepFre"));
        lineEdit_StepFre->setGeometry(QRect(86, 122, 90, 28));
        lineEdit_StepFre->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        label_27 = new QLabel(groupBox_SweepFre);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(182, 125, 32, 22));
        label_27->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_33 = new QLabel(groupBox_SweepFre);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(16, 160, 71, 20));
        label_33->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_SweepTimes = new QLineEdit(groupBox_SweepFre);
        lineEdit_SweepTimes->setObjectName(QStringLiteral("lineEdit_SweepTimes"));
        lineEdit_SweepTimes->setEnabled(false);
        lineEdit_SweepTimes->setGeometry(QRect(86, 160, 90, 28));
        lineEdit_SweepTimes->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        pushButton_SendSweepFre = new QPushButton(groupBox_SweepFre);
        pushButton_SendSweepFre->setObjectName(QStringLiteral("pushButton_SendSweepFre"));
        pushButton_SendSweepFre->setGeometry(QRect(19, 200, 160, 32));
        pushButton_SendSweepFre->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        label_41 = new QLabel(groupBox_SweepFre);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(16, 12, 71, 22));
        label_41->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        groupBox_FixFre = new QGroupBox(groupBox_wave);
        groupBox_FixFre->setObjectName(QStringLiteral("groupBox_FixFre"));
        groupBox_FixFre->setEnabled(false);
        groupBox_FixFre->setGeometry(QRect(0, 410, 376, 92));
        groupBox_FixFre->setStyleSheet(QStringLiteral("border: none;background-color: rgb(42, 41, 41); "));
        label_11 = new QLabel(groupBox_FixFre);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(16, 47, 75, 20));
        label_11->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_FixFre = new QLineEdit(groupBox_FixFre);
        lineEdit_FixFre->setObjectName(QStringLiteral("lineEdit_FixFre"));
        lineEdit_FixFre->setGeometry(QRect(86, 44, 90, 28));
        lineEdit_FixFre->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        label_17 = new QLabel(groupBox_FixFre);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(182, 47, 32, 22));
        label_17->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        pushButton_SendFixFre = new QPushButton(groupBox_FixFre);
        pushButton_SendFixFre->setObjectName(QStringLiteral("pushButton_SendFixFre"));
        pushButton_SendFixFre->setGeometry(QRect(230, 42, 116, 32));
        pushButton_SendFixFre->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        label_42 = new QLabel(groupBox_FixFre);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(16, 12, 71, 22));
        label_42->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        pushButton_StartWave = new QPushButton(groupBox_wave);
        pushButton_StartWave->setObjectName(QStringLiteral("pushButton_StartWave"));
        pushButton_StartWave->setEnabled(false);
        pushButton_StartWave->setGeometry(QRect(18, 520, 160, 32));
        pushButton_StartWave->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_ResetWave = new QPushButton(groupBox_wave);
        pushButton_ResetWave->setObjectName(QStringLiteral("pushButton_ResetWave"));
        pushButton_ResetWave->setEnabled(false);
        pushButton_ResetWave->setGeometry(QRect(198, 520, 160, 32));
        pushButton_ResetWave->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        groupBox_pusle = new QGroupBox(QDM_InterfaceClass);
        groupBox_pusle->setObjectName(QStringLiteral("groupBox_pusle"));
        groupBox_pusle->setGeometry(QRect(1520, 100, 360, 51));
        groupBox_pusle->setStyleSheet(QStringLiteral("border: none;background-color: rgb(42, 41, 41); "));
        pushButton_OpenPulseSettingPage = new QPushButton(groupBox_pusle);
        pushButton_OpenPulseSettingPage->setObjectName(QStringLiteral("pushButton_OpenPulseSettingPage"));
        pushButton_OpenPulseSettingPage->setGeometry(QRect(0, 0, 160, 32));
        pushButton_OpenPulseSettingPage->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_ClearPulseManual = new QPushButton(groupBox_pusle);
        pushButton_ClearPulseManual->setObjectName(QStringLiteral("pushButton_ClearPulseManual"));
        pushButton_ClearPulseManual->setGeometry(QRect(180, 0, 160, 32));
        pushButton_ClearPulseManual->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        label_43 = new QLabel(QDM_InterfaceClass);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setGeometry(QRect(920, 610, 71, 22));
        label_43->setFont(font1);
        label_43->setStyleSheet(QLatin1String("width: 114px;\n"
"height: 22px;\n"
"font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 500;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_44 = new QLabel(QDM_InterfaceClass);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setGeometry(QRect(0, 0, 1920, 13));
        label_44->setStyleSheet(QStringLiteral(""));
        frame_7 = new QFrame(QDM_InterfaceClass);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setGeometry(QRect(1170, 760, 354, 272));
        frame_7->setStyleSheet(QLatin1String("\n"
"background: #252525;"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        textEdit_Log = new QTextEdit(frame_7);
        textEdit_Log->setObjectName(QStringLiteral("textEdit_Log"));
        textEdit_Log->setEnabled(true);
        textEdit_Log->setGeometry(QRect(0, 40, 354, 231));
        textEdit_Log->setStyleSheet(QLatin1String("border: none;background-color: rgb(42, 41, 41); \n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        pushButton_ClearLog = new QPushButton(frame_7);
        pushButton_ClearLog->setObjectName(QStringLiteral("pushButton_ClearLog"));
        pushButton_ClearLog->setGeometry(QRect(311, 5, 32, 32));
        pushButton_ClearLog->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"             border-image: url(:/Image/\347\231\275\345\210\240\351\231\244-01.svg);\n"
"}\n"
"QPushButton:Hover{\n"
"			border-image:url(:/Image/\345\210\240\351\231\244.svg);\n"
"\n"
"}\n"
""));
        label_45 = new QLabel(frame_7);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setGeometry(QRect(16, 10, 96, 22));
        label_45->setFont(font3);
        label_45->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        groupBox_coil = new QGroupBox(QDM_InterfaceClass);
        groupBox_coil->setObjectName(QStringLiteral("groupBox_coil"));
        groupBox_coil->setGeometry(QRect(1520, 100, 360, 291));
        groupBox_coil->setStyleSheet(QStringLiteral("border: none;background-color: rgb(42, 41, 41); "));
        label_46 = new QLabel(groupBox_coil);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setGeometry(QRect(10, 10, 41, 28));
        label_46->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_CoilX_V = new QLineEdit(groupBox_coil);
        lineEdit_CoilX_V->setObjectName(QStringLiteral("lineEdit_CoilX_V"));
        lineEdit_CoilX_V->setGeometry(QRect(60, 10, 51, 28));
        lineEdit_CoilX_V->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        label_48 = new QLabel(groupBox_coil);
        label_48->setObjectName(QStringLiteral("label_48"));
        label_48->setGeometry(QRect(10, 60, 41, 28));
        label_48->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_CoilX_A = new QLineEdit(groupBox_coil);
        lineEdit_CoilX_A->setObjectName(QStringLiteral("lineEdit_CoilX_A"));
        lineEdit_CoilX_A->setGeometry(QRect(60, 60, 51, 28));
        lineEdit_CoilX_A->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        pushButton_CoilXSet = new QPushButton(groupBox_coil);
        pushButton_CoilXSet->setObjectName(QStringLiteral("pushButton_CoilXSet"));
        pushButton_CoilXSet->setGeometry(QRect(10, 110, 110, 32));
        pushButton_CoilXSet->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_CoilXOut = new QPushButton(groupBox_coil);
        pushButton_CoilXOut->setObjectName(QStringLiteral("pushButton_CoilXOut"));
        pushButton_CoilXOut->setGeometry(QRect(10, 160, 110, 32));
        pushButton_CoilXOut->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        pushButton_CoilYSet = new QPushButton(groupBox_coil);
        pushButton_CoilYSet->setObjectName(QStringLiteral("pushButton_CoilYSet"));
        pushButton_CoilYSet->setGeometry(QRect(140, 110, 110, 32));
        pushButton_CoilYSet->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        lineEdit_CoilY_V = new QLineEdit(groupBox_coil);
        lineEdit_CoilY_V->setObjectName(QStringLiteral("lineEdit_CoilY_V"));
        lineEdit_CoilY_V->setGeometry(QRect(190, 10, 51, 28));
        lineEdit_CoilY_V->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        lineEdit_CoilY_A = new QLineEdit(groupBox_coil);
        lineEdit_CoilY_A->setObjectName(QStringLiteral("lineEdit_CoilY_A"));
        lineEdit_CoilY_A->setGeometry(QRect(190, 60, 51, 28));
        lineEdit_CoilY_A->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        pushButton_CoilYOut = new QPushButton(groupBox_coil);
        pushButton_CoilYOut->setObjectName(QStringLiteral("pushButton_CoilYOut"));
        pushButton_CoilYOut->setGeometry(QRect(140, 160, 110, 32));
        pushButton_CoilYOut->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        label_49 = new QLabel(groupBox_coil);
        label_49->setObjectName(QStringLiteral("label_49"));
        label_49->setGeometry(QRect(140, 60, 41, 28));
        label_49->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_47 = new QLabel(groupBox_coil);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setGeometry(QRect(140, 10, 41, 28));
        label_47->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        pushButton_CoilZSet = new QPushButton(groupBox_coil);
        pushButton_CoilZSet->setObjectName(QStringLiteral("pushButton_CoilZSet"));
        pushButton_CoilZSet->setGeometry(QRect(260, 110, 110, 32));
        pushButton_CoilZSet->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        lineEdit_CoilZ_V = new QLineEdit(groupBox_coil);
        lineEdit_CoilZ_V->setObjectName(QStringLiteral("lineEdit_CoilZ_V"));
        lineEdit_CoilZ_V->setGeometry(QRect(310, 10, 51, 28));
        lineEdit_CoilZ_V->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        lineEdit_CoilZ_A = new QLineEdit(groupBox_coil);
        lineEdit_CoilZ_A->setObjectName(QStringLiteral("lineEdit_CoilZ_A"));
        lineEdit_CoilZ_A->setGeometry(QRect(310, 60, 51, 28));
        lineEdit_CoilZ_A->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        pushButton_CoilZOut = new QPushButton(groupBox_coil);
        pushButton_CoilZOut->setObjectName(QStringLiteral("pushButton_CoilZOut"));
        pushButton_CoilZOut->setGeometry(QRect(260, 160, 110, 32));
        pushButton_CoilZOut->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        label_50 = new QLabel(groupBox_coil);
        label_50->setObjectName(QStringLiteral("label_50"));
        label_50->setGeometry(QRect(260, 60, 41, 28));
        label_50->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_51 = new QLabel(groupBox_coil);
        label_51->setObjectName(QStringLiteral("label_51"));
        label_51->setGeometry(QRect(260, 10, 41, 28));
        label_51->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_XAV = new QLabel(groupBox_coil);
        label_XAV->setObjectName(QStringLiteral("label_XAV"));
        label_XAV->setGeometry(QRect(20, 200, 211, 21));
        label_XAV->setStyleSheet(QLatin1String("font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_YAV = new QLabel(groupBox_coil);
        label_YAV->setObjectName(QStringLiteral("label_YAV"));
        label_YAV->setGeometry(QRect(20, 230, 201, 21));
        label_YAV->setStyleSheet(QLatin1String("font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_ZAV = new QLabel(groupBox_coil);
        label_ZAV->setObjectName(QStringLiteral("label_ZAV"));
        label_ZAV->setGeometry(QRect(20, 260, 201, 21));
        label_ZAV->setStyleSheet(QLatin1String("font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        layoutWidget = new QWidget(QDM_InterfaceClass);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(1000, 600, 131, 41));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_CamFps_2 = new QLabel(layoutWidget);
        label_CamFps_2->setObjectName(QStringLiteral("label_CamFps_2"));
        label_CamFps_2->setFont(font1);
        label_CamFps_2->setStyleSheet(QLatin1String("width: 114px;\n"
"height: 22px;\n"
"font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 500;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));

        horizontalLayout_10->addWidget(label_CamFps_2);

        label_CamFps = new QLabel(layoutWidget);
        label_CamFps->setObjectName(QStringLiteral("label_CamFps"));
        label_CamFps->setFont(font1);
        label_CamFps->setStyleSheet(QLatin1String("width: 114px;\n"
"height: 22px;\n"
"font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 500;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));

        horizontalLayout_10->addWidget(label_CamFps);

        groupBox_Sensitivity = new QGroupBox(QDM_InterfaceClass);
        groupBox_Sensitivity->setObjectName(QStringLiteral("groupBox_Sensitivity"));
        groupBox_Sensitivity->setGeometry(QRect(1520, 100, 381, 471));
        groupBox_Sensitivity->setStyleSheet(QLatin1String("border: none;\n"
"background-color: rgb(42, 41, 41); "));
        label_54 = new QLabel(groupBox_Sensitivity);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setGeometry(QRect(10, 15, 21, 22));
        label_54->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_55 = new QLabel(groupBox_Sensitivity);
        label_55->setObjectName(QStringLiteral("label_55"));
        label_55->setGeometry(QRect(10, 55, 21, 22));
        label_55->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_56 = new QLabel(groupBox_Sensitivity);
        label_56->setObjectName(QStringLiteral("label_56"));
        label_56->setGeometry(QRect(10, 95, 71, 22));
        label_56->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_57 = new QLabel(groupBox_Sensitivity);
        label_57->setObjectName(QStringLiteral("label_57"));
        label_57->setGeometry(QRect(10, 140, 71, 22));
        label_57->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        pushButton_CalSensitivity = new QPushButton(groupBox_Sensitivity);
        pushButton_CalSensitivity->setObjectName(QStringLiteral("pushButton_CalSensitivity"));
        pushButton_CalSensitivity->setGeometry(QRect(10, 380, 118, 32));
        pushButton_CalSensitivity->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        label_58 = new QLabel(groupBox_Sensitivity);
        label_58->setObjectName(QStringLiteral("label_58"));
        label_58->setGeometry(QRect(10, 185, 71, 22));
        label_58->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_59 = new QLabel(groupBox_Sensitivity);
        label_59->setObjectName(QStringLiteral("label_59"));
        label_59->setGeometry(QRect(10, 305, 71, 22));
        label_59->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_Std = new QLineEdit(groupBox_Sensitivity);
        lineEdit_Std->setObjectName(QStringLiteral("lineEdit_Std"));
        lineEdit_Std->setGeometry(QRect(130, 300, 120, 32));
        lineEdit_Std->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        lineEdit_Std->setAlignment(Qt::AlignCenter);
        lineEdit_K = new QLineEdit(groupBox_Sensitivity);
        lineEdit_K->setObjectName(QStringLiteral("lineEdit_K"));
        lineEdit_K->setGeometry(QRect(130, 340, 120, 32));
        lineEdit_K->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        lineEdit_K->setAlignment(Qt::AlignCenter);
        label_60 = new QLabel(groupBox_Sensitivity);
        label_60->setObjectName(QStringLiteral("label_60"));
        label_60->setGeometry(QRect(10, 345, 71, 22));
        label_60->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        pushButton_CalParams = new QPushButton(groupBox_Sensitivity);
        pushButton_CalParams->setObjectName(QStringLiteral("pushButton_CalParams"));
        pushButton_CalParams->setGeometry(QRect(10, 260, 118, 32));
        pushButton_CalParams->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}\n"
"QPushButton{\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"font-size: 14px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #656565;\n"
"line-height: 17px;\n"
"border: 1px solid #979797;\n"
"}\n"
""));
        label_61 = new QLabel(groupBox_Sensitivity);
        label_61->setObjectName(QStringLiteral("label_61"));
        label_61->setGeometry(QRect(10, 435, 71, 22));
        label_61->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        layoutWidget_2 = new QWidget(groupBox_Sensitivity);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(90, 10, 161, 31));
        gridLayout = new QGridLayout(layoutWidget_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_F0 = new QLineEdit(layoutWidget_2);
        lineEdit_F0->setObjectName(QStringLiteral("lineEdit_F0"));
        lineEdit_F0->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        lineEdit_F0->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_F0, 0, 0, 1, 1);

        label_62 = new QLabel(layoutWidget_2);
        label_62->setObjectName(QStringLiteral("label_62"));
        label_62->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));

        gridLayout->addWidget(label_62, 0, 1, 1, 1);

        layoutWidget_3 = new QWidget(groupBox_Sensitivity);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(90, 50, 161, 31));
        gridLayout_2 = new QGridLayout(layoutWidget_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_F1 = new QLineEdit(layoutWidget_3);
        lineEdit_F1->setObjectName(QStringLiteral("lineEdit_F1"));
        lineEdit_F1->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        lineEdit_F1->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_F1, 0, 0, 1, 1);

        label_63 = new QLabel(layoutWidget_3);
        label_63->setObjectName(QStringLiteral("label_63"));
        label_63->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));

        gridLayout_2->addWidget(label_63, 0, 1, 1, 1);

        layoutWidget_4 = new QWidget(groupBox_Sensitivity);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(90, 90, 161, 31));
        gridLayout_3 = new QGridLayout(layoutWidget_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_KStart = new QLineEdit(layoutWidget_4);
        lineEdit_KStart->setObjectName(QStringLiteral("lineEdit_KStart"));
        lineEdit_KStart->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        lineEdit_KStart->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lineEdit_KStart, 0, 0, 1, 1);

        label_64 = new QLabel(layoutWidget_4);
        label_64->setObjectName(QStringLiteral("label_64"));
        label_64->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));

        gridLayout_3->addWidget(label_64, 0, 1, 1, 1);

        layoutWidget_5 = new QWidget(groupBox_Sensitivity);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(90, 135, 161, 31));
        gridLayout_4 = new QGridLayout(layoutWidget_5);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        lineEdit_KEnd = new QLineEdit(layoutWidget_5);
        lineEdit_KEnd->setObjectName(QStringLiteral("lineEdit_KEnd"));
        lineEdit_KEnd->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        lineEdit_KEnd->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lineEdit_KEnd, 0, 0, 1, 1);

        label_65 = new QLabel(layoutWidget_5);
        label_65->setObjectName(QStringLiteral("label_65"));
        label_65->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));

        gridLayout_4->addWidget(label_65, 0, 1, 1, 1);

        layoutWidget_6 = new QWidget(groupBox_Sensitivity);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(90, 180, 161, 31));
        gridLayout_5 = new QGridLayout(layoutWidget_6);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        lineEdit_Exp = new QLineEdit(layoutWidget_6);
        lineEdit_Exp->setObjectName(QStringLiteral("lineEdit_Exp"));
        lineEdit_Exp->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        lineEdit_Exp->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lineEdit_Exp, 0, 0, 1, 1);

        label_66 = new QLabel(layoutWidget_6);
        label_66->setObjectName(QStringLiteral("label_66"));
        label_66->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));

        gridLayout_5->addWidget(label_66, 0, 1, 1, 1);

        label_67 = new QLabel(groupBox_Sensitivity);
        label_67->setObjectName(QStringLiteral("label_67"));
        label_67->setGeometry(QRect(10, 220, 111, 22));
        label_67->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_OffWaveValue = new QLineEdit(groupBox_Sensitivity);
        lineEdit_OffWaveValue->setObjectName(QStringLiteral("lineEdit_OffWaveValue"));
        lineEdit_OffWaveValue->setGeometry(QRect(130, 220, 120, 32));
        lineEdit_OffWaveValue->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        lineEdit_OffWaveValue->setAlignment(Qt::AlignCenter);
        layoutWidget_7 = new QWidget(groupBox_Sensitivity);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(90, 430, 211, 31));
        gridLayout_6 = new QGridLayout(layoutWidget_7);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        lineEdit_Sensitivity = new QLineEdit(layoutWidget_7);
        lineEdit_Sensitivity->setObjectName(QStringLiteral("lineEdit_Sensitivity"));
        lineEdit_Sensitivity->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        lineEdit_Sensitivity->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(lineEdit_Sensitivity, 0, 0, 1, 1);

        label_68 = new QLabel(layoutWidget_7);
        label_68->setObjectName(QStringLiteral("label_68"));
        label_68->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));

        gridLayout_6->addWidget(label_68, 0, 1, 1, 1);

        layoutWidget1 = new QWidget(groupBox_Sensitivity);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(260, 90, 121, 26));
        gridLayout_7 = new QGridLayout(layoutWidget1);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        label_71 = new QLabel(layoutWidget1);
        label_71->setObjectName(QStringLiteral("label_71"));
        label_71->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));

        gridLayout_7->addWidget(label_71, 0, 0, 1, 1);

        lineEdit_StartY = new QLineEdit(layoutWidget1);
        lineEdit_StartY->setObjectName(QStringLiteral("lineEdit_StartY"));
        lineEdit_StartY->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));

        gridLayout_7->addWidget(lineEdit_StartY, 0, 1, 1, 1);

        layoutWidget2 = new QWidget(groupBox_Sensitivity);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(260, 140, 121, 26));
        gridLayout_8 = new QGridLayout(layoutWidget2);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        label_72 = new QLabel(layoutWidget2);
        label_72->setObjectName(QStringLiteral("label_72"));
        label_72->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));

        gridLayout_8->addWidget(label_72, 0, 0, 1, 1);

        lineEdit_EndY = new QLineEdit(layoutWidget2);
        lineEdit_EndY->setObjectName(QStringLiteral("lineEdit_EndY"));
        lineEdit_EndY->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));

        gridLayout_8->addWidget(lineEdit_EndY, 0, 1, 1, 1);

        label_Point_1 = new QLabel(QDM_InterfaceClass);
        label_Point_1->setObjectName(QStringLiteral("label_Point_1"));
        label_Point_1->setGeometry(QRect(1150, 600, 59, 39));
        label_Point_1->setFont(font1);
        label_Point_1->setStyleSheet(QLatin1String("width: 114px;\n"
"height: 22px;\n"
"font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 500;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        label_Point = new QLabel(QDM_InterfaceClass);
        label_Point->setObjectName(QStringLiteral("label_Point"));
        label_Point->setGeometry(QRect(1215, 602, 111, 39));
        label_Point->setFont(font1);
        label_Point->setStyleSheet(QLatin1String("width: 114px;\n"
"height: 22px;\n"
"font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 500;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        layoutWidget3 = new QWidget(QDM_InterfaceClass);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(1340, 600, 121, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_Point_2 = new QLabel(layoutWidget3);
        label_Point_2->setObjectName(QStringLiteral("label_Point_2"));
        label_Point_2->setFont(font1);
        label_Point_2->setStyleSheet(QLatin1String("width: 114px;\n"
"height: 22px;\n"
"font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 500;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));

        horizontalLayout_2->addWidget(label_Point_2);

        label_GrayValue = new QLabel(layoutWidget3);
        label_GrayValue->setObjectName(QStringLiteral("label_GrayValue"));
        label_GrayValue->setFont(font1);
        label_GrayValue->setStyleSheet(QLatin1String("width: 114px;\n"
"height: 22px;\n"
"font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 500;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));

        horizontalLayout_2->addWidget(label_GrayValue);

        layoutWidget->raise();
        label_Point_1->raise();
        label_Point->raise();
        treeWidget->raise();
        groupBox_pusle->raise();
        groupBox_coil->raise();
        groupBox_MT->raise();
        groupBox_wave->raise();
        label_2->raise();
        widget->raise();
        label_ColorCard->raise();
        graphicsView->raise();
        frame_3->raise();
        frame->raise();
        frame_2->raise();
        frame_4->raise();
        minimizeButton->raise();
        closeButton->raise();
        label_4->raise();
        label_43->raise();
        label_44->raise();
        frame_7->raise();
        layoutWidget->raise();
        groupBox_Gs->raise();
        groupBox_Sensitivity->raise();
        groupBox_camera->raise();
        groupBox_Connect->raise();

        retranslateUi(QDM_InterfaceClass);

        comboBox_serialPort->setCurrentIndex(-1);
        comboBox_Current->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(QDM_InterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *QDM_InterfaceClass)
    {
        QDM_InterfaceClass->setWindowTitle(QApplication::translate("QDM_InterfaceClass", "QDM_Interface", Q_NULLPTR));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->topLevelItem(0);
        ___qtreewidgetitem->setText(0, QApplication::translate("QDM_InterfaceClass", "     \351\200\232\350\256\257\350\256\276\347\275\256", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem1->setText(0, QApplication::translate("QDM_InterfaceClass", "     \347\233\270\346\234\272\350\256\276\347\275\256", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem2->setText(0, QApplication::translate("QDM_InterfaceClass", "     \345\276\256\346\263\242\350\256\276\347\275\256", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem3->setText(0, QApplication::translate("QDM_InterfaceClass", "     \347\224\265\346\234\272\350\256\276\347\275\256", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem4->setText(0, QApplication::translate("QDM_InterfaceClass", "     LED\350\256\276\347\275\256", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget->topLevelItem(5);
        ___qtreewidgetitem5->setText(0, QApplication::translate("QDM_InterfaceClass", "     \350\204\211\345\206\262\350\256\276\347\275\256", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem6 = treeWidget->topLevelItem(6);
        ___qtreewidgetitem6->setText(0, QApplication::translate("QDM_InterfaceClass", "     \347\272\277\345\234\210\347\224\265\346\265\201\350\256\276\347\275\256", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem7 = treeWidget->topLevelItem(7);
        ___qtreewidgetitem7->setText(0, QApplication::translate("QDM_InterfaceClass", "     \347\201\265\346\225\217\345\272\246\350\256\241\347\256\227", Q_NULLPTR));
        treeWidget->setSortingEnabled(__sortingEnabled);

        label_2->setText(QApplication::translate("QDM_InterfaceClass", "\346\211\253\351\242\221ODMR\350\260\261\345\233\276", Q_NULLPTR));
        label_ColorCard->setText(QString());
        pushButton_StartFixFreMeasure->setText(QApplication::translate("QDM_InterfaceClass", "\345\274\200\345\247\213\345\233\272\345\256\232\347\202\271\351\242\221\346\265\213\351\207\217", Q_NULLPTR));
        label->setText(QApplication::translate("QDM_InterfaceClass", "\347\202\271\351\242\221\347\273\223\346\236\234\350\277\255\344\273\243\346\254\241\346\225\260\357\274\232", Q_NULLPTR));
        lineEdit_IterationTime->setText(QApplication::translate("QDM_InterfaceClass", "100", Q_NULLPTR));
        label_8->setText(QApplication::translate("QDM_InterfaceClass", "\345\277\253\351\200\237\345\257\271\346\257\224\345\272\246\346\210\220\345\203\217", Q_NULLPTR));
        pushButton_StopFixFreMeasure->setText(QApplication::translate("QDM_InterfaceClass", "\345\201\234\346\255\242\347\202\271\351\242\221", Q_NULLPTR));
        pushButton_StartFixFreMeasureAllPoint->setText(QApplication::translate("QDM_InterfaceClass", "\345\205\250\351\242\221\346\256\265\347\202\271\351\242\221", Q_NULLPTR));
        checkBox_IsLockIn->setText(QApplication::translate("QDM_InterfaceClass", "\351\224\201\347\233\270\346\226\271\346\263\225", Q_NULLPTR));
        pushButton_StartSweepMeasure->setText(QApplication::translate("QDM_InterfaceClass", "\345\274\200\345\247\213\346\211\253\351\242\221\346\265\213\351\207\217", Q_NULLPTR));
        label_28->setText(QApplication::translate("QDM_InterfaceClass", "\345\256\236\346\227\266ODMR", Q_NULLPTR));
        pushButton_StartAllOut->setText(QApplication::translate("QDM_InterfaceClass", "\344\270\200\351\224\256\350\277\236\346\216\245\350\256\276\345\244\207", Q_NULLPTR));
        label_29->setText(QApplication::translate("QDM_InterfaceClass", "\351\242\221\347\216\207\346\212\223\345\233\276\346\254\241\346\225\260\357\274\232", Q_NULLPTR));
        lineEdit_PicNums->setText(QApplication::translate("QDM_InterfaceClass", "1", Q_NULLPTR));
        radioButton_Mag->setText(QApplication::translate("QDM_InterfaceClass", "\345\201\217\347\275\256\347\243\201\345\234\272", Q_NULLPTR));
        radioButton_NoMag->setText(QApplication::translate("QDM_InterfaceClass", "\346\227\240\345\201\217\347\275\256\347\243\201\345\234\272", Q_NULLPTR));
        pushButton_StopSweepMeasure->setText(QApplication::translate("QDM_InterfaceClass", "\345\201\234\346\255\242\346\211\253\351\242\221", Q_NULLPTR));
        pushButton_OpenColorMapPage->setText(QApplication::translate("QDM_InterfaceClass", "\347\237\242\351\207\217\n"
"\344\274\252\345\275\251\345\233\276", Q_NULLPTR));
        lineEdit_DataDimension->setText(QApplication::translate("QDM_InterfaceClass", "1", Q_NULLPTR));
        pushButton_StartAnalysisNoMag->setText(QApplication::translate("QDM_InterfaceClass", "\345\237\272\345\207\206\347\243\201\345\234\272\345\256\232\351\207\217\345\210\206\346\236\220", Q_NULLPTR));
        pushButton_StartAnalysisWithMag->setText(QApplication::translate("QDM_InterfaceClass", "\345\276\205\346\265\213\347\243\201\345\234\272\345\256\232\351\207\217\345\210\206\346\236\220", Q_NULLPTR));
        radioButton_AnalysisSelf->setText(QApplication::translate("QDM_InterfaceClass", "\350\207\252\350\272\253\345\210\206\346\236\220", Q_NULLPTR));
        radioButton_AnalysisAll->setText(QApplication::translate("QDM_InterfaceClass", "\347\273\274\345\220\210\345\210\206\346\236\220", Q_NULLPTR));
        label_9->setText(QApplication::translate("QDM_InterfaceClass", "\345\271\263\345\235\207\347\273\264\345\272\246", Q_NULLPTR));
        pushButton_StartAllAnalysis->setText(QApplication::translate("QDM_InterfaceClass", "\347\273\274\345\220\210\n"
"\345\210\206\346\236\220", Q_NULLPTR));
        label_30->setText(QApplication::translate("QDM_InterfaceClass", "\347\243\201\345\234\272\345\256\232\351\207\217\345\210\206\346\236\220", Q_NULLPTR));
        label_10->setText(QApplication::translate("QDM_InterfaceClass", "\345\237\272\345\207\206\347\243\201\345\234\272", Q_NULLPTR));
        label_12->setText(QApplication::translate("QDM_InterfaceClass", "\345\276\205\346\265\213\347\243\201\345\234\272", Q_NULLPTR));
        pushButton_ImportPicNoMag->setText(QApplication::translate("QDM_InterfaceClass", "\345\257\274\345\205\245\345\237\272\345\207\206\347\243\201\345\234\272\347\205\247\347\211\207", Q_NULLPTR));
        pushButton_ImportPicWithMag->setText(QApplication::translate("QDM_InterfaceClass", "\345\257\274\345\205\245\345\276\205\346\265\213\347\243\201\345\234\272\347\205\247\347\211\207", Q_NULLPTR));
        pushButton_ImportParaNoMag->setText(QApplication::translate("QDM_InterfaceClass", "\345\257\274\345\205\245\345\210\235\345\247\213\345\217\202\346\225\260", Q_NULLPTR));
        pushButton_ImportParaWithMag->setText(QApplication::translate("QDM_InterfaceClass", "\345\257\274\345\205\245\345\210\235\345\247\213\345\217\202\346\225\260", Q_NULLPTR));
        pushButton_AverODMRNoMag->setText(QApplication::translate("QDM_InterfaceClass", "\346\225\264\344\275\223ODMR\345\210\206\346\236\220", Q_NULLPTR));
        pushButton_AverODMRWithMag->setText(QApplication::translate("QDM_InterfaceClass", "\346\225\264\344\275\223ODMR\345\210\206\346\236\220", Q_NULLPTR));
        pushButton_GetInitParaNoMag->setText(QApplication::translate("QDM_InterfaceClass", "\346\213\237\345\220\210\345\217\202\346\225\260\345\210\206\346\236\220", Q_NULLPTR));
        pushButton_GetInitParaWithMag->setText(QApplication::translate("QDM_InterfaceClass", "\346\213\237\345\220\210\345\217\202\346\225\260\345\210\206\346\236\220", Q_NULLPTR));

        const bool __sortingEnabled1 = tableWidget_ParaWithMag->isSortingEnabled();
        tableWidget_ParaWithMag->setSortingEnabled(false);
        tableWidget_ParaWithMag->setSortingEnabled(__sortingEnabled1);

        pushButton_AnalysisRoi->setText(QApplication::translate("QDM_InterfaceClass", "\347\237\242\351\207\217ROI\350\256\276\347\275\256", Q_NULLPTR));
        pushButton_SaveParaNoMag->setText(QApplication::translate("QDM_InterfaceClass", "save", Q_NULLPTR));
        pushButton_SaveParaWithMag->setText(QApplication::translate("QDM_InterfaceClass", "save", Q_NULLPTR));
        pushButton_loadNoMagData->setText(QApplication::translate("QDM_InterfaceClass", "\350\275\275\345\205\245\345\237\272\345\207\206\346\225\260\346\215\256", Q_NULLPTR));
        pushButton_OpenRoiAnalysePage->setText(QApplication::translate("QDM_InterfaceClass", "\347\246\273\347\272\277ROI\345\210\206\346\236\220", Q_NULLPTR));
        label_15->setText(QApplication::translate("QDM_InterfaceClass", "\347\246\273\347\272\277\345\210\206\346\236\220", Q_NULLPTR));
        minimizeButton->setText(QString());
        closeButton->setText(QString());
        groupBox_MT->setTitle(QString());
        pushButton_FindZero->setText(QApplication::translate("QDM_InterfaceClass", "\346\211\276\351\233\266\347\202\271", Q_NULLPTR));
        pushButton_WriteLoadPos->setText(QApplication::translate("QDM_InterfaceClass", "\350\256\260\345\275\225\344\270\212\346\226\231\344\275\215\347\275\256", Q_NULLPTR));
        pushButton_WriteUnloadPos->setText(QApplication::translate("QDM_InterfaceClass", "\350\256\260\345\275\225\344\270\213\346\226\231\344\275\215\347\275\256", Q_NULLPTR));
        pushButton_MotorStop->setText(QString());
        pushButton_LoadPos->setText(QApplication::translate("QDM_InterfaceClass", "\344\270\212\346\226\231", Q_NULLPTR));
        pushButton_UnlodPos->setText(QApplication::translate("QDM_InterfaceClass", "\344\270\213\346\226\231", Q_NULLPTR));
        lineEdit_RelativeDistance->setText(QApplication::translate("QDM_InterfaceClass", "1", Q_NULLPTR));
        label_7->setText(QApplication::translate("QDM_InterfaceClass", "mm", Q_NULLPTR));
        pushButton_Left->setText(QString());
        pushButton_Forward->setText(QString());
        pushButton_Right->setText(QString());
        pushButton_Up->setText(QString());
        pushButton_Backward->setText(QString());
        pushButton_Down->setText(QString());
        label_MotorPos->setText(QString());
        radioButton_Standard->setText(QApplication::translate("QDM_InterfaceClass", "\346\240\207\345\207\206", Q_NULLPTR));
        radioButton_FineTuning->setText(QApplication::translate("QDM_InterfaceClass", "\345\276\256\350\260\203", Q_NULLPTR));
        groupBox_camera->setTitle(QString());
        groupBox_ExposureSetting->setTitle(QString());
        radioButton_AutoExpo->setText(QApplication::translate("QDM_InterfaceClass", "\350\207\252\345\212\250", Q_NULLPTR));
        radioButton_MannualExpo->setText(QApplication::translate("QDM_InterfaceClass", "\346\211\213\345\212\250", Q_NULLPTR));
        pushButton_autoFindExpTime->setText(QApplication::translate("QDM_InterfaceClass", "\350\207\252\345\212\250\345\257\273\346\211\276\346\233\235\345\205\211", Q_NULLPTR));
        label_6->setText(QApplication::translate("QDM_InterfaceClass", "\346\233\235\345\205\211\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        lineEdit_ExposureTime->setText(QApplication::translate("QDM_InterfaceClass", "20", Q_NULLPTR));
        label_36->setText(QApplication::translate("QDM_InterfaceClass", "ms", Q_NULLPTR));
        label_37->setText(QApplication::translate("QDM_InterfaceClass", "\346\233\235\345\205\211\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_TriggerSetting->setTitle(QString());
        radioButton_ContTrigger->setText(QApplication::translate("QDM_InterfaceClass", "\350\277\236\347\273\255\351\207\207\351\233\206", Q_NULLPTR));
        radioButton_SoftTrigger->setText(QApplication::translate("QDM_InterfaceClass", "\350\275\257\350\247\246\345\217\221", Q_NULLPTR));
        radioButton_HardTrigger->setText(QApplication::translate("QDM_InterfaceClass", "\347\241\254\350\247\246\345\217\221", Q_NULLPTR));
        pushButton_SoftTriggerOnce->setText(QApplication::translate("QDM_InterfaceClass", "\350\275\257\344\273\266\350\247\246\345\217\221\344\270\200\346\254\241", Q_NULLPTR));
        label_38->setText(QApplication::translate("QDM_InterfaceClass", "\350\247\246\345\217\221\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_RoiSetting->setTitle(QString());
        label_5->setText(QApplication::translate("QDM_InterfaceClass", "X", Q_NULLPTR));
        label_18->setText(QApplication::translate("QDM_InterfaceClass", "Y", Q_NULLPTR));
        label_20->setText(QApplication::translate("QDM_InterfaceClass", "W", Q_NULLPTR));
        label_21->setText(QApplication::translate("QDM_InterfaceClass", "H", Q_NULLPTR));
        pushButton_SetROI->setText(QApplication::translate("QDM_InterfaceClass", "\347\241\256\350\256\244\n"
"\350\256\276\347\275\256", Q_NULLPTR));
        label_39->setText(QApplication::translate("QDM_InterfaceClass", "ROI\350\256\276\347\275\256", Q_NULLPTR));
        pushButton_zaoshengfenxi->setText(QApplication::translate("QDM_InterfaceClass", "\345\231\252\345\243\260\345\210\206\346\236\220", Q_NULLPTR));
        checkBox_AutoSave->setText(QApplication::translate("QDM_InterfaceClass", "\350\207\252\345\212\250\344\277\235\345\255\230", Q_NULLPTR));
        pushButton_ChooseSavePath->setText(QApplication::translate("QDM_InterfaceClass", "...", Q_NULLPTR));
        label_19->setText(QApplication::translate("QDM_InterfaceClass", "\344\277\235\345\255\230\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
        pushButton_SavePic->setText(QApplication::translate("QDM_InterfaceClass", "\344\277\235\345\255\230\345\233\276\347\211\207", Q_NULLPTR));
        label_16->setText(QApplication::translate("QDM_InterfaceClass", "\345\203\217\347\264\240\345\220\210\345\271\266", Q_NULLPTR));
        lineEdit_Binning->setText(QApplication::translate("QDM_InterfaceClass", "1", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_52->setText(QApplication::translate("QDM_InterfaceClass", "\351\207\207\351\233\206\346\250\241\345\274\217", Q_NULLPTR));
        radioButton_Stander->setText(QApplication::translate("QDM_InterfaceClass", "\346\240\207\345\207\206\346\250\241\345\274\217", Q_NULLPTR));
        radioButton_LowNoise14->setText(QApplication::translate("QDM_InterfaceClass", "\344\275\216\345\231\252\345\243\26014bit", Q_NULLPTR));
        radioButton_LowNoise16->setText(QApplication::translate("QDM_InterfaceClass", "\344\275\216\345\231\252\345\243\26016bit", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label_53->setText(QApplication::translate("QDM_InterfaceClass", "\345\205\250\345\261\200\345\242\236\347\233\212", Q_NULLPTR));
        radioButton_Gain0->setText(QApplication::translate("QDM_InterfaceClass", "Gain0:3.0e-", Q_NULLPTR));
        radioButton_Gain1->setText(QApplication::translate("QDM_InterfaceClass", "Gain1:1.0e-", Q_NULLPTR));
        radioButton_Gain2->setText(QApplication::translate("QDM_InterfaceClass", "Gain2:0.5e-", Q_NULLPTR));
        radioButton_Gain3->setText(QApplication::translate("QDM_InterfaceClass", "Gain3:0.2e-", Q_NULLPTR));
        label_69->setText(QApplication::translate("QDM_InterfaceClass", "\345\257\271\346\257\224\345\272\246", Q_NULLPTR));
        label_70->setText(QApplication::translate("QDM_InterfaceClass", "gamma", Q_NULLPTR));
        lineEdit_ConTrast->setText(QApplication::translate("QDM_InterfaceClass", "128", Q_NULLPTR));
        lineEdit_Gamma->setText(QApplication::translate("QDM_InterfaceClass", "1", Q_NULLPTR));
        label_73->setText(QApplication::translate("QDM_InterfaceClass", "Gain", Q_NULLPTR));
        lineEdit_Gain->setText(QApplication::translate("QDM_InterfaceClass", "1", Q_NULLPTR));
        groupBox_Connect->setTitle(QString());
        pushButton_ConnectCamera->setText(QApplication::translate("QDM_InterfaceClass", "\350\277\236\346\216\245\347\233\270\346\234\272", Q_NULLPTR));
        label_3->setText(QApplication::translate("QDM_InterfaceClass", "\345\276\256\346\263\242\347\275\221\345\217\243", Q_NULLPTR));
        comboBox_serialPort->setCurrentText(QString());
        pushButton_ConnectWave->setText(QApplication::translate("QDM_InterfaceClass", "\350\277\236\346\216\245\345\276\256\346\263\242", Q_NULLPTR));
        label_31->setText(QApplication::translate("QDM_InterfaceClass", "\345\205\211\346\272\220\344\270\262\345\217\243", Q_NULLPTR));
        comboBox_Current->setCurrentText(QString());
        pushButton_ConnectCurrent->setText(QApplication::translate("QDM_InterfaceClass", "\350\277\236\346\216\245\345\205\211\346\272\220", Q_NULLPTR));
        pushButton_ConnectPulse->setText(QApplication::translate("QDM_InterfaceClass", "\350\277\236\346\216\245\350\204\211\345\206\262\345\215\241", Q_NULLPTR));
        pushButton_ConnectMotor->setText(QApplication::translate("QDM_InterfaceClass", "\350\277\236\346\216\245\347\224\265\346\234\272", Q_NULLPTR));
        pushButton_ConnectCoilXYZ->setText(QApplication::translate("QDM_InterfaceClass", "\350\277\236\346\216\245\347\272\277\345\234\210", Q_NULLPTR));
        pushButton_OpenLaser->setText(QApplication::translate("QDM_InterfaceClass", "\346\211\223\345\274\200\346\277\200\345\205\211", Q_NULLPTR));
        pushButton_OpenLED->setText(QApplication::translate("QDM_InterfaceClass", "\346\211\223\345\274\200Led", Q_NULLPTR));
        label_4->setText(QApplication::translate("QDM_InterfaceClass", "\345\256\275 \345\234\272 \346\223\215 \344\275\234 \347\263\273 \347\273\237", Q_NULLPTR));
        groupBox_Gs->setTitle(QString());
        label_AV->setText(QString());
        lineEdit_V->setText(QApplication::translate("QDM_InterfaceClass", "8", Q_NULLPTR));
        label_32->setText(QApplication::translate("QDM_InterfaceClass", "V", Q_NULLPTR));
        lineEdit_A->setText(QApplication::translate("QDM_InterfaceClass", "6", Q_NULLPTR));
        label_34->setText(QApplication::translate("QDM_InterfaceClass", "A", Q_NULLPTR));
        pushButton_CurrentSet->setText(QApplication::translate("QDM_InterfaceClass", "\350\256\276\345\256\232", Q_NULLPTR));
        pushButton_CurrentOut->setText(QApplication::translate("QDM_InterfaceClass", "\350\276\223\345\207\272", Q_NULLPTR));
        label_14->setText(QApplication::translate("QDM_InterfaceClass", "\345\256\236\346\227\266\346\265\213\351\207\217\345\200\274", Q_NULLPTR));
        label_22->setText(QApplication::translate("QDM_InterfaceClass", "\350\256\276\345\256\232\347\224\265\345\216\213", Q_NULLPTR));
        label_35->setText(QApplication::translate("QDM_InterfaceClass", "\350\256\276\345\256\232\347\224\265\346\265\201", Q_NULLPTR));
        groupBox_wave->setTitle(QString());
        groupBox_FreMode->setTitle(QString());
        radioButton_SweepFreMode->setText(QApplication::translate("QDM_InterfaceClass", "\346\211\253\351\242\221\346\250\241\345\274\217", Q_NULLPTR));
        radioButton_FixFreMode->setText(QApplication::translate("QDM_InterfaceClass", "\347\202\271\351\242\221\346\250\241\345\274\217", Q_NULLPTR));
        pushButton_SendWaveMode->setText(QApplication::translate("QDM_InterfaceClass", "\345\267\245\344\275\234\346\250\241\345\274\217\344\270\213\345\217\221", Q_NULLPTR));
        label_40->setText(QApplication::translate("QDM_InterfaceClass", "\345\267\245\344\275\234\346\250\241\345\274\217\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_SweepFre->setTitle(QString());
        label_24->setText(QApplication::translate("QDM_InterfaceClass", "\350\265\267\345\247\213\351\242\221\347\216\207", Q_NULLPTR));
        lineEdit_StartFre->setText(QApplication::translate("QDM_InterfaceClass", "2.72", Q_NULLPTR));
        label_25->setText(QApplication::translate("QDM_InterfaceClass", "GHz", Q_NULLPTR));
        label_13->setText(QApplication::translate("QDM_InterfaceClass", "\347\273\210\346\255\242\351\242\221\347\216\207", Q_NULLPTR));
        lineEdit_EndFre->setText(QApplication::translate("QDM_InterfaceClass", "3.02", Q_NULLPTR));
        label_23->setText(QApplication::translate("QDM_InterfaceClass", "GHz", Q_NULLPTR));
        label_26->setText(QApplication::translate("QDM_InterfaceClass", "\346\255\245\350\277\233\351\242\221\347\216\207", Q_NULLPTR));
        lineEdit_StepFre->setText(QApplication::translate("QDM_InterfaceClass", "500", Q_NULLPTR));
        label_27->setText(QApplication::translate("QDM_InterfaceClass", "kHz", Q_NULLPTR));
        label_33->setText(QApplication::translate("QDM_InterfaceClass", "\346\211\253\351\242\221\346\254\241\346\225\260", Q_NULLPTR));
        lineEdit_SweepTimes->setText(QApplication::translate("QDM_InterfaceClass", "1", Q_NULLPTR));
        pushButton_SendSweepFre->setText(QApplication::translate("QDM_InterfaceClass", "\346\211\253\351\242\221\345\217\202\346\225\260\344\270\213\345\217\221", Q_NULLPTR));
        label_41->setText(QApplication::translate("QDM_InterfaceClass", "\346\211\253\351\242\221\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_FixFre->setTitle(QString());
        label_11->setText(QApplication::translate("QDM_InterfaceClass", "\345\233\272\345\256\232\351\242\221\347\216\207", Q_NULLPTR));
        lineEdit_FixFre->setText(QApplication::translate("QDM_InterfaceClass", "2.855", Q_NULLPTR));
        label_17->setText(QApplication::translate("QDM_InterfaceClass", "GHz", Q_NULLPTR));
        pushButton_SendFixFre->setText(QApplication::translate("QDM_InterfaceClass", "\347\202\271\351\242\221\345\217\202\346\225\260\344\270\213\345\217\221", Q_NULLPTR));
        label_42->setText(QApplication::translate("QDM_InterfaceClass", "\347\202\271\351\242\221\350\256\276\347\275\256", Q_NULLPTR));
        pushButton_StartWave->setText(QApplication::translate("QDM_InterfaceClass", "\345\220\257\345\212\250\345\276\256\346\263\242\350\276\223\345\207\272", Q_NULLPTR));
        pushButton_ResetWave->setText(QApplication::translate("QDM_InterfaceClass", "\345\276\256\346\263\242\345\201\234\346\255\242\345\217\212\345\244\215\344\275\215", Q_NULLPTR));
        groupBox_pusle->setTitle(QString());
        pushButton_OpenPulseSettingPage->setText(QApplication::translate("QDM_InterfaceClass", "\346\211\223\345\274\200\350\204\211\345\206\262\350\256\276\347\275\256\347\252\227\345\217\243", Q_NULLPTR));
        pushButton_ClearPulseManual->setText(QApplication::translate("QDM_InterfaceClass", "\346\211\213\345\212\250\346\270\205\347\251\272\350\204\211\345\206\262", Q_NULLPTR));
        label_43->setText(QApplication::translate("QDM_InterfaceClass", "\347\201\260\345\272\246\345\233\276", Q_NULLPTR));
        label_44->setText(QString());
        textEdit_Log->setHtml(QApplication::translate("QDM_InterfaceClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI Light'; font-size:14px; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12px;\"><br /></p></body></html>", Q_NULLPTR));
        pushButton_ClearLog->setText(QString());
        label_45->setText(QApplication::translate("QDM_InterfaceClass", "\350\275\257\344\273\266\346\211\247\350\241\214\346\227\245\345\277\227", Q_NULLPTR));
        groupBox_coil->setTitle(QString());
        label_46->setText(QApplication::translate("QDM_InterfaceClass", "X\347\224\265\345\216\213", Q_NULLPTR));
        lineEdit_CoilX_V->setText(QApplication::translate("QDM_InterfaceClass", "42", Q_NULLPTR));
        label_48->setText(QApplication::translate("QDM_InterfaceClass", "X\347\224\265\346\265\201", Q_NULLPTR));
        lineEdit_CoilX_A->setText(QApplication::translate("QDM_InterfaceClass", "0.75", Q_NULLPTR));
        pushButton_CoilXSet->setText(QApplication::translate("QDM_InterfaceClass", "\347\272\277\345\234\210X\350\256\276\345\256\232", Q_NULLPTR));
        pushButton_CoilXOut->setText(QApplication::translate("QDM_InterfaceClass", "\347\272\277\345\234\210X\350\276\223\345\207\272", Q_NULLPTR));
        pushButton_CoilYSet->setText(QApplication::translate("QDM_InterfaceClass", "\347\272\277\345\234\210Y\350\256\276\345\256\232", Q_NULLPTR));
        lineEdit_CoilY_V->setText(QApplication::translate("QDM_InterfaceClass", "42", Q_NULLPTR));
        lineEdit_CoilY_A->setText(QApplication::translate("QDM_InterfaceClass", "0.75", Q_NULLPTR));
        pushButton_CoilYOut->setText(QApplication::translate("QDM_InterfaceClass", "\347\272\277\345\234\210Y\350\276\223\345\207\272", Q_NULLPTR));
        label_49->setText(QApplication::translate("QDM_InterfaceClass", "Y\347\224\265\346\265\201", Q_NULLPTR));
        label_47->setText(QApplication::translate("QDM_InterfaceClass", "Y\347\224\265\345\216\213", Q_NULLPTR));
        pushButton_CoilZSet->setText(QApplication::translate("QDM_InterfaceClass", "\347\272\277\345\234\210Z\350\256\276\345\256\232", Q_NULLPTR));
        lineEdit_CoilZ_V->setText(QApplication::translate("QDM_InterfaceClass", "42", Q_NULLPTR));
        lineEdit_CoilZ_A->setText(QApplication::translate("QDM_InterfaceClass", "0.75", Q_NULLPTR));
        pushButton_CoilZOut->setText(QApplication::translate("QDM_InterfaceClass", "\347\272\277\345\234\210Z\350\276\223\345\207\272", Q_NULLPTR));
        label_50->setText(QApplication::translate("QDM_InterfaceClass", "Z\347\224\265\346\265\201", Q_NULLPTR));
        label_51->setText(QApplication::translate("QDM_InterfaceClass", "Z\347\224\265\345\216\213", Q_NULLPTR));
        label_XAV->setText(QApplication::translate("QDM_InterfaceClass", "X", Q_NULLPTR));
        label_YAV->setText(QApplication::translate("QDM_InterfaceClass", "Y", Q_NULLPTR));
        label_ZAV->setText(QApplication::translate("QDM_InterfaceClass", "Z", Q_NULLPTR));
        label_CamFps_2->setText(QApplication::translate("QDM_InterfaceClass", "FPS\357\274\232", Q_NULLPTR));
        label_CamFps->setText(QString());
        groupBox_Sensitivity->setTitle(QString());
        label_54->setText(QApplication::translate("QDM_InterfaceClass", "f0", Q_NULLPTR));
        label_55->setText(QApplication::translate("QDM_InterfaceClass", "f1", Q_NULLPTR));
        label_56->setText(QApplication::translate("QDM_InterfaceClass", "\347\272\277\346\200\247\350\265\267\347\202\271", Q_NULLPTR));
        label_57->setText(QApplication::translate("QDM_InterfaceClass", "\347\272\277\346\200\247\347\273\210\347\202\271", Q_NULLPTR));
        pushButton_CalSensitivity->setText(QApplication::translate("QDM_InterfaceClass", "\350\256\241\347\256\227\347\201\265\346\225\217\345\272\246", Q_NULLPTR));
        label_58->setText(QApplication::translate("QDM_InterfaceClass", "\346\233\235\345\205\211\346\227\266\351\227\264", Q_NULLPTR));
        label_59->setText(QApplication::translate("QDM_InterfaceClass", "\346\240\207\345\207\206\345\267\256", Q_NULLPTR));
        lineEdit_Std->setText(QApplication::translate("QDM_InterfaceClass", "1", Q_NULLPTR));
        lineEdit_K->setText(QApplication::translate("QDM_InterfaceClass", "1", Q_NULLPTR));
        label_60->setText(QApplication::translate("QDM_InterfaceClass", "\346\226\234\347\216\207", Q_NULLPTR));
        pushButton_CalParams->setText(QApplication::translate("QDM_InterfaceClass", "\350\256\241\347\256\227\345\217\202\346\225\260", Q_NULLPTR));
        label_61->setText(QApplication::translate("QDM_InterfaceClass", "\347\201\265\346\225\217\345\272\246", Q_NULLPTR));
        lineEdit_F0->setText(QApplication::translate("QDM_InterfaceClass", "1", Q_NULLPTR));
        label_62->setText(QApplication::translate("QDM_InterfaceClass", "MHz", Q_NULLPTR));
        lineEdit_F1->setText(QApplication::translate("QDM_InterfaceClass", "1", Q_NULLPTR));
        label_63->setText(QApplication::translate("QDM_InterfaceClass", "MHz", Q_NULLPTR));
        lineEdit_KStart->setText(QApplication::translate("QDM_InterfaceClass", "1", Q_NULLPTR));
        label_64->setText(QApplication::translate("QDM_InterfaceClass", "MHz", Q_NULLPTR));
        lineEdit_KEnd->setText(QApplication::translate("QDM_InterfaceClass", "1", Q_NULLPTR));
        label_65->setText(QApplication::translate("QDM_InterfaceClass", "MHz", Q_NULLPTR));
        lineEdit_Exp->setText(QApplication::translate("QDM_InterfaceClass", "1", Q_NULLPTR));
        label_66->setText(QApplication::translate("QDM_InterfaceClass", "S", Q_NULLPTR));
        label_67->setText(QApplication::translate("QDM_InterfaceClass", "offWave\347\201\260\345\272\246\345\200\274", Q_NULLPTR));
        lineEdit_OffWaveValue->setText(QApplication::translate("QDM_InterfaceClass", "1", Q_NULLPTR));
        lineEdit_Sensitivity->setText(QApplication::translate("QDM_InterfaceClass", "1", Q_NULLPTR));
        label_68->setText(QApplication::translate("QDM_InterfaceClass", "\316\274T", Q_NULLPTR));
        label_71->setText(QApplication::translate("QDM_InterfaceClass", "\350\265\267\347\202\271Y", Q_NULLPTR));
        label_72->setText(QApplication::translate("QDM_InterfaceClass", "\347\273\210\347\202\271Y", Q_NULLPTR));
        label_Point_1->setText(QApplication::translate("QDM_InterfaceClass", "Point\357\274\232", Q_NULLPTR));
        label_Point->setText(QString());
        label_Point_2->setText(QApplication::translate("QDM_InterfaceClass", "\347\201\260\345\272\246\345\200\274", Q_NULLPTR));
        label_GrayValue->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QDM_InterfaceClass: public Ui_QDM_InterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDM_INTERFACE_H
