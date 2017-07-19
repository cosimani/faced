#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#define INITIAL_NODE_ID "inicio"

#include <QWidget>
#include <QPalette>
#include <QList>
#include <QKeyEvent>
#include <QSound>

#include "graph/graph.hpp"
#include "theme/colorizer.hpp"
#include "interface/block.hpp"
#include "processor/camera.hpp"
#include "interface/camerawidget.h"

#include "common.hpp"

#ifdef CON_SPEECH
#include "speech.hpp"
#endif

namespace Ui
{
    class Interface;
}

class Interface : public QWidget
{
    Q_OBJECT

private:

    Ui::Interface *ui;
    Graph *graph;
    Camera *camera;

    QTimer *blockSelectionTimer;
    bool blockSelection;

    void setStyle();
    void changeStyle();

#ifdef CON_SPEECH
    Speech *speaker;
#endif

    CameraWidget * cameraWidget;

public:

    explicit Interface( QWidget *parent = NULL );
    ~Interface();

    Graph *getGraph() const;
    void setGraph( Graph *value );

    Camera *getCamera() const;
    void setCamera( Camera *value );

    QTimer *getBlockSelectionTimer() const;
    void setBlockSelectionTimer( QTimer *value );

    bool getBlockSelection() const;
    void setBlockSelection( bool value );

#ifdef CON_SPEECH
    Speech *getSpeaker() const;
    void setSpeaker( Speech *value );
#endif

    bool initInterface( QFile *file );

protected:

    void keyPressEvent( QKeyEvent *event );
    void resizeEvent( QResizeEvent * e );
    void closeEvent(QCloseEvent * );

private slots:

    void createAndSet( Node *node );
    void activateBlock( int index );
    void clickBlock( int index );
    void unblockSelection();
    void phraseReset();
};

#endif // INTERFACE_HPP

