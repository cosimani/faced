#ifndef HAAR_H
#define HAAR_H

#include <QObject>
#include <QTimer>
#include <QPoint>
#include <QRect>

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
    ~Haar();

    CascadeClassifier *getClassifier() const;
    void setClassifier(CascadeClassifier *value);

    QTimer *getTimer() const;
    void setTimer(QTimer *value);

    void startTracking();
    void stopTracking();

    QRect getFaceRoi();

private slots:

    void process();

signals:

    void face(QRect f);
    void nose(QRect n);
    void point(QPoint p);
};

#endif // HAAR_H
