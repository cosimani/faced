#include "camera/camera.h"

Camera* Camera::instance = NULL;

Camera::Camera(QObject *parent):
    QObject(parent)
{
    init();
}

void Camera::init()
{
    LOG_INF("Camera successfully initialized");
}

Camera *Camera::getInstance()
{
    if(instance == NULL)
    {
        instance = new Camera();
    }
    return instance;
}

Camera::~Camera()
{
    if(instance != NULL)
    {
        delete instance;
    }
}
