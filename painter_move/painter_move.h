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
	//���͸���Ҫ�޸������ƶ��Ĵ��� Painter ����Ӽ���update�����ĵ��ã����£��ɼ��󽵵�paintEvent��ˢ��
	// ����paintEventˢ�´�����һ�ַ�ʽ
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
	
	//tiansPont ���õ� painter.translate(point)  scaleSize ���õ� painter.scale��x,y)
	// scaleSize ����ֵΪ��0��0��ʱ ��ʾ���ƶ���������
	void moveAndScale(const QPointF transPoint, const QSizeF scaleSize);	

public:
	QPointF movePointToleftTop(const QPointF point);

	void setTransPoint(const QPointF& point);			
	void setTransPoint(const qreal&  x ,const qreal& y);

	//  δ����onMoce֮ǰΪ����ԭ������
	void setScaleSize(const qreal& multiple);
	void setScaleSize(const qreal& scaleX, const qreal& scaleY);

	void setCurrentPoint(const QMouseEvent* event);		//��Ҫ������ΪmousePressEvent�����Ĳۺ���

	void onMove(const QMouseEvent* event);				//��Ҫ������ΪmouseMoveEvent�����Ĳۺ���
	void onScale(const QWheelEvent* event);				//��Ҫ�����ӵ�wheelEvent�����Ĳۺ���

private:
	void onMove(const qreal& x, const qreal& y);
	void onScale(const qreal& scaleX, const qreal& scaleY, const QPointF & point = QPointF(-999999,-999999));

private:
	QPointF m_transPoint = QPointF(0, 0);
	
	qreal m_scaleMultipleX = 1.0f;
	qreal m_scaleMultipleY = 1.0f;

	QPointF m_currentPoint = QPointF(0, 0);
};
