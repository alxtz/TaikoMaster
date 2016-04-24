#include <QBrush>
#include <QImage>
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
    playEngine->setFocus();
    playScene->addItem(playEngine);

    ove = new QGraphicsPixmapItem();
    ove->setPixmap(QPixmap(":/images/ove.png"));
    ove->setPos(0,295);
    playScene->addItem(ove);

    hitPoint = new HitPoint();
    hitPoint->setPen(Qt::NoPen);//不知道為什麼不能寫在constructor裡面
    playScene->addItem(hitPoint);

    BlueDon * blueDon = new BlueDon();
    playScene->addItem(blueDon);
    blueDon->setPos(202 , 320);//測試用

    RedDon * redDon = new RedDon();
    playScene->addItem(redDon);
    redDon->setPos(250 , 350);//測試用

    GreatIcon * great  = new GreatIcon();
    //playScene->addItem(great);

}
