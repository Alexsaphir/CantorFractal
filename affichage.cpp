#include "affichage.h"

Affichage::Affichage() : QWidget(), QEvent(QEvent::Wheel)
{
	step=0;
    scene = new QGraphicsScene;
	view = new QGraphicsView(scene);
    BnextStep = new QPushButton("Next Frame");
    BZoom = new QPushButton("zoom");
    Grid = new QGridLayout;
	Grid->addWidget(BnextStep,0,0);
    Grid->addWidget(BZoom,0,2);
	Grid->addWidget(view,1,0,4,4);



	//view->viewport()->installEventFilter(this);
	//view->setMouseTracking(true);
	qDebug()<<view->isInteractive();




	this->setMinimumSize(500,500);
	this->setLayout(Grid);
	view->show();


	QObject::connect(BnextStep, SIGNAL(clicked(bool)),this,SLOT(Actualiser()));
    QObject::connect(BZoom, SIGNAL(clicked(bool)),this,SLOT(zoomIn()));
	//QObject::connect(view, SIGNAL(),this,SLOT(zoomIn()));
}

void Affichage::Actualiser()
{
	scene->clear();//On effece l'écran
	++step;
	if (step!=1)
		F.RunOnce();
    qreal h=50;
	for(int i=0; i<F.getSizeEnsForme();++i)
	{
//Special pour cantor car on dessine les ligne une en dessous de l'autre
		//Segment S=F.getFromE(i);
		//qreal x=k*S.getA().x();
		//qreal y=k*S.getB().x();

		//scene->addLine(x,h*step,y,h*step);


		QPen Pen(Qt::PenStyle);
		Pen.setWidth(0);
		Forme tmpForme=F.getFromEnsForme(i);
		for(int j=0;j<tmpForme.GetSize()-1;++j)
		{
			scene->addLine(h*tmpForme.GetPoint(j).x(), -h*tmpForme.GetPoint(j).y(), h*tmpForme.GetPoint(j+1).x(), -h*tmpForme.GetPoint(j+1).y(),Pen);
		}
		scene->addLine(h*tmpForme.GetPoint(0).x(), -h*tmpForme.GetPoint(0).y(),h* tmpForme.GetPoint(tmpForme.GetSize()-1).x(), -h*tmpForme.GetPoint(tmpForme.GetSize()-1).y());
	}
	qDebug() << view->geometry().width();
}

void Affichage::zoomIn()
{
	view->scale(1.5,1.5);

}

void Affichage::zoomOut()
{
	view->scale(1/1.5,1/1.5);
}

void Affichage::wheelEvent(QWheelEvent *event)
{
    //event.ignore();

    if(event->delta()>0)
        zoomIn();
    else
        zoomOut();
	qDebug()<<"is call";
    //view->scale(1.5,1.5);
}

void Affichage::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mousePressEvent";
}
