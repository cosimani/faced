#include <QApplication>

#include "config/config.h"
#include "logger/logger.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Config::getInstance();

    return app.exec();
}
