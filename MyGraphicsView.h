#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QDebug>

class MyGraphicsView : public QGraphicsView
{
	Q_OBJECT

public:
	MyGraphicsView(QWidget *parent = nullptr) : QGraphicsView(parent) 
	{
		setMouseTracking(true); // ∆Ù”√ Û±Í∏˙◊Ÿ
	}

protected:
	void mouseMoveEvent(QMouseEvent *event) override;
signals:
	void SendGrapViewPoint(int x,int y);
};

#endif // MYGRAPHICSVIEW_H