#ifndef STREAMCLIENT_H
#define STREAMCLIENT_H

#include <QObject>
#include <QTcpSocket>

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
    void socketReadComplete(QByteArray data);

private:
    QTcpSocket *socket;
};

#endif // STREAMCLIENT_H
