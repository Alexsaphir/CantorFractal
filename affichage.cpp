#include "affichage.h"

Affichage::Affichage() : QWidget(), QEvent(QEvent::Wheel)
{
	step=0;
    scene = new QGraphicsScene;
	view = new QGraphicsView(scene);
    BnextStep = new QPushButton("Next Frame");
    BZoom = new QPushButton("zoom");
    Grid = new QGridLayout;

    Pen1.setWidth(1);
    Pen1.setCosmetic(true);

    Grid->addWidget(BnextStep,0,0);
    Grid->addWidget(BZoom,0,2);
	Grid->addWidget(view,1,0,4,4);


	this->setMinimumSize(500,500);
	this->setLayout(Grid);
	view->show();


    QObject::connect(BnextStep, SIGNAL(clicked(bool)),this,SLOT(Actualiser()));


//Garde le point sous le curseur durant le zoom
    view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);



    //On installe le filtre d'events
    view->scene()->installEventFilter(this);

}

void Affichage::Actualiser()
{
    scene->clear();//On efface l'écran
	++step;
    if (step!=1)//Permet de ne pas calculer si on est a la premiere etape et d'afficher la forme initiale
        F.RunOnce();
    qreal h=1;
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
            scene->addLine(h*tmpForme.GetPoint(j).x(), -h*tmpForme.GetPoint(j).y(), h*tmpForme.GetPoint(j+1).x(), -h*tmpForme.GetPoint(j+1).y(),Pen1);
		}
        scene->addLine(h*tmpForme.GetPoint(0).x(), -h*tmpForme.GetPoint(0).y(),h* tmpForme.GetPoint(tmpForme.GetSize()-1).x(), -h*tmpForme.GetPoint(tmpForme.GetSize()-1).y(),Pen1);
	}
//Mise au point
    if (step==1)
    {
        view->fitInView( view->scene()->sceneRect(), Qt::KeepAspectRatio );
    }
}





void Affichage::Zoom(QGraphicsSceneWheelEvent *event)
{
    qreal scaleFactor=pow((double)2, event->delta() / 240.0);
    qreal factor = view->transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    //if (factor < 0.07 || factor > 100)
       // return;

    view->scale(scaleFactor, scaleFactor);
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
