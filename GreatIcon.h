#ifndef GREATICON_H
#define GREATICON_H


#include <QObject>
#include <QGraphicsPixmapItem>

class GreatIcon : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        GreatIcon();

    public slots:
        void destroySelf();
};

#endif // GREATICON_H
