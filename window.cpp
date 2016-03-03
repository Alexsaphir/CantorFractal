#include "window.h"

Window::Window() : QMainWindow()
{
	//Type SDI
	SDI_Area = new QWidget;
	GridLayout = new QGridLayout;
	B_next = new QPushButton("Next Step");
	scene = new QGraphicsScene;
	view = new QGraphicsView(scene);

	GridLayout->addWidget(view);

	//Configuration de la vue
	view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	view->setDragMode(QGraphicsView::ScrollHandDrag);
	//Filtre d'événement
	view->scene()->installEventFilter(this);
	ToolBar = addToolBar("ToolBar");


	ToolBar->setMovable(false);

	ToolBar->addWidget(B_next);






	SDI_Area->setLayout(GridLayout);
	setCentralWidget(SDI_Area);

	setWindowTitle("QMainWindow");
	this->resize(800,800);
}

void Window::refreshView()
{
	//Permet d'afficher la fractale a l'écran
	scene->clear();//Efface l'écran
}




bool Window::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::GraphicsSceneWheel)
	{
		Zoom(static_cast<QGraphicsSceneWheelEvent*> (event));
		event->accept();//On ne propage pas l'event
		return true;
	}
	return false;
}

void Window::Zoom(QGraphicsSceneWheelEvent *event)
{
	qreal scaleFactor=pow((double)2, event->delta() / 240.0);//Calcul le Facteur de zoom
	qreal factor = view->transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
	view->scale(scaleFactor, scaleFactor);//Applique le zoom
}
