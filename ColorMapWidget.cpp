#include "ColorMapWidget.h"
#include <CameraDataProcess.h>

extern int g_Width;
extern int g_Height;

ColorMapWidget::ColorMapWidget(vector<double> B, vector<double> Bx,
	vector<double> By, vector<double> Bz, int dimension, QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	magValueVec = B;
	magValueVec_x = Bx;
	magValueVec_y = By;
	magValueVec_z = Bz;

	if (magValueVec.size())
	{
		// 找出最小值
		auto minElement = std::min_element(magValueVec.begin(), magValueVec.end());
		double minValue = *minElement;
		// 找出最大值
		auto maxElement = std::max_element(magValueVec.begin(), magValueVec.end());
		double maxValue = *maxElement;
		ui.lineEdit_DownValue_2->setText(QString::number(minValue));
		ui.lineEdit_UpperValue_2->setText(QString::number(maxValue));
	}



	m_scene_1 = new QGraphicsScene(this);
	ui.graphicsView_1->setScene(m_scene_1);
	m_scene_2 = new QGraphicsScene(this);
	ui.graphicsView_2->setScene(m_scene_2);
	m_scene_3 = new QGraphicsScene(this);
	ui.graphicsView_3->setScene(m_scene_3);
	m_scene_4 = new QGraphicsScene(this);
	ui.graphicsView_4->setScene(m_scene_4);

	m_image_item_1 = 0;
	m_image_item_2 = 0;
	m_image_item_3 = 0;
	m_image_item_4 = 0;

	ui.label_ColorCard_1->installEventFilter(this);
	//ui.label_ColorCard_1->hide();
	ui.label_ColorCard_2->installEventFilter(this);
	//ui.label_ColorCard_2->hide();
	ui.label_ColorCard_3->installEventFilter(this);
	ui.label_ColorCard_4->installEventFilter(this);
	ui.graphicsView_1->installEventFilter(this);
	ui.graphicsView_2->installEventFilter(this);
	ui.graphicsView_3->installEventFilter(this);
	ui.graphicsView_4->installEventFilter(this);

	dataDimension = dimension;
	/*height = g_Height;
	width = g_Width;*/
	connect(ui.pushButton_ConfirmColorSetting_1, &QPushButton::clicked, this, &ColorMapWidget::drawColorMap);
	connect(ui.pushButton_ConfirmColorSetting_2, &QPushButton::clicked, this, &ColorMapWidget::drawColorMap);
	connect(ui.pushButton_ConfirmColorSetting_3, &QPushButton::clicked, this, &ColorMapWidget::drawColorMap);
	connect(ui.pushButton_ImportData, &QPushButton::clicked, this, &ColorMapWidget::importData);
	connect(ui.pushButton_ChangeBToMat, &QPushButton::clicked, this, &ColorMapWidget::ChangeBToMat);
	connect(ui.pushButton_ReadTiff, &QPushButton::clicked, this, &ColorMapWidget::readTiff);
	connect(ui.pushButton_transimg, &QPushButton::clicked, this, &ColorMapWidget::transImg);

	

	ui.groupBox->hide();
}

ColorMapWidget::~ColorMapWidget()
{}

void ColorMapWidget::setRawMagValue(std::vector<double> magValueVec, std::vector<double> magValueVec_x, std::vector<double> magValueVec_y, std::vector<double> magValueVec_z)
{

	magValueVec_raw = magValueVec;
	magValueVec_x_raw = magValueVec_x;
	magValueVec_y_raw = magValueVec_y;
	magValueVec_z_raw = magValueVec_z;


	if (magValueVec_x_raw.size())
	{
		// 找出最小值
		auto minElement = std::min_element(magValueVec_x_raw.begin(), magValueVec_x_raw.end());
		double minValue = *minElement;
		// 找出最大值
		auto maxElement = std::max_element(magValueVec_x_raw.begin(), magValueVec_x_raw.end());
		double maxValue = *maxElement;

		double A0 = (maxValue - minValue) / 4;

		double num = maxValue;
		string str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_X_1->setText(QString::number(num));

		num = maxValue - A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_X_2->setText(QString::number(num));

		num = maxValue - 2 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_X_3->setText(QString::number(num));

		num = maxValue - 3 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_X_4->setText(QString::number(num));

		num = maxValue - 4 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_X_5->setText(QString::number(num));

	}
	if (magValueVec_y_raw.size())
	{
		// 找出最小值
		auto minElement = std::min_element(magValueVec_y_raw.begin(), magValueVec_y_raw.end());
		double minValue = *minElement;
		// 找出最大值
		auto maxElement = std::max_element(magValueVec_y_raw.begin(), magValueVec_y_raw.end());
		double maxValue = *maxElement;

		double A0 = (maxValue - minValue) / 4;

		double num = maxValue;
		string str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Y_1->setText(QString::number(num));

		num = maxValue - A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Y_2->setText(QString::number(num));

		num = maxValue - 2 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Y_3->setText(QString::number(num));

		num = maxValue - 3 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Y_4->setText(QString::number(num));

		num = maxValue - 4 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Y_5->setText(QString::number(num));

	}
	if (magValueVec_z_raw.size())
	{
		// 找出最小值
		auto minElement = std::min_element(magValueVec_z_raw.begin(), magValueVec_z_raw.end());
		double minValue = *minElement;
		// 找出最大值
		auto maxElement = std::max_element(magValueVec_z_raw.begin(), magValueVec_z_raw.end());
		double maxValue = *maxElement;

		double A0 = (maxValue - minValue) / 4;

		double num = maxValue;
		string str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Z_1->setText(QString::number(num));

		num = maxValue - A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Z_2->setText(QString::number(num));

		num = maxValue - 2 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Z_3->setText(QString::number(num));

		num = maxValue - 3 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Z_4->setText(QString::number(num));

		num = maxValue - 4 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Z_5->setText(QString::number(num));

	}
	if (magValueVec_raw.size())
	{
		// 找出最小值
		auto minElement = std::min_element(magValueVec_raw.begin(), magValueVec_raw.end());
		double minValue = *minElement;
		// 找出最大值
		auto maxElement = std::max_element(magValueVec_raw.begin(), magValueVec_raw.end());
		double maxValue = *maxElement;

		double A0 = (maxValue - minValue) / 4;

		double num = maxValue;
		string str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_B_1->setText(QString::number(num));

		num = maxValue - A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_B_2->setText(QString::number(num));

		num = maxValue - 2 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_B_3->setText(QString::number(num));

		num = maxValue - 3 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_B_4->setText(QString::number(num));

		num = maxValue - 4 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_B_5->setText(QString::number(num));

	}
}

