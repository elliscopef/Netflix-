#ifndef RATEWINDOW_H
#define RATEWINDOW_H

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QSpinBox>
#include "netflix.h"
#include "movie.h"
#include "lib/set.h"

class NewUserWindow;
class MovieSearchWindow;


class RateWindow : public QWidget
{
  Q_OBJECT

 public:
  RateWindow(QWidget* parent,NetFlix* c);


  // Help define initial size
  QSize sizeHint() const { return QSize( 100, 100); }
  // Not totally useful in the main widget/window
  QSize minimumSizeHint() const { return QSize( 200, 150 ); }

  QSpinBox* getSpinBox()
  {
    return RateScaleSpinBox;
  }

  int rate_return();

  //string getUserName();

 private slots:
  void Save();


 protected:

 private:

  QWidget* parent;
  NetFlix* netflix;


  void createSpinBoxes();



  QSpinBox *RateScaleSpinBox;
  QLabel* MovieRate_label;
  QPushButton* SaveButton;

  QLabel *RateMovie_label;
  QLabel *Skip_label;
};

#endif
