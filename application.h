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

	std::complex<qreal> getApplication() const;
	QPointF getCentre() const;
	QPointF DoForQPointF(QPointF const &P) const;
	Forme DoForForme(Forme const &F) const;
	QList<Forme> DoForEns(const QList<Forme> &EnsForme) const;

	void setW(std::complex<qreal> W);
	void setY(std::complex<qreal> Y);


	bool isHomothetie() const;
	bool isRotation() const;


protected:
	std::complex<qreal> y;//y représente la transformation
	std::complex<qreal> w;//Représente le centre
};

bool operator ==(Application const &A, Application const &B);

#endif // APPLICATION_H
