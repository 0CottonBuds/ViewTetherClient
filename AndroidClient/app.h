#ifndef APP_H
#define APP_H

#include <QObject>
#include <QApplication>

#include "clientwidget.h"
#include "VIdeoWidget.h"

class App : public QObject
{
    Q_OBJECT
public:
    App(int argc, char *argv[]);

private:
    QApplication *qApplication;
    Ui_ClientWidget *clientWidget;
    VideoWidget videoWidget;

signals:
};

#endif // APP_H
