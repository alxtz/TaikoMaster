#include <QPixmap>
#include "RedDon.h"

RedDon::RedDon()
{
    setPixmap(QPixmap(":/images/RedDon.png"));
    setPos(800 , 343);
}

void RedDon::move()
{
    setPos( x()-4 , y() );
}
