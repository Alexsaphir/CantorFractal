#ifndef SIMILITUDEINDIRECTE_H
#define SIMILITUDEINDIRECTE_H

#include <QtGlobal>
#include <QtMath>
#include <QPointF>

#include "application.h"

class SimilitudeIndirecte : public Application
{
public:
	SimilitudeIndirecte();
	SimilitudeIndirecte(qreal K, qreal theta, QPointF P);
	SimilitudeIndirecte(qreal K, qreal theta, QPointF P, QPointF C);

	void setSimilitudeIndirecte(qreal K, qreal theta, QPointF P);
	void setSimilitudeIndirecte(qreal K, qreal theta, QPointF P, QPointF C);
};

#endif // SIMILITUDEINDIRECTE_H
