#include <QApplication>
#include <QFile>

#include "interface/interface.hpp"
#include "common.hpp"
#include "processor/camera.hpp"

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    QString xml( DATA_PATH );
    xml.append( XML_PATH );
    xml.append( "ottaa.xml" );
//    xml.append( "ubp.xml" );
//    xml.append( "casa.xml" );
    QFile file( xml );

    Interface *_interface = new Interface();
    _interface->showMaximized();
//    _interface->show();
    _interface->initInterface( &file );

    return app.exec();
}
