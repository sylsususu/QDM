#include "MyGraphicsView.h"

void MyGraphicsView::mouseMoveEvent(QMouseEvent * event)
{
	int x = event->x();
	int y = event->y();
	emit SendGrapViewPoint(x, y);
	// 继续处理其他事件
	QGraphicsView::mouseMoveEvent(event);
}
