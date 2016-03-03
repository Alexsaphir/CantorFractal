#ifndef HOMOTHETIE_H
#define HOMOTHETIE_H

#include "application.h"

class Homothetie : public Application
{
public:
	Homothetie();
	Homothetie(qreal k);//On est en centre (0,0)
	Homothetie(qreal k, QPointF C);//rapport K de centre C;

	void setHomothetie(qreal k);
	void setHomothetie(qreal k, QPointF C);

	qreal getHomothetie() const;
};

#endif // HOMOTHETIE_H
