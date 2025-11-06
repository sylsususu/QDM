#include "radiusprogressbar.h"
#include <QPainter>

RadiusProgressBar::RadiusProgressBar(QWidget *parent) : QProgressBar(parent)
{
    setMinimum(0);
    setMaximum(100);
    setValue(0);
}

void RadiusProgressBar::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QRect rect = QRect(0, 0, width(), height()/2);
    QRect textRect = QRect(0, height()/2, width(), height()/2);

    const double k = (double)(value() - minimum()) / (maximum()-minimum());
    int x = (int)(rect.width() * k);
    QRect fillRect = rect.adjusted(0, 0, x-rect.width(), 0);

    QString valueStr = QString("计算进度:%1%").arg(QString::number(value()));
    QPixmap buttomMap = QPixmap(":/resource/radius_back.png");
    QPixmap fillMap = QPixmap(":/resource/radius_front.png");


	//画进度条
	p.drawPixmap(rect, buttomMap);
	p.drawPixmap(fillRect, fillMap, fillRect);

    //画文字
    QFont f = QFont("Microsoft YaHei UI Light", 10, QFont::Bold);
    p.setFont(f);
    p.setPen(QColor("#FFFFFF"));
    p.drawText(textRect, Qt::AlignCenter, valueStr);
}

