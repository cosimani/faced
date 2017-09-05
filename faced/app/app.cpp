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
    navigator->showMaximized();
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
