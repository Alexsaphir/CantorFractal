#ifndef FRACTALE_H
#define FRACTALE_H

#include <QPointF>
#include <QList>

#include "application.h"
#include "forme.h"

class Fractale
{
public:
	Fractale();
	void AddAppli(bool isSimi, qreal k, qreal r, QPointF Centre);
	void AddForme(const Forme &F);

	bool isLikeCantor() const;

	void RunOnce();

	Forme getFromEnsForme(int i) const;
	int getSizeEnsForme() const;
	int getSizeEnsAppli() const;

private:
	QList<Application> EnsA;
	QList<Forme> EnsF;

	bool isCantor;
};

#endif // FRACTALE_H
