#ifndef GOODICON_H
#define GOODICON_H


#include <QObject>
#include <QGraphicsPixmapItem>

class GoodIcon : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        GoodIcon();

   public slots:
        void destroySelf();
};

#endif // GOODICON_H
