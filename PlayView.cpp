#include <QPen>
#include <QBrush>
#include <QImage>
#include <QWidget>
#include <QPainter>
#include "PlayView.h"
#include "BlueDon.h"
#include "RedDon.h"
#include "GreatIcon.h"

PlayView::PlayView()
{
    setFixedSize(800 , 600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setBackgroundBrush( QBrush( QImage( ":/images/backGround_haruhi.png" ) ) );

    playScene = new QGraphicsScene(this);
    playScene->setSceneRect(0 , 0 , 800 , 600);
    setScene(playScene);

    playEngine = new PlayEngine();
    playEngine->setFlag(QGraphicsItem::ItemIsFocusable);
    playScene->addItem(playEngine);
    playEngine->setFocus();
    playEngine->grabKeyboard();
    playEngine->readSheetMusic();
    //playEngine->playSheetMusic();
    //playEngine->playMusic();

    ove = new QGraphicsPixmapItem();
    ove->setPixmap(QPixmap(":/images/ove.png"));
    ove->setPos(0,295);
    playScene->addItem(ove);

    hitPoint = new HitPoint();
    hitPoint->setPen(Qt::NoPen);//不知道為什麼不能寫在constructor裡面
    playScene->addItem(hitPoint);

    drum = new Drum();
    playScene->addItem(drum);

    scoreNow = new ScoreNow();
    playScene->addItem(scoreNow);
    
    percentNow = new PercentNow();
    playScene->addItem(percentNow);

    combo = new Combo();
    playScene->addItem(combo);


    //playEngine->spawnBlueDon();
}
