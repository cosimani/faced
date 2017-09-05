#ifndef APP_H
#define APP_H

#include <QObject>

#include "logger/logger.h"
#include "app/navigator.h"

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

    Navigator *navigator;

public:

    static App *getInstance();
    ~App();

    void run();

    Navigator *getNavigator() const;
    void setNavigator(Navigator *value);
};

#endif // WIDGETS_H
