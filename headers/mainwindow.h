#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

#include "credit.h"
#include "debit.h"
#include "graphicwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  GraphicWindow *secondWindow;
  credit *thirdWindow;
  debit *fourthWindow;

 private slots:
  void insertText();
  void on_pushButton_dot_clicked();
  void on_pushButton_all_clear_clicked();
  void on_pushButton_clear_entry_clicked();
  void on_pushButton_equal_clicked();
  void on_comboBox_textActivated(const QString &arg1);
};
#endif  // MAINWINDOW_H
