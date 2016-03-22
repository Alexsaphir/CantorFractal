#ifndef WINDOWGENFRACTALE_H
#define WINDOWGENFRACTALE_H

#include <QWidget>
#include <QTabWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QScrollArea>

class WindowGenFractale : public QWidget
{

public:
    WindowGenFractale();

private:
    QTabWidget *tabWidget;
    QGridLayout *gridLayout;
    QList<QPushButton*> listButton;
    QScrollArea *scroll;
};

#endif // WINDOWGENFRACTALE_H
