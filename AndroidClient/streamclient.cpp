#include "streamclient.h"
#include <QAbstractSocket>
#include <QByteArray>

StreamClient::StreamClient() {
    socket = new QTcpSocket();

    connect(socket, &QTcpSocket::connected, this, &StreamClient::connected);
    connect(socket, &QTcpSocket::connected, this, []{qDebug() << "Connected to server!";});
    connect(socket, &QTcpSocket::disconnected, this, &StreamClient::disconnected);
    connect(socket, &QTcpSocket::disconnected, this, []{qDebug() << "Disconnected to server!";});

    connect(socket, &QTcpSocket::errorOccurred, this, [this]{emit errorOccurred(socket->errorString());});
    connect(socket, &QTcpSocket::errorOccurred, this, [this]{qDebug() << socket->errorString();});

    connect(socket, &QTcpSocket::readyRead, this, &StreamClient::read);
}

QTcpSocket *StreamClient::getSocket(){
    return socket;
}

void StreamClient::connectToHost(QString ip, quint16 port){
    socket->connectToHost(ip, port);
}

void StreamClient::read(){
    QByteArray buffer;

    while(socket->bytesAvailable()){
        buffer.append(socket->readAll());
    }
    qDebug() << buffer;

    emit socketReadComplete(buffer);
}
