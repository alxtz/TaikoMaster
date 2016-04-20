#include <QList>
#include <QGraphicsScene>
#include <typeinfo>
#include <QDebug>
#include <QPixmap>
#include "HitPoint.h"
#include "RedDon.h"
#include "BlueDon.h"

HitPoint::HitPoint()
{
    setRect(0 , 0 , 80 , 60);
    setPos(182 , 280);

    hitIcon = new QGraphicsPixmapItem(this);
    hitIcon->setPixmap(QPixmap(":/images/hitPoint.png"));
    hitIcon->setPos(10 , 0);

}

void HitPoint::checkCollision(int type)
{
    //紅0藍1
    qDebug()<<"檢查碰撞";
    QList<QGraphicsItem * >colliding_items = collidingItems();
    qDebug()<<"碰撞物數量"<<colliding_items.size();
    if(type==0)
    {
        for(int i=0 , n=colliding_items.size(); i<n; i++ )
        {
            if(typeid( *(colliding_items[i]) ) == typeid(RedDon))
            {
                if( colliding_items[i]->x()>=192 && colliding_items[i]->x()<=205 )
                {
                    qDebug()<<"Great Hit!";
                }
                else if( colliding_items[i]->x()>=165 && colliding_items[i]->x()<=232 )
                {
                    qDebug()<<"Good Hit!";
                }
                else if( colliding_items[i]->x()>=135 && colliding_items[i]->x()<=262 )
                {
                    qDebug()<<"Bad Hit!";
                }
                scene()->removeItem( colliding_items[i] );
                delete colliding_items[i];
                return;
            }
        }
    }
    else if(type==1)
    {
        for(int i=0 , n=colliding_items.size(); i<n; i++ )
        {
            if(typeid( *(colliding_items[i]) ) == typeid(BlueDon))
            {
                if( colliding_items[i]->x()>=192 && colliding_items[i]->x()<=205 )
                {
                    qDebug()<<"Great Hit!";
                }
                else if( colliding_items[i]->x()>=165 && colliding_items[i]->x()<=232 )
                {
                    qDebug()<<"Good Hit!";
                }
                else if( colliding_items[i]->x()>=135 && colliding_items[i]->x()<=262 )
                {
                    qDebug()<<"Bad Hit!";
                }
                scene()->removeItem( colliding_items[i] );
                delete colliding_items[i];
                return;
            }
        }
    }
}
