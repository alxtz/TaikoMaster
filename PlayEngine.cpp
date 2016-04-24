#include <QDebug>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "PlayEngine.h"
#include "PlayView.h"
#include "GreatIcon.h"
#include "GoodIcon.h"
#include "BadIcon.h"

extern PlayView * playView;

GreatIcon * greatNow;
GoodIcon * goodNow;
BadIcon * badNow;

PlayEngine::PlayEngine()
{
    QObject::connect(this , SIGNAL(setGrade(int)) , this , SLOT(spawnGrade(int)) );
}

void PlayEngine::keyPressEvent(QKeyEvent *event)
{
    if( event->key()==Qt::Key_F)
    {
        qDebug()<<"you pressed F !";
        playView->hitPoint->checkCollision(0);
        //spawnGrade(1);
    }
    else if( event->key()==Qt::Key_K )
    {
        qDebug()<<"you pressed K !";
        playView->hitPoint->checkCollision(1);
        //spawnGrade(2);
    }
}

void PlayEngine::spawnGrade(int grade)
{
    //0是不可，1是可，2是良
    if(grade==0)
    {
        qDebug()<<"spawn不可";
        BadIcon * bad = new BadIcon();
        badNow = bad;
        scene()->addItem(bad);
        QTimer::singleShot(500 , this , SLOT(deleteBad()) );
    }
    else if(grade==1)
    {
        qDebug()<<"spawn可";
        GoodIcon * good = new GoodIcon();
        goodNow = good;
        scene()->addItem(good);
        QTimer::singleShot(500 , this , SLOT(deleteGood()) );
    }
    else if(grade==2)
    {
        qDebug()<<"spawn良";
        GreatIcon * great = new GreatIcon();
        greatNow=great;
        scene()->addItem(great);
        QTimer::singleShot(500 , this , SLOT(deleteGreat()) );
    }
}

void PlayEngine::deleteGreat()
{
    scene()->removeItem(greatNow);
    delete greatNow;
}

void PlayEngine::deleteGood()
{
    scene()->removeItem(goodNow);
    delete goodNow;
}

void PlayEngine::deleteBad()
{
    scene()->removeItem(badNow);
    delete badNow;
}


