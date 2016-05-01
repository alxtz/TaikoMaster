#include <fstream>
#include <QDebug>
#include <QTimer>
#include <QSound>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "PlayEngine.h"
#include "PlayView.h"
#include "GreatIcon.h"
#include "GoodIcon.h"
#include "BadIcon.h"
#include "RedDon.h"
#include "BlueDon.h"
#include "SheetMusic.h"

using namespace std;

extern PlayView * playView;

GreatIcon * greatNow;
GoodIcon * goodNow;
BadIcon * badNow;

QTimer * moveTimer;

PlayEngine::PlayEngine()
{
    QObject::connect(this , SIGNAL(setGrade(int)) , this , SLOT(spawnGrade(int)) );

    moveTimer = new QTimer();
    moveTimer->start(7);

    dongPlayer = new QMediaPlayer();
    dongPlayer->setMedia(QUrl("qrc:/sounds/dong.wav"));


    kaPlayer = new QMediaPlayer();
    kaPlayer->setMedia(QUrl("qrc:/sounds/ka.wav"));

    sheetMusicPlayer = new SheetMusicPlayer( & sheetMusic);

    BGMusic = new QMediaPlayer();
    BGMusic->setMedia(QUrl("qrc:/sounds/sunday.mp3"));
}

void PlayEngine::keyPressEvent(QKeyEvent *event)
{
    if( event->key()==Qt::Key_F)
    {
        qDebug()<<"you pressed F !";
        playView->hitPoint->checkCollision(0);
        playView->drum->setSmall();
        QSound::play("./dong.wav");

        //dongPlayer->stop();
        //dongPlayer->play();
    }
    else if( event->key()==Qt::Key_K )
    {
        qDebug()<<"you pressed K !";
        playView->hitPoint->checkCollision(1);
        playView->drum->setSmall();
        QSound::play("./ka.wav");
        //kaPlayer->stop();
        //kaPlayer->play();
    }
}

void PlayEngine::spawnRedDon()
{
    RedDon * red = new RedDon();
    scene()->addItem(red);
    connect( moveTimer , SIGNAL(timeout()) , red , SLOT(move()) );
}

void PlayEngine::spawnBlueDon()
{
    BlueDon * blue = new BlueDon();
    scene()->addItem(blue);
    connect( moveTimer , SIGNAL(timeout()) , blue , SLOT(move()) );
}

void PlayEngine::readSheetMusic()
{
    int BPM=172;

    float speedFactor = (float) 60 / (BPM*2);//每個八分音符的時間長度

    ifstream inputOve("./ove.txt" , ios::in );

    if(!inputOve)
    {
        qDebug()<<"打開失敗~";
    }

    for(int i=0; i<=999; i++)
    {
        float foo;
        if(inputOve>>foo)
        {
            qDebug()<<"第"<<i<<"個拍子數是"<<foo;
            //sheetMusic.notes[i].spawnSec = foo * speedFactor * 1000 + 10370;
            sheetMusic.notes[i].spawnSec = foo * speedFactor * 1000 + 10375;
            //10550後面會有一點問題，之後在改譜面
        }
        else
        {
            qDebug()<<"ove結束";
            break;
        }
        qDebug()<<"第"<<i<<"個note的出生時間是"<< sheetMusic.notes[i].spawnSec;
        inputOve>>foo;
        sheetMusic.notes[i].type = foo;
        qDebug()<<"第"<<i<<"個note的類型是"<< sheetMusic.notes[i].type;
    }
}

void PlayEngine::playSheetMusic()
{
    sheetMusicPlayer->start();
}

void PlayEngine::playMusic()
{
    BGMusic->play();
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
        //QTimer::singleShot(150 , this , SLOT(deleteBad()) );
    }
    else if(grade==1)
    {
        qDebug()<<"spawn可";
        GoodIcon * good = new GoodIcon();
        goodNow = good;
        scene()->addItem(good);
        //QTimer::singleShot(150 , this , SLOT(deleteGood()) );
    }
    else if(grade==2)
    {
        qDebug()<<"spawn良";
        GreatIcon * great = new GreatIcon();
        greatNow=great;
        scene()->addItem(great);
        //QTimer::singleShot(150 , this , SLOT(deleteGreat()) );
    }
}

void PlayEngine::deleteGreat()
{
    qDebug()<<"刪除一個良";
    scene()->removeItem(greatNow);
    delete greatNow;
}

void PlayEngine::deleteGood()
{
    qDebug()<<"刪除一個可";
    scene()->removeItem(goodNow);
    delete goodNow;
}

void PlayEngine::deleteBad()
{
    qDebug()<<"刪除一個不可";
    scene()->removeItem(badNow);
    delete badNow;
}


