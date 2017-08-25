#ifndef CAMERA_H
#define CAMERA_H

#define CAMERA "CAMERA"

#include <QObject>
#include <QTimer>
#include <QPoint>

#include <opencv2/opencv.hpp>

#include "logger/logger.h"
#include "config/config.h"

using namespace cv;
using namespace std;

class Camera : public QObject
{
    Q_OBJECT

private:

    static Camera *instance;

    explicit Camera(QObject *parent = NULL);
    void init();

    VideoCapture *frameCapturer;
    Mat *currentFrame;
    QTimer *frameUpdater;

public:

    static Camera *getInstance();
    ~Camera();

    VideoCapture *getFrameCapturer() const;
    void setFrameCapturer(VideoCapture *value);

    Mat *getCurrentFrame() const;
    void setCurrentFrame(Mat *value);

    QTimer *getFrameUpdater() const;
    void setFrameUpdater(QTimer *value);

    int getFrameCapturerBrightness();
    int getFrameCapturerContrast();
    int getFrameCapturerSaturation();
    int getFrameCapturerHue();

private slots:

    void updateCurrentFrame();

public slots:

    void setFrameCapturerBrightness( int value );
    void setFrameCapturerContrast( int value );
    void setFrameCapturerSaturation( int value );
    void setFrameCapturerHue( int value );
};

#endif // CAMERA_H
