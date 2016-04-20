#include <QDebug>
#include <QKeyEvent>
#include "PlayEngine.h"
#include "PlayView.h"

extern PlayView * playView;

PlayEngine::PlayEngine()
{

}

void PlayEngine::keyPressEvent(QKeyEvent *event)
{
    if( event->key()==Qt::Key_F)
    {
        qDebug()<<"you pressed F !";
        playView->hitPoint->checkCollision(0);
    }
    else if( event->key()==Qt::Key_K )
    {
        qDebug()<<"you pressed K !";
        playView->hitPoint->checkCollision(1);
    }
}
