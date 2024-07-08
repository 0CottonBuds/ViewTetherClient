QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    StreamCodec.cpp \
    app.cpp \
    main.cpp \
    streamclient.cpp

HEADERS += \
    StreamCodec.h \
    VIdeoWidget.h \
    app.h \
    clientwidget.h \
    streamclient.h

FORMS += \
    clientwidget.ui

#ffmpeg path
INCLUDEPATH = "C:/Users/Cotton-Orion/Documents/ffmpeg_x86_android/include"
LIBS += -L"C:/Users/Cotton-Orion/Documents/ffmpeg_x86_android/lib" -lavcodec -lavdevice -lavfilter -lavformat -lavutil -lswresample -lswscale
#LIBS += -landroid


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    android-source/AndroidManifest.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-source/