void ColorMapWidget::ChangeBToMat()
{
	int row = (height) / dataDimension;
	int col = (width) / dataDimension;


	QString filenamex = QFileDialog::getSaveFileName(nullptr, "Save Bx File", "", "TIFF files (*.tiff)");

	if (!filenamex.isEmpty()) {
		if (!filenamex.endsWith(".tiff", Qt::CaseInsensitive)) {
			filenamex += ".tiff";
		}
	}
	QFile filex(filenamex);

	if (filex.open(QIODevice::WriteOnly)) {
		// 文件创建成功
		filex.close();
		// 将vector<double>转换为Mat
		if (magValueVec_x_raw.size())
		{
			cv::Mat B_Mat(magValueVec_x_raw);
			B_Mat = B_Mat.reshape(0, row);
			B_Mat.convertTo(B_Mat, CV_32FC1);
			std::string s(filenamex.toLocal8Bit().constData());
			cv::imwrite(s, B_Mat);
		}
	}
	else {
		// 文件创建失败
		qDebug() << "save B.tiff failure!";
	}




	QString filenamey = QFileDialog::getSaveFileName(nullptr, "Save By File", "", "TIFF files (*.tiff)");

	if (!filenamey.isEmpty()) {
		if (!filenamey.endsWith(".tiff", Qt::CaseInsensitive)) {
			filenamey += ".tiff";
		}
	}
	QFile filey(filenamey);

	if (filey.open(QIODevice::WriteOnly)) {
		// 文件创建成功
		filey.close();
		// 将vector<double>转换为Mat
		if (magValueVec_y_raw.size())
		{
			cv::Mat B_Mat(magValueVec_y_raw);
			B_Mat = B_Mat.reshape(0, row);
			B_Mat.convertTo(B_Mat, CV_32FC1);
			std::string s(filenamey.toLocal8Bit().constData());
			cv::imwrite(s, B_Mat);
		}
	}
	else {
		// 文件创建失败
		qDebug() << "save B.tiff failure!";
	}




	QString filenamez = QFileDialog::getSaveFileName(nullptr, "Save Bz File", "", "TIFF files (*.tiff)");

	if (!filenamez.isEmpty()) {
		if (!filenamez.endsWith(".tiff", Qt::CaseInsensitive)) {
			filenamez += ".tiff";
		}
	}
	QFile filez(filenamez);

	if (filez.open(QIODevice::WriteOnly)) {
		// 文件创建成功
		filez.close();
		// 将vector<double>转换为Mat
		if (magValueVec_z_raw.size())
		{
			cv::Mat B_Mat(magValueVec_z_raw);
			B_Mat = B_Mat.reshape(0, row);
			B_Mat.convertTo(B_Mat, CV_32FC1);
			std::string s(filenamez.toLocal8Bit().constData());
			cv::imwrite(s, B_Mat);
		}
	}
	else {
		// 文件创建失败
		qDebug() << "save B.tiff failure!";
	}




	QString filename = QFileDialog::getSaveFileName(nullptr, "Save B File", "", "TIFF files (*.tiff)");

	if (!filename.isEmpty()) {
		if (!filename.endsWith(".tiff", Qt::CaseInsensitive)) {
			filename += ".tiff";
		}
	}
	QFile file(filename);

	if (file.open(QIODevice::WriteOnly)) {
		// 文件创建成功
		file.close();
		// 将vector<double>转换为Mat
		if (magValueVec_raw.size())
		{
			cv::Mat B_Mat(magValueVec_raw);
			B_Mat = B_Mat.reshape(0, row);
			B_Mat.convertTo(B_Mat, CV_32FC1);
			std::string s(filename.toLocal8Bit().constData());
			cv::imwrite(s, B_Mat);
		}
	}
	else {
		// 文件创建失败
		qDebug() << "save B.tiff failure!";
	}




}

