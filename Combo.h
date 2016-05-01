#ifndef COMBO_H
#define COMBO_H


#include <QGraphicsTextItem>

class Combo : public QGraphicsTextItem
{
    public:
        Combo();
        void addCombo();
        void endCombo();

    private:
        int comboAmount;
};

#endif // COMBO_H
