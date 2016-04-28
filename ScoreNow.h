#ifndef SCORENOW_H
#define SCORENOW_H


#include <QWidget>
#include <QPainter>
#include <QGraphicsTextItem>

class ScoreNow :public QGraphicsTextItem
{
    public:
        ScoreNow(QGraphicsItem * parent = 0);
        void addScore(int amount);

    private:
        int scoreNow;
};

#endif // SCORENOW_H
