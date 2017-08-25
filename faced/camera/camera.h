#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>

#include "logger/logger.h"

class Camera : public QObject
{
    Q_OBJECT

private:

    static Camera *instance;

    explicit Camera(QObject *parent = NULL);
    void init();

public:

    static Camera *getInstance();
    ~Camera();
};

#endif // CAMERA_H
