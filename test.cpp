#include <QApplication>
#include <QDesktopWidget>
#include "mainwindow.h"
#include "netflix.h"

int main(int argc, char* argv[])
{

  QApplication app(argc, argv);
   NetFlix* netflix;
   netflix= new NetFlix();
   netflix->read_user_info();
   netflix->read_movie_info();

   MainWindow* movieapp;
   movieapp=new MainWindow(netflix);


   movieapp->adjustSize();
   movieapp->move(QApplication::desktop()->screen()->rect().center() - movieapp->rect().center());
   movieapp->show();
   
   
   return app.exec();
}
