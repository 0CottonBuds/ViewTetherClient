#include "app.h"
#include <QMainWindow>
#include <QMessageBox>

App::App(int argc, char *argv[]){
    qApplication = new QApplication(argc, argv);
    QMainWindow *mainWindow = new QMainWindow();
    mainWindow->setLayout(new QVBoxLayout());
    clientWidget = new Ui_ClientWidget();
    clientWidget->setupUi(mainWindow);

    clientWidget->streamPage->setLayout(new QVBoxLayout());
    videoWidget = new VideoWidget(clientWidget->streamPage);

    connect(clientWidget->connectButton, &QPushButton::clicked, this, &App::connectToServer);

    mainWindow->showFullScreen();
    mainWindow->show();
    qApplication->exec();
}


void App::connectToServer(){
    try{
        QString ipString =clientWidget->ipLineEdit->text();
        QString portString = clientWidget->portLineEdit->text();
        quint16 port = (quint16) portString.toInt();
        socket = new QTcpSocket();
        socket->connectToHost(ipString, port);

        connect(socket, &QTcpSocket::errorOccurred, this, &App::socketError);
        connect(socket, &QTcpSocket::disconnected, this, [this]{socket = nullptr;});
        connect(socket, &QTcpSocket::readyRead, this, &App::socketRead);
        qDebug() << "Successfully conneted to server" ;

        clientWidget->appRouter->setCurrentWidget(clientWidget->streamPage);
    }
    catch(std::exception e){
        qDebug() << "error connecting to server" ;
    }

}

void App::socketRead(){

}

void App::socketError(){
    QMessageBox *errorMsgBox = new QMessageBox();
    clientWidget->ipLineEdit->setText("");
    clientWidget->portLineEdit->setText("");
    errorMsgBox->setText("Socket Error: " + socket->errorString());
    errorMsgBox->exec();

    clientWidget->appRouter->setCurrentWidget(clientWidget->connectionPage);
}
