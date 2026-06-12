TEMPLATE = app
TARGET   = AgentePETE

QT      += core gui widgets network
CONFIG  += c++17

INCLUDEPATH += $$PWD/include

SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/ChatController.cpp \
    src/Prompt.cpp \
    src/Message.cpp \
    src/calendarwin.cpp \
    src/dayagendadialog.cpp \
    src/newtaskdialog.cpp \
    src/OllamaProvider.cpp \
    src/Task.cpp \
    src/DayMonYear.cpp

HEADERS += \
    include/MainWindow.h \
    include/ChatController.h \
    include/Prompt.h \
    include/Message.h \
    include/calendarwin.h \
    include/dayagendadialog.h \
    include/newtaskdialog.h \
    include/OllamaProvider.h \
    include/PeteExceptions.h \
    include/Task.h \
    include/DayMonYear.h

FORMS += \
    calendarwin.ui \
    dayagendadialog.ui \
    newtaskdialog.ui
