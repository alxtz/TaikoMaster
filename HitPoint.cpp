#include <QList>
#include <QGraphicsScene>
#include <typeinfo>
#include <QDebug>
#include <QPixmap>
#include "PlayView.h"
#include "HitPoint.h"
#include "RedDon.h"
#include "BlueDon.h"

extern PlayView * playView;

HitPoint::HitPoint()
{
    setRect(0 , 0 , 80 , 60);
    setPos(182 , 335);

    hitIcon = new QGraphicsPixmapItem(this);
    hitIcon->setPixmap(QPixmap(":/images/hitPoint.png"));
    hitIcon->setPos(10 , 0);

}

void HitPoint::checkCollision(int type)
{
    QList<QGraphicsItem * >colliding_items = collidingItems();
    if(type==0)
    {
        for(int i=0 , n=colliding_items.size(); i<n; i++ )
        {
            if(typeid( *(colliding_items[i]) ) == typeid(RedDon))
            {
                if( colliding_items[i]->x()>=192 && colliding_items[i]->x()<=205 )
                {
                    qDebug()<<"Great Hit!";
                    playView->playEngine->setGrade(2);
                    playView->scoreNow->addScore(500);
                    playView->percentNow->hitted(true);
                    playView->combo->addCombo();
                }
                else if( colliding_items[i]->x()>=165 && colliding_items[i]->x()<=232 )
                {
                    qDebug()<<"Good Hit!";
                    playView->playEngine->setGrade(1);
                    playView->scoreNow->addScore(200);
                    playView->percentNow->hitted(true);
                    playView->combo->addCombo();
                }
                else if( colliding_items[i]->x()>=135 && colliding_items[i]->x()<=262 )
                {
                    qDebug()<<"Bad Hit!";
                    playView->playEngine->setGrade(0);
                    playView->percentNow->hitted(false);
                    playView->combo->endCombo();
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
                    playView->playEngine->setGrade(2);
                    playView->scoreNow->addScore(500);
                    playView->percentNow->hitted(true);
                    playView->combo->addCombo();
                }
                else if( colliding_items[i]->x()>=165 && colliding_items[i]->x()<=232 )
                {
                    qDebug()<<"Good Hit!";
                    playView->playEngine->setGrade(1);
                    playView->scoreNow->addScore(200);
                    playView->percentNow->hitted(true);
                    playView->combo->addCombo();
                }
                else if( colliding_items[i]->x()>=135 && colliding_items[i]->x()<=262 )
                {
                    qDebug()<<"Bad Hit!";
                    playView->playEngine->setGrade(0);
                    playView->percentNow->hitted(false);
                    playView->combo->endCombo();
                }
                scene()->removeItem( colliding_items[i] );
                delete colliding_items[i];
                return;
            }
        }
    }
}
