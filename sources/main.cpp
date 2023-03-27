#include <QApplication>
#include <QFile>

#include "../headers/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QFile file(":/style.css");
  file.open(QFile::ReadOnly);
  a.setStyleSheet(file.readAll());

  MainWindow w;
  w.setWindowTitle("SmartCalc");
  w.show();

  return a.exec();
}
