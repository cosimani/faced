#include "app/app.h"

App* App::instance = NULL;

/**
 * @brief App::App
 * @param parent
 * Constructor
 */
App::App(QObject *parent):
    QObject(parent)
{
    init();
}

/**
 * @brief App::init
 * Auxiliar method
 */
void App::init()
{
    LOG_INF("App successfully initialized");
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
    if(instance != NULL)
    {
        delete instance;
    }
}

/**
 * @brief App::run
 * Run the application with its intrinsic logic
 */
#include "haar/haar.h"
void App::run()
{
Haar * h = new Haar();
}
