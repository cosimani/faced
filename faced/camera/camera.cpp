#include "camera/camera.h"

Camera* Camera::instance = NULL;

Camera::Camera(QObject *parent):
    QObject(parent)
{
    init();
}

void Camera::init()
{
    this->setFrameCapturer( new VideoCapture( Config::getInstance()->getInt(CAMERA) ) );
    this->setFrameUpdater( new QTimer( this ) );
    this->setCurrentFrame( new Mat() );

    this->connect( this->getFrameUpdater(), SIGNAL( timeout() ), this, SLOT( updateCurrentFrame() ) );
    this->getFrameUpdater()->setInterval( 20 );
    this->getFrameUpdater()->start();

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
    delete this->getFrameCapturer();
    delete this->getCurrentFrame();
    delete this->getFrameUpdater();
    delete this->getInstance();

    if(instance != NULL)
    {
        delete instance;
    }
}

VideoCapture *Camera::getFrameCapturer() const
{
    return frameCapturer;
}

void Camera::setFrameCapturer(VideoCapture *value)
{
    frameCapturer = value;
}

Mat *Camera::getCurrentFrame() const
{
    return currentFrame;
}

void Camera::setCurrentFrame(Mat *value)
{
    currentFrame = value;
}

QTimer *Camera::getFrameUpdater() const
{
    return frameUpdater;
}

void Camera::setFrameUpdater(QTimer *value)
{
    frameUpdater = value;
}

int Camera::getFrameCapturerBrightness()
{
    return this->getFrameCapturer()->get( CV_CAP_PROP_BRIGHTNESS ) * 100;
}

int Camera::getFrameCapturerContrast()
{
    return this->getFrameCapturer()->get( CV_CAP_PROP_CONTRAST ) * 100;
}

int Camera::getFrameCapturerSaturation()
{
    return this->getFrameCapturer()->get( CV_CAP_PROP_SATURATION ) * 100;
}

int Camera::getFrameCapturerHue()
{
    return this->getFrameCapturer()->get( CV_CAP_PROP_HUE ) * 100;
}

void Camera::updateCurrentFrame()
{
    this->getFrameCapturer()->operator >>( *this->getCurrentFrame() );
}

void Camera::setFrameCapturerBrightness( int value )
{
    this->getFrameCapturer()->set( CV_CAP_PROP_BRIGHTNESS, value / ( double )100 );
}

void Camera::setFrameCapturerContrast( int value )
{
    this->getFrameCapturer()->set( CV_CAP_PROP_CONTRAST, value / ( double )100 );
}

void Camera::setFrameCapturerSaturation( int value )
{
    this->getFrameCapturer()->set( CV_CAP_PROP_SATURATION, value / ( double )100 );
}

void Camera::setFrameCapturerHue( int value )
{
    this->getFrameCapturer()->set( CV_CAP_PROP_HUE, value / ( double )100 );
}
