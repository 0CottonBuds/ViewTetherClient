#include "tcpclient.h"
#include <QAbstractSocket>

TcpClient::TcpClient() {
    socket = new QTcpSocket();
}

QTcpSocket *TcpClient::getSocket(){
    return socket;
}

void TcpClient::connectToHost(QString ip, quint16 port){
    socket->connectToHost(ip, port);

    connect(socket, &QTcpSocket::connected, this, &TcpClient::connected);
    connect(socket, &QTcpSocket::disconnected, this, &TcpClient::disconnected);
    connect(socket, &QTcpSocket::errorOccurred, this, [this]{emit errorOccurred(socket->errorString());});
    connect(socket, &QTcpSocket::errorOccurred, this, [this]{qDebug() << socket->errorString();});
    connect(socket, &QTcpSocket::readyRead, this, &TcpClient::readyRead);
}

void TcpClient::readyRead()
{
    qDebug() << "ready to read on socket";
}
