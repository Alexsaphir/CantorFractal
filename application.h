#ifndef APPLICATION_H
#define APPLICATION_H

#include <QList>
#include <QMatrix2x2>

#include <math.h>

#include "forme.h"

class Application
{
public:
	Application();
	Application(bool pSimi, qreal K, qreal R, QPointF CENTRE);
	bool isSimilitude() const;
	bool isHomothetie() const;



	QList<Forme> doForEns(const QList<Forme> &EnsForme) const;//Applique la transformation sur un ensemble


private:
	bool isSimi;
	QPointF Centre;
	qreal k;
	qreal r;
    QMatrix2x2 matR;//Matrice de rotation associé a l'angle r
};

#endif // APPLICATION_H


//Homothetie ou similitude
