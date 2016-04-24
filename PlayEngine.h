#ifndef PLAYENGINE_H
#define PLAYENGINE_H


#include <QObject>
#include <QGraphicsPixmapItem>

class PlayEngine : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        PlayEngine();
        void keyPressEvent(QKeyEvent * event);

    public slots:
        void spawnGrade(int);
        void deleteGreat();
        void deleteGood();
        void deleteBad();

    signals:
        void setGrade(int);


};

#endif // PLAYENGINE_H
