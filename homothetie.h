#ifndef HOMOTHETIE_H
#define HOMOTHETIE_H

#include <QtGlobal>
#include <QtMath>

#include "application.h"

class Homothetie : public Application
{
public:
	Homothetie();
	Homothetie(qreal K);//On est en centre (0,0)
	Homothetie(qreal K, QPointF C);//rapport K de centre C;

	void setHomothetie(qreal K);
	void setHomothetie(qreal K, QPointF C);

};

#endif // HOMOTHETIE_H
