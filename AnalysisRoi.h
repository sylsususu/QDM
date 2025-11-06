#pragma once

#include <QDialog>
#include "ui_AnalysisRoi.h"

class AnalysisRoi : public QDialog
{
	Q_OBJECT

public:
	static AnalysisRoi* getInstance(QWidget *parent = nullptr) {
		if (!instance) {
			instance = new AnalysisRoi(parent);
		}
		return instance;
	}

	void show() {
		// 设置窗口的固定大小
		setFixedSize(320, 150);
		// 设置窗口标志，使窗口保持在最前方
		setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
		// 调用QDialog的show方法显示界面
		QDialog::show();
		
	}

	// 删除拷贝构造函数和赋值运算符重载，以防止外部复制实例
	AnalysisRoi(const AnalysisRoi&) = delete;
	AnalysisRoi& operator=(const AnalysisRoi&) = delete;

private:
	explicit AnalysisRoi(QWidget *parent = nullptr) : QDialog(parent) {
		ui.setupUi(this);
		connect(ui.pushButton_AnalySetROI, &QPushButton::clicked, this, &AnalysisRoi::setRoi);
		connect(ui.pushButton_AnalyDisROI, &QPushButton::clicked, this, &AnalysisRoi::cancelAnalysisRoi);
	}

	~AnalysisRoi() {
		// 私有析构函数
	}
	void setRoi();

	void disRoi();

	Ui::AnalysisRoiClass ui;

	static AnalysisRoi* instance;
signals:
	void getAnalysisRoi(int x, int y, int w,int h);
	void cancelAnalysisRoi();
};