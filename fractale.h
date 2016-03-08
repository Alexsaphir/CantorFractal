#ifndef FRACTALE_H
#define FRACTALE_H

#include <QtGlobal>
#include <QtMath>

#include <QPointF>
#include <QList>

#include "application.h"
#include "homothetie.h"
#include "rotation.h"
#include "forme.h"

class Fractale
{
public:
	Fractale();

	void AddApplication(Application A);

	void AddHomothetie(qreal k);
	void AddHomothetie(qreal k, QPointF Centre);
	void AddHomothetie(qreal k, qreal x, qreal y);

	void AddRotation(qreal theta);
	void AddRotation(qreal theta, QPointF Centre);
	void AddRotation(qreal theta, qreal x, qreal y);

	void AddForme(Forme F);

	bool isLikeCantor() const;
	void setLikeCantor(bool p);

	void RunOnce();

	Forme getFromEnsForme(int i) const;
	int getSizeEnsForme() const;
	int getSizeEnsAppli() const;

	void generateExisting(quint32 n);

private:
	QList<Application> EnsA;
	QList<Forme> EnsF;

	bool isCantor;
};

#endif // FRACTALE_H
