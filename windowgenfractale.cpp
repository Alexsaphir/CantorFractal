#include "windowgenfractale.h"

WindowGenFractale::WindowGenFractale() : QScrollArea()
{
	gridLayout	= new QGridLayout;
	widget			= new QWidget;
	for(int i=0;i<10;++i)
	{
		listButton.append(new QPushButton("bouton"));
		gridLayout->addWidget(listButton.at(i), i,1);
	}
	widget->setLayout(gridLayout);
	this->setWidget(widget);
}

