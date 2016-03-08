#include <QApplication>
#include <iostream>
#include <QDebug>

#include "window.h"
#include "similitudedirecte.h"
#include "application.h"
#include <complex>

#include <QGraphicsRectItem>

#define N 3

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);


	Window Fen;
	Fen.fractale = new Fractale;

//	//Triangle de spiernsky
//	Forme F;F.generateExisting(1);//genere triangle
//	Fen.fractale->AddForme(F);
//	for(int i=0;i<F.GetSize();++i)
//	{
//		Fen.fractale->AddHomothetie(1./2.,F.GetPoint(i));
//	}
//	Fen.tweak=true;
//	Fen.show();
	Fen.tweak=true;
	Fen.fractale->generateExisting(1);
	Fen.show();

	return app.exec();
}
