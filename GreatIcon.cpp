#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>
#include "GreatIcon.h"

GreatIcon::GreatIcon()
{
    setPixmap(QPixmap(":/images/great.png"));
    setPos(208,305);

    QTimer::singleShot(200 , this , SLOT(destroySelf()));
}

void GreatIcon::destroySelf()
{
    scene()->removeItem(this);
    delete this;
}

