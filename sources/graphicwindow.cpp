#include "../headers/graphicwindow.h"

#include "ui_graphicwindow.h"

GraphicWindow::GraphicWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::GraphicWindow) {
  ui->setupUi(this);

  ui->widget->addGraph();
  ui->widget->graph(0)->setPen(QPen(Qt::black));
  ui->widget->setBackground(QColor(238, 241, 255, 0));
  ui->widget->replot();
}

GraphicWindow::~GraphicWindow() { delete ui; }

void GraphicWindow::on_draw_clicked() {
  bool numX1, numX2, numY1, numY2;
  (ui->x1->text()).toInt(&numX1, 10);
  (ui->x1->text()).toInt(&numX2, 10);
  (ui->x1->text()).toInt(&numY1, 10);
  (ui->x1->text()).toInt(&numY2, 10);

  if (numX1 && numX2 && numY1 && numY2) {
    double x1 = (ui->x1->text()).toDouble();
    double x2 = (ui->x2->text()).toDouble();
    double y1 = (ui->y1->text()).toDouble();
    double y2 = (ui->y2->text()).toDouble();

    if (-1000000 <= x1 && x1 < x2 && x2 <= 1000000 && -1000000 <= y1 &&
        y1 < y2 && y2 <= 1000000) {
      std::string stringText = ui->expression->text().toStdString();
      const char *expression = stringText.c_str();
      int errorCode = 0;
      long double result = 0.0;
      reversePolish *firstElement =
          (reversePolish *)calloc(1, sizeof(reversePolish));
      toReversePolish(expression, &errorCode, firstElement);
      double h = 0.1, X;
      QVector<double> x, y;
      if (errorCode == 0) {
        for (X = x1; X <= x2; X += h) {
          fromReversePolish(&result, firstElement, &errorCode, X);
          if (errorCode == 3) {
            ui->expression->setText("Division by zero");
          }
          if (!errorCode && resultIsOk(result)) {
            x.push_back(X);
            y.push_back(result);
          }
        }
        removeList(firstElement);
      } else if (errorCode == 1) {
        ui->expression->setText("Incorrect input");
      } else if (errorCode == 2) {
        ui->expression->setText("Memory error");
      }
      ui->widget->xAxis->setRange(x1, x2);
      ui->widget->yAxis->setRange(y1, y2);
      ui->widget->addGraph();
      ui->widget->graph(0)->setPen(QPen(Qt::black));
      ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
      ui->widget->graph(0)->setScatterStyle(
          QCPScatterStyle(QCPScatterStyle::ssCircle, 1));
      ui->widget->setBackground(QColor(238, 241, 255, 0));
      ui->widget->graph(0)->addData(x, y);
      ui->widget->replot();
    } else {
      ui->expression->setText("Out of range");
    }
  }
}

void GraphicWindow::on_clear_clicked() {
  ui->x1->setText("");
  ui->x2->setText("");
  ui->y1->setText("");
  ui->y2->setText("");
  ui->expression->setText("");
  ui->widget->graph(0)->data()->clear();
  ui->widget->replot();
}

void GraphicWindow::on_back_clicked() {
  this->close();
  emit MainWindow();
}
