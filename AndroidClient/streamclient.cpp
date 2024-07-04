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
    QByteArray headerBodyBuffer;
    headerBodyBuffer.resize(headerSize);
    headerStream.readRawData(headerBodyBuffer.data(), headerSize);
    std::string packetIdentifier = QString::fromUtf8(headerBodyBuffer).toStdString();

    QByteArray bodyBuffer;
    QDataStream bodyStream(&bodyBuffer, QIODevice::ReadOnly);

    //read body size
    bodyBuffer.append(socket->read(4));
    qint32 bodySize;
    bodyStream >> bodySize;

    // note data is after 4 bytes
    // read body data
    // loop until packet buffer has all the data
    bodyBuffer.append(socket->read(bodySize));
    while(bodyBuffer.size() - (qint32) sizeof(qint32) < bodySize){
        if(socket->waitForReadyRead(3000)){
            bodyBuffer.append(socket->read(bodySize - bodyBuffer.size() - sizeof(qint32)));
        }
        else{
            qDebug() << "Timeout or error occurred";
            exit(1);
        }
    }


    if(packetIdentifier == "msg"){
        qDebug() << "Host Message: " <<  bodyBuffer.mid(4);
        return;
    }
    else if(packetIdentifier == "pkt"){
        qDebug() << "packet acquired";

        AVPacket *avPacket = av_packet_alloc();

        avPacket->size = bodySize;
        avPacket->data = (unsigned char *) av_malloc(bodySize);

        if(!avPacket->data){
            qDebug() << "Error allocating memory on avpacket.data";
            exit(1);
        }

        memcpy(avPacket->data, bodyBuffer.data(), bodySize);
    }
}
