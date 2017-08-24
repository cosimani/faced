#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#define INITIAL_NODE_ID "inicio"

#include <QWidget>
#include <QPalette>
#include <QList>
#include <QKeyEvent>
#include <QSound>

#include "config/config.h"

#include "theme/colorizer.hpp"
#include "interface/block.hpp"
#include "processor/camera.hpp"

#include "common.hpp"

namespace Ui
{
    class Interface;
}

class Interface : public QWidget
{
    Q_OBJECT

private:

    Ui::Interface *ui;
    Camera *camera;

    QTimer *blockSelectionTimer;
    bool blockSelection;

    void setStyle();
    void changeStyle();

public:

    explicit Interface( QWidget *parent = NULL );
    ~Interface();

    Camera *getCamera() const;
    void setCamera( Camera *value );

    QTimer *getBlockSelectionTimer() const;
    void setBlockSelectionTimer( QTimer *value );

    bool getBlockSelection() const;
    void setBlockSelection( bool value );

    bool initInterface( QFile *file );

protected:

    void keyPressEvent( QKeyEvent *event );

private slots:

    void createAndSet();
    void activateBlock( int index );
    void clickBlock( int index );
    void unblockSelection();
};

#endif // INTERFACE_HPP

