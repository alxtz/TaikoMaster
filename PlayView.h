#ifndef PLAYVIEW_H
#define PLAYVIEW_H


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "Drum.h"
#include "ScoreNow.h"
#include "HitPoint.h"
#include "PlayEngine.h"

class PlayView : public QGraphicsView
{
    public:
        PlayView();
        QGraphicsScene * playScene;
        PlayEngine * playEngine;
        QGraphicsPixmapItem * ove;
        HitPoint * hitPoint;
        Drum * drum;
        ScoreNow * scoreNow;
};

#endif // PLAYVIEW_H
