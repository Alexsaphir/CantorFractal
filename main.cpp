#include <QApplication>
#include <iostream>

#include "window.h"
#include "windowgenfractale.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

//	WindowGenFractale W;
//	W.show();

	Window Fen;
	Fen.show();
	return app.exec();
}
