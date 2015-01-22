#include <iostream>
#include <fstream>
#include <string>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QDesktopWidget>
#include <Qt>
#include <QApplication>
#include <QString>
#include "mainwindow.h"
#include "newuserwindow.h"
#include "moviesearchwindow.h"
#include "movie.h"
#include "user.h"
#include <QCloseEvent>
#include "movieinfo_window.h"

using namespace std;

MovieSearchWindow::MovieSearchWindow(QWidget* parent,NetFlix* c): QWidget(parent)

{

 
  MovieInfo_w=new MovieInfo_Window(this,c);
  MovieInfo_w->setWindowFlags(Qt::Window);

  RateWindow_w=new RateWindow(this,c);
  RateWindow_w->setWindowFlags(Qt::Window);

  PopUp_w= new PopUpWindow(this,c);
  PopUp_w->setWindowFlags(Qt::Window);
 
  this->parent=parent;
  this->netflix=c;
  update_qi_indi=true;
 

  ReturnMovieButton = new QPushButton("&Return Movie");

  RentMovieButton= new QPushButton("&Rent Movie");
  DeleteFromQueueButton = new QPushButton("&Delete From Queue");
  MoveToBackButton = new QPushButton("&Move To Back");
  

  SearchByTitleButton = new QPushButton("&Search By Title");
  SearchByKeyWordButton = new QPushButton("&Search By KeyWord");
  LogOutButton=new QPushButton("Log Out");

  MovieSearchWelcomeLabel=new QLabel("<b>Welcome to CSCI 104- Flix</b>\n");
  MovieSearchWelcomeLabel->setAlignment(Qt::AlignCenter);

  Welcome_Label=new QLabel("Hello ");
  FrontOfQueue = new QLabel("Front of Queue:");
  YourCurrentMovieLabel=new QLabel("\n Your Current Movie");
  YourMovieQueue=new QLabel("Your Movie Queue");
  SearchForAMovie=new QLabel("Search for a movie");
  ErrorMovieTitle=new QLabel("The Movie title or Keywords aren't correct. (Case Sensitive)");

  
  MovieRatedIndication = new QLabel("This movie has been rated");
  CurrentMovie_v=new QLabel("No Movie");
  FrontOfQueueMovieName = new QLabel("No Movie"); 
  ErrorRent=new QLabel(""); 
  MovieSearhLineEdit = new QLineEdit;
 
  //current movie user interface
  QFormLayout* fLayout1 = new QFormLayout;
  fLayout1->addRow(MovieSearchWelcomeLabel);
  fLayout1->addRow(Welcome_Label);
  fLayout1->addRow(YourCurrentMovieLabel);
  fLayout1->addRow(CurrentMovie_v);
  fLayout1->addRow(MovieRatedIndication);
  MovieRatedIndication->hide();
  fLayout1->addRow(ReturnMovieButton); 
  


  //The first HBoxLayout->buttons
  QHBoxLayout* botRow1 = new QHBoxLayout;
  botRow1->addWidget(RentMovieButton);
  botRow1->addWidget(DeleteFromQueueButton);
  botRow1->addWidget(MoveToBackButton);
  
  //add buttons to fLayout2
  QFormLayout* fLayout2 = new QFormLayout;
  fLayout2->addRow(YourMovieQueue);
  fLayout2->addRow(FrontOfQueue);
  fLayout2->addRow(FrontOfQueueMovieName);
  fLayout2->addRow(ErrorRent);
  fLayout2->addRow(botRow1);  
  
  //add buttons to the HBoxLayout
  QHBoxLayout* botRow2 = new QHBoxLayout;
  botRow2->addWidget(SearchByTitleButton);
  botRow2->addWidget(SearchByKeyWordButton);


  //add search movie thing to the flayout3  
  QFormLayout* fLayout3 = new QFormLayout;
  fLayout3->addRow(SearchForAMovie);
  fLayout3->addRow(ErrorMovieTitle);
  ErrorMovieTitle->hide();
  fLayout3->addRow("&Search",MovieSearhLineEdit);
  fLayout3->addRow(botRow2);
  fLayout3->addRow(LogOutButton);
  
  //add all above widgets to the main layout
  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainLayout->addLayout(fLayout1);
  mainLayout->addLayout(fLayout2);
  mainLayout->addLayout(fLayout3);




  //connect the three buttons: login,new_user and quit
  connect(ReturnMovieButton, SIGNAL(clicked()),
	  this,       SLOT(ReturnMovieClicked()));
  connect(RentMovieButton, SIGNAL(clicked()),
	  this,       SLOT(RentMovieClicked()));
  connect(DeleteFromQueueButton, SIGNAL(clicked()),
    this,       SLOT(DeleteFromQueueClicked()));
  connect(MoveToBackButton, SIGNAL(clicked()),
    this,       SLOT(MoveToBackClicked()));
  connect(SearchByTitleButton, SIGNAL(clicked()),
    this,       SLOT(SearchByTitleClicked()));
  connect(SearchByKeyWordButton, SIGNAL(clicked()),
    this,       SLOT(SearchByKeyWordClicked()));
  connect(LogOutButton, SIGNAL(clicked()),
    this,       SLOT(LogOutClicked()));

  setLayout(mainLayout);
}




