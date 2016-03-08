#include "similitudeindirecte.h"

SimilitudeIndirecte::SimilitudeIndirecte() : Application()
{

}

SimilitudeIndirecte::SimilitudeIndirecte(qreal K, qreal theta, QPointF P) : Application()
{
	k=K;

	m11 = qCos(theta);
	m12 = qSin(theta);
	m21 = qSin(theta);
	m22 = -qCos(theta);

	v1 = P.x();
	v2 = P.y();
}

SimilitudeIndirecte::SimilitudeIndirecte(qreal K, qreal theta, QPointF P, QPointF C) : Application()
{
	k=K;

	m11 = qCos(theta);
	m12 = qSin(theta);
	m21 = qSin(theta);
	m22 = -qCos(theta);

	v1 = P.x();
	v2 = P.y();

	Centre = C;
}

SimilitudeIndirecte::setSimilitudeIndirecte(qreal K, qreal theta, QPointF P)
{
	k=K;

	m11 = qCos(theta);
	m12 = qSin(theta);
	m21 = qSin(theta);
	m22 = -qCos(theta);

	v1 = P.x();
	v2 = P.y();
}

SimilitudeIndirecte::setSimilitudeIndirecte(qreal K, qreal theta, QPointF P, QPointF C)
{
	k=K;

	m11 = qCos(theta);
	m12 = qSin(theta);
	m21 = qSin(theta);
	m22 = -qCos(theta);

	v1 = P.x();
	v2 = P.y();

	Centre = C;
}
