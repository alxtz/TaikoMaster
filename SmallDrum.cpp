#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>
#include "SmallDrum.h"

SmallDrum::SmallDrum()
{
    setPixmap( QPixmap(":/images/smallDrum.jpg") );
    setZValue(11);
    setPos(0 , 295);

    QTimer::singleShot(100 , this , SLOT(destroySelf()));
}

void SmallDrum::destroySelf()
{
    scene()->removeItem(this);
    delete this;
}

