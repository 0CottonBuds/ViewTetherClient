#ifndef APP_H
#define APP_H

#include <QObject>
#include <QApplication>

#ifdef Q_OS_ANDROID
#include <QJniObject>
#include <QJniEnvironment>
#include <QtCore/private/qandroidextras_p.h>
#include <QtCore>
#endif

#include <streamclient.h>
#include "clientwidget.h"
#include "VIdeoWidget.h"
#include "StreamCodec.h"
#include <QThread>

class App : public QObject
{
    Q_OBJECT
public:
    App(int argc, char *argv[]);
    ~App();

private:
    QApplication *qApplication;
    Ui_ClientWidget *clientWidget;
    VideoWidget *videoWidget;
    StreamClient *streamClient;
    QThread streamDecoderThread;
    StreamCodec *streamDecoder;

    void initializeThreads();
    void initializeVideoWidget();
    void initializeButtons();
    void initializeMainEventLoop();
    void initializeOrientation();

public slots:
    void connectToServer();
    void socketError(QString errorString);
    void processFrame(AVFrame *frame);
    void setOrientationLandscape();
    void setOrientationPortrait();

signals:
    void imageReady(std::shared_ptr<QImage> img);
};

#endif // APP_H
