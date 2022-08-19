#pragma once

#include <QObject>
#include <QPointF>
#include <QSize>
#include <QMouseEvent>

class Painter_move  : public QObject
{
	Q_OBJECT

public:
	Painter_move();
	Painter_move(QObject *parent);
	~Painter_move();
signals:
	//发送给需要修改缩放移动的窗口 Painter 可添加减少update（）的调用，如下，可极大降低paintEvent的刷新
	// 减少paintEvent刷新次数的一种方式
	//static long temp = 0;
	//if (scaleSize == QSizeF(0, 0)) {
	//	temp++;
	//	if (temp % 5 != 0) {
	//		return;
	//	}
	//	m_translatePoint = transPoint;
	//	update();
	//}
	//else
	//{
	//	m_translatePoint = transPoint;
	//	m_scaleSize = scaleSize;
	//	update();
	//}
	
	//tiansPont 设置到 painter.translate(point)  scaleSize 设置到 painter.scale（x,y)
	// scaleSize 返回值为（0，0）时 表示仅移动，不缩放
	void moveAndScale(const QPointF transPoint, const QSizeF scaleSize);	

public:
	QPointF movePointToleftTop(const QPointF point);

	void setTransPoint(const QPointF& point);			
	void setTransPoint(const qreal&  x ,const qreal& y);

	//  未调用onMoce之前为根据原点缩放
	void setScaleSize(const qreal& multiple);
	void setScaleSize(const qreal& scaleX, const qreal& scaleY);

	void setCurrentPoint(const QMouseEvent* event);		//需要被连接为mousePressEvent（）的槽函数

	void onMove(const QMouseEvent* event);				//需要配连接为mouseMoveEvent（）的槽函数
	void onScale(const QWheelEvent* event);				//需要被连接到wheelEvent（）的槽函数

private:
	void onMove(const qreal& x, const qreal& y);
	void onScale(const qreal& scaleX, const qreal& scaleY, const QPointF & point = QPointF(-999999,-999999));

private:
	QPointF m_transPoint = QPointF(0, 0);
	
	qreal m_scaleMultipleX = 1.0f;
	qreal m_scaleMultipleY = 1.0f;

	QPointF m_currentPoint = QPointF(0, 0);
};
