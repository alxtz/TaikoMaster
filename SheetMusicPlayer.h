#ifndef SHEETMUSICPLAYER_H
#define SHEETMUSICPLAYER_H


#include <QObject>
#include "SheetMusic.h"

class SheetMusicPlayer : public QObject
{
    Q_OBJECT

    public:
        SheetMusicPlayer(SheetMusic * inputSheet);
        int currentNote;
        SheetMusic & sheetMusic;
        void count();
        void start();

    public slots:
        void spawn();
};

#endif // SHEETMUSICPLAYER_H
