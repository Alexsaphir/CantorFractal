#ifndef SIMILITUDEDIRECTE_H
#define SIMILITUDEDIRECTE_H

#include <QtGlobal>
#include <QtMath>
#include <QPointF>

#include "application.h"

class SimilitudeDirecte : public Application
{
public:
	SimilitudeDirecte();
	SimilitudeDirecte(qreal K, qreal theta, QPointF P);
	SimilitudeDirecte(qreal K, qreal theta, QPointF P, QPointF C);
};

#endif // SIMILITUDEDIRECTE_H
