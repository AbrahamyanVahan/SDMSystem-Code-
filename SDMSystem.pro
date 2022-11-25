QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    frame.cpp \
    main.cpp \
    mainsdms.cpp \
    mainwindow.cpp \
    registerwindow.cpp \
    taskframe.cpp

HEADERS += \
    frame.h \
    mainsdms.h \
    mainwindow.h \
    registerwindow.h \
    taskframe.h

FORMS += \
    frame.ui \
    mainsdms.ui \
    mainwindow.ui \
    registerwindow.ui \
    taskframe.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    SDMSystem.pro.user

RESOURCES += \
    images.qrc
