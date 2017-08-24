#include "interface.hpp"
#include "ui_interface.h"

Interface::Interface( QWidget *parent ) :
    QWidget( parent ),
    ui( new Ui::Interface )
{
    this->setCamera( new Camera( this ) );
    this->setBlockSelectionTimer( new QTimer( this ) );
    this->setBlockSelection( false );

    ui->setupUi( this );
    ui->scrollArea->setFixedHeight( SCROLL_AREA_HEIGHT );
    this->setStyle();

    connect( this->ui->calibrateButton,
             SIGNAL( pressed() ),
             this->getCamera(),
             SLOT( calibrate() ) );

    connect( this->getCamera(),
             SIGNAL( positionDetected( int ) ),
             SLOT( activateBlock( int ) ) );

    connect( this->getCamera(),
             SIGNAL( selectionDetected( int ) ),
             SLOT( clickBlock( int ) ) );

    connect( blockSelectionTimer,
             SIGNAL( timeout() ),
             SLOT( unblockSelection() ) );
}

Interface::~Interface()
{
    delete ui;
}

void Interface::setStyle()
{
    this->setAutoFillBackground( true );

    QPalette palette( this->palette() );
    palette.setColor( QPalette::Background, Colorizer::getInstance()->getTheme()->getBackgroundColor() );
    palette.setColor( QPalette::WindowText, QColor( Qt::white ) );
    this->setPalette( palette );
}

void Interface::changeStyle()
{
     Colorizer::getInstance()->getNextTheme();

     QList< Block* > blocksList = this->findChildren< Block* >();
     for( int i = 0; i < blocksList.size(); i++ )
     {
         blocksList.at( i )->setStyle( false );
     }

     this->setStyle();
}

Camera *Interface::getCamera() const
{
    return camera;
}

void Interface::setCamera( Camera *value )
{
    camera = value;
}

QTimer *Interface::getBlockSelectionTimer() const
{
    return blockSelectionTimer;
}

void Interface::setBlockSelectionTimer( QTimer *value )
{
    blockSelectionTimer = value;
}

bool Interface::getBlockSelection() const
{
    return blockSelection;
}

void Interface::setBlockSelection( bool value )
{
    blockSelection = value;
}

bool Interface::initInterface( QFile *file )
{
    return true;
}

void Interface::keyPressEvent( QKeyEvent *event )
{
    switch( event->key() )
    {
    case Qt::Key_C:

        this->changeStyle();

        break;

    case Qt::Key_I:

        this->ui->sentenceLabel->clear();
        this->createAndSet();

        break;

    default:

        break;
    }
}

void Interface::createAndSet()
{
    QList< Block* > blocksList = this->findChildren< Block* >();
    qDeleteAll( blocksList );

    this->ui->nodeTitleLabel->setText( "" );

    if( "node->getText()" != "" )
    {
        QString sentence( ui->sentenceLabel->text() );
        sentence.append( " " );
        sentence.append( /* node->getText().toUpper()*/ "");
        this->ui->sentenceLabel->setText( sentence );
    }

    for( int i = 0; i < 5/*node->getChildren().size()*/; i++ )
    {
        if( true )
        {
            Block *block = new Block( this );
            this->ui->blocksLayout->addWidget( block );
            connect( block, SIGNAL( clicked() ), SLOT( createAndSet() ) );
        }
    }

    this->getCamera()->setSize( 5 );
}

void Interface::activateBlock( int index )
{
    QList< Block* > blocksList = this->findChildren< Block* >();
    if( index >= 0 && index < blocksList.size() )
    {
        for( int i = 0; i < blocksList.size(); i++ )
        {
            blocksList.at( i )->setActive( false );
        }
        blocksList.at( index )->setActive( true );
    }
}

void Interface::clickBlock( int index )
{
    if( !this->getBlockSelection() )
    {
        QString sound( Config::getInstance()->getString("APPLICATION_PATH") );
        sound.append( Config::getInstance()->getString("SOUNDS_PATH") );
        sound.append( "selected.wav" );
        QSound::play( sound );

        QList< Block* > blocksList = this->findChildren< Block* >();
        if( index >= 0 && index < blocksList.size() )
        {
            blocksList.at( index )->simulateClick();
        }

        this->setBlockSelection( true );
        blockSelectionTimer->start( 1000 );
    }
}

void Interface::unblockSelection()
{
    blockSelectionTimer->stop();
    this->setBlockSelection( false );
}
