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

	void setm11(qreal m);
	void setm12(qreal m);
	void setm21(qreal m);
	void setm22(qreal m);
	void setv1(qreal m);
	void setv2(qreal m);
	void setCentre(QPointF P);
	void setK(qreal K);

	qreal getm11() const;
	qreal getm12() const;
	qreal getm21() const;
	qreal getm22() const;
	qreal getv1() const;
	qreal getv2() const;
	QPointF getCentre() const;
	qreal getK() const;
	qreal getTheta() const;//Calculer à partir de la matrice de rotation M


	bool isHomothetie() const;
	bool isRotation() const;


	QPointF DoForQPointF(QPointF const &P) const;
	Forme DoForForme(Forme const &F) const;
	QList<Forme> DoForEns(const QList<Forme> &EnsForme) const;

protected:
	qreal k;
	qreal m11, m12, m21, m22;
	qreal v1, v2;
	QPointF Centre;
};

bool operator ==(Application const &A, Application const &B);

#endif // APPLICATION_H
