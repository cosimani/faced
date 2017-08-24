#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <QWidget>
#include <QPalette>
#include <QEvent>

#include "theme/colorizer.hpp"

#include "image.hpp"

#include "common.hpp"

namespace Ui
{
    class Block;
}

class Block : public QWidget
{
    Q_OBJECT

private:

    Ui::Block *ui;
    bool active;

public:

    explicit Block( QWidget *parent = NULL );
    ~Block();

    bool getActive() const;
    void setActive( bool value );

    void setStyle( bool active );

    void simulateClick();

protected:

    bool event( QEvent *event );
    void mousePressEvent( QMouseEvent* );

signals:

    void clicked();
};

#endif // BLOCK_HPP

