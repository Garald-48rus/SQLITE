QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addproduct.cpp \
    db.cpp \
    izmproduct.cpp \
    main.cpp \
    mainwindow.cpp \
    productsales.cpp \
    saleproduct.cpp

HEADERS += \
    addproduct.h \
    db.h \
    izmproduct.h \
    mainwindow.h \
    productsales.h \
    saleproduct.h

FORMS += \
    addproduct.ui \
    izmproduct.ui \
    mainwindow.ui \
    productsales.ui \
    saleproduct.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
