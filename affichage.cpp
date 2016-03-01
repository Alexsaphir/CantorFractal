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


	this->setMinimumSize(500,500);
	this->setLayout(Grid);
	view->show();

    QObject::connect(BnextStep, SIGNAL(clicked(bool)),this,SLOT(Actualiser()));



    //view->setTransformationAnchor(QGraphicsView::NoAnchor);
    //view->setResizeAnchor(QGraphicsView::NoAnchor);



    //On installe le filtre d'events
    view->scene()->installEventFilter(this);

}

void Affichage::Actualiser()
{
	scene->clear();//On effece l'écran
	++step;
	if (step!=1)
		F.RunOnce();
    qreal h=1000;
	for(int i=0; i<F.getSizeEnsForme();++i)
	{
//Special pour cantor car on dessine les ligne une en dessous de l'autre
		//Segment S=F.getFromE(i);
		//qreal x=k*S.getA().x();
		//qreal y=k*S.getB().x();

		//scene->addLine(x,h*step,y,h*step);


        //QPen Pen(Qt::PenStyle);
        //Pen.setWidth(0);
		Forme tmpForme=F.getFromEnsForme(i);
		for(int j=0;j<tmpForme.GetSize()-1;++j)
		{
            scene->addLine(h*tmpForme.GetPoint(j).x(), -h*tmpForme.GetPoint(j).y(), h*tmpForme.GetPoint(j+1).x(), -h*tmpForme.GetPoint(j+1).y());
		}
		scene->addLine(h*tmpForme.GetPoint(0).x(), -h*tmpForme.GetPoint(0).y(),h* tmpForme.GetPoint(tmpForme.GetSize()-1).x(), -h*tmpForme.GetPoint(tmpForme.GetSize()-1).y());
	}
	qDebug() << view->geometry().width();
}





void Affichage::Zoom(QGraphicsSceneWheelEvent *event)
{
    if(event->delta()>0)
    {
        view->scale(1.01,1.01);
    }
    else
    {
        view->scale(1/1.01,1/1.01);
    }
    qDebug()<< event->scenePos();
    view->centerOn(event->scenePos());

}

bool Affichage::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::GraphicsSceneWheel)
    {
        Zoom(static_cast<QGraphicsSceneWheelEvent*> (event));
        event->accept();//On ne propage pas l'event
        return true;
    }
    return false;
}
