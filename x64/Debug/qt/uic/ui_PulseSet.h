/********************************************************************************
** Form generated from reading UI file 'PulseSet.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PULSESET_H
#define UI_PULSESET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_PulseSetClass
{
public:
    QCustomPlot *widget;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_startTime0_0;
    QLabel *label_3;
    QLineEdit *lineEdit_ctuTime0_0;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QLineEdit *lineEdit_startTime1_0;
    QLabel *label_7;
    QLineEdit *lineEdit_ctuTime1_0;
    QLabel *label_8;
    QLineEdit *lineEdit_startTime1_1;
    QLabel *label_9;
    QLineEdit *lineEdit_ctuTime1_1;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_5;
    QLabel *label_12;
    QLineEdit *lineEdit_startTime2_0;
    QLabel *label_13;
    QLineEdit *lineEdit_ctuTime2_0;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_cycleTime;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEdit_pulseNumber;
    QPushButton *pushButton_showPulse;
    QPushButton *pushButton_savePulse;
    QPushButton *pushButton_readPulse;

    void setupUi(QDialog *PulseSetClass)
    {
        if (PulseSetClass->objectName().isEmpty())
            PulseSetClass->setObjectName(QStringLiteral("PulseSetClass"));
        PulseSetClass->resize(959, 492);
        PulseSetClass->setStyleSheet(QLatin1String("\n"
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
        widget = new QCustomPlot(PulseSetClass);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(260, 70, 681, 411));
        widget->setStyleSheet(QLatin1String("border: 1px solid #E6E6E6;\n"
""));
        groupBox = new QGroupBox(PulseSetClass);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 231, 461));
        groupBox->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 100, 171, 91));
        groupBox_2->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 131, 58));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_startTime0_0 = new QLineEdit(layoutWidget);
        lineEdit_startTime0_0->setObjectName(QStringLiteral("lineEdit_startTime0_0"));
        lineEdit_startTime0_0->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));

        gridLayout->addWidget(lineEdit_startTime0_0, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_ctuTime0_0 = new QLineEdit(layoutWidget);
        lineEdit_ctuTime0_0->setObjectName(QStringLiteral("lineEdit_ctuTime0_0"));
        lineEdit_ctuTime0_0->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));

        gridLayout->addWidget(lineEdit_ctuTime0_0, 1, 1, 1, 1);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 200, 171, 151));
        groupBox_3->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 131, 120));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_startTime1_0 = new QLineEdit(layoutWidget1);
        lineEdit_startTime1_0->setObjectName(QStringLiteral("lineEdit_startTime1_0"));
        lineEdit_startTime1_0->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));

        gridLayout_3->addWidget(lineEdit_startTime1_0, 0, 1, 1, 1);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_ctuTime1_0 = new QLineEdit(layoutWidget1);
        lineEdit_ctuTime1_0->setObjectName(QStringLiteral("lineEdit_ctuTime1_0"));
        lineEdit_ctuTime1_0->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));

        gridLayout_3->addWidget(lineEdit_ctuTime1_0, 1, 1, 1, 1);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 2, 0, 1, 1);

        lineEdit_startTime1_1 = new QLineEdit(layoutWidget1);
        lineEdit_startTime1_1->setObjectName(QStringLiteral("lineEdit_startTime1_1"));
        lineEdit_startTime1_1->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));

        gridLayout_3->addWidget(lineEdit_startTime1_1, 2, 1, 1, 1);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 3, 0, 1, 1);

        lineEdit_ctuTime1_1 = new QLineEdit(layoutWidget1);
        lineEdit_ctuTime1_1->setObjectName(QStringLiteral("lineEdit_ctuTime1_1"));
        lineEdit_ctuTime1_1->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));

        gridLayout_3->addWidget(lineEdit_ctuTime1_1, 3, 1, 1, 1);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 360, 171, 91));
        groupBox_4->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        layoutWidget_3 = new QWidget(groupBox_4);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 20, 131, 58));
        gridLayout_5 = new QGridLayout(layoutWidget_3);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_5->addWidget(label_12, 0, 0, 1, 1);

        lineEdit_startTime2_0 = new QLineEdit(layoutWidget_3);
        lineEdit_startTime2_0->setObjectName(QStringLiteral("lineEdit_startTime2_0"));
        lineEdit_startTime2_0->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));

        gridLayout_5->addWidget(lineEdit_startTime2_0, 0, 1, 1, 1);

        label_13 = new QLabel(layoutWidget_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_5->addWidget(label_13, 1, 0, 1, 1);

        lineEdit_ctuTime2_0 = new QLineEdit(layoutWidget_3);
        lineEdit_ctuTime2_0->setObjectName(QStringLiteral("lineEdit_ctuTime2_0"));
        lineEdit_ctuTime2_0->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));

        gridLayout_5->addWidget(lineEdit_ctuTime2_0, 1, 1, 1, 1);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 20, 106, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_cycleTime = new QLineEdit(layoutWidget2);
        lineEdit_cycleTime->setObjectName(QStringLiteral("lineEdit_cycleTime"));
        lineEdit_cycleTime->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));

        horizontalLayout->addWidget(lineEdit_cycleTime);

        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 60, 111, 27));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        lineEdit_pulseNumber = new QLineEdit(layoutWidget3);
        lineEdit_pulseNumber->setObjectName(QStringLiteral("lineEdit_pulseNumber"));
        lineEdit_pulseNumber->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,0.3); line-height: 22px; }"));

        horizontalLayout_2->addWidget(lineEdit_pulseNumber);

        pushButton_showPulse = new QPushButton(PulseSetClass);
        pushButton_showPulse->setObjectName(QStringLiteral("pushButton_showPulse"));
        pushButton_showPulse->setGeometry(QRect(260, 30, 100, 30));
        pushButton_showPulse->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}"));
        pushButton_savePulse = new QPushButton(PulseSetClass);
        pushButton_savePulse->setObjectName(QStringLiteral("pushButton_savePulse"));
        pushButton_savePulse->setGeometry(QRect(370, 30, 100, 30));
        pushButton_savePulse->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}"));
        pushButton_readPulse = new QPushButton(PulseSetClass);
        pushButton_readPulse->setObjectName(QStringLiteral("pushButton_readPulse"));
        pushButton_readPulse->setGeometry(QRect(480, 30, 100, 30));
        pushButton_readPulse->setStyleSheet(QLatin1String("QPushButton:Hover\n"
"{\n"
"	border-radius: 2px;\n"
"	border: 1px solid #1765AD;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: #1765AD;\n"
"	border-radius: 2px;\n"
"}"));

        retranslateUi(PulseSetClass);

        QMetaObject::connectSlotsByName(PulseSetClass);
    } // setupUi

    void retranslateUi(QDialog *PulseSetClass)
    {
        PulseSetClass->setWindowTitle(QApplication::translate("PulseSetClass", "PulseSet", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("PulseSetClass", "\350\204\211\345\206\262\350\256\276\347\275\256", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("PulseSetClass", "\345\210\207\351\242\221\350\204\211\345\206\262", Q_NULLPTR));
        label_2->setText(QApplication::translate("PulseSetClass", "\350\265\267\347\202\271/ms", Q_NULLPTR));
        lineEdit_startTime0_0->setText(QApplication::translate("PulseSetClass", "10", Q_NULLPTR));
        label_3->setText(QApplication::translate("PulseSetClass", "\346\214\201\347\273\255/ms", Q_NULLPTR));
        lineEdit_ctuTime0_0->setText(QApplication::translate("PulseSetClass", "10", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("PulseSetClass", "\347\233\270\346\234\272\350\247\246\345\217\221\350\204\211\345\206\262", Q_NULLPTR));
        label_6->setText(QApplication::translate("PulseSetClass", "\350\265\267\347\202\2711/ms", Q_NULLPTR));
        lineEdit_startTime1_0->setText(QApplication::translate("PulseSetClass", "50", Q_NULLPTR));
        label_7->setText(QApplication::translate("PulseSetClass", "\346\214\201\347\273\2551/ms", Q_NULLPTR));
        lineEdit_ctuTime1_0->setText(QApplication::translate("PulseSetClass", "10", Q_NULLPTR));
        label_8->setText(QApplication::translate("PulseSetClass", "\350\265\267\347\202\2712/ms", Q_NULLPTR));
        lineEdit_startTime1_1->setText(QApplication::translate("PulseSetClass", "180", Q_NULLPTR));
        label_9->setText(QApplication::translate("PulseSetClass", "\346\214\201\347\273\2552/ms", Q_NULLPTR));
        lineEdit_ctuTime1_1->setText(QApplication::translate("PulseSetClass", "10", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("PulseSetClass", "\345\276\256\346\263\242\345\274\200\345\205\263\350\204\211\345\206\262", Q_NULLPTR));
        label_12->setText(QApplication::translate("PulseSetClass", "\350\265\267\347\202\271/ms", Q_NULLPTR));
        lineEdit_startTime2_0->setText(QApplication::translate("PulseSetClass", "40", Q_NULLPTR));
        label_13->setText(QApplication::translate("PulseSetClass", "\346\214\201\347\273\255/ms", Q_NULLPTR));
        lineEdit_ctuTime2_0->setText(QApplication::translate("PulseSetClass", "50", Q_NULLPTR));
        label->setText(QApplication::translate("PulseSetClass", "\345\221\250\346\234\237/ms", Q_NULLPTR));
        lineEdit_cycleTime->setText(QApplication::translate("PulseSetClass", "300", Q_NULLPTR));
        label_4->setText(QApplication::translate("PulseSetClass", "\350\204\211\345\206\262\346\254\241\346\225\260", Q_NULLPTR));
        lineEdit_pulseNumber->setText(QApplication::translate("PulseSetClass", "601", Q_NULLPTR));
        pushButton_showPulse->setText(QApplication::translate("PulseSetClass", "\347\241\256\350\256\244\350\204\211\345\206\262", Q_NULLPTR));
        pushButton_savePulse->setText(QApplication::translate("PulseSetClass", "\345\272\217\345\210\227\344\277\235\345\255\230", Q_NULLPTR));
        pushButton_readPulse->setText(QApplication::translate("PulseSetClass", "\345\272\217\345\210\227\350\257\273\345\217\226", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PulseSetClass: public Ui_PulseSetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PULSESET_H
