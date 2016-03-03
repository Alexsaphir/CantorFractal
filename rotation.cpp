#include "rotation.h"

Rotation::Rotation() : Application()
{
}

Rotation::Rotation(double theta) : Application()
{
	//y=exp(1i*theta);
	//on traduit l'exp par son equivalent en cos+isin
	y=qCos(theta)+1i*qSin(theta);

}

Rotation::Rotation(qreal theta, QPointF C) : Application()
{
	//y=exp(1i*theta);
	//on traduit l'exp par son equivalent en cos+isin
	y=qCos(theta)+1i*qSin(theta);
	w = C.x() + C.y()*1i;
}

void Rotation::setRotation(qreal theta)
{
	y=qCos(theta)+1i*qSin(theta);
}

void Rotation::setRotation(qreal theta, QPointF C)
{
	y=qCos(theta)+1i*qSin(theta);
	w = C.x() + C.y()*1i;
}

qreal Rotation::getRotation() const
{
	return qAcos(y.real());//qAcos <=> arccos
}
