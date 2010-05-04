#include <QtGui/QApplication>
#include "mainwindow.h"
#include "VDownloader/Megavideo/megavideo.h"
#include <iostream>

/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
*/


int main ()
{
    Megavideo mv;
    mv.setUrl("http://www.megavideo.com/?v=199MT4EE");
    std::cout << mv.getDownLink() << std::endl;
    return 0;
}
