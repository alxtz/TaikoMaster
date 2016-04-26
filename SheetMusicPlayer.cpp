#include <QDebug>
#include <QTimer>
#include "SheetMusicPlayer.h"
#include "PlayView.h"

extern PlayView * playView;

SheetMusicPlayer::SheetMusicPlayer(SheetMusic * inputSheet) : sheetMusic(*inputSheet)
{
    currentNote=0;
}


void SheetMusicPlayer::start()
{
    count();
}

void SheetMusicPlayer::count()
{
    if(sheetMusic.notes[currentNote].type==-1)
        {
            qDebug()<<"譜面結束";
            return;
        }
    int delayTime;
    if(currentNote==0)
    {
        delayTime=sheetMusic.notes[currentNote].spawnSec;
    }
    else
    {
        delayTime=sheetMusic.notes[currentNote].spawnSec - sheetMusic.notes[currentNote-1].spawnSec;
    }
    QTimer::singleShot(delayTime , this , SLOT( spawn() ) );
}

void SheetMusicPlayer::spawn()
{
    if(sheetMusic.notes[currentNote].type==0)
    {
        qDebug()<<"產生紅咚";
        qDebug()<<"第"<<currentNote<<"個節拍";
        playView->playEngine->spawnRedDon();
    }
    else  if(sheetMusic.notes[currentNote].type==1)
    {
        qDebug()<<"產生藍咚";
        qDebug()<<"第"<<currentNote<<"個節拍";
        playView->playEngine->spawnBlueDon();
    }
    currentNote++;
    count();
}
