#ifndef REDDON_H
#define REDDON_H


#include <QObject>
#include <QGraphicsPixmapItem>

class RedDon : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        RedDon();

    public slots:
        void move();
};

#endif // REDDON_H
