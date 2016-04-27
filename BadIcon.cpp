#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>
#include "BadIcon.h"

BadIcon::BadIcon()
{
    setPixmap( QPixmap(":/images/bad.png") );
    setPos(195 , 305);

    QTimer::singleShot(200 , this , SLOT(destroySelf()));
}

void BadIcon::destroySelf()
{
    scene()->removeItem(this);
    delete this;
}
