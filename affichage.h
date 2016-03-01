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

#include <math.h>

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
    //void scaleView(double scalefactor);

private:
	//Cantor F;
	QGraphicsScene *scene;
	QGraphicsView *view;
	QPushButton *BnextStep;
    QPushButton *BZoom;
	QGridLayout *Grid;
    QPen Pen1;
	int step;

    //float ZoomFactor;
};

#endif // AFFICHAGE_H
