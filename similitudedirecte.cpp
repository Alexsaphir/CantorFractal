#include "similitudedirecte.h"

SimilitudeDirecte::SimilitudeDirecte() : Application()
{

}

SimilitudeDirecte::SimilitudeDirecte(qreal K, qreal theta, QPointF P) :Application()
{
	k=K;

	m11 = qCos(theta);
	m12 = -qSin(theta);
	m21 = qSin(theta);
	m22 = qCos(theta);

	v1 = P.x();
	v2 = P.y();

	Centre.setX(0);
	Centre.setY(0);
}

SimilitudeDirecte::SimilitudeDirecte(qreal K, qreal theta, QPointF P, QPointF C) : Application()
{
	k=K;

	m11 = qCos(theta);
	m12 = -qSin(theta);
	m21 = qSin(theta);
	m22 = qCos(theta);

	v1 = P.x();
	v2 = P.y();

	Centre = C;
}