void ColorMapWidget::readTiff()
{
	QString imgPath = QFileDialog::getOpenFileName(nullptr, "Choose Bx Tiff", "", "All Files (*);;Text Files (*.tiff)");

	cv::Mat Bx = cv::imread(QStr2Str(imgPath), cv::IMREAD_UNCHANGED | cv::IMREAD_ANYDEPTH);
	/*g_Width = Bx.cols;
	g_Height = Bx.rows;*/
	width = Bx.cols;
	height = Bx.rows;
	dataDimension = 1;
	scalex = static_cast<float>(width) / dataDimension / ui.graphicsView_1->width();
	scaley = static_cast<float>(height) / dataDimension / ui.graphicsView_1->height();

	magValueVec_x_raw.clear();
	for (int i = 0; i < Bx.rows; ++i) {
		for (int j = 0; j < Bx.cols; ++j) {
			magValueVec_x_raw.push_back(Bx.at<float>(i, j));
		}
	}

	imgPath = QFileDialog::getOpenFileName(nullptr, "Choose By Tiff", "", "All Files (*);;Text Files (*.tiff)");

	cv::Mat By = cv::imread(QStr2Str(imgPath), cv::IMREAD_UNCHANGED | cv::IMREAD_ANYDEPTH);

	magValueVec_y_raw.clear();
	for (int i = 0; i < By.rows; ++i) {
		for (int j = 0; j < By.cols; ++j) {
			magValueVec_y_raw.push_back(By.at<float>(i, j));
		}
	}

	imgPath = QFileDialog::getOpenFileName(nullptr, "Choose Bz Tiff", "", "All Files (*);;Text Files (*.tiff)");

	cv::Mat Bz = cv::imread(QStr2Str(imgPath), cv::IMREAD_UNCHANGED | cv::IMREAD_ANYDEPTH);

	magValueVec_z_raw.clear();
	for (int i = 0; i < Bz.rows; ++i) {
		for (int j = 0; j < Bz.cols; ++j) {
			magValueVec_z_raw.push_back(Bz.at<float>(i, j));
		}
	}

	imgPath = QFileDialog::getOpenFileName(nullptr, "Choose B Tiffs", "", "All Files (*);;Text Files (*.tiff)");

	cv::Mat B = cv::imread(QStr2Str(imgPath), cv::IMREAD_UNCHANGED | cv::IMREAD_ANYDEPTH);

	magValueVec_raw.clear();
	for (int i = 0; i < B.rows; ++i) {
		for (int j = 0; j < B.cols; ++j) {
			magValueVec_raw.push_back(B.at<float>(i, j));
		}
	}

	magValueVec = magValueVec_raw;
	magValueVec_x = magValueVec_x_raw;
	magValueVec_y = magValueVec_y_raw;
	magValueVec_z = magValueVec_z_raw;
	//增加对比度矢量的归一化处理
	std::vector<double>::iterator max_it, min_it;
	double dis, dis_X, dis_Y, dis_Z;
	double minValue, minValue_X, minValue_Y, minValue_Z;

	max_it = std::max_element(magValueVec.begin(), magValueVec.end());
	min_it = std::min_element(magValueVec.begin(), magValueVec.end());
	minValue = *min_it;
	dis = (*max_it) - (*min_it);

	max_it = std::max_element(magValueVec_x.begin(), magValueVec_x.end());
	min_it = std::min_element(magValueVec_x.begin(), magValueVec_x.end());
	minValue_X = *min_it;
	dis_X = (*max_it) - (*min_it);

	max_it = std::max_element(magValueVec_y.begin(), magValueVec_y.end());
	min_it = std::min_element(magValueVec_y.begin(), magValueVec_y.end());
	minValue_Y = *min_it;
	dis_Y = (*max_it) - (*min_it);

	max_it = std::max_element(magValueVec_z.begin(), magValueVec_z.end());
	min_it = std::min_element(magValueVec_z.begin(), magValueVec_z.end());
	minValue_Z = *min_it;
	dis_Z = (*max_it) - (*min_it);


	for (int i = 0; i < magValueVec.size(); i++)
	{
		magValueVec[i] = (magValueVec[i] - minValue) / dis;
		magValueVec_x[i] = (magValueVec_x[i] - minValue_X) / dis_X;
		magValueVec_y[i] = (magValueVec_y[i] - minValue_Y) / dis_Y;
		magValueVec_z[i] = (magValueVec_z[i] - minValue_Z) / dis_Z;
	}

	if (magValueVec_x_raw.size())
	{
		// 找出最小值
		auto minElement = std::min_element(magValueVec_x_raw.begin(), magValueVec_x_raw.end());
		double minValue = *minElement;
		// 找出最大值
		auto maxElement = std::max_element(magValueVec_x_raw.begin(), magValueVec_x_raw.end());
		double maxValue = *maxElement;

		double A0 = (maxValue - minValue) / 4;

		double num = maxValue;
		string str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_X_1->setText(QString::number(num));

		num = maxValue - A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_X_2->setText(QString::number(num));

		num = maxValue - 2 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_X_3->setText(QString::number(num));

		num = maxValue - 3 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_X_4->setText(QString::number(num));

		num = maxValue - 4 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_X_5->setText(QString::number(num));

	}
	if (magValueVec_y_raw.size())
	{
		// 找出最小值
		auto minElement = std::min_element(magValueVec_y_raw.begin(), magValueVec_y_raw.end());
		double minValue = *minElement;
		// 找出最大值
		auto maxElement = std::max_element(magValueVec_y_raw.begin(), magValueVec_y_raw.end());
		double maxValue = *maxElement;

		double A0 = (maxValue - minValue) / 4;

		double num = maxValue;
		string str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Y_1->setText(QString::number(num));

		num = maxValue - A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Y_2->setText(QString::number(num));

		num = maxValue - 2 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Y_3->setText(QString::number(num));

		num = maxValue - 3 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Y_4->setText(QString::number(num));

		num = maxValue - 4 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Y_5->setText(QString::number(num));

	}
	if (magValueVec_z_raw.size())
	{
		// 找出最小值
		auto minElement = std::min_element(magValueVec_z_raw.begin(), magValueVec_z_raw.end());
		double minValue = *minElement;
		// 找出最大值
		auto maxElement = std::max_element(magValueVec_z_raw.begin(), magValueVec_z_raw.end());
		double maxValue = *maxElement;

		double A0 = (maxValue - minValue) / 4;

		double num = maxValue;
		string str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Z_1->setText(QString::number(num));

		num = maxValue - A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Z_2->setText(QString::number(num));

		num = maxValue - 2 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Z_3->setText(QString::number(num));

		num = maxValue - 3 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Z_4->setText(QString::number(num));

		num = maxValue - 4 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Z_5->setText(QString::number(num));

	}
	if (magValueVec_raw.size())
	{
		// 找出最小值
		auto minElement = std::min_element(magValueVec_raw.begin(), magValueVec_raw.end());
		double minValue = *minElement;
		// 找出最大值
		auto maxElement = std::max_element(magValueVec_raw.begin(), magValueVec_raw.end());
		double maxValue = *maxElement;

		double A0 = (maxValue - minValue) / 4;

		double num = maxValue;
		string str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_B_1->setText(QString::number(num));

		num = maxValue - A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_B_2->setText(QString::number(num));

		num = maxValue - 2 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_B_3->setText(QString::number(num));

		num = maxValue - 3 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_B_4->setText(QString::number(num));

		num = maxValue - 4 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_B_5->setText(QString::number(num));

	}

	drawColorMap();
}

