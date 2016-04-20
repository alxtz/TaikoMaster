#ifndef HITPOINT_H
#define HITPOINT_H


#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class HitPoint : public QGraphicsRectItem
{
    public:
        HitPoint();
        void checkCollision(int keyType);
    private:
        //QGraphicsRectItem * hitBox;//參考用
        //QGraphicsRectItem * badHitBox;//參考用
        QGraphicsPixmapItem * hitCircle;
};

#endif // HITPOINT_H
