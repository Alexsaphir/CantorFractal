#include <QApplication>
#include <iostream>
#include <QDebug>

#include "window.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);


	Window Fen;
	Fen.show();
	return app.exec();
}
