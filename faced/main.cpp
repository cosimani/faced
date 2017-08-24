#include <QApplication>
#include "logger.h"

#define LOG_DIR "../log"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Logger::getInstance()->setOut(LOG_DIR);

    return app.exec();
}
