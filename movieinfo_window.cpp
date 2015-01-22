#include <iostream>
#include <fstream>
#include <string>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <Qt>
#include <QDesktopWidget>
#include <QApplication>
#include "mainwindow.h"
#include "newuserwindow.h"
#include "moviesearchwindow.h"
#include "movieinfo_window.h"
#include "lib/set.h"
#include "user.h"
#include "netflix.h"
#include <QCloseEvent>


using namespace std;



MovieInfo_Window::MovieInfo_Window(QWidget* parent,NetFlix* c)
{


  this->netflix=c;
  this->parent=parent;


 

  MovieInfo = new QLabel("Movie Info");
  MovieInfo->setAlignment(Qt::AlignCenter);

  NextMovieButton= new QPushButton("&Next Movie"); 
  AddToMyQueueButton=new QPushButton("&Add To My Queue");
  ReturnToMainMenuButton=new QPushButton("&Return To Main Menu");


  MovieTitle_L= new QLabel("");
  KeyWord= new QLabel("");
 

  QFormLayout* fLayout6 = new QFormLayout;
  fLayout6->addRow(MovieTitle_L);
  fLayout6->addRow(KeyWord);


  QHBoxLayout* botRow3 = new QHBoxLayout;
  botRow3->addWidget(NextMovieButton);
  botRow3->addWidget(AddToMyQueueButton);
  botRow3->addWidget(ReturnToMainMenuButton);

  setAttribute(Qt::WA_DeleteOnClose); 

  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainLayout->addLayout(fLayout6);
  mainLayout->addLayout(botRow3);

  connect(NextMovieButton, SIGNAL(clicked()),
	  this,       SLOT(NextMovie()));

  connect(AddToMyQueueButton, SIGNAL(clicked()),
	  this,       SLOT(AddToMyQueue()));
  connect(ReturnToMainMenuButton, SIGNAL(clicked()),
    this,       SLOT(ReturnToMainMenu()));

  connect(qApp, SIGNAL(aboutToQuit()),
    this,       SLOT(ReturnToMainMenu()));

  setLayout(mainLayout);
}

void MovieInfo_Window::closeEvent(QCloseEvent *event)
 {
    cout << "Close only the small window" << endl; 
    ReturnToMainMenu();
    this->hide();
    event->ignore(); 
 }

void MovieInfo_Window::updateIterator()
{

   netflix->vector_pos=0;

}

void MovieInfo_Window::NextMovie()
 {

    int temp_size=netflix->getMovieVector().size();
    if(netflix->vector_pos< temp_size-1)
     {
      cout<<temp_size<<endl;
      cout<<netflix->vector_pos<<endl;
      netflix->vector_pos=netflix->vector_pos+1;
      updateMovie_ks();
      updateMovie_title();
      updateMovie_keyword();
     }
     else
     {
       cout<<"Not the beginning"<<endl;
       MovieTitle_L->setText("<b>No Movie</b>"); 
       KeyWord->clear();
     }
 }

void MovieInfo_Window::AddToMyQueue()
  {
    cout<<"add to queue"<<endl;
    netflix->getCurrentUser()->movieQueue()->enqueue(movie_i);
    cout<<"here in the add to my queue"<<endl;
    cout<<movie_i->getTitle()<<endl;

    NextMovie();
  }

void MovieInfo_Window::ReturnToMainMenu()
  {
    ((MovieSearchWindow*)this->parent)->FrontQueue();
    cout<<"in return to main menu"<<endl;
    this->hide();  
  }

void MovieInfo_Window::updateMovie_ks()
 {
    movie_i=netflix->getKey_QuerySet().get(netflix->getMovieVector(netflix->vector_pos));
 }

void MovieInfo_Window::updateMovie(Movie* p)
  {
    movie_i=p;
  }
void MovieInfo_Window::updateMovie_title()
  {
    string movie_temp2=movie_i->getTitle();
    cout<<movie_temp2<<endl;
    QString qstr(movie_temp2.c_str());
    MovieTitle_L->setText(qstr); 
  }

void MovieInfo_Window::updateMovie_keyword()
 {
   string movie_keyword_temp="";
   
  
   for(int a=0;a<netflix->getMovieHash().getM();a++)
   {
    if(!movie_i->getAllKeywords().isEmpty(a))
     {
      string temp_k=movie_i->getAllKeywords().getHashList(a).value;
      movie_keyword_temp +="KeyWord: ";
      movie_keyword_temp += temp_k +"\n";

     }
   }

    for(int a=0;a<netflix->getMovieHash().getM();a++)
   {
    if(!movie_i->getAllActors().isEmpty(a))
     {
      string temp_k=movie_i->getAllActors().getHashList(a).value;
      movie_keyword_temp +="Cast: ";
      movie_keyword_temp += temp_k +"\n";
     }
   }
  
   QString qstr6(movie_keyword_temp.c_str());
   KeyWord->setText(qstr6); 
 }



