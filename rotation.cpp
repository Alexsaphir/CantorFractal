#include "rotation.h"

///
/// \brief Rotation::Rotation
///
Rotation::Rotation() : Application()
{
}

///
/// \brief Rotation::Rotation
/// \param theta
///
Rotation::Rotation(double theta) : Application()
{
	//Matrice de rotation
	m11 = qCos(theta);
	m12 = -qSin(theta);
	m21 = qSin(theta);
	m22 = qCos(theta);
	//Centre 0

}

///
/// \brief Rotation::Rotation
/// \param theta
/// \param C
///
Rotation::Rotation(qreal theta, QPointF C) : Application()
{
	//Matrice de rotation
	m11 = qCos(theta);
	m12 = -qSin(theta);
	m21 = qSin(theta);
	m22 = qCos(theta);

	Centre=C;
}

///
/// \brief Rotation::setRotation
/// \param theta
///
void Rotation::setRotation(qreal theta)
{
	//Matrice de rotation
	m11 = qCos(theta);
	m12 = -qSin(theta);
	m21 = qSin(theta);
	m22 = qCos(theta);
}

///
/// \brief Rotation::setRotation
/// \param theta
/// \param C
///
void Rotation::setRotation(qreal theta, QPointF C)
{
	//Matrice de rotation
	m11 = qCos(theta);
	m12 = -qSin(theta);
	m21 = qSin(theta);
	m22 = qCos(theta);

	Centre=C;
}
