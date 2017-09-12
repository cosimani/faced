#include "navigator.h"

/**
 * @brief Navigator::Navigator
 * @param parent
 * Constructor
 */
Navigator::Navigator(QWidget *parent) :
    QWidget(parent)
{
    this->init();
}

/**
 * @brief Navigator::init
 * Auxiliar method
 */
void Navigator::init()
{
    this->setTitle(new QLabel(this));

    QFont font = this->getTitle()->font();
    font.setPointSize(30);

    this->getTitle()->setFont(font);
    this->getTitle()->setStyleSheet("QLabel { background-color : black; color : white; }");
    this->getTitle()->setGeometry(10, 10, this->width(), this->getTitle()->sizeHint().height());

    this->setImages(new QVector<Image *>());

    QPalette palette = this->palette();
    palette.setColor(QPalette::Background, Qt::black);
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    this->loadFolder(Config::getInstance()->getString(FOLDER));

    LOG_INF("Navigator: successfully initialized");
}

/**
 * @brief Navigator::loadFolder
 * @param folder
 * This method loads a folder in the navigator view
 */
void Navigator::loadFolder(QString folder)
{
    this->getTitle()->setText("Current folder: " + folder);

    for(int i = 0; i < this->getImages()->length(); i++)
    {
        LOG_INF("Deleting image");

        delete this->getImages()->operator [](i);
    }
    this->getImages()->clear();

    QDirIterator it(folder, QStringList() << "*.jpg", QDir::Files, QDirIterator::Subdirectories);
    int i = 0;
    while (it.hasNext()) {
        Image *image = new Image(this);

        image->load(it.next());

        int x = 0;
        int y = 0;
        int w = image->width();
        int h = image->height();
        image->setGeometry(x, y, w, h);

        this->getImages()->append(image);
        i++;
    }

    this->alignImages();
}

/**
 * @brief Navigator::alignImages
 * Method for align images
 */
void Navigator::alignImages()
{
    int currentX = 0;
    int margin = 20;
    for(int i = 0; i < this->getImages()->length(); i++)
    {
        Image *image = this->getImages()->at(i);

        image->setGeometry(
            currentX,
            this->height() / (float)2 - image->height() / (float)2,
            image->width(),
            image->height());

        currentX += image->width() + margin;
    }
}

/**
 * @brief Navigator::~Navigator
 * Destructor
 */
Navigator::~Navigator()
{
    for(int i = 0; i < this->getImages()->length(); i++)
    {
        delete this->getImages()->operator [](i);
    }
    delete this->getImages();
}

/**
 * @brief Navigator::getTitle
 * @return the title label
 */
QLabel *Navigator::getTitle() const
{
    return title;
}

/**
 * @brief Navigator::setTitle
 * @param value
 */
void Navigator::setTitle(QLabel *value)
{
    title = value;
}

/**
 * @brief Navigator::getImages
 * @return the images
 */
QVector<Image *> *Navigator::getImages() const
{
    return images;
}

/**
 * @brief Navigator::setImages
 * @param value
 */
void Navigator::setImages(QVector<Image *> *value)
{
    images = value;
}

/**
 * @brief Navigator::resizeEvent
 * @param event
 * Redefinition of resizeEvent
 */
void Navigator::resizeEvent(QResizeEvent *event)
{
    this->getTitle()->setGeometry(10, 10, this->width(), this->getTitle()->sizeHint().height());
    this->alignImages();

    QWidget::resizeEvent(event);
}
