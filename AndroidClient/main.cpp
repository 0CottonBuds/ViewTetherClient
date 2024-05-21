#include "clientwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow *mainWindow = new QMainWindow();
    Ui_ClientWidget clientWidget;
    clientWidget.setupUi(mainWindow);
    mainWindow->show();
    return a.exec();
}
