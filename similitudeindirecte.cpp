#include "similitudeindirecte.h"

///
/// \brief SimilitudeIndirecte::SimilitudeIndirecte
///
SimilitudeIndirecte::SimilitudeIndirecte() : Application()
{

}

///
/// \brief SimilitudeIndirecte::SimilitudeIndirecte
/// \param K
/// \param theta
/// \param P
///
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

///
/// \brief SimilitudeIndirecte::SimilitudeIndirecte
/// \param K
/// \param theta
/// \param P
/// \param C
///
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

///
/// \brief SimilitudeIndirecte::setSimilitudeIndirecte
/// \param K
/// \param theta
/// \param P
///
void SimilitudeIndirecte::setSimilitudeIndirecte(qreal K, qreal theta, QPointF P)
{
	k=K;

	m11 = qCos(theta);
	m12 = qSin(theta);
	m21 = qSin(theta);
	m22 = -qCos(theta);

	v1 = P.x();
	v2 = P.y();
}

///
/// \brief SimilitudeIndirecte::setSimilitudeIndirecte
/// \param K
/// \param theta
/// \param P
/// \param C
///
void SimilitudeIndirecte::setSimilitudeIndirecte(qreal K, qreal theta, QPointF P, QPointF C)
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
