#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include "netflix.h"
#include <QMessageBox>


class NewUserWindow;
class MovieSearchWindow;

class MainWindow : public QWidget
{
  Q_OBJECT

 public:
  NetFlix* netflix;

  MainWindow(NetFlix* netflix);
  NewUserWindow* QNewUser_w;
  MovieSearchWindow* QMovieSearch_w;


  // Help define initial size
  QSize sizeHint() const { return QSize( 300, 100 ); }
  // Not totally useful in the main widget/window
  QSize minimumSizeHint() const { return QSize( 200, 150 ); }



 private slots:
  void LoginClicked();
  void QuitClicked();
  void NewUserClicked();
 protected:

 private:
  string username;

  QLabel* LoginLabel;
  QLabel* WelcomeWord;
  QLabel* ErrorLoginLabel;

  QLineEdit* UserNameText;

  QPushButton* LoginButton;
  QPushButton* NewUserButton;
  QPushButton* QuitButton;

};

#endif
