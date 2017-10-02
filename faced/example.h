#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <QObject>
#include <QDebug>

#include "detector/haar.h"

class Example : public QObject
{
    Q_OBJECT

    Haar *haarDetector;

public:

    Example()
    {
        haarDetector = new Haar();

        connect(haarDetector, SIGNAL(point(QPoint)), SLOT(detected(QPoint)));

        haarDetector->startTracking();
    }

private slots:

    void detected(QPoint pos)
    {
        qDebug() << pos;
    }
};

#endif // EXAMPLE_H
