#include <QApplication>

#include <app.h>
#include <streamclient.h>
#include <QNetworkProxy>

int main(int argc, char *argv[])
{
    //App app = App(argc, argv);
    QApplication app(argc, argv);

    QTcpSocket *socket = new QTcpSocket();

    QObject::connect(socket, &QTcpSocket::connected, []() {
        qDebug() << "Connected to server";
    });

    QObject::connect(socket, &QTcpSocket::disconnected, []() {
        qDebug() << "Disconnected from server";
    });

    QObject::connect(socket, &QTcpSocket::readyRead, [socket]() {
        QByteArray data = socket->readAll();
        qDebug() << "Received data:" << data;
    });

    QObject::connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::errorOccurred), [socket](QAbstractSocket::SocketError socketError) {
        qDebug() << "Socket error:" << socket->errorString();
    });

    socket->setProxy(QNetworkProxy::NoProxy);
    socket->connectToHost("192.168.56.1", 9999);

    if (!socket->waitForConnected()) { // 3000 ms timeout for the connection
        qDebug() << "Connection failed:" << socket->errorString();
        //return -1;
    }

    socket->write("Hello\n");

    return app.exec();
    return 0;
}
