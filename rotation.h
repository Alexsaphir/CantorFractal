#ifndef ROTATION_H
#define ROTATION_H

#include <QtGlobal>
#include <QtMath>

#include "application.h"

class Rotation : public Application
{
public:
	Rotation();
	Rotation(qreal theta);//On est en centre (0,0)
	Rotation(qreal theta, QPointF C);//rotation theta de centre C;

	void setRotation(qreal theta);
	void setRotation(qreal theta, QPointF C);

	qreal getRotation() const;
};

#endif // ROTATION_H
