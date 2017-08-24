#include "block.hpp"
#include "ui_block.h"

Block::Block( QWidget *parent ) :
    QWidget( parent ),
    ui( new Ui::Block )
{
    this->setFixedSize( BLOCK_SIDE, BLOCK_SIDE );
    ui->setupUi( this );

    this->setActive( false );
    this->setMouseTracking( true );
}

Block::~Block()
{
    /**
     * No eliminar el nodo asociado
     * Porque el bloque podría volver a crearse en el futuro
     * Y no podríamos acceder a la información en ese caso
     **/
}

bool Block::getActive() const
{
    return active;
}

void Block::setActive( bool value )
{
    this->setStyle( value );

    active = value;
}

void Block::simulateClick()
{
    emit clicked();
}

void Block::setStyle( bool active )
{
    this->setAutoFillBackground( true );

    QPalette palette( this->palette() );

    palette.setColor( QPalette::Background,
                      active ? Colorizer::getInstance()->getTheme()->getHighlightColor() :
                               Colorizer::getInstance()->getTheme()->getBackColor() );

    palette.setColor( QPalette::WindowText,
                      QColor( Qt::white ) );

    this->setPalette( palette );
}

bool Block::Block::event( QEvent *event )
{
    if( event->type() == QEvent::Enter )
    {
        this->setStyle( true );
    }

    if( event->type() == QEvent::Leave )
    {
        this->setStyle( false );
    }

    return QWidget::event( event );
}

void Block::mousePressEvent( QMouseEvent* )
{
    emit clicked();
}
