#ifndef APP_H
#define APP_H

#include <QObject>

#include "logger/logger.h"

class App : public QObject
{
    Q_OBJECT

private:

    static App *instance;

    explicit App(QObject *parent = NULL);
    void init();

public:

    static App *getInstance();
    ~App();

    void run();
};

#endif // WIDGETS_H
