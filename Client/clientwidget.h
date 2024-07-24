/********************************************************************************
** Form generated from reading UI file 'clientwidgetjkgLAN.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CLIENTWIDGETJKGLAN_H
#define CLIENTWIDGETJKGLAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QWidget *settingsPage;
    QPushButton *backButton;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *serverButton;
    QPushButton *clientButton;
    QPushButton *linkedinButton;
    QPushButton *githubButton;
    QPushButton *facebookButton;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *websiteButton;
    QWidget *welcomePage;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QPushButton *connectionPageButton;
    QPushButton *aboutButton;
    QSpacerItem *verticalSpacer_3;
    QWidget *connectionPage;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ipLineEdit;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *portLineEdit;
    QPushButton *connectButton;
    QPushButton *backButton1;
    QSpacerItem *verticalSpacer;
    QWidget *streamPage;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName("ClientWidget");
        ClientWidget->resize(434, 686);
        centralwidget = new QWidget(ClientWidget);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        appRouter = new QStackedWidget(centralwidget);
        appRouter->setObjectName("appRouter");
        settingsPage = new QWidget();
        settingsPage->setObjectName("settingsPage");
        backButton = new QPushButton(settingsPage);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(16, 16, 71, 31));
        label_6 = new QLabel(settingsPage);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(192, 16, 89, 33));
        QFont font;
        font.setPointSize(16);
        label_6->setFont(font);
        label_7 = new QLabel(settingsPage);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(16, 88, 417, 81));
        label_7->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_7->setWordWrap(true);
        serverButton = new QPushButton(settingsPage);
        serverButton->setObjectName("serverButton");
        serverButton->setGeometry(QRect(24, 232, 75, 33));
        clientButton = new QPushButton(settingsPage);
        clientButton->setObjectName("clientButton");
        clientButton->setGeometry(QRect(24, 280, 75, 33));
        linkedinButton = new QPushButton(settingsPage);
        linkedinButton->setObjectName("linkedinButton");
        linkedinButton->setGeometry(QRect(24, 392, 75, 41));
        githubButton = new QPushButton(settingsPage);
        githubButton->setObjectName("githubButton");
        githubButton->setGeometry(QRect(24, 448, 75, 41));
        facebookButton = new QPushButton(settingsPage);
        facebookButton->setObjectName("facebookButton");
        facebookButton->setGeometry(QRect(24, 504, 75, 41));
        label_8 = new QLabel(settingsPage);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(24, 184, 257, 33));
        label_8->setFont(font);
        label_9 = new QLabel(settingsPage);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(24, 336, 257, 33));
        label_9->setFont(font);
        websiteButton = new QPushButton(settingsPage);
        websiteButton->setObjectName("websiteButton");
        websiteButton->setGeometry(QRect(24, 560, 75, 41));
        appRouter->addWidget(settingsPage);
        welcomePage = new QWidget();
        welcomePage->setObjectName("welcomePage");
        verticalLayout_4 = new QVBoxLayout(welcomePage);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(welcomePage);
        label_3->setObjectName("label_3");
        QFont font1;
        font1.setPointSize(20);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        frame_3 = new QFrame(welcomePage);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(frame_3);
        label_4->setObjectName("label_4");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_4);

        connectionPageButton = new QPushButton(frame_3);
        connectionPageButton->setObjectName("connectionPageButton");
        connectionPageButton->setMinimumSize(QSize(0, 50));

        verticalLayout_3->addWidget(connectionPageButton);

        aboutButton = new QPushButton(frame_3);
        aboutButton->setObjectName("aboutButton");
        aboutButton->setMinimumSize(QSize(0, 50));

        verticalLayout_3->addWidget(aboutButton);


        verticalLayout_4->addWidget(frame_3);

        verticalSpacer_3 = new QSpacerItem(20, 200, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_3);

        appRouter->addWidget(welcomePage);
        connectionPage = new QWidget();
        connectionPage->setObjectName("connectionPage");
        verticalLayout_2 = new QVBoxLayout(connectionPage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_2);

        frame_4 = new QFrame(connectionPage);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_5 = new QLabel(frame_4);
        label_5->setObjectName("label_5");
        QFont font2;
        font2.setPointSize(12);
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_5);


        verticalLayout_2->addWidget(frame_4);

        frame = new QFrame(connectionPage);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(frame);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        ipLineEdit = new QLineEdit(frame);
        ipLineEdit->setObjectName("ipLineEdit");
        ipLineEdit->setMaxLength(50);
        ipLineEdit->setCursorPosition(0);
        ipLineEdit->setClearButtonEnabled(false);

        horizontalLayout->addWidget(ipLineEdit);


        verticalLayout_2->addWidget(frame);

        frame_2 = new QFrame(connectionPage);
        frame_2->setObjectName("frame_2");
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


        verticalLayout_2->addWidget(frame_2);

        connectButton = new QPushButton(connectionPage);
        connectButton->setObjectName("connectButton");

        verticalLayout_2->addWidget(connectButton);

        backButton1 = new QPushButton(connectionPage);
        backButton1->setObjectName("backButton1");

        verticalLayout_2->addWidget(backButton1);

        verticalSpacer = new QSpacerItem(20, 300, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        verticalLayout_2->addItem(verticalSpacer);

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

        appRouter->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QMainWindow *ClientWidget)
    {
        ClientWidget->setWindowTitle(QCoreApplication::translate("ClientWidget", "ClientWidget", nullptr));
        backButton->setText(QCoreApplication::translate("ClientWidget", "Back", nullptr));
        label_6->setText(QCoreApplication::translate("ClientWidget", "About", nullptr));
        label_7->setText(QCoreApplication::translate("ClientWidget", "View Tether Client is an Desktop and Android application designed to receive and display pixel data streamed from the View Tether Server. This allows your other device to function as a secondary screen for your Windows machine. Make sure to have the View Tether application installed and running on your Windows computer.", nullptr));
        serverButton->setText(QCoreApplication::translate("ClientWidget", "Server", nullptr));
        clientButton->setText(QCoreApplication::translate("ClientWidget", "Client", nullptr));
        linkedinButton->setText(QCoreApplication::translate("ClientWidget", "Linkedin", nullptr));
        githubButton->setText(QCoreApplication::translate("ClientWidget", "Github", nullptr));
        facebookButton->setText(QCoreApplication::translate("ClientWidget", "Facebook", nullptr));
        label_8->setText(QCoreApplication::translate("ClientWidget", "Open Source Repositories", nullptr));
        label_9->setText(QCoreApplication::translate("ClientWidget", "My Socials", nullptr));
        websiteButton->setText(QCoreApplication::translate("ClientWidget", "Website", nullptr));
        label_3->setText(QCoreApplication::translate("ClientWidget", "Welcome to View Tether Client", nullptr));
        label_4->setText(QCoreApplication::translate("ClientWidget", "To get Started", nullptr));
        connectionPageButton->setText(QCoreApplication::translate("ClientWidget", "Connect to Server", nullptr));
        aboutButton->setText(QCoreApplication::translate("ClientWidget", "About", nullptr));
        label_5->setText(QCoreApplication::translate("ClientWidget", "Connect using the address in your View Tether server", nullptr));
        label->setText(QCoreApplication::translate("ClientWidget", "IP:", nullptr));
        label_2->setText(QCoreApplication::translate("ClientWidget", "PORT:", nullptr));
        connectButton->setText(QCoreApplication::translate("ClientWidget", "Connect", nullptr));
        backButton1->setText(QCoreApplication::translate("ClientWidget", "Go Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CLIENTWIDGETJKGLAN_H
