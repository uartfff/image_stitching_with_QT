#-------------------------------------------------
#
# Project created by QtCreator 2011-09-28T11:25:55
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

TARGET = IV2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imgwin.cpp \
    imgabout.cpp \
    imageeditlabel.cpp

HEADERS  += mainwindow.h \
    imgwin.h \
    imgabout.h \
    imageeditlabel.h\
    QMainWindow.h

FORMS    += mainwindow.ui \
    imgwin.ui \
    imgabout.ui \
    imgresizedialog.ui \
    ParameterDialog.ui

OTHER_FILES += \
    README.txt


INCLUDEPATH += D:/opencv/install/include \
    D:/opencv/install/include/opencv \
    D:/opencv/install/include/opencv2

LIBS += D:/opencv/install/x64/vc14/lib/*.lib
