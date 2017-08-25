#include "app/app.h"

App* App::instance = NULL;

App::App(QObject *parent):
    QObject(parent)
{
    init();
}

void App::init()
{
    LOG_INF("App successfully initialized");
}

App *App::getInstance()
{
    if(instance == NULL)
    {
        instance = new App();
    }
    return instance;
}

App::~App()
{
    if(instance != NULL)
    {
        delete instance;
    }
}

void App::run()
{

}
