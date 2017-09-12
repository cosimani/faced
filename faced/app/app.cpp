#include "app/app.h"

App* App::instance = NULL;

/**
 * @brief App::App
 * @param parent
 * Constructor
 */
App::App(QObject *parent):
    QObject(parent),
    navigator(new Navigator(NULL))
{
    init();
}

/**
 * @brief App::init
 * Auxiliar method
 */
void App::init()
{
    this->setHaar(new Haar(this));
    this->setFeatures(new Features(this));
    this->setFeaturesCalibrated(false);
    this->getFirstHaarRect().setRect(0, 0, 0, 0);

    this->connect(this->getHaar(), SIGNAL(nose(QRect)), this, SLOT(haarNoseDetected(QRect)));
    this->connect(this->getFeatures(), SIGNAL(detected(QPoint)), this, SLOT(featuresDetected(QPoint)));

    LOG_INF("App: successfully initialized");
}

/**
 * @brief App::getInstance
 * @return the instance
 */
App *App::getInstance()
{
    if(instance == NULL)
    {
        instance = new App();
    }
    return instance;
}

/**
 * @brief App::~App
 * Destructor
 */
App::~App()
{
    delete navigator;
    if(instance != NULL)
    {
        delete instance;
    }
}

/**
 * @brief App::run
 * Run the application with its intrinsic logic
 */
void App::run()
{
    Camera::getInstance();

    this->getHaar()->startTracking();

    this->getNavigator()->showMaximized();
}

/**
 * @brief App::getNavigator
 * @return the navigator object
 */
Navigator *App::getNavigator() const
{
    return navigator;
}

/**
 * @brief App::setNavigator
 * @param value
 */
void App::setNavigator(Navigator *value)
{
    navigator = value;
}

/**
 * @brief App::getHaar
 * @return the haar detector
 */
Haar *App::getHaar() const
{
    return haar;
}

/**
 * @brief App::setHaar
 * @param value
 */
void App::setHaar(Haar *value)
{
    haar = value;
}

/**
 * @brief App::getFeatures
 * @return the features extractor
 */
Features *App::getFeatures() const
{
    return features;
}

/**
 * @brief App::setFeatures
 * @param value
 */
void App::setFeatures(Features *value)
{
    features = value;
}

/**
 * @brief App::haarDetected
 * Invocated when haar detects a point
 */
void App::haarNoseDetected(QRect n)
{
    if(!n.isEmpty() && !this->getFeaturesCalibrated())
    {
        this->getFeatures()->calibrate(n);
        this->getFeatures()->startTracking();
        this->setFirstHaarRect(n);
        this->setFeaturesCalibrated(true);
        return;
    }

    QPoint p(n.x() + n.width() / (double)2, n.y() + n.height() / (double)2);

    QRect r = this->getFirstHaarRect();

    QPoint c(r.x() + r.width() / (float)2, r.y() + r.height() / (float)2);

    QPoint d(p.x() - c.x(), p.y() - c.y());

    this->getNavigator()->move(d.x());
}

/**
 * @brief App::featuresDetected
 * Invocated when features detects a point
 */
void App::featuresDetected(QPoint p)
{
    QRect r = this->getFeatures()->getRoi();

    QPoint c(r.x() + r.width() / (float)2, r.y() + r.height() / (float)2);

    QPoint d(p.x() - c.x(), p.y() - c.y());

    //this->getNavigator()->move(d.x());
}

/**
 * @brief App::getFeaturesCalibrated
 * @return if features are calibrated
 */
bool App::getFeaturesCalibrated() const
{
    return featuresCalibrated;
}

/**
 * @brief App::setFeaturesCalibrated
 * @param value
 */
void App::setFeaturesCalibrated(bool value)
{
    featuresCalibrated = value;
}

/**
 * @brief App::getFirstHaarRect
 * @return the first haar rect
 */
QRect App::getFirstHaarRect() const
{
    return firstHaarRect;
}

/**
 * @brief App::setFirstHaarRect
 * @param value
 */
void App::setFirstHaarRect(const QRect &value)
{
    firstHaarRect = value;
}
