#ifndef APP_H
#define APP_H

#include <QObject>

#include "logger/logger.h"

/**
 * @brief The App class
 * This class allows you to separate the instrinsic logic of the project libraries
 */
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
