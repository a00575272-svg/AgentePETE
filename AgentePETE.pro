TEMPLATE = app
TARGET   = AgentePETE

QT      += core gui widgets
CONFIG  += c++17

INCLUDEPATH += $$PWD/include

SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/ChatController.cpp

HEADERS += \
    include/MainWindow.h \
    include/ChatController.h
