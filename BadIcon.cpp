#include <QPixmap>
#include "BadIcon.h"

BadIcon::BadIcon()
{
    setPixmap( QPixmap(":/images/bad.png") );
    setPos(195 , 305);
}
