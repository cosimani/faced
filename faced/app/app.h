#ifndef APP_H
#define APP_H

#include <QObject>

#include "logger/logger.h"
#include "app/navigator.h"
#include "camera/camera.h"
#include "haar/haar.h"
#include "features/features.h"

/**
 * @brief The App class
 * This class allows you to separate the instrinsic logic of the project libraries
 */
class App : public QObject
{
    Q_OBJECT

private:

    static App *instance;

    explicit App(QObject *parent = NULL);
    void init();

    Navigator *navigator;
    Haar *haar;
    Features *features;

    bool featuresCalibrated;
    QRect firstHaarRect;

public:

    static App *getInstance();
    ~App();

    void run();

    Navigator *getNavigator() const;
    void setNavigator(Navigator *value);

    Haar *getHaar() const;
    void setHaar(Haar *value);

    Features *getFeatures() const;
    void setFeatures(Features *value);

    bool getFeaturesCalibrated() const;
    void setFeaturesCalibrated(bool value);

    QRect getFirstHaarRect() const;
    void setFirstHaarRect(const QRect &value);

private slots:

    void haarNoseDetected(QRect n);
    void featuresDetected(QPoint p);
};

#endif // WIDGETS_H
