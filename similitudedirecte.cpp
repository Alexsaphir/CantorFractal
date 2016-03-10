#include "similitudedirecte.h"

///
/// \brief SimilitudeDirecte::SimilitudeDirecte
///
SimilitudeDirecte::SimilitudeDirecte() : Application()
{
	//Application id grace au constructeur de Application()
}

///
/// \brief SimilitudeDirecte::SimilitudeDirecte
/// \param K
/// \param theta
/// \param C
///
SimilitudeDirecte::SimilitudeDirecte(qreal K, qreal theta, QPointF C) : Application()
{
	k=K;

	m11 = qCos(theta);
	m12 = -qSin(theta);
	m21 = qSin(theta);
	m22 = qCos(theta);

	Centre = C;
}

///
/// \brief SimilitudeDirecte::SimilitudeDirecte
/// \param K
/// \param theta
/// \param C
/// \param P
///
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

///
/// \brief SimilitudeDirecte::setSimilitudeDirecte
/// \param K
/// \param theta
/// \param C
///
void SimilitudeDirecte::setSimilitudeDirecte(qreal K, qreal theta, QPointF C)
{
	k=K;

	m11 = qCos(theta);
	m12 = -qSin(theta);
	m21 = qSin(theta);
	m22 = qCos(theta);

	Centre = C;
}

///
/// \brief SimilitudeDirecte::setSimilitudeDirecte
/// \param K
/// \param theta
/// \param C
/// \param P
///
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

///
/// \brief SimilitudeDirecte::setTheta
/// \param theta
///
void SimilitudeDirecte::setTheta(qreal theta)
{
	m11 = qCos(theta);
	m12 = -qSin(theta);
	m21 = qSin(theta);
	m22 = qCos(theta);
}
