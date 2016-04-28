#include <QPen>
#include <QFont>
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

    setDefaultTextColor(Qt::white);
    setFont(QFont("SansSerif" , 40));
}

void ScoreNow::addScore(int amount)
{
    scoreNow += amount;
    setPlainText(QString::number(scoreNow));
}
