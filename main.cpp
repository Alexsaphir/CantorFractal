#include <QApplication>
#include <iostream>
#include <QDebug>

#include "window.h"
#include <complex>

#include <QGraphicsRectItem>

#define N 3

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);



	Window Fen;
	Fen.fractale = new Fractale;
	/*
	//Triangle de spiernsky
	Forme F;F.generateExisting(1);//genere triangle
	Fen.fractale->AddForme(F);
	for(int i=0;i<F.GetSize();++i)
	{
		Fen.fractale->AddHomothetie(1./2.,F.GetPoint(i));
	}
	//Fen.tweak=true;
	*/

	//Flocon de knock
	std::complex<qreal> alpha=1./3.;
	Forme F;F.generateExisting(1);
	qDebug() << alpha.real() << alpha.imag();
	Fen.fractale->AddForme(F);
	Application F1,F2,F3;
	F1.setY(alpha);
	F2.setY(alpha);
	F3.setY(alpha);

	F1.setW();
	F2.setW(1);
	F3.setW();
	//F1.setuseConj(true);
	//F2.setuseConj(true);
	Fen.fractale->AddApplication(F1);

	//Fen.show();
	qDebug() <<F1.DoForQPointF(QPointF(1.,0.));

	return app.exec();
}
