#include <QBrush>
#include <QImage>
#include "PlayView.h"
#include "BlueDon.h"
#include "RedDon.h"

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
    playEngine->setFocus();
    playScene->addItem(playEngine);

    ove = new QGraphicsPixmapItem();
    ove->setPixmap(QPixmap(":/images/ove.png"));
    ove->setPos(0,240);
    playScene->addItem(ove);

    hitPoint = new HitPoint();
    //hitPoint->setPen(Qt::NoPen);//不知道為什麼不能寫在constructor裡面
    playScene->addItem(hitPoint);

    BlueDon * blueDon = new BlueDon();
    playScene->addItem(blueDon);
    blueDon->setPos(222 , 300);//測試用

    RedDon * redDon = new RedDon();
    playScene->addItem(redDon);
    redDon->setPos(222 , 300);//測試用

    //hitPoint->checkCollision(1);
}
