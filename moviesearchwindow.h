#ifndef MOVIESEARCHWINDOW_H
#define MOVIESEARCHWINDOW_H


#include "movieinfo_window.h"
#include "ratewindow.h"
#include "popupwindow.h"

#include <iostream>
#include <string>


#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include "mainwindow.h"
#include "netflix.h"


class MovieSearchWindow: public QWidget
{
  Q_OBJECT

 public:
  
  MovieSearchWindow(QWidget* parent,NetFlix* netflix);
  MovieInfo_Window* MovieInfo_w;
  RateWindow* RateWindow_w;
  PopUpWindow* PopUp_w;


  void updateCurrentMovie();
  void FrontQueue();


  QSize sizeHint() const { return QSize( 500, 700 ); }
  // Not totally useful in the main widget/window
  QSize minimumSizeHint() const { return QSize( 200, 150 ); }



 private slots:
  void ReturnMovieClicked();
  void RentMovieClicked();
  void DeleteFromQueueClicked();
  
  void MoveToBackClicked();
  void SearchByTitleClicked();
  void SearchByKeyWordClicked();
  void LogOutClicked();
  void closeEvent(QCloseEvent *event);

 protected:
 
 private:

  QWidget* parent;
  NetFlix* netflix;

  bool update_qi_indi;
 

  QPushButton* ReturnMovieButton;

  
  QPushButton* RentMovieButton;
  QPushButton* DeleteFromQueueButton;
  QPushButton* MoveToBackButton;

  QPushButton* SearchByTitleButton;
  QPushButton* SearchByKeyWordButton;
  QPushButton* LogOutButton;
  
  
  
  QLabel* Welcome_Label;
  QLabel* YourCurrentMovieLabel;
  QLabel* CurrentMovie_v;
  QLabel* YourMovieQueue;
  QLabel* SearchForAMovie;
  QLabel* MovieSearchWelcomeLabel;
  QLabel* FrontOfQueue;
  QLabel* FrontOfQueueMovieName;
  QLabel* ErrorRent;
  QLabel* MovieRatedIndication;

  QLabel* ErrorMovieTitle;
  
  QLineEdit* MovieSearhLineEdit;

  QPushButton* LoginButton;
  QPushButton* NewUserButton;
  QPushButton* QuitButton;



};

#endif
