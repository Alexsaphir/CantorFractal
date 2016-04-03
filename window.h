#ifndef WINDOW_H
#define WINDOW_H

#include <QtWidgets>
#include <QInputDialog>
#include <QtPrintSupport/QPrinter>
#include <QScrollArea>

#include "fractale.h"
#include "windowgenfractale.h"

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
	void erase();
	void createOrAff();


private:
	QWidget *SDI_Area;
	QGridLayout *GridLayout;
	QGridLayout *GridLayout2;
	QToolBar *ToolBar;

	QGraphicsView *view;
	QGraphicsScene *scene;
	QScrollArea *Scroll;
	WindowGenFractale *WGF;
	QPen Pen1;

	QPushButton *B_next;
	QPushButton *B_load;
	QPushButton *B_createOrAff;
	QPushButton *B_erase;

	QString Str1;
	QString Str2;

	quint32 step;
};

#endif // WINDOW_H
