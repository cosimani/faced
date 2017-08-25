#ifndef WIDGETS_H
#define WIDGETS_H

#include <QObject>

#include "logger/logger.h"

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
