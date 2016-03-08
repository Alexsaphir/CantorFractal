#ifndef WINDOW_H
#define WINDOW_H
#include <QtWidgets>
#include <QInputDialog>

#include <QtGlobal>
#include <QtMath>
#include <QtPrintSupport/QPrinter>

#include "fractale.h"

class Window : public QMainWindow
{
	Q_OBJECT
public:
	Window();

	bool tweak;
	Fractale *fractale;
protected:
	virtual bool eventFilter(QObject *obj, QEvent *event);

private:
	void Zoom(QGraphicsSceneWheelEvent *event);
	void loadExistingFractal(quint64);
	void refreshViewSpecialCantor();
	void refreshViewColor();

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


	quint32 step;
};

#endif // WINDOW_H
