#include <QPixmap>
#include "BlueDon.h"

BlueDon::BlueDon()
{
    setPixmap(QPixmap(":/images/BlueDon.png"));
    setPos(800 , 343);
}

void BlueDon::move()
{
    setPos( x()-4 , y() );
}
