#ifndef FEATURES_H
#define FEATURES_H

#include <QObject>

/**
 * @brief The Features class
 * This class allows to extract features and send coordinates
 */
class Features : public QObject
{
    Q_OBJECT

public:

    explicit Features(QObject *parent = NULL);
};

#endif // FEATURES_H
