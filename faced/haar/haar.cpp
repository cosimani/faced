#include "haar/haar.h"

/**
 * @brief Haar::Haar
 * @param parent
 * Constructor
 */
Haar::Haar(QObject *parent) :
    QObject(parent)
{
    init();
}

/**
 * @brief Haar::init
 * Auxiliar method
 */
void Haar::init()
{
    this->setClassifier( new CascadeClassifier(Config::getInstance()->getStdString(CLASSIFIER) ) );
    if(this->getClassifier()->empty())
    {
        LOG_ERR("Cannot load classifier" << Config::getInstance()->getString(CLASSIFIER));
    }
    this->setTimer( new QTimer(this) );

    this->connect( this->getTimer(), SIGNAL( timeout() ), this, SLOT( process() ) );
    this->getTimer()->setInterval( Config::getInstance()->getInt(TIMEOUT) );
    this->getTimer()->start();
}

/**
 * @brief Haar::getClassifier
 * @return the classifier
 */
CascadeClassifier *Haar::getClassifier() const
{
    return classifier;
}

/**
 * @brief Haar::setClassifier
 * @param value
 */
void Haar::setClassifier(CascadeClassifier *value)
{
    classifier = value;
}

/**
 * @brief Haar::getTimer
 * @return the timer
 */
QTimer *Haar::getTimer() const
{
    return timer;
}

/**
 * @brief Haar::setTimer
 * @param value
 */
void Haar::setTimer(QTimer *value)
{
    timer = value;
}

/**
 * @brief Haar::process
 * Process camera frame and emit detected events
 */
void Haar::process()
{
    if(this->getClassifier()->empty())
    {
        LOG_ERR("Classifier is empty");
        return;
    }

    Mat *currentFrame = Camera::getInstance()->getCurrentFrame();

    if(currentFrame->empty())
    {
        LOG_ERR("Current camera frame is empty");
        return;
    }

    vector< Rect > detectedObjects;
    detectedObjects.clear();
    classifier->detectMultiScale( *currentFrame, detectedObjects,
                                  1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size( 150, 150 ) );
    if(detectedObjects.size() == 0)
    {
        return;
    }

    float x = (detectedObjects[0].x + detectedObjects[0].width / (float)2) / (float)currentFrame->cols;
    float y = (detectedObjects[0].y + detectedObjects[0].height / (float)2) / (float)currentFrame->rows;

    emit detected( QPointF(x, y) );
}
