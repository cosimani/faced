#ifndef FEATURES_H
#define FEATURES_H

#include <QObject>
#include <QTimer>
#include <QPointF>

#include "config/config.h"
#include "logger/logger.h"
#include "app/keys.h"
#include "camera/camera.h"

/**
 * @brief The Features class
 * This class allows to extract features and send events
 */
class Features : public QObject
{
    Q_OBJECT

private:

    void init();

    QTimer *timer;

public:

    explicit Features(QObject *parent = NULL);

    QTimer *getTimer() const;
    void setTimer(QTimer *value);

private slots:

    void process();

signals:

    void detected(QPointF pos);
};

#endif // FEATURES_H
