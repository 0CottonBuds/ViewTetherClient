#ifndef STREAMCLIENT_H
#define STREAMCLIENT_H

#include <QObject>
#include <QTcpSocket>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/opt.h>
#include <libavutil/imgutils.h>
#include <libswscale/swscale.h>
}


class StreamClient : public QObject
    {
    Q_OBJECT
public:
    StreamClient();
    QTcpSocket* getSocket();

public slots:
    void connectToHost(QString ip, quint16 port);
    void read();

signals:
    void errorOccurred(QString errorString);
    void connected();
    void disconnected();
    void packetReady(AVPacket* packet);

private:
    QTcpSocket *socket;
};

#endif // STREAMCLIENT_H
