#include "streamclient.h"
#include <QAbstractSocket>

StreamClient::StreamClient() {
    socket = new QTcpSocket();
}

QTcpSocket *StreamClient::getSocket(){
    return socket;
}

void StreamClient::connectToHost(QString ip, quint16 port){
    socket->connectToHost(ip, port);

    connect(socket, &QTcpSocket::connected, this, &StreamClient::connected);
    connect(socket, &QTcpSocket::disconnected, this, &StreamClient::disconnected);
    connect(socket, &QTcpSocket::errorOccurred, this, [this]{emit errorOccurred(socket->errorString());});
    connect(socket, &QTcpSocket::errorOccurred, this, [this]{qDebug() << socket->errorString();});
    connect(socket, &QTcpSocket::readyRead, this, &StreamClient::readyRead);
}

void StreamClient::readyRead()
{
    qDebug() << "ready to read on socket";
}
