#include <QApplication>

#include <app.h>
#include <tcpclient.h>

int main(int argc, char *argv[])
{
    //App app = App(argc, argv);
    QApplication app(argc, argv);
    TcpClient client;
    client.connectToHost("localhost", 9999);
    app.exec();
    return 0;
}
