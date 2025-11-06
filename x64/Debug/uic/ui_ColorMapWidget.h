/********************************************************************************
** Form generated from reading UI file 'ColorMapWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORMAPWIDGET_H
#define UI_COLORMAPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColorMapWidgetClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *label_17;
    QLineEdit *lineEdit_DownValue_2;
    QLabel *label_18;
    QLineEdit *lineEdit_UpperValue_2;
    QPushButton *pushButton_ConfirmColorSetting_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QGraphicsView *graphicsView_1;
    QGraphicsView *graphicsView_2;
    QGraphicsView *graphicsView_3;
    QLabel *label_ColorCard_1;
    QLabel *label_4;
    QGraphicsView *graphicsView_4;
    QLabel *label_ColorCard_2;
    QLabel *label_B;
    QPushButton *pushButton_ChangeBToMat;
    QLabel *label_ColorCard_3;
    QLabel *label_ColorCard_4;
    QLabel *label_X_1;
    QLabel *label_X_2;
    QLabel *label_X_3;
    QLabel *label_X_4;
    QLabel *label_X_5;
    QLabel *label_Y_1;
    QLabel *label_Y_2;
    QLabel *label_Y_3;
    QLabel *label_Y_4;
    QLabel *label_Y_5;
    QLabel *label_Z_1;
    QLabel *label_Z_2;
    QLabel *label_Z_3;
    QLabel *label_Z_4;
    QLabel *label_Z_5;
    QLabel *label_B_1;
    QLabel *label_B_2;
    QLabel *label_B_3;
    QLabel *label_B_4;
    QLabel *label_B_5;
    QLabel *label_19;
    QLabel *label_20;
    QLineEdit *lineEdit_DownValue_3;
    QLineEdit *lineEdit_UpperValue_3;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *lineEdit_DownValue_4;
    QLineEdit *lineEdit_UpperValue_4;
    QLabel *label_16;
    QPushButton *pushButton_ConfirmColorSetting_1;
    QLabel *label_15;
    QLineEdit *lineEdit_UpperValue_1;
    QLineEdit *lineEdit_DownValue_1;
    QPushButton *pushButton_ReadTiff;
    QGroupBox *groupBox;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *lineEdit_1;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QLabel *label_8;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_ImportData;
    QPushButton *pushButton_transimg;
    QPushButton *pushButton_ConfirmColorSetting_3;

    void setupUi(QWidget *ColorMapWidgetClass)
    {
        if (ColorMapWidgetClass->objectName().isEmpty())
            ColorMapWidgetClass->setObjectName(QStringLiteral("ColorMapWidgetClass"));
        ColorMapWidgetClass->resize(1920, 1000);
        ColorMapWidgetClass->setStyleSheet(QLatin1String("\n"
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
"QLabel{\n"
"font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,0.2); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }\n"
"\n"
"QWidget{\n"
"background: #060606;\n"
"}"));
        layoutWidget = new QWidget(ColorMapWidgetClass);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(700, 750, 251, 121));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_3->addWidget(label_17, 0, 0, 1, 3);

        lineEdit_DownValue_2 = new QLineEdit(layoutWidget);
        lineEdit_DownValue_2->setObjectName(QStringLiteral("lineEdit_DownValue_2"));
        lineEdit_DownValue_2->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));

        gridLayout_3->addWidget(lineEdit_DownValue_2, 1, 0, 1, 1);

        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_3->addWidget(label_18, 1, 1, 1, 1);

        lineEdit_UpperValue_2 = new QLineEdit(layoutWidget);
        lineEdit_UpperValue_2->setObjectName(QStringLiteral("lineEdit_UpperValue_2"));
        lineEdit_UpperValue_2->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));

        gridLayout_3->addWidget(lineEdit_UpperValue_2, 1, 2, 1, 1);

        pushButton_ConfirmColorSetting_2 = new QPushButton(layoutWidget);
        pushButton_ConfirmColorSetting_2->setObjectName(QStringLiteral("pushButton_ConfirmColorSetting_2"));
        pushButton_ConfirmColorSetting_2->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}"));

        gridLayout_3->addWidget(pushButton_ConfirmColorSetting_2, 2, 0, 1, 3);

        label = new QLabel(ColorMapWidgetClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 250, 19, 21));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI Light"));
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(ColorMapWidgetClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(660, 250, 18, 21));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(ColorMapWidgetClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1290, 250, 19, 21));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        graphicsView_1 = new QGraphicsView(ColorMapWidgetClass);
        graphicsView_1->setObjectName(QStringLiteral("graphicsView_1"));
        graphicsView_1->setGeometry(QRect(50, 10, 480, 480));
        graphicsView_1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_2 = new QGraphicsView(ColorMapWidgetClass);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(690, 10, 480, 480));
        graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_3 = new QGraphicsView(ColorMapWidgetClass);
        graphicsView_3->setObjectName(QStringLiteral("graphicsView_3"));
        graphicsView_3->setGeometry(QRect(1320, 10, 480, 480));
        graphicsView_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_ColorCard_1 = new QLabel(ColorMapWidgetClass);
        label_ColorCard_1->setObjectName(QStringLiteral("label_ColorCard_1"));
        label_ColorCard_1->setGeometry(QRect(540, 10, 16, 480));
        label_4 = new QLabel(ColorMapWidgetClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 730, 16, 21));
        label_4->setFont(font);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignCenter);
        graphicsView_4 = new QGraphicsView(ColorMapWidgetClass);
        graphicsView_4->setObjectName(QStringLiteral("graphicsView_4"));
        graphicsView_4->setGeometry(QRect(50, 500, 480, 480));
        graphicsView_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_ColorCard_2 = new QLabel(ColorMapWidgetClass);
        label_ColorCard_2->setObjectName(QStringLiteral("label_ColorCard_2"));
        label_ColorCard_2->setGeometry(QRect(1180, 10, 16, 480));
        label_B = new QLabel(ColorMapWidgetClass);
        label_B->setObjectName(QStringLiteral("label_B"));
        label_B->setGeometry(QRect(710, 510, 211, 20));
        pushButton_ChangeBToMat = new QPushButton(ColorMapWidgetClass);
        pushButton_ChangeBToMat->setObjectName(QStringLiteral("pushButton_ChangeBToMat"));
        pushButton_ChangeBToMat->setGeometry(QRect(700, 890, 111, 31));
        pushButton_ChangeBToMat->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}"));
        label_ColorCard_3 = new QLabel(ColorMapWidgetClass);
        label_ColorCard_3->setObjectName(QStringLiteral("label_ColorCard_3"));
        label_ColorCard_3->setGeometry(QRect(1810, 10, 16, 480));
        label_ColorCard_4 = new QLabel(ColorMapWidgetClass);
        label_ColorCard_4->setObjectName(QStringLiteral("label_ColorCard_4"));
        label_ColorCard_4->setGeometry(QRect(540, 500, 16, 480));
        label_X_1 = new QLabel(ColorMapWidgetClass);
        label_X_1->setObjectName(QStringLiteral("label_X_1"));
        label_X_1->setGeometry(QRect(565, 10, 70, 22));
        label_X_2 = new QLabel(ColorMapWidgetClass);
        label_X_2->setObjectName(QStringLiteral("label_X_2"));
        label_X_2->setGeometry(QRect(570, 130, 70, 22));
        label_X_3 = new QLabel(ColorMapWidgetClass);
        label_X_3->setObjectName(QStringLiteral("label_X_3"));
        label_X_3->setGeometry(QRect(570, 250, 70, 22));
        label_X_4 = new QLabel(ColorMapWidgetClass);
        label_X_4->setObjectName(QStringLiteral("label_X_4"));
        label_X_4->setGeometry(QRect(570, 370, 70, 22));
        label_X_5 = new QLabel(ColorMapWidgetClass);
        label_X_5->setObjectName(QStringLiteral("label_X_5"));
        label_X_5->setGeometry(QRect(570, 460, 70, 22));
        label_Y_1 = new QLabel(ColorMapWidgetClass);
        label_Y_1->setObjectName(QStringLiteral("label_Y_1"));
        label_Y_1->setGeometry(QRect(1210, 10, 70, 22));
        label_Y_2 = new QLabel(ColorMapWidgetClass);
        label_Y_2->setObjectName(QStringLiteral("label_Y_2"));
        label_Y_2->setGeometry(QRect(1210, 130, 70, 22));
        label_Y_3 = new QLabel(ColorMapWidgetClass);
        label_Y_3->setObjectName(QStringLiteral("label_Y_3"));
        label_Y_3->setGeometry(QRect(1210, 250, 70, 22));
        label_Y_4 = new QLabel(ColorMapWidgetClass);
        label_Y_4->setObjectName(QStringLiteral("label_Y_4"));
        label_Y_4->setGeometry(QRect(1210, 370, 70, 22));
        label_Y_5 = new QLabel(ColorMapWidgetClass);
        label_Y_5->setObjectName(QStringLiteral("label_Y_5"));
        label_Y_5->setGeometry(QRect(1210, 460, 70, 22));
        label_Z_1 = new QLabel(ColorMapWidgetClass);
        label_Z_1->setObjectName(QStringLiteral("label_Z_1"));
        label_Z_1->setGeometry(QRect(1840, 10, 70, 22));
        label_Z_2 = new QLabel(ColorMapWidgetClass);
        label_Z_2->setObjectName(QStringLiteral("label_Z_2"));
        label_Z_2->setGeometry(QRect(1840, 130, 70, 22));
        label_Z_3 = new QLabel(ColorMapWidgetClass);
        label_Z_3->setObjectName(QStringLiteral("label_Z_3"));
        label_Z_3->setGeometry(QRect(1840, 250, 70, 22));
        label_Z_4 = new QLabel(ColorMapWidgetClass);
        label_Z_4->setObjectName(QStringLiteral("label_Z_4"));
        label_Z_4->setGeometry(QRect(1840, 370, 70, 22));
        label_Z_5 = new QLabel(ColorMapWidgetClass);
        label_Z_5->setObjectName(QStringLiteral("label_Z_5"));
        label_Z_5->setGeometry(QRect(1840, 460, 70, 22));
        label_B_1 = new QLabel(ColorMapWidgetClass);
        label_B_1->setObjectName(QStringLiteral("label_B_1"));
        label_B_1->setGeometry(QRect(570, 510, 70, 22));
        label_B_2 = new QLabel(ColorMapWidgetClass);
        label_B_2->setObjectName(QStringLiteral("label_B_2"));
        label_B_2->setGeometry(QRect(570, 620, 70, 22));
        label_B_3 = new QLabel(ColorMapWidgetClass);
        label_B_3->setObjectName(QStringLiteral("label_B_3"));
        label_B_3->setGeometry(QRect(570, 740, 70, 22));
        label_B_4 = new QLabel(ColorMapWidgetClass);
        label_B_4->setObjectName(QStringLiteral("label_B_4"));
        label_B_4->setGeometry(QRect(570, 850, 70, 22));
        label_B_5 = new QLabel(ColorMapWidgetClass);
        label_B_5->setObjectName(QStringLiteral("label_B_5"));
        label_B_5->setGeometry(QRect(570, 950, 70, 22));
        label_19 = new QLabel(ColorMapWidgetClass);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(940, 610, 17, 21));
        label_20 = new QLabel(ColorMapWidgetClass);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(700, 610, 125, 21));
        lineEdit_DownValue_3 = new QLineEdit(ColorMapWidgetClass);
        lineEdit_DownValue_3->setObjectName(QStringLiteral("lineEdit_DownValue_3"));
        lineEdit_DownValue_3->setGeometry(QRect(830, 610, 100, 24));
        lineEdit_DownValue_3->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));
        lineEdit_UpperValue_3 = new QLineEdit(ColorMapWidgetClass);
        lineEdit_UpperValue_3->setObjectName(QStringLiteral("lineEdit_UpperValue_3"));
        lineEdit_UpperValue_3->setGeometry(QRect(960, 610, 100, 24));
        lineEdit_UpperValue_3->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));
        label_21 = new QLabel(ColorMapWidgetClass);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(940, 660, 17, 21));
        label_22 = new QLabel(ColorMapWidgetClass);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(700, 660, 125, 21));
        lineEdit_DownValue_4 = new QLineEdit(ColorMapWidgetClass);
        lineEdit_DownValue_4->setObjectName(QStringLiteral("lineEdit_DownValue_4"));
        lineEdit_DownValue_4->setGeometry(QRect(830, 660, 100, 24));
        lineEdit_DownValue_4->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));
        lineEdit_UpperValue_4 = new QLineEdit(ColorMapWidgetClass);
        lineEdit_UpperValue_4->setObjectName(QStringLiteral("lineEdit_UpperValue_4"));
        lineEdit_UpperValue_4->setGeometry(QRect(960, 660, 100, 24));
        lineEdit_UpperValue_4->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));
        label_16 = new QLabel(ColorMapWidgetClass);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(937, 560, 17, 21));
        pushButton_ConfirmColorSetting_1 = new QPushButton(ColorMapWidgetClass);
        pushButton_ConfirmColorSetting_1->setObjectName(QStringLiteral("pushButton_ConfirmColorSetting_1"));
        pushButton_ConfirmColorSetting_1->setGeometry(QRect(700, 710, 161, 31));
        pushButton_ConfirmColorSetting_1->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}"));
        label_15 = new QLabel(ColorMapWidgetClass);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(700, 560, 125, 21));
        lineEdit_UpperValue_1 = new QLineEdit(ColorMapWidgetClass);
        lineEdit_UpperValue_1->setObjectName(QStringLiteral("lineEdit_UpperValue_1"));
        lineEdit_UpperValue_1->setGeometry(QRect(960, 560, 100, 24));
        lineEdit_UpperValue_1->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));
        lineEdit_DownValue_1 = new QLineEdit(ColorMapWidgetClass);
        lineEdit_DownValue_1->setObjectName(QStringLiteral("lineEdit_DownValue_1"));
        lineEdit_DownValue_1->setGeometry(QRect(831, 560, 100, 24));
        lineEdit_DownValue_1->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));
        pushButton_ReadTiff = new QPushButton(ColorMapWidgetClass);
        pushButton_ReadTiff->setObjectName(QStringLiteral("pushButton_ReadTiff"));
        pushButton_ReadTiff->setGeometry(QRect(840, 890, 111, 31));
        pushButton_ReadTiff->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}"));
        groupBox = new QGroupBox(ColorMapWidgetClass);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(1640, 780, 221, 201));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 30, 161, 161));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        lineEdit_1 = new QLineEdit(layoutWidget1);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));
        lineEdit_1->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));

        gridLayout->addWidget(lineEdit_1, 0, 1, 1, 1);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget1);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget1);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget1);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));

        gridLayout->addWidget(lineEdit_4, 3, 1, 1, 1);

        pushButton_ImportData = new QPushButton(layoutWidget1);
        pushButton_ImportData->setObjectName(QStringLiteral("pushButton_ImportData"));
        pushButton_ImportData->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}"));

        gridLayout->addWidget(pushButton_ImportData, 4, 0, 1, 2);

        pushButton_transimg = new QPushButton(ColorMapWidgetClass);
        pushButton_transimg->setObjectName(QStringLiteral("pushButton_transimg"));
        pushButton_transimg->setGeometry(QRect(700, 940, 111, 31));
        pushButton_transimg->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}"));
        pushButton_ConfirmColorSetting_3 = new QPushButton(ColorMapWidgetClass);
        pushButton_ConfirmColorSetting_3->setObjectName(QStringLiteral("pushButton_ConfirmColorSetting_3"));
        pushButton_ConfirmColorSetting_3->setGeometry(QRect(840, 940, 111, 31));
        pushButton_ConfirmColorSetting_3->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}"));
        label_16->raise();
        pushButton_ConfirmColorSetting_1->raise();
        label_15->raise();
        lineEdit_UpperValue_1->raise();
        lineEdit_DownValue_1->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        graphicsView_1->raise();
        graphicsView_2->raise();
        graphicsView_3->raise();
        label_ColorCard_1->raise();
        label_4->raise();
        graphicsView_4->raise();
        label_ColorCard_2->raise();
        layoutWidget->raise();
        label_B->raise();
        pushButton_ChangeBToMat->raise();
        label_ColorCard_3->raise();
        label_ColorCard_4->raise();
        label_X_1->raise();
        label_X_2->raise();
        label_X_3->raise();
        label_X_4->raise();
        label_X_5->raise();
        label_Y_1->raise();
        label_Y_2->raise();
        label_Y_3->raise();
        label_Y_4->raise();
        label_Y_5->raise();
        label_Z_1->raise();
        label_Z_2->raise();
        label_Z_3->raise();
        label_Z_4->raise();
        label_Z_5->raise();
        label_B_1->raise();
        label_B_2->raise();
        label_B_3->raise();
        label_B_4->raise();
        label_B_5->raise();
        label_19->raise();
        label_20->raise();
        lineEdit_DownValue_3->raise();
        lineEdit_UpperValue_3->raise();
        label_21->raise();
        label_22->raise();
        lineEdit_DownValue_4->raise();
        lineEdit_UpperValue_4->raise();
        pushButton_ReadTiff->raise();
        groupBox->raise();
        pushButton_transimg->raise();
        pushButton_ConfirmColorSetting_3->raise();

        retranslateUi(ColorMapWidgetClass);

        QMetaObject::connectSlotsByName(ColorMapWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *ColorMapWidgetClass)
    {
        ColorMapWidgetClass->setWindowTitle(QApplication::translate("ColorMapWidgetClass", "ColorMapWidget", Q_NULLPTR));
        label_17->setText(QApplication::translate("ColorMapWidgetClass", "\346\240\207\351\207\217B\344\274\252\345\275\251\345\233\276\346\225\260\345\200\274\344\270\212\344\270\213\351\231\220", Q_NULLPTR));
        lineEdit_DownValue_2->setText(QApplication::translate("ColorMapWidgetClass", "0", Q_NULLPTR));
        label_18->setText(QApplication::translate("ColorMapWidgetClass", "\342\200\224", Q_NULLPTR));
        lineEdit_UpperValue_2->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        pushButton_ConfirmColorSetting_2->setText(QApplication::translate("ColorMapWidgetClass", "\347\241\256\345\256\232\344\274\252\345\275\251\345\233\276\350\256\276\347\275\256", Q_NULLPTR));
        label->setText(QApplication::translate("ColorMapWidgetClass", "BX", Q_NULLPTR));
        label_2->setText(QApplication::translate("ColorMapWidgetClass", "BY", Q_NULLPTR));
        label_3->setText(QApplication::translate("ColorMapWidgetClass", "BZ", Q_NULLPTR));
        label_ColorCard_1->setText(QString());
        label_4->setText(QApplication::translate("ColorMapWidgetClass", "B", Q_NULLPTR));
        label_ColorCard_2->setText(QString());
        label_B->setText(QString());
        pushButton_ChangeBToMat->setText(QApplication::translate("ColorMapWidgetClass", "\345\257\274\345\207\272\344\270\272Tiff", Q_NULLPTR));
        label_ColorCard_3->setText(QString());
        label_ColorCard_4->setText(QString());
        label_X_1->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_X_2->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_X_3->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_X_4->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_X_5->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_Y_1->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_Y_2->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_Y_3->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_Y_4->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_Y_5->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_Z_1->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_Z_2->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_Z_3->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_Z_4->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_Z_5->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_B_1->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_B_2->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_B_3->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_B_4->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_B_5->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_19->setText(QApplication::translate("ColorMapWidgetClass", "\342\200\224", Q_NULLPTR));
        label_20->setText(QApplication::translate("ColorMapWidgetClass", "Y\344\274\252\345\275\251\345\233\276\344\270\212\344\270\213\351\231\220", Q_NULLPTR));
        lineEdit_DownValue_3->setText(QApplication::translate("ColorMapWidgetClass", "0", Q_NULLPTR));
        lineEdit_UpperValue_3->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_21->setText(QApplication::translate("ColorMapWidgetClass", "\342\200\224", Q_NULLPTR));
        label_22->setText(QApplication::translate("ColorMapWidgetClass", "Z\344\274\252\345\275\251\345\233\276\344\270\212\344\270\213\351\231\220", Q_NULLPTR));
        lineEdit_DownValue_4->setText(QApplication::translate("ColorMapWidgetClass", "0", Q_NULLPTR));
        lineEdit_UpperValue_4->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        label_16->setText(QApplication::translate("ColorMapWidgetClass", "\342\200\224", Q_NULLPTR));
        pushButton_ConfirmColorSetting_1->setText(QApplication::translate("ColorMapWidgetClass", "\347\241\256\345\256\232\344\274\252\345\275\251\345\233\276\350\256\276\347\275\256", Q_NULLPTR));
        label_15->setText(QApplication::translate("ColorMapWidgetClass", "X\344\274\252\345\275\251\345\233\276\344\270\212\344\270\213\351\231\220", Q_NULLPTR));
        lineEdit_UpperValue_1->setText(QApplication::translate("ColorMapWidgetClass", "1", Q_NULLPTR));
        lineEdit_DownValue_1->setText(QApplication::translate("ColorMapWidgetClass", "0", Q_NULLPTR));
        pushButton_ReadTiff->setText(QApplication::translate("ColorMapWidgetClass", "\345\257\274\345\205\245Tiff", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ColorMapWidgetClass", "GroupBox", Q_NULLPTR));
        label_5->setText(QApplication::translate("ColorMapWidgetClass", "B1\347\254\246\345\217\267", Q_NULLPTR));
        label_6->setText(QApplication::translate("ColorMapWidgetClass", "B2\347\254\246\345\217\267", Q_NULLPTR));
        label_7->setText(QApplication::translate("ColorMapWidgetClass", "B3\347\254\246\345\217\267", Q_NULLPTR));
        label_8->setText(QApplication::translate("ColorMapWidgetClass", "B4\347\254\246\345\217\267", Q_NULLPTR));
        pushButton_ImportData->setText(QApplication::translate("ColorMapWidgetClass", "\345\257\274\345\205\245\346\225\260\346\215\256", Q_NULLPTR));
        pushButton_transimg->setText(QApplication::translate("ColorMapWidgetClass", "\345\211\215\346\231\257\351\200\217\346\230\216\345\272\246", Q_NULLPTR));
        pushButton_ConfirmColorSetting_3->setText(QApplication::translate("ColorMapWidgetClass", "\345\217\226\346\266\210\351\200\217\346\230\216\345\272\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ColorMapWidgetClass: public Ui_ColorMapWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORMAPWIDGET_H
