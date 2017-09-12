#include <QApplication>

#include "app/app.h"

/**
 * @brief main
 * @param argc
 * @param argv
 * @return the exec code
 */
int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    App::getInstance()->run();

    return app.exec();
}
