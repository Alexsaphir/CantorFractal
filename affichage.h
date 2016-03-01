#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPen>

#include <QEvent>
#include <QWheelEvent>
#include <QGraphicsSceneWheelEvent>

#include <QDebug>


//#include "cantor.h"
#include "fractale.h"

class Affichage : public QWidget, public QEvent
{
	Q_OBJECT
public:
	Affichage();
	Fractale F;
protected:
    virtual bool eventFilter(QObject *obj, QEvent *event);
    //virtual void wheelEvent(QWheelEvent *event);
        //virtual void mousePressEvent(QMouseEvent *event);

public slots:
	void Actualiser();
private:
    void Zoom(QGraphicsSceneWheelEvent *event);

private:
	//Cantor F;
	QGraphicsScene *scene;
	QGraphicsView *view;
	QPushButton *BnextStep;
    QPushButton *BZoom;
	QGridLayout *Grid;
	int step;
};

#endif // AFFICHAGE_H
