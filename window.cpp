#include "window.h"

///
/// \brief Window::Window
/// Constructeur par defaut de la classe Window
/// \n Crée les differents objets nécessaire
///
Window::Window() : QMainWindow()
{
	Str1 = "Create Fractal";

	//Type SDI
	SDI_Area = new QWidget;
	GridLayout = new QGridLayout;
	GridLayout2 = new QGridLayout;

	B_createOrAff	= new QPushButton(Str1);
	B_erase			= new QPushButton("Erase");
	B_next			= new QPushButton("Next Step");
	B_load			= new QPushButton("Load");


	scene = new QGraphicsScene;
	view = new QGraphicsView(scene);

	fractale=NULL;
	WGF = new WindowGenFractale;

	this->setWindowTitle("Fractale");
	//Configuration de la vue
	GridLayout->addWidget(view);

	view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	view->setDragMode(QGraphicsView::ScrollHandDrag);
	//Configuration Pen
	Pen1.setWidth(1);
	Pen1.setCosmetic(true);
	//Filtre d'événement pour capturer roulette
	view->scene()->installEventFilter(this);


	//ToolBar
	ToolBar = addToolBar("ToolBar");
	ToolBar->setMovable(false);
	ToolBar->addWidget(B_next);
	ToolBar->addWidget(B_load);
	ToolBar->addWidget(B_createOrAff);
	ToolBar->addSeparator();
	ToolBar->addWidget(B_erase);
	B_next->setDisabled(true);//To test new Fractale in main

	SDI_Area->setLayout(GridLayout);
	setCentralWidget(SDI_Area);

	setWindowTitle("QMainWindow");
	this->resize(800,800);

	connect(B_next, SIGNAL(clicked(bool)), this, SLOT(refreshView()));
	connect(B_load, SIGNAL(clicked(bool)), this, SLOT(load()));
	connect(B_erase, SIGNAL(clicked(bool)), this, SLOT(erase()));
	connect(B_createOrAff, SIGNAL(clicked(bool)), this, SLOT(createOrAff()));

	step=0;
	tweak = false;
	srand(time(NULL));
	this->show();
	this->load();
}

void Window::createOrAff()
{
	Forme forme;
	forme.AddPoint(QPointF(0.,0.));
	int nbr=rand() % 3+1;
	if (fractale != NULL)
		delete fractale;
	view->scene()->clear();
	step=0;
	fractale = new Fractale;

	for (int i = 1; i < nbr; ++i)
	{
		float r1 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/2.));
		float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/2.));
		forme.AddPoint(QPointF(r1,r2));
	}
	fractale->AddForme(forme);
	for (int i = 0; i < nbr; ++i)
	{
		float k = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/.9));
		float r1 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(2.*M_PI)));
		Application A;
		A.setCentre(forme.GetPoint(i));
		A.setK(k);
		A.setm11(qCos(r1));
		A.setm12(-qSin(r1));
		A.setm21(qSin(r1));
		A.setm22(qCos(r1));

		r1 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/2.));
		float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/2.));
		A.setv1(r1);
		A.setv2(r2);
		fractale->AddApplication(A);
		qDebug() <<"Rapport" <<A.getK();
	}
	refreshView();
	B_next->setDisabled(false);
}

void Window::erase()
{
	delete fractale;
	fractale=NULL;
	B_next->setDisabled(true);
	refreshView();
}

///
/// \brief Window::load
/// Affiche une fenetre permettant de choisir une fractale par defaut
///
void Window::load()
{
	QStringList items;
	items << "Cantor" << "triangle de sierpinski" << "Courbe de Koch" << "Flocon de Koch" << "Hata's tree-like set" << "Lévy Curve" << "PentaKun" << "sierpinski carpet";

	bool ok;
	QString item = QInputDialog::getItem(this, "Séléction Fractale", "Fractale:", items, 0, false, &ok);
	if (ok && !item.isEmpty())

	{
		if (fractale != NULL)
			delete fractale;
		view->scene()->clear();
		tweak=false;
		step=0;
		fractale = new Fractale;
		fractale->generateExisting(items.indexOf(item));
		if(items.indexOf(item)==1 || items.indexOf(item)==7)
			tweak=1;

		refreshView();
		B_next->setDisabled(false);// !!!!!!!!!!!
	}

}

