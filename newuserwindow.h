#ifndef NEWUSERWINDOWH_H
#define NEWUSERWINDOWH_H

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include "mainwindow.h"
#include "netflix.h"

class NewUserWindow: public QWidget
{
  Q_OBJECT

 public:

  NewUserWindow(QWidget* parent = NULL);
  void setNetflix(NetFlix* a);


  // Help define initial size
  QSize sizeHint() const { return QSize( 300, 100 ); };
  // Not totally useful in the main widget/window
  QSize minimumSizeHint() const { return QSize( 200, 150 ); };

 private slots:
  void ConfirmClicked();
  void CancelClicked();


 private:
  MainWindow * parent;
  NetFlix* netflix;

  QLabel* SignUpLabel;
  


  QLineEdit* NewUserNameText;
  QLineEdit* NewNameText;

  QPushButton* ConfirmButton;
  QPushButton* CancelButton;
};

#endif
