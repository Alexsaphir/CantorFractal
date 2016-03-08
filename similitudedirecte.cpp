#include "similitudedirecte.h"

SimilitudeDirecte::SimilitudeDirecte() : Application()
{
	//Application id grace au constructeur de Application()
}

SimilitudeDirecte::SimilitudeDirecte(qreal K, qreal theta, QPointF C) : Application()
{
	k=K;

	m11 = qCos(theta);
	m12 = -qSin(theta);
	m21 = qSin(theta);
	m22 = qCos(theta);

	Centre = C;
}

SimilitudeDirecte::SimilitudeDirecte(qreal K, qreal theta, QPointF C, QPointF P) : Application()
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

void SimilitudeDirecte::setSimilitudeDirecte(qreal K, qreal theta, QPointF C)
{
	k=K;

	m11 = qCos(theta);
	m12 = -qSin(theta);
	m21 = qSin(theta);
	m22 = qCos(theta);

	Centre = C;
}

void SimilitudeDirecte::setSimilitudeDirecte(qreal K, qreal theta, QPointF C, QPointF P)
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

void SimilitudeDirecte::setTheta(qreal theta)
{
	m11 = qCos(theta);
	m12 = -qSin(theta);
	m21 = qSin(theta);
	m22 = qCos(theta);
}
