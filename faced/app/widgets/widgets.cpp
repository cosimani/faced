#include "app/widgets/widgets.h"

Widgets* Widgets::instance = NULL;

Widgets::Widgets(QObject *parent):
    QObject(parent)
{
    init();
}

void Widgets::init()
{
    LOG_INF("Widgets successfully initialized");
}

Widgets *Widgets::getInstance()
{
    if(instance == NULL)
    {
        instance = new Widgets();
    }
    return instance;
}

Widgets::~Widgets()
{
    if(instance != NULL)
    {
        delete instance;
    }
}
