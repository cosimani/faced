#ifndef WIDGETS_H
#define WIDGETS_H

#include <QObject>

#include "logger/logger.h"

/**
 * @brief The Widgets class
 * This class allows you to manage the order and sequence of app widgets
 */
class Widgets : public QObject
{
    Q_OBJECT

private:

    static Widgets *instance;

    explicit Widgets(QObject *parent = NULL);
    void init();

public:

    static Widgets *getInstance();
    ~Widgets();
};

#endif // WIDGETS_H
