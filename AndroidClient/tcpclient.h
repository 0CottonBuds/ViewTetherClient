#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>

class TcpClient : public QObject
    {
    Q_OBJECT
public:
    TcpClient();
    QTcpSocket* getSocket();

public slots:
    void connectToHost(QString ip, quint16 port);
    void readyRead();

signals:
    void errorOccurred(QString errorString);
    void connected();
    void disconnected();

private:
    QTcpSocket *socket;
};

#endif // TCPCLIENT_H
