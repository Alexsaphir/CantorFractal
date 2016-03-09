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
	Fen.show();

	return app.exec();
}
