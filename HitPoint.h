#ifndef HITPOINT_H
#define HITPOINT_H


#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class HitPoint : public QGraphicsRectItem
{
    public:
        HitPoint();
        void checkCollision(int type);
    private:
        QGraphicsPixmapItem * hitIcon;

};

#endif // HITPOINT_H
