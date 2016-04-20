#ifndef PLAYENGINE_H
#define PLAYENGINE_H


#include <QGraphicsPixmapItem>

class PlayEngine : public QGraphicsPixmapItem
{
    public:
        PlayEngine();
        void keyPressEvent(QKeyEvent * event);
};

#endif // PLAYENGINE_H
