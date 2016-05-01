#ifndef PERCENTNOW_H
#define PERCENTNOW_H


#include <QGraphicsTextItem>

class PercentNow : public QGraphicsTextItem
{
    public:
        PercentNow();
        void hitted(bool correct);

    private:
        int totalHits;
        int correctHits;
        float percent;
};

#endif // PERCENTNOW_H
