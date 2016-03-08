#include "rotation.h"

Rotation::Rotation() : Application()
{
}

Rotation::Rotation(double theta) : Application()
{
	//Matrice de rotation
	m11 = qCos(theta);
	m12 = -qSin(theta);
	m21 = qSin(theta);
	m22 = qCos(theta);
	//Centre 0

}

Rotation::Rotation(qreal theta, QPointF C) : Application()
{
	//Matrice de rotation
	m11 = qCos(theta);
	m12 = -qSin(theta);
	m21 = qSin(theta);
	m22 = qCos(theta);

	Centre=C;
}

void Rotation::setRotation(qreal theta)
{
	//Matrice de rotation
	m11 = qCos(theta);
	m12 = -qSin(theta);
	m21 = qSin(theta);
	m22 = qCos(theta);
}

void Rotation::setRotation(qreal theta, QPointF C)
{
	//Matrice de rotation
	m11 = qCos(theta);
	m12 = -qSin(theta);
	m21 = qSin(theta);
	m22 = qCos(theta);

	Centre=C;
}
