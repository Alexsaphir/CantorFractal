#ifndef WINDOW_H
#define WINDOW_H

#include <QtWidgets>

class Window : public QMainWindow
{
public:
	Window();

protected:
	virtual bool eventFilter(QObject *obj, QEvent *event);

private:
	void Zoom(QGraphicsSceneWheelEvent *event);
	void refreshView();
	void loadExistingFractal(quint64);

private:
	QWidget *SDI_Area;
	QGridLayout *GridLayout;
	QToolBar *ToolBar;

	QGraphicsView *view;
	QGraphicsScene *scene;


	QPushButton *B_next;
};

#endif // WINDOW_H
