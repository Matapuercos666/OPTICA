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
    Eliminar_Usuarios.cpp \
    Info_paciente.cpp \
    Inventario.cpp \
    Lista_Clientes.cpp \
    Llenar_Consulta.cpp \
    ManejoDeData.cpp \
    Menu.cpp \
    PuntoVenta.cpp \
    USUARIOS.cpp \
    Usuario_Actual.cpp \
    Validacion.cpp \
    main.cpp \
    LOGIN.cpp

HEADERS += \
    Agregar_Paciente.h \
    Agregar_Usuario.h \
    Cambiar_Nombre.h \
    Cambiar_Password.h \
    ESTILOS.h \
    Eliminar_Usuarios.h \
    Info_paciente.h \
    Inventario.h \
    LOGIN.h \
    Lista_Clientes.h \
    Llenar_Consulta.h \
    ManejoDeData.h \
    Menu.h \
    PuntoVenta.h \
    USUARIOS.h \
    Usuario_Actual.h \
    Utils.h \
    Validacion.h

FORMS += \
    Agregar_Paciente.ui \
    Agregar_Usuario.ui \
    Cambiar_Nombre.ui \
    Cambiar_Password.ui \
    Eliminar_Usuarios.ui \
    Info_paciente.ui \
    Inventario.ui \
    LOGIN.ui \
    Lista_Clientes.ui \
    Llenar_Consulta.ui \
    Menu.ui \
    PuntoVenta.ui \
    USUARIOS.ui \
    Validacion.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    RECURSOS.qrc
