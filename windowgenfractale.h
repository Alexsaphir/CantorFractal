#ifndef WINDOWGENFRACTALE_H
#define WINDOWGENFRACTALE_H

#include <QWidget>
#include <QTabWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QScrollArea>

class WindowGenFractale : public QScrollArea
{

public:
    WindowGenFractale();

private:
    QTabWidget *tabWidget;
    QGridLayout *gridLayout;
    QList<QPushButton*> listButton;
	QWidget *widget;
};

#endif // WINDOWGENFRACTALE_H
