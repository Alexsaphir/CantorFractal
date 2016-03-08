#include "homothetie.h"



Homothetie::Homothetie() : Application()
{
	//Le constructeur de Application est appellé et *this= Id
}

Homothetie::Homothetie(qreal k) : Application()
{
	k = K;
}

Homothetie::Homothetie(qreal K, QPointF C) :Application()
{
	k = K;
	Centre = C;
}

void Homothetie::setHomothetie(qreal K)
{
	k = K;
}

void Homothetie::setHomothetie(qreal K, QPointF C)
{
	k = K;
	Centre = C;
}
