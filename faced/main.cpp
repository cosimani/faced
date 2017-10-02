#include <QApplication>

#include "example.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Example example;

    return app.exec();
}
