#include "window.h"

Window::Window() : QMainWindow()
{
	//Type SDI
	SDI_Area = new QWidget;
	GridLayout = new QGridLayout;

	B_next = new QPushButton("Next Step");
	B_load = new QPushButton("Load");

	scene = new QGraphicsScene;
	view = new QGraphicsView(scene);
	fractale=NULL;


	GridLayout->addWidget(view);
	//Configuration de la vue
	view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	view->setDragMode(QGraphicsView::ScrollHandDrag);
	Pen1.setWidth(1);
	Pen1.setCosmetic(true);
	//Filtre d'événement
	view->scene()->installEventFilter(this);


	//ToolBar
	ToolBar = addToolBar("ToolBar");
	ToolBar->setMovable(false);
	ToolBar->addWidget(B_next);
	ToolBar->addWidget(B_load);
	B_next->setDisabled(true);


	SDI_Area->setLayout(GridLayout);
	setCentralWidget(SDI_Area);

	setWindowTitle("QMainWindow");
	this->resize(800,800);

	connect(B_next, SIGNAL(clicked(bool)), this, SLOT(refreshView()));
	connect(B_load, SIGNAL(clicked(bool)), this, SLOT(load()));

	step=0;
}

void Window::load()
{
	qDebug() << "call load";

	QStringList items;
	items << "Cantor";

	bool ok;
	QString item = QInputDialog::getItem(this, "Séléction Fractale", "Fractale:", items, 0, false, &ok);
	if (ok && !item.isEmpty())

	{
		if(item==items.at(0))
		{
			//Création Cantor

			fractale = new Fractale;
			fractale->generateExisting(0);
		}
	}
	refreshView();
	B_next->setDisabled(false);//!!!!!!!!!!!
}

void Window::refreshView()
{
	//Permet d'afficher la fractale a l'écran

	if(fractale == NULL)
		return;//Si Aucune fractale n'a été créé on n'affiche rien
	if(step!=0)
		fractale->RunOnce();
	if(fractale->isLikeCantor())
	{
		refreshViewSpecial();
		return;
	}
	scene->clear();//Efface l'écran


	for(int i=0; i<fractale->getSizeEnsForme();++i)
	{
		//Special pour cantor car on dessine les ligne une en dessous de l'autre
		//Segment S=F.getFromE(i);
		//qreal x=k*S.getA().x();
		//qreal y=k*S.getB().x();
		//scene->addLine(x,h*step,y,h*step);
		Forme tmpForme=fractale->getFromEnsForme(i);
		for(int j=0;j<tmpForme.GetSize()-1;++j)
		{
			scene->addLine( tmpForme.GetPoint(j).x(),
							-tmpForme.GetPoint(j).y(),
							tmpForme.GetPoint(j+1).x(),
							-tmpForme.GetPoint(j+1).y(),Pen1);
		}
		scene->addLine( tmpForme.GetPoint(0).x(),
						-tmpForme.GetPoint(0).y(),
						tmpForme.GetPoint(tmpForme.GetSize()-1).x(),
						-tmpForme.GetPoint(tmpForme.GetSize()-1).y(),Pen1);
	}
//Mise au point
	if (step==0)
	{
		view->fitInView( view->scene()->sceneRect(), Qt::KeepAspectRatio );
	}

	++step;
}

void Window::refreshViewSpecial()
{
	qreal h=1./128.;//decalage
	for(int i=0; i<fractale->getSizeEnsForme();++i)
	{
		//Special pour cantor car on dessine les ligne une en dessous de l'autre
		//Segment S=F.getFromE(i);
		Forme tmp = fractale->getFromEnsForme(i);
		qreal x=tmp.GetPoint(0).x();
		qreal y=tmp.GetPoint(1).x();
		scene->addLine(x,h*step,y,h*step,Pen1);

	}
//Mise au point
	if (step==0)
	{
		view->fitInView( view->scene()->sceneRect(), Qt::KeepAspectRatio );
	}

	++step;
}

bool Window::eventFilter(QObject *obj, QEvent *event)
{

	if (event->type() == QEvent::GraphicsSceneWheel)
	{
		qDebug()<< "catch whell";
		Zoom(static_cast<QGraphicsSceneWheelEvent*> (event));
		event->accept();//On ne propage pas l'event
		return true;
	}
	return false;
}

void Window::Zoom(QGraphicsSceneWheelEvent *event)
{
	qreal scaleFactor=pow((double)2, event->delta() / 240.0);//Calcul le Facteur de zoom
	//qreal factor = view->transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
	view->scale(scaleFactor, scaleFactor);//Applique le zoom
}
