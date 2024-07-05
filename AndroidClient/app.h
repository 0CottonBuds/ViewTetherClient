#ifndef APP_H
#define APP_H

#include <QObject>
#include <QApplication>
#include <streamclient.h>

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
    VideoWidget *videoWidget;
    StreamClient streamClient;

public slots:
    void connectToServer();
    void socketError(QString errorString);

signals:
};

#endif // APP_H
