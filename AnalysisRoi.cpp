#include "AnalysisRoi.h"

// 初始化静态成员变量
AnalysisRoi* AnalysisRoi::instance = nullptr;

void AnalysisRoi::setRoi()
{
	int x = ui.lineEdit_AnalyRoiX->text().toInt();
	int y = ui.lineEdit_AnalyRoiY->text().toInt();
	int w = ui.lineEdit_AnalyRoiW->text().toInt();
	int h = ui.lineEdit_AnalyRoiH->text().toInt();
	emit getAnalysisRoi(x, y, w, h);
}

void AnalysisRoi::disRoi()
{
	emit cancelAnalysisRoi();
}
