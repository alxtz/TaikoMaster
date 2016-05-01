#include <QPen>
#include <QFont>
#include <QColor>
#include <QPainter>
#include <QPainterPath>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QInputDialog>
#include "ScoreNow.h"

ScoreNow::ScoreNow(QGraphicsItem * parent) :QGraphicsTextItem(parent)
{
    scoreNow = 0;

    setPlainText(QString::number(scoreNow));

    //setDefaultTextColor(QColor(214,40,17));
    setDefaultTextColor(Qt::white);
    setFont(QFont("SansSerif" , 60));
    setPos(550 , 190 );
}

void ScoreNow::addScore(int amount)
{
    scoreNow += amount;
    /*
    if(scoreNow>40000)
    {
        setDefaultTextColor(QColor(132,56,194));
    }
    else if(scoreNow>30000)
    {
        setDefaultTextColor(QColor(214,40,17));
    }
    else if(scoreNow>20000)
    {
        setDefaultTextColor(Qt::yellow);
    }
    */
    setPlainText(QString::number(scoreNow));
}
