#include <QCoreApplication>
#include "Server.h"
#include <ctime>

int main(int argc, char *argv[])
{
    srand(time(0));
    QCoreApplication a(argc, argv);

    server Server;

    Server.startServer();

    return a.exec();
}
