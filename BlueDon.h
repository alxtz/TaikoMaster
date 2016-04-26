#ifndef BLUEDON_H
#define BLUEDON_H


#include <QObject>
#include <QGraphicsPixmapItem>

class BlueDon : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        BlueDon();

    public slots:
        void move();
};

#endif // BLUEDON_H
