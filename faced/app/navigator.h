#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <QWidget>
#include <QVector>
#include <QPalette>
#include <QDirIterator>
#include <QStringList>
#include <QDir>
#include <QLabel>
#include <QFont>

#include "app/image.h"
#include "app/keys.h"
#include "config/config.h"

/**
 * @brief The Navigator class
 * This class allows to navigate into a folder
 */
class Navigator : public QWidget
{
    Q_OBJECT

private:

    void init();

    QLabel *title;
    QVector<Image *> *images;

    void loadFolder(QString folder);
    void alignImages();

public:

    explicit Navigator(QWidget *parent = NULL);
    ~Navigator();

    QLabel *getTitle() const;
    void setTitle(QLabel *value);

    QVector<Image *> *getImages() const;
    void setImages(QVector<Image *> *value);

    void move(float level);

protected:

    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
};

#endif // NAVIGATOR_H
