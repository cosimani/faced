#include "config.h"

Config* Config::instance = NULL;
QVector<QStringList>* Config::strings = new QVector<QStringList>();

Config::Config(QObject *parent) :
    QObject(parent)
{
    init();
}

void Config::init()
{
    QFile inputFile(CONFIG_FILE);
    if(inputFile.open(QIODevice::ReadOnly) == false)
    {
        LOG_ERR("Config file not exists");
        return;
    }
    QTextStream in(&inputFile);
    while (!in.atEnd())
    {
        QString line = in.readLine();

        if(line.contains(CONFIG_COMMENT))
        {
            line = line.remove(line.indexOf(CONFIG_COMMENT),
                               line.length() - line.indexOf(CONFIG_COMMENT));
        }

        if(line.simplified().isEmpty()) {
            continue;
        }

        QStringList kv = line.split(CONFIG_ASSIGNMENT);

        if(kv.size() == 2)
        {
            for(int i = 0; i < 2; i++)
            {
                kv.operator [](i) = kv.at(i).simplified();
            }
        }
        strings->append(kv);
        LOG_INF(kv.at(0) << "was setted");
    }
    inputFile.close();
    LOG_INF("Config successfully initialized");
}

Config *Config::getInstance()
{
    if(instance == NULL)
    {
        instance = new Config();
    }
    return instance;
}

Config::~Config()
{
    if(instance != NULL)
    {
        delete instance;
    }
}

QString Config::getString(QString key)
{
    for(int i = 0; i < strings->size(); i++)
    {
        if(strings->at(i).at(0) == key)
        {
            return strings->at(i).at(1);
        }
    }

    LOG_ERR("Config string not found");
    return "";
}

string Config::getStdString(QString key)
{
    return getString(key).toStdString();
}

const char *Config::getCharString(QString key)
{
    return getStdString(key).c_str();
}
