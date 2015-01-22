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



RateWindow::RateWindow(QWidget* parent,NetFlix* c)
{


  this->netflix=c;
  this->parent=parent;


   //set up the spinbox 
   RateMovie_label = new QLabel(tr("Enter a value between "
       "%1 and %2: to rate the movie").arg(1).arg(5));
   RateScaleSpinBox = new QSpinBox;
   RateScaleSpinBox->setRange(1, 5);

   RateScaleSpinBox->setValue(1);

  //Label
  MovieRate_label = new QLabel("Movie Rating: ");
  MovieRate_label->setAlignment(Qt::AlignCenter);

  //Button
  SaveButton= new QPushButton("&Save"); 

  
  //layout
  QHBoxLayout *RateWindow_layout = new QHBoxLayout;

  //RateWindow_layout->addWidget(MovieRate_label);
  RateWindow_layout->addWidget(RateMovie_label);
  RateWindow_layout->addWidget(RateScaleSpinBox);
  RateWindow_layout->addWidget(SaveButton);


  connect(SaveButton, SIGNAL(clicked()),
	  this,       SLOT(Save()));

//setlayout
  setLayout(RateWindow_layout);
}

int RateWindow::rate_return()
{
  return RateScaleSpinBox->value();
}

void RateWindow::Save()
 {
    
    this->hide();
    netflix->return_movie(rate_return());
 }

