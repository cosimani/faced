#ifndef CONFIG_H
#define CONFIG_H

#define CONFIG_FILE "../project.config"
#define CONFIG_COMMENT "*"
#define CONFIG_ASSIGNMENT "="

#include <QObject>
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QIODevice>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QVector>

#include "logger/logger.h"

using namespace std;

class Config : public QObject
{
    Q_OBJECT

private:

    static Config *instance;
    static QVector<QStringList> *strings;

    explicit Config(QObject *parent=NULL);
    void init();

public:

    static Config *getInstance();
    ~Config();

    QString getString(QString key);
    string getStdString(QString key);
    const char *getCharString(QString key);

};

#endif // CONFIG_H
