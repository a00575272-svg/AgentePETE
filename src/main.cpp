#include <QApplication>
#include "MainWindow.h"
#include "ChatWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("AgentePETE");

    ChatWindow window;
    window.show();

    return app.exec();
}