void ColorMapWidget::transImg()
{
	QString backgroundimagePath = QFileDialog::getOpenFileName(nullptr, "选择背景图片", "", "All Files (*);;Text Files (*.tiff)");
	cv::Mat backMat = cv::imread(QStr2Str(backgroundimagePath), cv::IMREAD_UNCHANGED | cv::IMREAD_ANYDEPTH);
	if (!backMat.empty())
	{
		cv::normalize(backMat, backMat, 0, 1, cv::NORM_MINMAX);
		backMat.convertTo(backMat, CV_8U, 255.0);
		cv::resize(backMat, backMat, cv::Size(width / dataDimension, height / dataDimension));

		QImage backimage(backMat.cols, backMat.rows, QImage::Format_ARGB32);
		for (int i = 0; i < backMat.rows; i++)
		{
			const uchar* p = backMat.ptr<uchar>(i);
			QRgb *q = (QRgb*)backimage.scanLine(i);
			for (int j = 0; j < backMat.cols; j++)
			{
				q[j] = qRgba(p[j], p[j], p[j], 255);
			}
		}

		QImage B = imgB;//伪彩imgB
		QImage forwardimage = B.convertToFormat(QImage::Format_ARGB32);
		for (int y = 0; y < forwardimage.height(); ++y) {
			QRgb *scanLine = reinterpret_cast<QRgb*>(forwardimage.scanLine(y));
			for (int x = 0; x < forwardimage.width(); ++x) {
				QRgb color = scanLine[x];
				int alpha = qAlpha(color) * 0.4; // 40% opacity
				scanLine[x] = qRgba(qRed(color), qGreen(color), qBlue(color), alpha);
			}
		}

		// 创建一个新的QImage对象用于存储叠加后的图像
		QImage resultB(backimage.size(), QImage::Format_ARGB32);
		resultB.fill(Qt::transparent); // 填充透明背景
		// 将两张图像叠加在一起
		QPainter painter(&resultB);
		painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
		painter.drawImage(0, 0, backimage);
		painter.drawImage(0, 0, forwardimage);
		painter.end();
		//show
		QImage imgScaled = resultB.scaled(ui.graphicsView_1->width(), ui.graphicsView_1->height());
		m_image_item_4 = m_scene_4->addPixmap(QPixmap::fromImage(imgScaled));

		////////////////////BX
		B = imgBx;//伪彩imgB
		forwardimage = B.convertToFormat(QImage::Format_ARGB32);
		for (int y = 0; y < forwardimage.height(); ++y) {
			QRgb *scanLine = reinterpret_cast<QRgb*>(forwardimage.scanLine(y));
			for (int x = 0; x < forwardimage.width(); ++x) {
				QRgb color = scanLine[x];
				int alpha = qAlpha(color) * 0.4; // 40% opacity
				scanLine[x] = qRgba(qRed(color), qGreen(color), qBlue(color), alpha);
			}
		}

		// 创建一个新的QImage对象用于存储叠加后的图像
		QImage resultBx(backimage.size(), QImage::Format_ARGB32);
		resultBx.fill(Qt::transparent); // 填充透明背景
		// 将两张图像叠加在一起
		QPainter painterx(&resultBx);
		painterx.setCompositionMode(QPainter::CompositionMode_SourceOver);
		painterx.drawImage(0, 0, backimage);
		painterx.drawImage(0, 0, forwardimage);
		painterx.end();
		//show
		imgScaled = resultBx.scaled(ui.graphicsView_1->width(), ui.graphicsView_1->height());
		m_image_item_1 = m_scene_1->addPixmap(QPixmap::fromImage(imgScaled));
		////////////////////By
		B = imgBy;//伪彩imgB
		forwardimage = B.convertToFormat(QImage::Format_ARGB32);
		for (int y = 0; y < forwardimage.height(); ++y) {
			QRgb *scanLine = reinterpret_cast<QRgb*>(forwardimage.scanLine(y));
			for (int x = 0; x < forwardimage.width(); ++x) {
				QRgb color = scanLine[x];
				int alpha = qAlpha(color) * 0.4; // 40% opacity
				scanLine[x] = qRgba(qRed(color), qGreen(color), qBlue(color), alpha);
			}
		}

		// 创建一个新的QImage对象用于存储叠加后的图像
		QImage resultBy(backimage.size(), QImage::Format_ARGB32);
		resultBy.fill(Qt::transparent); // 填充透明背景
		// 将两张图像叠加在一起
		QPainter paintery(&resultBy);
		paintery.setCompositionMode(QPainter::CompositionMode_SourceOver);
		paintery.drawImage(0, 0, backimage);
		paintery.drawImage(0, 0, forwardimage);
		paintery.end();
		//show
		imgScaled = resultBy.scaled(ui.graphicsView_1->width(), ui.graphicsView_1->height());
		m_image_item_2 = m_scene_2->addPixmap(QPixmap::fromImage(imgScaled));
		////////////////////Bz
		B = imgBz;//伪彩imgB
		forwardimage = B.convertToFormat(QImage::Format_ARGB32);
		for (int y = 0; y < forwardimage.height(); ++y) {
			QRgb *scanLine = reinterpret_cast<QRgb*>(forwardimage.scanLine(y));
			for (int x = 0; x < forwardimage.width(); ++x) {
				QRgb color = scanLine[x];
				int alpha = qAlpha(color) * 0.4; // 40% opacity
				scanLine[x] = qRgba(qRed(color), qGreen(color), qBlue(color), alpha);
			}
		}

		// 创建一个新的QImage对象用于存储叠加后的图像
		QImage resultBz(backimage.size(), QImage::Format_ARGB32);
		resultBz.fill(Qt::transparent); // 填充透明背景
		// 将两张图像叠加在一起
		QPainter painterz(&resultBz);
		painterz.setCompositionMode(QPainter::CompositionMode_SourceOver);
		painterz.drawImage(0, 0, backimage);
		painterz.drawImage(0, 0, forwardimage);
		painterz.end();
		//show
		imgScaled = resultBz.scaled(ui.graphicsView_1->width(), ui.graphicsView_1->height());
		m_image_item_3 = m_scene_3->addPixmap(QPixmap::fromImage(imgScaled));

	}
}

