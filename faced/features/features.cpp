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



    float x = 0;
    float y = 0;

    emit detected( QPointF(x, y) );
}
