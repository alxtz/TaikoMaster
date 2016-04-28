#ifndef SMALLDRUM_H
#define SMALLDRUM_H


#include <QObject>
#include <QGraphicsPixmapItem>

class SmallDrum : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        SmallDrum();

    public slots:
        void destroySelf();
};

#endif // SMALLDRUM_H
