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
        streamClient.connectToHost(ipString, port);

        connect(&streamClient, &StreamClient::errorOccurred, this, &App::socketError);

        clientWidget->appRouter->setCurrentWidget(clientWidget->streamPage);
    }
    catch(std::exception e){
        qDebug() << "error connecting to server" ;
    }
}

void App::socketError(QString errorString){
    QMessageBox *errorMsgBox = new QMessageBox();
    clientWidget->ipLineEdit->setText("");
    clientWidget->portLineEdit->setText("");
    errorMsgBox->setText("Socket Error: " + errorString);
    errorMsgBox->exec();

    clientWidget->appRouter->setCurrentWidget(clientWidget->connectionPage);
}
