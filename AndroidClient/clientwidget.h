/********************************************************************************
** Form generated from reading UI file 'clientwidgetYZQxbb.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CLIENTWIDGETYZQXBB_H
#define CLIENTWIDGETYZQXBB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *appRouter;
    QWidget *connectionPage;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *portLineEdit;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ipLineEdit;
    QPushButton *connectButton;
    QWidget *streamPage;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName("ClientWidget");
        ClientWidget->resize(461, 686);
        centralwidget = new QWidget(ClientWidget);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        appRouter = new QStackedWidget(centralwidget);
        appRouter->setObjectName("appRouter");
        connectionPage = new QWidget();
        connectionPage->setObjectName("connectionPage");
        frame_2 = new QFrame(connectionPage);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(30, 180, 381, 42));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        portLineEdit = new QLineEdit(frame_2);
        portLineEdit->setObjectName("portLineEdit");

        horizontalLayout_2->addWidget(portLineEdit);

        frame = new QFrame(connectionPage);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(50, 130, 361, 42));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(frame);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        ipLineEdit = new QLineEdit(frame);
        ipLineEdit->setObjectName("ipLineEdit");

        horizontalLayout->addWidget(ipLineEdit);

        connectButton = new QPushButton(connectionPage);
        connectButton->setObjectName("connectButton");
        connectButton->setGeometry(QRect(170, 260, 75, 24));
        appRouter->addWidget(connectionPage);
        streamPage = new QWidget();
        streamPage->setObjectName("streamPage");
        appRouter->addWidget(streamPage);

        verticalLayout->addWidget(appRouter);

        ClientWidget->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ClientWidget);
        statusbar->setObjectName("statusbar");
        ClientWidget->setStatusBar(statusbar);

        retranslateUi(ClientWidget);

        appRouter->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QMainWindow *ClientWidget)
    {
        ClientWidget->setWindowTitle(QCoreApplication::translate("ClientWidget", "ClientWidget", nullptr));
        label_2->setText(QCoreApplication::translate("ClientWidget", "PORT:", nullptr));
        label->setText(QCoreApplication::translate("ClientWidget", "IP:", nullptr));
        connectButton->setText(QCoreApplication::translate("ClientWidget", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CLIENTWIDGETYZQXBB_H
