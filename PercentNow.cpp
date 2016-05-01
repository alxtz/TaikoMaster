#include <QFont>
#include <QColor>
#include <QDebug>
#include <QTextCharFormat>
#include "PercentNow.h"

PercentNow::PercentNow()
{
    totalHits=0;
    correctHits=0;
    percent=0;

    percent = (float)((int)(percent*100*100)*0.01);

    setPlainText(QString::number(percent) + QString("%"));

    setDefaultTextColor(QColor(0 , 60 , 255));
    setFont(QFont("SansSerif" , 25));
    //setPos(670 , 180);
    setPos(195 , 430);
}

void PercentNow::hitted(bool correct)
{
    totalHits++;

    if(correct==true)
    {
        correctHits++;
    }
    percent=((float)correctHits / totalHits)*100;

    percent = (float)((int)(percent*100)*0.01);

    setPlainText(QString::number(percent) + QString("%"));
}
