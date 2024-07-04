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
    // packet identifier can be of these types
    // msg = messages
    // pkt = AVPacket
    // err = error messages
    QByteArray headerBuffer;
    QDataStream headerStream(&headerBuffer, QIODevice::ReadOnly);

    // read header size
    headerBuffer.append(socket->read(4));
    qint32 headerSize;
    headerStream >> headerSize;

    // read header data
    headerBuffer.append(socket->read(headerSize));
    QByteArray headerIdentifierBuffer;
    headerIdentifierBuffer.resize(headerSize);
    headerStream.readRawData(headerIdentifierBuffer.data(), headerSize);
    std::string headerIdentifier = QString::fromUtf8(headerIdentifierBuffer).toStdString();

    // contains the data of the packet
    QByteArray bodyBuffer;
    QDataStream bodyStream(&bodyBuffer, QIODevice::ReadOnly);

    //read body size
    bodyBuffer.append(socket->read(4));
    qint32 bodySize;
    bodyStream >> bodySize;

    // note data is after 4 bytes
    // read body data
    // loop until packet buffer has all the data
    while(socket->bytesAvailable() < bodySize){
        socket->waitForReadyRead();
    }
    bodyBuffer.append(socket->read(bodySize));


    if(headerIdentifier == "msg"){
        qDebug() << "Host Message: " <<  bodyBuffer.mid(4);
        return;
    }
    else if(headerIdentifier == "pkt"){
        qDebug() << "packet acquired";

        AVPacket *avPacket = av_packet_alloc();

        avPacket->size = bodySize;
        avPacket->data = (unsigned char *) av_malloc(bodySize);

        if(!avPacket->data){
            qDebug() << "Error allocating memory on avpacket.data";
            exit(1);
        }

        memcpy(avPacket->data, bodyBuffer.mid(4).data(), bodySize);
        packetReady(avPacket);
    }
}
