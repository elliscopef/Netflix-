#ifndef MOVIEINFO_WINDOW_H
#define MOVIEINFO_WINDOW_H

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include "netflix.h"
#include "movie.h"
#include "lib/set.h"

class NewUserWindow;
class MovieSearchWindow;


class MovieInfo_Window : public QWidget
{
  Q_OBJECT

 public:
  MovieInfo_Window(QWidget* parent,NetFlix* c);

  void updateMovie_ks();
  void updateMovie(Movie* p);
  void updateMovie_title();
  void updateMovie_keyword();
  void updateIterator();


  // Help define initial size
  QSize sizeHint() const { return QSize( 300, 100 ); }
  // Not totally useful in the main widget/window
  QSize minimumSizeHint() const { return QSize( 200, 150 ); }

  //string getUserName();

 private slots:

  void NextMovie();
  void AddToMyQueue();
  void ReturnToMainMenu();
  void closeEvent(QCloseEvent *event);
  //void quitThisWindow();

 protected:

 private:
  QWidget* parent;
  NetFlix* netflix;
  QLabel* MovieInfo;
  QLabel* MovieTitle_L;
  QLabel* KeyWord;

  Set<Movie*>::Iterator qi;
  int qi_counter;

  Set<Movie*> key_querySet;

  Movie* movie_i;

  QPushButton* NextMovieButton;
  QPushButton* AddToMyQueueButton;
  QPushButton* ReturnToMainMenuButton;

};

#endif