void ColorMapWidget::setHW(int h, int w)
{
	height = h;
	width = w;
	scalex = static_cast<float>(width) / dataDimension / ui.graphicsView_1->width();
	scaley = static_cast<float>(height) / dataDimension / ui.graphicsView_1->height();
}

bool ColorMapWidget::eventFilter(QObject * obj, QEvent * event)
{


	if (obj == ui.label_ColorCard_1 && event->type() == QEvent::Paint)
	{
		///EventFilter中的QPainter设备是需要监视的对象，不能是this父窗口
		//QPainter painter(this);
		QPainter painter(ui.label_ColorCard_1);
		painter.setRenderHint(QPainter::Antialiasing);//反锯齿
		/*int x = ui.label_ColorCard->x();
		int y = ui.label_ColorCard->y();*/
		int x = 0;
		int y = 0;
		int w = ui.label_ColorCard_1->rect().width();
		int h = ui.label_ColorCard_1->rect().height();
		QLinearGradient linearGradient(x, y, x, y + h);//渐变区域
		linearGradient.setColorAt(0, Qt::red);
		linearGradient.setColorAt(0.33, Qt::yellow);
		linearGradient.setColorAt(0.66, Qt::green);
		linearGradient.setColorAt(1, Qt::blue);
		painter.setBrush(linearGradient);//设置画刷，则painter.drawRect(rect());绘制出渐变背景
		painter.drawRect(QRect(x, y, w, h));
	}
	if (obj == ui.label_ColorCard_2 && event->type() == QEvent::Paint)
	{
		///EventFilter中的QPainter设备是需要监视的对象，不能是this父窗口
		//QPainter painter(this);
		QPainter painter(ui.label_ColorCard_2);
		painter.setRenderHint(QPainter::Antialiasing);//反锯齿
		/*int x = ui.label_ColorCard->x();
		int y = ui.label_ColorCard->y();*/
		int x = 0;
		int y = 0;
		int w = ui.label_ColorCard_2->rect().width();
		int h = ui.label_ColorCard_2->rect().height();
		QLinearGradient linearGradient(x, y, x, y + h);//渐变区域
		linearGradient.setColorAt(0, Qt::red);
		linearGradient.setColorAt(0.33, Qt::yellow);
		linearGradient.setColorAt(0.66, Qt::green);
		linearGradient.setColorAt(1, Qt::blue);
		painter.setBrush(linearGradient);//设置画刷，则painter.drawRect(rect());绘制出渐变背景
		painter.drawRect(QRect(x, y, w, h));
	}
	if (obj == ui.label_ColorCard_3 && event->type() == QEvent::Paint)
	{
		///EventFilter中的QPainter设备是需要监视的对象，不能是this父窗口
		//QPainter painter(this);
		QPainter painter(ui.label_ColorCard_3);
		painter.setRenderHint(QPainter::Antialiasing);//反锯齿
		/*int x = ui.label_ColorCard->x();
		int y = ui.label_ColorCard->y();*/
		int x = 0;
		int y = 0;
		int w = ui.label_ColorCard_3->rect().width();
		int h = ui.label_ColorCard_3->rect().height();
		QLinearGradient linearGradient(x, y, x, y + h);//渐变区域
		linearGradient.setColorAt(0, Qt::red);
		linearGradient.setColorAt(0.33, Qt::yellow);
		linearGradient.setColorAt(0.66, Qt::green);
		linearGradient.setColorAt(1, Qt::blue);
		painter.setBrush(linearGradient);//设置画刷，则painter.drawRect(rect());绘制出渐变背景
		painter.drawRect(QRect(x, y, w, h));
	}
	if (obj == ui.label_ColorCard_4 && event->type() == QEvent::Paint)
	{
		///EventFilter中的QPainter设备是需要监视的对象，不能是this父窗口
		//QPainter painter(this);
		QPainter painter(ui.label_ColorCard_4);
		painter.setRenderHint(QPainter::Antialiasing);//反锯齿
		/*int x = ui.label_ColorCard->x();
		int y = ui.label_ColorCard->y();*/
		int x = 0;
		int y = 0;
		int w = ui.label_ColorCard_4->rect().width();
		int h = ui.label_ColorCard_4->rect().height();
		QLinearGradient linearGradient(x, y, x, y + h);//渐变区域
		linearGradient.setColorAt(0, Qt::red);
		linearGradient.setColorAt(0.33, Qt::yellow);
		linearGradient.setColorAt(0.66, Qt::green);
		linearGradient.setColorAt(1, Qt::blue);
		painter.setBrush(linearGradient);//设置画刷，则painter.drawRect(rect());绘制出渐变背景
		painter.drawRect(QRect(x, y, w, h));
	}

	if (obj == ui.graphicsView_1&&event->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
		if (mouseEvent->button() == Qt::LeftButton)
		{
			int x = mouseEvent->x(); // 获取鼠标位置的x坐标
			int y = mouseEvent->y(); // 获取鼠标位置的y坐标
			int imgx = static_cast<int>(scalex * (float)x); // 将乘法结果四舍五入为最接近的整数
			int imgy = static_cast<int>(scaley * (float)y);
			if (magValueVec_x_raw.size() > imgy*width / dataDimension + imgx)
			{
				float Bx = magValueVec_x_raw[imgy*width / dataDimension + imgx];
				qDebug() << Bx;
				ui.label_B->setText(QString::number(imgx) + "," + QString::number(imgy) + ":" + QString::number(Bx));

			}
		}

	}
	if (obj == ui.graphicsView_2&&event->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
		if (mouseEvent->button() == Qt::LeftButton)
		{
			int x = mouseEvent->x(); // 获取鼠标位置的x坐标
			int y = mouseEvent->y(); // 获取鼠标位置的y坐标
			int imgx = static_cast<int>(scalex * (float)x); // 将乘法结果四舍五入为最接近的整数
			int imgy = static_cast<int>(scaley * (float)y);
			if (magValueVec_y_raw.size() > imgy*width / dataDimension + imgx)
			{
				float Bx = magValueVec_y_raw[imgy*width / dataDimension + imgx];
				qDebug() << Bx;
				ui.label_B->setText(QString::number(imgx) + "," + QString::number(imgy) + ":" + QString::number(Bx));

			}
		}

	}
	if (obj == ui.graphicsView_3&&event->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
		if (mouseEvent->button() == Qt::LeftButton)
		{
			int x = mouseEvent->x(); // 获取鼠标位置的x坐标
			int y = mouseEvent->y(); // 获取鼠标位置的y坐标
			int imgx = static_cast<int>(scalex * (float)x); // 将乘法结果四舍五入为最接近的整数
			int imgy = static_cast<int>(scaley * (float)y);
			if (magValueVec_z_raw.size() > imgy*width / dataDimension + imgx)
			{
				float Bx = magValueVec_z_raw[imgy*width / dataDimension + imgx];
				qDebug() << Bx;
				ui.label_B->setText(QString::number(imgx) + "," + QString::number(imgy) + ":" + QString::number(Bx));
			}
		}

	}
	if (obj == ui.graphicsView_4&&event->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
		if (mouseEvent->button() == Qt::LeftButton)
		{
			int x = mouseEvent->x(); // 获取鼠标位置的x坐标
			int y = mouseEvent->y(); // 获取鼠标位置的y坐标
			int imgx = static_cast<int>(scalex * (float)x); // 将乘法结果四舍五入为最接近的整数
			int imgy = static_cast<int>(scaley * (float)y);
			if (magValueVec_raw.size() > imgy*width / dataDimension + imgx)
			{
				float Bx = magValueVec_raw[imgy*width / dataDimension + imgx];
				qDebug() << Bx;
				ui.label_B->setText(QString::number(imgx) + "," + QString::number(imgy) + ":" + QString::number(Bx));
			}
		}

	}

	return QWidget::eventFilter(obj, event);
}

