#ifndef HAAR_H
#define HAAR_H

#include <QObject>
#include <QTimer>
#include <QPointF>

#include <opencv2/opencv.hpp>

#include "config/config.h"
#include "logger/logger.h"
#include "app/keys.h"
#include "camera/camera.h"

using namespace cv;
using namespace std;

/**
 * @brief The Haar class
 * This class allows to identify classifiers and send events
 */
class Haar : public QObject
{
    Q_OBJECT

private:

    void init();

    CascadeClassifier *classifier;
    QTimer *timer;

public:

    explicit Haar(QObject *parent = NULL);

    CascadeClassifier *getClassifier() const;
    void setClassifier(CascadeClassifier *value);

    QTimer *getTimer() const;
    void setTimer(QTimer *value);

    void startTracking();
    void stopTracking();

private slots:

    void process();

signals:

    void detected(QPointF pos);
};

#endif // HAAR_H
