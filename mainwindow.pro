QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ./sources/credit.cpp \
    ./sources/debit.cpp \
    ./sources/findResult.c \
    ./sources/graphicwindow.cpp \
    ./sources/main.cpp \
    ./sources/mainwindow.cpp \
    ./sources/optional.c \
    ./sources/parserToReversePolish.c \
    qcustomplot.cpp

HEADERS += \
    ./headers/calculation.h \
    ./headers/credit.h \
    ./headers/debit.h \
    ./headers/graphicwindow.h \
    ./headers/mainwindow.h \
    qcustomplot.h

FORMS += \
    ./forms/credit.ui \
    ./forms/debit.ui \
    ./forms/graphicwindow.ui \
    ./forms/mainwindow.ui

win32:RC_FILE = ./qrc/file.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ./qrc/qrc.qrc

DISTFILES +=

#installfiles.files += SOURCES
#installfiles.files += HEADERS
#installfiles.files += FORMS
#installfiles.path = /src/calculator
#INSTALLS += installfiles

TARGET = calculator
DESTDIR = ./app