void ColorMapWidget::drawColorMap()
{
	QPixmap pix = grab(QRect(ui.label_ColorCard_1->x(), ui.label_ColorCard_1->y(), ui.label_ColorCard_1->width(), ui.label_ColorCard_1->height()));
	QImage image0 = pix.toImage();
	QImage colorImg_1 = CameraDataProcess::intChangetoQcolorimg(width / dataDimension, height / dataDimension, QVector<double>::fromStdVector(magValueVec_x),
		ui.lineEdit_DownValue_1->text().toDouble(), ui.lineEdit_UpperValue_1->text().toDouble(), image0);
	imgBx = colorImg_1;
	QImage imgScaled = colorImg_1.scaled(ui.graphicsView_1->width(), ui.graphicsView_1->height());
	if (m_image_item_1)
	{
		m_scene_1->removeItem(m_image_item_1);
		delete m_image_item_1;
		m_image_item_1 = 0;
	}

	m_image_item_1 = m_scene_1->addPixmap(QPixmap::fromImage(imgScaled));
	if (magValueVec_x_raw.size())
	{
		// 找出最小值
		auto minElement = std::min_element(magValueVec_x_raw.begin(), magValueVec_x_raw.end());
		double minValue = *minElement;
		// 找出最大值
		auto maxElement = std::max_element(magValueVec_x_raw.begin(), magValueVec_x_raw.end());
		double maxValue = *maxElement;

		double d_raw = maxValue - minValue;
		minValue += d_raw * ui.lineEdit_DownValue_1->text().toDouble();
		maxValue -= d_raw * (1-ui.lineEdit_UpperValue_1->text().toDouble());

		double A0 = (maxValue - minValue) / 4;

		double num = maxValue;
		string str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_X_1->setText(QString::number(num));

		num = maxValue - A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_X_2->setText(QString::number(num));

		num = maxValue - 2 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_X_3->setText(QString::number(num));

		num = maxValue - 3 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_X_4->setText(QString::number(num));

		num = maxValue - 4 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_X_5->setText(QString::number(num));

	}
	/// //////////////////////////////////////////////////////////////////////

	QImage colorImg_2 = CameraDataProcess::intChangetoQcolorimg(width / dataDimension, height / dataDimension, QVector<double>::fromStdVector(magValueVec_y),
		ui.lineEdit_DownValue_3->text().toDouble(), ui.lineEdit_UpperValue_3->text().toDouble(), image0);
	imgBy = colorImg_2;
	imgScaled = colorImg_2.scaled(ui.graphicsView_2->width(), ui.graphicsView_2->height());
	if (m_image_item_2)
	{
		m_scene_2->removeItem(m_image_item_2);
		delete m_image_item_2;
		m_image_item_2 = 0;
	}
	m_image_item_2 = m_scene_2->addPixmap(QPixmap::fromImage(imgScaled));
	if (magValueVec_y_raw.size())
	{
		// 找出最小值
		auto minElement = std::min_element(magValueVec_y_raw.begin(), magValueVec_y_raw.end());
		double minValue = *minElement;
		// 找出最大值
		auto maxElement = std::max_element(magValueVec_y_raw.begin(), magValueVec_y_raw.end());
		double maxValue = *maxElement;

		double d_raw = maxValue - minValue;
		minValue += d_raw * ui.lineEdit_DownValue_3->text().toDouble();
		maxValue -= d_raw * (1-ui.lineEdit_UpperValue_3->text().toDouble());

		double A0 = (maxValue - minValue) / 4;

		double num = maxValue;
		string str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Y_1->setText(QString::number(num));

		num = maxValue - A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Y_2->setText(QString::number(num));

		num = maxValue - 2 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Y_3->setText(QString::number(num));

		num = maxValue - 3 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Y_4->setText(QString::number(num));

		num = maxValue - 4 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Y_5->setText(QString::number(num));

	}
	////////////////////////////////////////////////////////////////
	QImage colorImg_3 = CameraDataProcess::intChangetoQcolorimg(width / dataDimension, height / dataDimension, QVector<double>::fromStdVector(magValueVec_z),
		ui.lineEdit_DownValue_4->text().toDouble(), ui.lineEdit_UpperValue_4->text().toDouble(), image0);
	imgBz = colorImg_3;
	imgScaled = colorImg_3.scaled(ui.graphicsView_3->width(), ui.graphicsView_3->height());
	if (m_image_item_3)
	{
		m_scene_3->removeItem(m_image_item_3);
		delete m_image_item_3;
		m_image_item_3 = 0;
	}
	m_image_item_3 = m_scene_3->addPixmap(QPixmap::fromImage(imgScaled));
	if (magValueVec_z_raw.size())
	{
		// 找出最小值
		auto minElement = std::min_element(magValueVec_z_raw.begin(), magValueVec_z_raw.end());
		double minValue = *minElement;
		// 找出最大值
		auto maxElement = std::max_element(magValueVec_z_raw.begin(), magValueVec_z_raw.end());
		double maxValue = *maxElement;

		double d_raw = maxValue - minValue;
		minValue += d_raw * ui.lineEdit_DownValue_4->text().toDouble();
		maxValue -= d_raw * (1-ui.lineEdit_UpperValue_4->text().toDouble());

		double A0 = (maxValue - minValue) / 4;

		double num = maxValue;
		string str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Z_1->setText(QString::number(num));

		num = maxValue - A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Z_2->setText(QString::number(num));

		num = maxValue - 2 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Z_3->setText(QString::number(num));

		num = maxValue - 3 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Z_4->setText(QString::number(num));

		num = maxValue - 4 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_Z_5->setText(QString::number(num));

	}
	///////////////////////////////////////////////////////////////////
	QImage colorImg_4 = CameraDataProcess::intChangetoQcolorimg(width / dataDimension, height / dataDimension, QVector<double>::fromStdVector(magValueVec),
		ui.lineEdit_DownValue_2->text().toDouble(), ui.lineEdit_UpperValue_2->text().toDouble(), image0);
	imgB = colorImg_4;
	imgScaled = colorImg_4.scaled(ui.graphicsView_4->width(), ui.graphicsView_4->height());
	if (m_image_item_4)
	{
		m_scene_4->removeItem(m_image_item_4);
		delete m_image_item_4;
		m_image_item_4 = 0;
	}
	m_image_item_4 = m_scene_4->addPixmap(QPixmap::fromImage(imgScaled));
	if (magValueVec_raw.size())
	{
		// 找出最小值
		auto minElement = std::min_element(magValueVec_raw.begin(), magValueVec_raw.end());
		double minValue = *minElement;
		// 找出最大值
		auto maxElement = std::max_element(magValueVec_raw.begin(), magValueVec_raw.end());
		double maxValue = *maxElement;

		double d_raw = maxValue - minValue;

		minValue += d_raw * ui.lineEdit_DownValue_2->text().toDouble();
		maxValue -= d_raw * (1-ui.lineEdit_UpperValue_2->text().toDouble());

		double A0 = (maxValue - minValue) / 4;

		double num = maxValue;
		string str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_B_1->setText(QString::number(num));

		num = maxValue - A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_B_2->setText(QString::number(num));

		num = maxValue - 2 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_B_3->setText(QString::number(num));

		num = maxValue - 3 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_B_4->setText(QString::number(num));

		num = maxValue - 4 * A0;
		str = to_string(num);
		str = str.substr(0, str.find(".") + 5);
		num = stod(str);
		ui.label_B_5->setText(QString::number(num));

	}
}

