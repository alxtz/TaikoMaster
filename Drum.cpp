#include <QPixmap>
#include <QGraphicsScene>
#include "Drum.h"
#include "SmallDrum.h"

Drum::Drum()
{
    setPixmap(QPixmap(":/images/drumPic.jpg"));
    setZValue(10);
    setPos(0 , 295);
}

void Drum::setSmall()
{
    SmallDrum * smallDrum = new SmallDrum();

    scene()->addItem(smallDrum);
}



