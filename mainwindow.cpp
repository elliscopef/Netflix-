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

using namespace std;

MainWindow::MainWindow(NetFlix* b)
{



  LoginButton = new QPushButton("&Login");
  NewUserButton = new QPushButton("&New User");
  QuitButton = new QPushButton("&Quit");

  LoginLabel=new QLabel("<b>Welcome to CSCI 104- Flix</b>");
  LoginLabel->setAlignment(Qt::AlignCenter);


  ErrorLoginLabel=new QLabel("The username isn't valid");
  ErrorLoginLabel->setAlignment(Qt::AlignCenter);

  UserNameText = new QLineEdit;

  QFormLayout* fLayout = new QFormLayout;
  fLayout->addRow(LoginLabel);
  fLayout->addRow(ErrorLoginLabel);
  ErrorLoginLabel->hide();
  fLayout->addRow("&Login:", UserNameText);


  
  QHBoxLayout* botRow = new QHBoxLayout;
  botRow->addWidget(LoginButton);
  botRow->addWidget(NewUserButton);
  botRow->addWidget(QuitButton);


  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainLayout->addLayout(fLayout);
  mainLayout->addLayout(botRow);

//Initialize other window class

  QNewUser_w=new NewUserWindow(this);
  QNewUser_w->setNetflix(b);
  QNewUser_w->setWindowFlags(Qt::Window);

  
  QMovieSearch_w=new MovieSearchWindow(this,b);
  QMovieSearch_w->setWindowFlags(Qt::Window);


  //connect the three buttons: login,new_user and quit
  //also connect the login button to the return key.
  connect(UserNameText, SIGNAL(returnPressed()),
    LoginButton,SIGNAL(clicked()));
  connect(LoginButton, SIGNAL(clicked()),
	  this,       SLOT(LoginClicked()));

  connect(NewUserButton, SIGNAL(clicked()),
	  this,       SLOT(NewUserClicked()));
  connect(QuitButton, SIGNAL(clicked()),
    this,       SLOT(QuitClicked()));


  this->netflix=b;


  setLayout(mainLayout);
}




void MainWindow::LoginClicked()
{
  string userName = UserNameText->text().toStdString();

  if(netflix->user_exist(userName))
  {   

   if(netflix->getCurrentUser()->currentMovie()!=NULL)
   {
   QMovieSearch_w->updateCurrentMovie();
   QMovieSearch_w->FrontQueue();
   } 
  
   this->hide();
   QMovieSearch_w->adjustSize();
   QMovieSearch_w->move(QApplication::desktop()->screen()->rect().center() - QMovieSearch_w->rect().center());
   QMovieSearch_w->show();
  }
  else
  {
    ErrorLoginLabel->show();
  }

  if(userName != ""){

  }
  else {
    UserNameText->setText(QString("Please enter username to login"));
  }
}

void MainWindow::QuitClicked()
{
  cout<<"Thanks for using the Netflix movie search app"<<endl;
  cout << "Bye Bye!" << endl;
  close();
}

void MainWindow::NewUserClicked()
{


  this->hide();

   QNewUser_w->adjustSize();
   QNewUser_w->move(QApplication::desktop()->screen()->rect().center() - QNewUser_w->rect().center());
   QNewUser_w->show();

}