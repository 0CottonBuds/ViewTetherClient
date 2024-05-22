#include "app.h"
#include <QMainWindow>

App::App(int argc, char *argv[]){
    qApplication = new QApplication(argc, argv);
    QMainWindow *mainWindow = new QMainWindow();
    clientWidget = new Ui_ClientWidget();
    clientWidget->setupUi(mainWindow);


    mainWindow->showMaximized();
    mainWindow->show();
    qApplication->exec();
}
