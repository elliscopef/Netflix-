#include <iostream>
#include <fstream>
#include <string>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <Qt>
#include "newuserwindow.h"

class NetFlix;

using namespace std;

NewUserWindow::NewUserWindow(QWidget* parent): QWidget(parent)

{

  this->parent= (MainWindow*) parent;
  ConfirmButton = new QPushButton("&Confirm");
  CancelButton = new QPushButton("&Cancel");
//add style
  SignUpLabel=new QLabel("<b>Please sign up for the CSCI 104 Flix</b>");
  SignUpLabel->setAlignment(Qt::AlignCenter);

  NewUserNameText = new QLineEdit;
   NewNameText=new QLineEdit;
   
 
  
  QFormLayout* fLayout = new QFormLayout;
  fLayout->addRow(SignUpLabel);
  fLayout->addRow("&New User Name:", NewUserNameText);
  fLayout->addRow("     Name:      ", NewNameText);


  
  QHBoxLayout* botRow = new QHBoxLayout;
  botRow->addWidget(ConfirmButton);
  botRow->addWidget(CancelButton);



  QVBoxLayout* NewUserLayout = new QVBoxLayout;
  NewUserLayout->addLayout(fLayout);
  NewUserLayout->addLayout(botRow);

  //connect the three buttons: login,new_user and quit
  connect(NewNameText, SIGNAL(returnPressed()),
    ConfirmButton,SIGNAL(clicked()));
  connect(ConfirmButton, SIGNAL(clicked()),
	  this,       SLOT(ConfirmClicked()));
  connect(CancelButton, SIGNAL(clicked()),
	  this,       SLOT(CancelClicked()));

  setLayout(NewUserLayout);
}


void NewUserWindow::setNetflix(NetFlix* a)
{
  this->netflix=a;
}



void NewUserWindow::ConfirmClicked()
{


  string NewUserName_s = NewUserNameText->text().toStdString();
  string NewName_s=NewNameText->text().toStdString();

  if(netflix->user_exist(NewUserName_s))
  {
    NewUserNameText->setText(QString("The username exist already, please enter another one"));
  }
  else if(NewUserName_s == "")
  {
    NewUserNameText->setText(QString("Please enter an username"));
  }
  else
  {
    cout<<"here in the last else condition in the confirm fucniton"<<endl;
    netflix->new_user(NewUserName_s, NewName_s);
    parent->show();
    cout<<"end of the else function"<<endl;
    close();
  }

  
}

void NewUserWindow::CancelClicked()
{
  
  parent->show();
  cout<<"Thanks for using the Netflix movie search app"<<endl;
  cout << "Bye Bye!" << endl;
  close();
}


