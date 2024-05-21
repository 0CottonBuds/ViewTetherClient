/********************************************************************************
** Form generated from reading UI file 'clientwidgetTLpDnV.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CLIENTWIDGETTLPDNV_H
#define CLIENTWIDGETTLPDNV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName("ClientWidget");
        ClientWidget->resize(800, 600);
        centralwidget = new QWidget(ClientWidget);
        centralwidget->setObjectName("centralwidget");
        ClientWidget->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ClientWidget);
        statusbar->setObjectName("statusbar");
        ClientWidget->setStatusBar(statusbar);

        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QMainWindow *ClientWidget)
    {
        ClientWidget->setWindowTitle(QCoreApplication::translate("ClientWidget", "ClientWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CLIENTWIDGETTLPDNV_H
