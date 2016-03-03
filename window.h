#ifndef WINDOW_H
#define WINDOW_H
#include <QtWidgets>
#include <QInputDialog>

#include <QtGlobal>
#include <QtMath>

#include "fractale.h"

class Window : public QMainWindow
{
	Q_OBJECT
public:
	Window();

protected:
	virtual bool eventFilter(QObject *obj, QEvent *event);

private:
	void Zoom(QGraphicsSceneWheelEvent *event);
	void loadExistingFractal(quint64);
	void refreshViewSpecial();

public slots:
	void load();
	void refreshView();


private:
	QWidget *SDI_Area;
	QGridLayout *GridLayout;
	QToolBar *ToolBar;

	QGraphicsView *view;
	QGraphicsScene *scene;
	QPen Pen1;


	QPushButton *B_next;
	QPushButton *B_load;

	Fractale *fractale;
	quint32 step;
};

#endif // WINDOW_H
