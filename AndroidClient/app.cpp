#include "app.h"
#include <QMainWindow>
#include <QMessageBox>

App::App(int argc, char *argv[]){
    qApplication = new QApplication(argc, argv);
    QMainWindow *mainWindow = new QMainWindow();
    clientWidget = new Ui_ClientWidget();
    clientWidget->setupUi(mainWindow);

    streamClient = new StreamClient();
    streamDecoder = new StreamCodec(1080, 1920, 60, CodecType::decode);
    streamDecoder->run();

    initializeVideoWidget();
    initializeButtons();
    initializeMainEventLoop();
    initializeOrientation();;

    #ifdef Q_OS_ANDROID
        mainWindow->showFullScreen();
    #endif
    mainWindow->show();
    qApplication->exec();
}

void App::initializeVideoWidget(){
    clientWidget->streamPage->setLayout(new QVBoxLayout());
    auto streamPageLayout = clientWidget->streamPage->layout();
    streamPageLayout->setSpacing(0);
    videoWidget = new VideoWidget();
    streamPageLayout->addWidget(videoWidget);
}

void App::initializeButtons(){
    connect(clientWidget->connectButton, &QPushButton::clicked, this, &App::connectToServer);
    connect(clientWidget->aboutButton, &QPushButton::clicked, this, [this]{clientWidget->appRouter->setCurrentWidget(clientWidget->settingsPage);});
    connect(clientWidget->connectionPageButton, &QPushButton::clicked, this, [this]{clientWidget->appRouter->setCurrentWidget(clientWidget->connectionPage);});
    connect(clientWidget->backButton, &QPushButton::clicked, this, [this]{clientWidget->appRouter->setCurrentWidget(clientWidget->welcomePage);});



}

void App::initializeMainEventLoop(){
    connect(streamClient, &StreamClient::packetReady, streamDecoder, &StreamCodec::decodePacket);
    connect(streamDecoder, &StreamCodec::decodeFinish, this, &App::processFrame);
    connect(this, &App::imageReady, videoWidget, &VideoWidget::updateImage);
}

void App::initializeOrientation(){
    connect(streamClient, &StreamClient::connected, this, &App::setOrientationLandscape);
    connect(streamClient, &StreamClient::disconnected, this, &App::setOrientationPortrait);
    connect(streamClient, &StreamClient::errorOccurred, this, &App::setOrientationPortrait);
}


void App::connectToServer(){
    try{
        QString ipString =clientWidget->ipLineEdit->text();
        QString portString = clientWidget->portLineEdit->text();
        quint16 port = (quint16) portString.toInt();
        streamClient->connectToHost(ipString, port);

        connect(streamClient, &StreamClient::errorOccurred, this, &App::socketError);

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

void App::processFrame(AVFrame *frame){
    QImage *image = new QImage(frame->data[0], 1920, 1080, QImage::Format_RGBA8888);
    std::shared_ptr<QImage> rgbSwappedImage = std::shared_ptr<QImage>(new QImage(image->rgbSwapped()));
    delete image;

    emit imageReady(rgbSwappedImage);

    av_frame_free(&frame);
}

void App::setOrientationLandscape(){
    #ifdef Q_OS_ANDROID
        qDebug() << "Setting orientation to landscape";
        QJniObject activity = QNativeInterface::QAndroidApplication::context();
        if(activity.isValid()){
            QJniObject::callStaticMethod<void>("org/qtproject/example/AndroidClient/MainActivity",
                                               "setOrientationLandscape",
                                               "(Landroid/app/Activity;)V",
                                               activity.object<jobject>());
        }
    #endif
}

void App::setOrientationPortrait(){
    #if defined(Q_OS_ANDROID)
        qDebug() << "Setting orientation to portrait";
        QJniObject activity = QNativeInterface::QAndroidApplication::context();
        if(activity.isValid()){
            QJniObject::callStaticMethod<void>("org/qtproject/example/AndroidClient/MainActivity",
                                               "setOrientationPortrait",
                                               "(Landroid/app/Activity;)V",
                                               activity.object<jobject>());
        }
    #endif
}
