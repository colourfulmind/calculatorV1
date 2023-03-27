#ifndef DEBIT_H
#define DEBIT_H

#include <QDialog>

extern "C" {
#include "../headers/calculation.h"
}

namespace Ui {
class debit;
}

class debit : public QDialog {
  Q_OBJECT

 public:
  explicit debit(QWidget *parent = nullptr);
  ~debit();

 signals:
  void MainWindow();

 private slots:
  void on_back_clicked();

  void on_calculate_clicked();

  void on_clear_clicked();

 private:
  Ui::debit *ui;
};

#endif  // DEBIT_H
