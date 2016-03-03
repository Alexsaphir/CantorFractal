#include "homothetie.h"



Homothetie::Homothetie() : Application()
{
}

Homothetie::Homothetie(qreal k) : Application()
{
	y = k;
}

Homothetie::Homothetie(qreal k, QPointF C) :Application()
{
	y = k;
	w = C.x() + C.y()*1i;
}

void Homothetie::setHomothetie(qreal k)
{
	y = k;
}

void Homothetie::setHomothetie(qreal k, QPointF C)
{
	y = k;
	w = C.x() + C.y()*1i;
}

qreal Homothetie::getHomothetie() const
{
	return y.real();
}
