#ifndef APP_H
#define APP_H

#include <QObject>
#include <QApplication>
#include <QTcpSocket>
#include <QtNetwork/QAbstractSocket>

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
    QTcpSocket *socket;

public slots:
    void connectToServer();
    void socketRead();
    void socketError();

signals:
};

#endif // APP_H