void ColorMapWidget::importData()
{
	QVector<double> B1_Vec, B2_Vec, B3_Vec, B4_Vec;

	QFile file_1("C:/Users/yedon/Desktop/MagResult/B1.dat");
	file_1.open(QIODevice::ReadOnly);
	QTextStream in_1(&file_1);
	while (!in_1.atEnd())
	{
		B1_Vec.push_back(in_1.readLine().toDouble());
	}

	QFile file_2("C:/Users/yedon/Desktop/MagResult/B2.dat");
	file_2.open(QIODevice::ReadOnly);
	QTextStream in_2(&file_2);
	while (!in_2.atEnd())
	{
		B2_Vec.push_back(in_2.readLine().toDouble());
	}

	QFile file_3("C:/Users/yedon/Desktop/MagResult/B3.dat");
	file_3.open(QIODevice::ReadOnly);
	QTextStream in_3(&file_3);
	while (!in_3.atEnd())
	{
		B3_Vec.push_back(in_3.readLine().toDouble());
	}

	QFile file_4("C:/Users/yedon/Desktop/MagResult/B4.dat");
	file_4.open(QIODevice::ReadOnly);
	QTextStream in_4(&file_4);
	while (!in_4.atEnd())
	{
		B4_Vec.push_back(in_4.readLine().toDouble());
	}
	double B1, B2, B3, B4, Bx, By, Bz, Bn;
	magValueVec.clear();
	magValueVec_x.clear();
	magValueVec_y.clear();
	magValueVec_z.clear();
	for (int i = 0; i < B1_Vec.size(); i++)
	{
		B1 = B1_Vec[i];
		B2 = B2_Vec[i];
		B3 = B3_Vec[i];
		B4 = B4_Vec[i];

		if (ui.lineEdit_1->text() == "0")
		{
			B1 = -B1;
		}
		if (ui.lineEdit_2->text() == "0")
		{
			B2 = -B2;
		}
		if (ui.lineEdit_3->text() == "0")
		{
			B3 = -B3;
		}
		if (ui.lineEdit_4->text() == "0")
		{
			B4 = -B4;
		}

		Bx = sqrt(3) / 4 * (B1 - B2 - B3 + B4);
		By = sqrt(3) / 4 * (B1 + B2 - B3 - B4);
		Bz = sqrt(3) / 4 * (B1 - B2 + B3 - B4);
		Bn = sqrt(pow(Bx, 2) + pow(By, 2) + pow(Bz, 2));

		/* Bx = sqrt(3) * (B1 + B3);
		 By = sqrt(3) * (-B2 - B3);
		 Bz = sqrt(3) * (B1 + B2);
		 Bn = sqrt(pow(Bx, 2) + pow(By, 2) + pow(Bz, 2));*/
		magValueVec.push_back(Bn);
		magValueVec_x.push_back(Bx);
		magValueVec_y.push_back(By);
		magValueVec_z.push_back(Bz);
	}
}




