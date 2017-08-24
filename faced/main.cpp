#include <QApplication>

#include "config.h"
#include "logger.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Config::getInstance();

    return app.exec();
}
