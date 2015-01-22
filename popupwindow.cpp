#include <iostream>
#include <fstream>
#include <string>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <Qt>
#include <QSpinBox>
#include <QDesktopWidget>
#include <QApplication>
#include "ratewindow.h"
#include "mainwindow.h"
#include "newuserwindow.h"
#include "moviesearchwindow.h"
#include "movieinfo_window.h"
#include "lib/set.h"
#include <QCloseEvent>

using namespace std;



PopUpWindow::PopUpWindow(QWidget* parent,NetFlix* c)
{


  this->netflix=c;
  this->parent=parent;

  RateWindow_w_1=new RateWindow(this,c);
  RateWindow_w_1->setWindowFlags(Qt::Window);


  //Label
  PopUp_label = new QLabel("This movie has been rated before. Do you want to Rerate it?");
  PopUp_label->setAlignment(Qt::AlignCenter);

  //Button
  ReRateButton= new QPushButton("&Yes"); 
  SkipButton= new QPushButton("&No"); 
  
  //layout
  QHBoxLayout *PopUpWindow_layout = new QHBoxLayout;

  
  PopUpWindow_layout->addWidget(PopUp_label);
  PopUpWindow_layout->addWidget(ReRateButton);
  PopUpWindow_layout->addWidget(SkipButton);


  connect(ReRateButton, SIGNAL(clicked()),
	  this,       SLOT(ReRate()));

  connect(SkipButton, SIGNAL(clicked()),
    this,       SLOT(Skip()));


//setlayout
  setLayout(PopUpWindow_layout);
}


void PopUpWindow::ReRate()
 {
    this->hide();

     RateWindow_w_1->adjustSize();
     RateWindow_w_1->move(QApplication::desktop()->screen()->rect().center() - RateWindow_w_1->rect().center());
     RateWindow_w_1->show();
 }

 void PopUpWindow::Skip()
 {
  this->hide();
  netflix->return_movie(0);
 }

