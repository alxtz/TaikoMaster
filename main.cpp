#include <QApplication>
#include "PlayView.h"

PlayView * playView;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    playView = new PlayView();
    playView->show();

    return a.exec();
}
