#include "app.h"
#include <QMainWindow>

App::App(int argc, char *argv[]){
    qApplication = new QApplication(argc, argv);
    QMainWindow *mainWindow = new QMainWindow();
    mainWindow->setLayout(new QVBoxLayout());
    clientWidget = new Ui_ClientWidget();
    clientWidget->setupUi(mainWindow);

    clientWidget->streamPage->setLayout(new QVBoxLayout());
    QLayout *streamPageLayout = clientWidget->streamPage->layout();
    streamPageLayout->addWidget(&videoWidget);

    mainWindow->showFullScreen();
    mainWindow->show();
    qApplication->exec();
}
