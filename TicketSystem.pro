QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql network

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#程序图标
#RC_ICONS = "ticketingsystem.ico"
include(./qtsingleapplication/qtsingleapplication.pri)
SOURCES += \
    dbhelper.cpp \
    http.cpp \
    listwidget.cpp \
    login.cpp \
    main.cpp \
    movie.cpp \
    personalinfo.cpp \
    shadowwidget.cpp \
    showingmovie.cpp \
    ticketingsystem.cpp \
    user.cpp

HEADERS += \
    dbhelper.h \
    http.h \
    listwidget.h \
    login.h \
    movie.h \
    personalinfo.h \
    shadowwidget.h \
    showingmovie.h \
    ticketingsystem.h \
    user.h

FORMS += \
    login.ui \
    personalinfo.ui \
    showingmovie.ui \
    ticketingsystem.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
