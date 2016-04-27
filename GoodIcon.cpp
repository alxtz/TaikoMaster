#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>
#include "GoodIcon.h"

GoodIcon::GoodIcon()
{
    setPixmap(QPixmap(":/images/good.png"));
    setPos(208 , 305);

    QTimer::singleShot(200 , this , SLOT(destroySelf()));
}

void GoodIcon::destroySelf()
{
    scene()->removeItem(this);
    delete this;
}
