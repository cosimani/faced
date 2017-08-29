#ifndef HAAR_H
#define HAAR_H

#include <QObject>

/**
 * @brief The Haar class
 * This class allows to identify classifiers and send coordinates
 */
class Haar : public QObject
{
    Q_OBJECT

public:

    explicit Haar(QObject *parent = NULL);
};

#endif // HAAR_H
