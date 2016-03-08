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


	//Flocon de knock
	Forme F;F.generateExisting(0);
	Fen.fractale->AddForme(F);
	SimilitudeDirecte S1,S2,S3,S4;
	S1.setK(1./3.);
	S1.setCentre(F.GetPoint(0));
	S2.setK(1./3.);
	S2.setCentre();

	Fen.fractale->AddApplication(S1);
	Fen.fractale->AddApplication(S2);
	//Fen.fractale->AddApplication(S3);
	//Fen.fractale->AddApplication(S4);

	Fen.show();
//	qDebug() <<F1.DoForQPointF(QPointF(1.,0.));

	return app.exec();
}