///
/// \brief Window::refreshView
/// Dessine la fractale
///
void Window::refreshView()
{
	//Permet d'afficher la fractale a l'écran

	if(fractale == NULL)
	{
		scene->clear();
		return;//Si Aucune fractale n'a été créé on n'affiche rien
	}
	if(step!=0)
		fractale->RunOnce();
	if(fractale->isLikeCantor())
	{
		refreshViewSpecialCantor();
		return;
	}
	else if(tweak)
	{
		refreshViewColor();
		return;
	}
	scene->clear();//Efface l'écran

	for(int i=0; i<fractale->getSizeEnsForme();++i)
	{
		QPainterPath path;
		Forme tmpForme=fractale->getFromEnsForme(i);
		for(int j=0; j<tmpForme.GetSize();++j)
		{
			if (j==0)
				path.moveTo(tmpForme.GetPoint(j).x(), -tmpForme.GetPoint(j).y());//On doit mettre des moints car l'axe des y est orienté negativement
			else if(j<tmpForme.GetSize()-1)
				path.lineTo(tmpForme.GetPoint(j).x(), -tmpForme.GetPoint(j).y());
			else
			{
				path.lineTo(tmpForme.GetPoint(j).x(), -tmpForme.GetPoint(j).y());
				path.lineTo(tmpForme.GetPoint(0).x(), -tmpForme.GetPoint(0).y());
			}
			view->scene()->addPath(path, Pen1);
		}
	}
	//Mise au point
	if (step==0)
	{
		view->fitInView( view->scene()->sceneRect(), Qt::KeepAspectRatio );
	}



	++step;
}

///
/// \brief Window::refreshViewSpecialCantor
/// Dessine de la fractale de typeCantor
///
void Window::refreshViewSpecialCantor()
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

///
/// \brief Window::refreshViewColor
/// Dessine la fractale en colorant l'intérieur de la figure
///
void Window::refreshViewColor()
{
	scene->clear();

	for(int i=0; i<fractale->getSizeEnsForme();++i)
	{
		QPainterPath path;
		Forme tmpForme=fractale->getFromEnsForme(i);
		for(int j=0; j<tmpForme.GetSize();++j)
		{
			if (j==0)
				path.moveTo(tmpForme.GetPoint(j).x(), -tmpForme.GetPoint(j).y());//On doit mettre des moints car l'axe des y est orrienté negativement
			else if(j<tmpForme.GetSize()-1)
				path.lineTo(tmpForme.GetPoint(j).x(), -tmpForme.GetPoint(j).y());
			else
			{
				path.lineTo(tmpForme.GetPoint(j).x(), -tmpForme.GetPoint(j).y());
				path.lineTo(tmpForme.GetPoint(0).x(), -tmpForme.GetPoint(0).y());
			}
			view->scene()->addPath(path, Qt::NoPen, QBrush(QColor("dark")));
		}
	}
	//Mise au point
	if (step==0)
	{
		view->fitInView( view->scene()->sceneRect(), Qt::KeepAspectRatio );
	}
	++step;
}

///
/// \brief Window::eventFilter
/// Filtre d'évenement pour capturer les evenemts spécifique
/// \param obj
/// \param event
/// \return
///
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

///
/// \brief Window::Zoom
/// Est Appelé quand l'évenement QEvent::GraphicsSceneWheel est capturé
/// \param event
///
void Window::Zoom(QGraphicsSceneWheelEvent *event)
{
	qreal scaleFactor=pow((double)2, event->delta() / 240.0);//Calcul le Facteur de zoom
	//qreal factor = view->transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
	view->scale(scaleFactor, scaleFactor);//Applique le zoom
}


/*QPrinter printer(QPrinter::HighResolution);
	printer.setOutputFileName("print.ps");
	QPainter painter;
	painter.begin(&printer);

	view->render(&painter);

	painter.end();
	*/
