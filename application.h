#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtGlobal>
#include <QtMath>
#include <QPointF>

#include <complex>
#include <cmath>

#include "forme.h"


class Application
{
public:
	Application();

	QPointF DoForQPointF(QPointF const &P) const;
	Forme DoForForme(Forme const &F) const;
	QList<Forme> DoForEns(const QList<Forme> &EnsForme) const;

	void setm11(qreal m);
	void setm12(qreal m);
	void setm21(qreal m);
	void setm22(qreal m);
	void setv1(qreal m);
	void setv2(qreal m);

	qreal getm11() const;
	qreal getm12() const;
	qreal getm21() const;
	qreal getm22() const;
	qreal getv1() const;
	qreal getv2() const;


	bool isHomothetie() const;
	bool isRotation() const;


protected:
	 qreal k;
	 qreal m11, m12, m21, m22;
	 qreal v1, v2;
};

bool operator ==(Application const &A, Application const &B);

#endif // APPLICATION_H
