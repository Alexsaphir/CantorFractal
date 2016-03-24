#include "windowgenfractale.h"

WindowGenFractale::WindowGenFractale() : QWidget()
{
	gridLayout = new QGridLayout;
	scroll = new QScrollArea;
	scroll->setWidgetResizable(true);
	scroll->setWidget(this);
	for(int i=0;i<10;++i)
	{
		listButton.append(new QPushButton("bouton"));
		gridLayout->addWidget(listButton.at(i), i,1);
	}
	this->setLayout(gridLayout);
}

