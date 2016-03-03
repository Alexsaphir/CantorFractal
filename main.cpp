#include <QApplication>
#include <iostream>
#include <QDebug>

#include "window.h"

#include <QGraphicsRectItem>

#define N 3

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);


//	Affichage Fen;
//	Forme FormeInitiale;

//	float theta=2*M_PI/N;
//	for (int i=0;i<N;++i)
//	{
//		QPointF P(cos((float)i*theta),sin((float)i*theta));
//		FormeInitiale.AddPoint(P);

//		Fen.F.AddHomothetie(0.33333, P);

//	}
//	Fen.F.AddForme(FormeInitiale);
//	Fen.Actualiser();
//	Fen.show();

	Window Fen;
	Fen.fractale = new Fractale;
	Forme F;F.generateExisting(1);//genere triangle
	Fen.fractale->AddForme(F);
	for(int i=0;i<F.GetSize();++i)
	{
		Fen.fractale->AddHomothetie(1./2.,F.GetPoint(i));
	}
	Fen.show();


	return app.exec();
}
