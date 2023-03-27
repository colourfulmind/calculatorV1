#ifndef GRAPHICWINDOW_H
#define GRAPHICWINDOW_H

#include <QDialog>

extern "C" {
#include "../headers/calculation.h"
}

namespace Ui {
class GraphicWindow;
}

class GraphicWindow : public QDialog {
  Q_OBJECT

 public:
  explicit GraphicWindow(QWidget *parent = nullptr);
  ~GraphicWindow();

 signals:
  void MainWindow();

 private slots:
  void on_draw_clicked();

  void on_clear_clicked();

  void on_back_clicked();

 private:
  Ui::GraphicWindow *ui;
};

#endif  // GRAPHICWINDOW_H
