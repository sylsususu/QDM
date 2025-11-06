/********************************************************************************
** Form generated from reading UI file 'AnalysisRoi.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSISROI_H
#define UI_ANALYSISROI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AnalysisRoiClass
{
public:
    QGroupBox *groupBox_AnalyRoiSetting;
    QLabel *label_5;
    QLineEdit *lineEdit_AnalyRoiX;
    QLabel *label_18;
    QLineEdit *lineEdit_AnalyRoiY;
    QLabel *label_20;
    QLineEdit *lineEdit_AnalyRoiW;
    QLabel *label_21;
    QLineEdit *lineEdit_AnalyRoiH;
    QPushButton *pushButton_AnalySetROI;
    QLabel *label_39;
    QPushButton *pushButton_AnalyDisROI;

    void setupUi(QDialog *AnalysisRoiClass)
    {
        if (AnalysisRoiClass->objectName().isEmpty())
            AnalysisRoiClass->setObjectName(QStringLiteral("AnalysisRoiClass"));
        AnalysisRoiClass->resize(320, 148);
        AnalysisRoiClass->setStyleSheet(QLatin1String("\n"
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
        groupBox_AnalyRoiSetting = new QGroupBox(AnalysisRoiClass);
        groupBox_AnalyRoiSetting->setObjectName(QStringLiteral("groupBox_AnalyRoiSetting"));
        groupBox_AnalyRoiSetting->setEnabled(true);
        groupBox_AnalyRoiSetting->setGeometry(QRect(0, 0, 320, 150));
        groupBox_AnalyRoiSetting->setStyleSheet(QStringLiteral("border: none;background-color: rgb(42, 41, 41); color:white;"));
        groupBox_AnalyRoiSetting->setCheckable(false);
        label_5 = new QLabel(groupBox_AnalyRoiSetting);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(16, 55, 16, 16));
        label_5->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_AnalyRoiX = new QLineEdit(groupBox_AnalyRoiSetting);
        lineEdit_AnalyRoiX->setObjectName(QStringLiteral("lineEdit_AnalyRoiX"));
        lineEdit_AnalyRoiX->setEnabled(true);
        lineEdit_AnalyRoiX->setGeometry(QRect(33, 50, 80, 32));
        lineEdit_AnalyRoiX->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        label_18 = new QLabel(groupBox_AnalyRoiSetting);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(123, 55, 16, 16));
        label_18->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_AnalyRoiY = new QLineEdit(groupBox_AnalyRoiSetting);
        lineEdit_AnalyRoiY->setObjectName(QStringLiteral("lineEdit_AnalyRoiY"));
        lineEdit_AnalyRoiY->setEnabled(true);
        lineEdit_AnalyRoiY->setGeometry(QRect(140, 50, 80, 32));
        lineEdit_AnalyRoiY->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        label_20 = new QLabel(groupBox_AnalyRoiSetting);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(16, 103, 16, 16));
        label_20->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_AnalyRoiW = new QLineEdit(groupBox_AnalyRoiSetting);
        lineEdit_AnalyRoiW->setObjectName(QStringLiteral("lineEdit_AnalyRoiW"));
        lineEdit_AnalyRoiW->setGeometry(QRect(33, 98, 80, 32));
        lineEdit_AnalyRoiW->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        label_21 = new QLabel(groupBox_AnalyRoiSetting);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(123, 103, 16, 16));
        label_21->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        lineEdit_AnalyRoiH = new QLineEdit(groupBox_AnalyRoiSetting);
        lineEdit_AnalyRoiH->setObjectName(QStringLiteral("lineEdit_AnalyRoiH"));
        lineEdit_AnalyRoiH->setGeometry(QRect(140, 98, 80, 32));
        lineEdit_AnalyRoiH->setStyleSheet(QLatin1String("QLineEdit:focus { border-radius: 2px; border: 2px solid rgba(60,154,232,1); }\n"
"QLineEdit { border-radius: 2px; border: 1px solid rgba(255,255,255,0.2); }\n"
"QLineEdit { font-size: 14px; font-family: \"Microsoft YaHei UI Light\";\n"
" font-weight: 400; color: rgba(255,255,255,1); line-height: 22px; }"));
        pushButton_AnalySetROI = new QPushButton(groupBox_AnalyRoiSetting);
        pushButton_AnalySetROI->setObjectName(QStringLiteral("pushButton_AnalySetROI"));
        pushButton_AnalySetROI->setEnabled(true);
        pushButton_AnalySetROI->setGeometry(QRect(240, 50, 56, 31));
        pushButton_AnalySetROI->setStyleSheet(QLatin1String("QPushButton:Hover\n"
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
        pushButton_AnalySetROI->setCheckable(true);
        label_39 = new QLabel(groupBox_AnalyRoiSetting);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(16, 12, 131, 22));
        label_39->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: \"Microsoft YaHei UI Light\";\n"
"font-weight: 400;\n"
"color: #FFFFFF;\n"
"line-height: 22px;"));
        pushButton_AnalyDisROI = new QPushButton(groupBox_AnalyRoiSetting);
        pushButton_AnalyDisROI->setObjectName(QStringLiteral("pushButton_AnalyDisROI"));
        pushButton_AnalyDisROI->setEnabled(true);
        pushButton_AnalyDisROI->setGeometry(QRect(240, 100, 56, 31));
        pushButton_AnalyDisROI->setStyleSheet(QLatin1String("QPushButton:Hover\n"
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
        pushButton_AnalyDisROI->setCheckable(true);

        retranslateUi(AnalysisRoiClass);

        QMetaObject::connectSlotsByName(AnalysisRoiClass);
    } // setupUi

    void retranslateUi(QDialog *AnalysisRoiClass)
    {
        AnalysisRoiClass->setWindowTitle(QApplication::translate("AnalysisRoiClass", "AnalysisRoi", Q_NULLPTR));
        groupBox_AnalyRoiSetting->setTitle(QString());
        label_5->setText(QApplication::translate("AnalysisRoiClass", "X", Q_NULLPTR));
        lineEdit_AnalyRoiX->setText(QApplication::translate("AnalysisRoiClass", "0", Q_NULLPTR));
        label_18->setText(QApplication::translate("AnalysisRoiClass", "Y", Q_NULLPTR));
        lineEdit_AnalyRoiY->setText(QApplication::translate("AnalysisRoiClass", "0", Q_NULLPTR));
        label_20->setText(QApplication::translate("AnalysisRoiClass", "W", Q_NULLPTR));
        lineEdit_AnalyRoiW->setText(QApplication::translate("AnalysisRoiClass", "3000", Q_NULLPTR));
        label_21->setText(QApplication::translate("AnalysisRoiClass", "H", Q_NULLPTR));
        lineEdit_AnalyRoiH->setText(QApplication::translate("AnalysisRoiClass", "3000", Q_NULLPTR));
        pushButton_AnalySetROI->setText(QApplication::translate("AnalysisRoiClass", "Roi\350\256\276\347\275\256", Q_NULLPTR));
        label_39->setText(QApplication::translate("AnalysisRoiClass", "\347\237\242\351\207\217\345\210\206\346\236\220ROI\350\256\276\347\275\256", Q_NULLPTR));
        pushButton_AnalyDisROI->setText(QApplication::translate("AnalysisRoiClass", "Roi\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AnalysisRoiClass: public Ui_AnalysisRoiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSISROI_H
