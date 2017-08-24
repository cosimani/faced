#ifndef LOGGER_H
#define LOGGER_H

#define PREF_INF "[INF]"
#define PREF_WAR "[WAR]"
#define PREF_ERR "[ERR]"

#define LOG_INF(X) qDebug() << PREF_INF << X
#define LOG_WAR(X) qDebug() << PREF_WAR << X
#define LOG_ERR(X) qDebug() << PREF_ERR << X

#include <QDebug>

#endif // LOGGER_H
