#include <QApplication>
#include <iostream>
#include <QDebug>

#include "affichage.h"
#include <math.h>

#define N 2

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
/*
	QGraphicsScene scene;
	QGraphicsView view;
	view.setScene(&scene);

	Cantor F;

	F.Aff(&scene,0);
	for(int i=0;i<10;++i)
	{
		std::cout<<i<<std::endl;
		F.doStep();
		F.Aff(&scene,i);

	}
	view.show();
*/


    Affichage Fen;
	Forme FormeInitiale;

	float theta=2*M_PI/N;
	for (int i=0;i<N;++i)
	{
		QPointF P(cos((float)i*theta),sin((float)i*theta));
		FormeInitiale.AddPoint(P);
		if(i%2)
		{
			Fen.F.AddAppli(0,0.3333,0,P);
		}
		else Fen.F.AddAppli(0,0.3333,0,P);
	}
	Fen.F.AddForme(FormeInitiale);

    Fen.show();
    //Hello

	return app.exec();
}
