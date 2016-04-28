#ifndef PLAYENGINE_H
#define PLAYENGINE_H


#include <QWidget>
#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include "SheetMusic.h"
#include "SheetMusicPlayer.h"

class PlayEngine : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        PlayEngine();
        void keyPressEvent(QKeyEvent * event);
        void spawnRedDon();
        void spawnBlueDon();
        void readSheetMusic();
        void playSheetMusic();
        void playMusic();
        SheetMusic sheetMusic;
        SheetMusicPlayer * sheetMusicPlayer;
        QMediaPlayer * dongPlayer;
        QMediaPlayer * kaPlayer;
        QMediaPlayer * BGMusic;

    public slots:
        void spawnGrade(int);
        void deleteGreat();
        void deleteGood();
        void deleteBad();

    signals:
        void setGrade(int);
};

#endif // PLAYENGINE_H
