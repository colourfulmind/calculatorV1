#ifndef CREDIT_H
#define CREDIT_H

#include <QDialog>

extern "C" {
#include "../headers/calculation.h"
}

namespace Ui {
class credit;
}

class credit : public QDialog {
  Q_OBJECT

 signals:
  void MainWindow();

 public:
  explicit credit(QWidget *parent = nullptr);
  ~credit();

 private slots:
  void on_back_clicked();

  void on_calculate_clicked();

  void on_clear_clicked();

 private:
  Ui::credit *ui;
};

#endif  // CREDIT_H
