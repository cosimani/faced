#include "app/widgets/widgets.h"

Widgets* Widgets::instance = NULL;

/**
 * @brief Widgets::Widgets
 * @param parent
 * Constructor
 */
Widgets::Widgets(QObject *parent):
    QObject(parent)
{
    init();
}

/**
 * @brief Widgets::init
 * Auxiliar method
 */
void Widgets::init()
{
    LOG_INF("Widgets: successfully initialized");
}

/**
 * @brief Widgets::getInstance
 * @return the instance
 */
Widgets *Widgets::getInstance()
{
    if(instance == NULL)
    {
        instance = new Widgets();
    }
    return instance;
}

/**
 * @brief Widgets::~Widgets
 * Destructor
 */
Widgets::~Widgets()
{
    if(instance != NULL)
    {
        delete instance;
    }
}
