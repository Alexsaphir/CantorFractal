#ifndef SIMILITUDEDIRECTE_H
#define SIMILITUDEDIRECTE_H

#include "application.h"

class SimilitudeDirecte : public Application
{
public:
	SimilitudeDirecte();
	SimilitudeDirecte(qreal K, qreal theta, QPointF C);
	SimilitudeDirecte(qreal K, qreal theta, QPointF C, QPointF P);

	void setSimilitudeDirecte(qreal K, qreal theta, QPointF C);
	void setSimilitudeDirecte(qreal K, qreal theta, QPointF C, QPointF P);
	void setTheta(qreal theta);
};

#endif // SIMILITUDEDIRECTE_H
