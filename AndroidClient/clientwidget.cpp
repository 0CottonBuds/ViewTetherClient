#include "clientwidget.h"
#include "ui_clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
}

ClientWidget::~ClientWidget()
{
    delete ui;
}
