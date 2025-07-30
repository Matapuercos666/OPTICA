QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Inventario.cpp \
    Lista_Clientes.cpp \
    Menu.cpp \
    PuntoVenta.cpp \
    USUARIOS.cpp \
    main.cpp \
    LOGIN.cpp

HEADERS += \
    ESTILOS.h \
    Inventario.h \
    LOGIN.h \
    Lista_Clientes.h \
    Menu.h \
    PuntoVenta.h \
    USUARIOS.h \
    Utils.h

FORMS += \
    Inventario.ui \
    LOGIN.ui \
    Lista_Clientes.ui \
    Menu.ui \
    PuntoVenta.ui \
    USUARIOS.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    RECURSOS.qrc
