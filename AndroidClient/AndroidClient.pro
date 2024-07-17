QT       += core gui network core-private


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
INCLUDEPATH = "./FFmpeg-libs/include"
#LIBS += -L$$PWD\FFmpeg-lib\lib -lavcodec -lavdevice -lavfilter -lavformat -lavutil -lswresample -lswscale

android:contains(QT_ARCH, arm64-v8a) {
    message("arm64!");
    LIBS += -L"C:\Users\Cotton-Orion\Documents\Screen-Capture-Android-Client\AndroidClient\FFmpeg-libs\lib\android-arm64" -lavcodec -lavdevice -lavfilter -lavformat -lavutil -lswresample -lswscale
}

android:contains(QMAKE_HOST.arch, x86_64){
    LIBS += -L"C:\Users\Cotton-Orion\Documents\Screen-Capture-Android-Client\AndroidClient\FFmpeg-libs\android-x86\lib" -lavcodec -lavdevice -lavfilter -lavformat -lavutil -lswresample -lswscale
}

contains(QMAKE_HOST.arch, x86_64){
    LIBS += -L"C:\Users\Cotton-Orion\Documents\Screen-Capture-Android-Client\AndroidClient\win-64\FFmpeg-libs\lib" -lavcodec -lavdevice -lavfilter -lavformat -lavutil -lswresample -lswscale
}

android {
    LIBS += -landroid
}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../README.md \
    android-source/AndroidManifest.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-source/
