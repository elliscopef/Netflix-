#ifndef POPUPWINDOW_H
#define POPUPWINDOW_H

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QSpinBox>
#include "netflix.h"
#include "movie.h"
#include "lib/set.h"
#include "ratewindow.h"

class NewUserWindow;
class MovieSearchWindow;


class PopUpWindow : public QWidget
{
  Q_OBJECT

 public:
  PopUpWindow(QWidget* parent,NetFlix* c);


  // Help define initial size
  QSize sizeHint() const { return QSize( 100, 100); }
  // Not totally useful in the main widget/window
  QSize minimumSizeHint() const { return QSize( 200, 150 ); }





 private slots:
  void ReRate();
  void Skip();


 protected:
  
 private:

  RateWindow* RateWindow_w_1;

  QWidget* parent;
  NetFlix* netflix;

  QPushButton* ReRateButton;
  QPushButton* SkipButton;

  QLabel *PopUp_label;
};

#endif
