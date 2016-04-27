#ifndef BADICON_H
#define BADICON_H


#include <QObject>
#include <QGraphicsPixmapItem>

class BadIcon : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        BadIcon();

    public slots:
        void destroySelf();
};

#endif // BADICON_H