void MovieSearchWindow::closeEvent(QCloseEvent *event)
{
  event->ignore();
}
void MovieSearchWindow::RentMovieClicked()
{
  
  if( FrontOfQueueMovieName->text().toStdString()!="No Movie")
  { 
    if(netflix->getCurrentUser()->currentMovie()==NULL)
    {
      netflix->getCurrentUser()->rentMovie(netflix->getCurrentUser()->movieQueue()->peekFront());
      updateCurrentMovie();
      DeleteFromQueueClicked();
      MovieRatedIndication->hide();
    }
    else
    {
       string ErrorLine="Please return the movie before rent new one";
       QString qstr3(ErrorLine.c_str());
       ErrorRent->setText(qstr3);
          MovieRatedIndication->hide();
    }
  }

}

 void MovieSearchWindow::FrontQueue()
 {
  string front_queue=netflix->FrontOfQueue();
  QString qstr1(front_queue.c_str());
  FrontOfQueueMovieName->setText(qstr1);
 }

void MovieSearchWindow::DeleteFromQueueClicked()
{
  netflix->delete_from_queue();
  string front_queue1=netflix->FrontOfQueue();
  QString qstr2(front_queue1.c_str());
  FrontOfQueueMovieName->setText(qstr2);
}

void MovieSearchWindow::ReturnMovieClicked()
{
    if(!netflix->getCurrentUser()->rent_movie_rated())
            { 
                 RateWindow_w->adjustSize();
                 RateWindow_w->move(QApplication::desktop()->screen()->rect().center() - RateWindow_w->rect().center());
                 RateWindow_w->show();
                 CurrentMovie_v->clear();
                 ErrorRent->clear();
            }
    else 
    {
      if(netflix->getCurrentUser()->currentMovie()!=NULL)
      {
        CurrentMovie_v->clear();
        ErrorRent->clear();
        PopUp_w->adjustSize();
        PopUp_w->move(QApplication::desktop()->screen()->rect().center() - PopUp_w->rect().center());
        PopUp_w->show();
        
      }
    
    }
    
}


   

void MovieSearchWindow::updateCurrentMovie()
{
  string movie_temp1=netflix->getCurrentUser()->currentMovie()->getTitle();
  QString qstr(movie_temp1.c_str());
  CurrentMovie_v->setText(qstr);
}

void MovieSearchWindow::MoveToBackClicked()
{
  if( FrontOfQueueMovieName->text().toStdString()!="No Movie")
   {
    netflix->getCurrentUser()->movieQueue()->enqueue(netflix->getCurrentUser()->movieQueue()->peekFront());
    netflix->getCurrentUser()->movieQueue()->dequeue();

    string front_queue1=netflix->FrontOfQueue();
    QString qstr2(front_queue1.c_str());
    FrontOfQueueMovieName->setText(qstr2);
   } 
}

void MovieSearchWindow::SearchByTitleClicked()
{

       string movie_search=MovieSearhLineEdit->text().toStdString();
       
       if(netflix->if_movie_exist(movie_search))
       {

             ErrorMovieTitle->hide();
            
             MovieInfo_w->adjustSize();
             MovieInfo_w->move(QApplication::desktop()->screen()->rect().center() - MovieInfo_w->rect().center());
             MovieInfo_w->show();

             MovieInfo_w->updateMovie(netflix->search_by_title(movie_search));
             MovieInfo_w->updateMovie_title();
             MovieInfo_w->updateMovie_keyword();
       }
       else
       {
             ErrorMovieTitle->show();
       }
      

}
void MovieSearchWindow::SearchByKeyWordClicked()
{
  cout<<"hello world"<<endl;
  string movie_search=MovieSearhLineEdit->text().toStdString();

  int search_result_indi;
  search_result_indi=netflix->if_keyword_exist(movie_search);
  cout<<search_result_indi<<" :search_result_indi "<<endl;


  if(search_result_indi==0)           
  {
    ErrorMovieTitle->show();
  }  
  else if(search_result_indi==1)
  {
    SearchByTitleClicked();
  }
  else if(search_result_indi==2)
  {
    //add all the movie to the hash table key_query and movie title to the vector
     netflix->search_by_keywords(movie_search);
     
     MovieInfo_w->adjustSize();
     MovieInfo_w->move(QApplication::desktop()->screen()->rect().center() - MovieInfo_w->rect().center());
     MovieInfo_w->show();

     
     MovieInfo_w->updateIterator();
     
     
     MovieInfo_w->updateMovie_ks();
     MovieInfo_w->updateMovie_title();
     MovieInfo_w->updateMovie_keyword();
  }
}
void MovieSearchWindow::LogOutClicked()
{
    netflix->writeout_file();
    update_qi_indi=true;
    this->hide();
    parent->show();
}