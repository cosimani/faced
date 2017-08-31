#include "features/features.h"

/**
 * @brief Features::Features
 * @param parent
 * Constructor
 */
Features::Features(QObject *parent) :
    QObject(parent)
{
    init();
}

/**
 * @brief Features::init
 * Auxiliar method
 */
void Features::init()
{
    this->setTimer( new QTimer(this) );

    this->setNeedCalibrate(true);
    this->setRoi(QRect(0, 0, 0, 0));

    this->connect( this->getTimer(), SIGNAL( timeout() ), this, SLOT( process() ) );
    this->getTimer()->setInterval( Config::getInstance()->getInt(TIMEOUT) );
    this->getTimer()->start();
}

/**
 * @brief Features::getTimer
 * @return the timer
 */
QTimer *Features::getTimer() const
{
    return timer;
}

/**
 * @brief Features::setTimer
 * @param value
 */
void Features::setTimer(QTimer *value)
{
    timer = value;
}

/**
 * @brief Features::getNeedCalibrate
 * @return if it's necessary to calibrate
 */
bool Features::getNeedCalibrate() const
{
    return needCalibrate;
}

/**
 * @brief Features::getRoi
 * @return the region of interest for features extracting
 */
QRect Features::getRoi() const
{
    return roi;
}

/**
 * @brief Features::setRoi
 * @param value
 */
void Features::setRoi(const QRect &value)
{
    roi = value;
}

/**
 * @brief Features::startTracking
 * Starts events tracking
 */
void Features::startTracking()
{
    this->getTimer()->start();
}

/**
 * @brief Features::stopTracking
 * Stops events tracking
 */
void Features::stopTracking()
{
    this->getTimer()->stop();
}

/**
 * @brief Features::setNeedCalibrate
 * @param value
 */
void Features::setNeedCalibrate(bool value)
{
    needCalibrate = value;
}

/**
 * @brief Features::process
 * Process camera frame and emit detected events
 */
void Features::process()
{
    Mat *currentFrame = Camera::getInstance()->getCurrentFrame();

    if(currentFrame->empty())
    {
        LOG_ERR("Current camera frame is empty");
        return;
    }

    if(this->getNeedCalibrate())
    {
        LOG_ERR("Features extraction is not calibrated yet");
        return;
    }

    float x = 0;
    float y = 0;

    emit detected( QPointF(x, y) );
}
