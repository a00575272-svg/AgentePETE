TEMPLATE = app
TARGET   = AgentePETE

QT      += core gui widgets
CONFIG  += c++17

INCLUDEPATH += $$PWD/include

SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/ChatController.cpp \
    src/ChatWindow.cpp \
    src/Prompt.cpp \
    src/Message.cpp \
    src/DayMonYear.cpp

HEADERS += \
    include/MainWindow.h \
    include/ChatController.h \
    include/ChatWindow.h \
    include/Prompt.h \
    include/Message.h \
    include/DayMonYear.h
