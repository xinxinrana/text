#include "painter_move.h"

Painter_move::Painter_move()
{
}

Painter_move::Painter_move(QObject *parent)
	: QObject(parent)
{
	
}

Painter_move::~Painter_move()
{
}

QPointF Painter_move::movePointToleftTop(const QPointF point)
{
	QPointF tempPoint = point - m_transPoint;
	tempPoint.setX(tempPoint.x() / m_scaleMultipleX);
	tempPoint.setY(tempPoint.y() / m_scaleMultipleY);


	return tempPoint;
}

void Painter_move::setTransPoint(const QPointF & point)
{
	onMove(point.x(), point.y());
}

void Painter_move::setTransPoint(const qreal& x, const qreal& y)
{
	onMove(x, y);
}

void Painter_move::setScaleSize(const qreal& multiple)
{
	onScale(multiple, multiple);
}

void Painter_move::setScaleSize(const qreal& scaleX, const qreal& scaleY)
{
	onScale(scaleX, scaleY);
}

void Painter_move::setCurrentPoint(const QMouseEvent* event)
{
	m_currentPoint = event->pos();
}

void Painter_move::onMove(const QMouseEvent* event)
{
	onMove(event->pos().x(), event->pos().y());
}

void Painter_move::onScale(const QWheelEvent* event)
{
	bool isToBig = event->delta() > 0;
	QSizeF tempScale = QSizeF(m_scaleMultipleX, m_scaleMultipleY);

	if (isToBig)
	{
		tempScale.setWidth(tempScale.width() * 1.1f);
		tempScale.setHeight(tempScale.height() * 1.1f);
	}
	else
	{
		tempScale.setWidth(tempScale.width() / 1.1f);
		tempScale.setHeight(tempScale.height() / 1.1f);
	}

	onScale(tempScale.width(), tempScale.height(), event->pos());
}

void Painter_move::onMove(const qreal& x, const qreal& y)
{
	QPointF offset = QPointF(x,y) - m_currentPoint;

	m_currentPoint = QPointF(x, y);
	m_transPoint += offset;

	emit moveAndScale(m_transPoint, QSizeF(0, 0));
}

void Painter_move::onScale(const qreal& scaleX, const qreal& scaleY, const QPointF & point )
{
	QPointF  tempPoint = point;
	if (point == QPointF(-999999, -999999)) {
		tempPoint = m_currentPoint;
	}

	QPointF offset = (tempPoint - m_transPoint);

	offset.setX(offset.x() * (scaleX / m_scaleMultipleX));
	offset.setY(offset.y() * (scaleY / m_scaleMultipleY));

	offset =  (tempPoint - m_transPoint) - offset;

	m_scaleMultipleX = scaleX;
	m_scaleMultipleY = scaleY;

	m_transPoint += offset;

	emit moveAndScale(m_transPoint, QSizeF(scaleX, scaleY));

}


