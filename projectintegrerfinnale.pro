QT       += core gui
QT += core gui sql multimedia multimediawidgets
QT       += core gui network
QT       += core gui printsupport
QT += quick  3dcore 3drender 3dinput 3dquick 3dextras 3dquickextras multimedia
QT +=     multimedia
QT +=    serialport
QT += core widgets charts
QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abonnementcode.cpp \
    admin.cpp \
    anglais.cpp \
    arduino.cpp \
    avions.cpp \
    clients.cpp \
    connexion.cpp \
    constructeur.cpp \
    destination.cpp \
    employe.cpp \
    fournisseur.cpp \
    gerer_vols.cpp \
    gestion.cpp \
    main.cpp \
    mainwindow.cpp \
    parkingcode.cpp \
    prodect.cpp \
    promotions.cpp \
    qcustomplot.cpp \
    shift.cpp \
    smtp.cpp

HEADERS += \
    abonnementcode.h \
    admin.h \
    anglais.h \
    arduino.h \
    avions.h \
    clients.h \
    connexion.h \
    constructeur.h \
    destination.h \
    employe.h \
    fournisseur.h \
    gerer_vols.h \
    gestion.h \
    mainwindow.h \
    parkingcode.h \
    prodect.h \
    promotions.h \
    qcustomplot.h \
    shift.h \
    smtp.h

FORMS += \
    anglais.ui \
    gestion.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    back.qrc
