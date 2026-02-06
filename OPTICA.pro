QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Agregar_Paciente.cpp \
    Agregar_Usuario.cpp \
    Cambiar_Nombre.cpp \
    Cambiar_Password.cpp \
    Historial_Caja.cpp \
    Home.cpp \
    Info_paciente.cpp \
    Inventario.cpp \
    Inventario_Usuario.cpp \
    Lista_Clientes.cpp \
    Lista_Usuarios.cpp \
    Llenar_Consulta.cpp \
    MainShell.cpp \
    ManejoDeData.cpp \
    Perfil_Usuario.cpp \
    PuntoVenta.cpp \
    Usuario_Actual.cpp \
    Validacion.cpp \
    VentanaBase.cpp \
    main.cpp \
    LOGIN.cpp

HEADERS += \
    Agregar_Paciente.h \
    Agregar_Usuario.h \
    Cambiar_Nombre.h \
    Cambiar_Password.h \
    ESTILOS.h \
    Historial_Caja.h \
    Home.h \
    Info_paciente.h \
    Inventario.h \
    Inventario_Usuario.h \
    LOGIN.h \
    Lista_Clientes.h \
    Lista_Usuarios.h \
    Llenar_Consulta.h \
    MainShell.h \
    ManejoDeData.h \
    Perfil_Usuario.h \
    PuntoVenta.h \
    Usuario_Actual.h \
    Utils.h \
    Validacion.h \
    VentanaBase.h

FORMS += \
    Agregar_Paciente.ui \
    Agregar_Usuario.ui \
    Cambiar_Nombre.ui \
    Cambiar_Password.ui \
    Historial_Caja.ui \
    Home.ui \
    Info_paciente.ui \
    Inventario.ui \
    Inventario_Usuario.ui \
    LOGIN.ui \
    Lista_Clientes.ui \
    Lista_Usuarios.ui \
    Llenar_Consulta.ui \
    Perfil_Usuario.ui \
    PuntoVenta.ui \
    Validacion.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    RECURSOS.qrc

DISTFILES +=
