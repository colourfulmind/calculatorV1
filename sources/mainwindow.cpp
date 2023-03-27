#include "../headers/mainwindow.h"

#include "ui_mainwindow.h"

int openBraces = 0;
int closeBraces = 0;
int dotFlag = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  secondWindow = new GraphicWindow();
  thirdWindow = new credit();
  fourthWindow = new debit();
  connect(secondWindow, &GraphicWindow::MainWindow, this, &MainWindow::show);
  connect(thirdWindow, &credit::MainWindow, this, &MainWindow::show);
  connect(fourthWindow, &debit::MainWindow, this, &MainWindow::show);

  connect(ui->pushButton_zero, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_one, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_two, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_three, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_four, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_five, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_six, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_seven, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_eight, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_nine, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_power, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_open_brace, SIGNAL(clicked()), this,
          SLOT(insertText()));
  connect(ui->pushButton_close_brace, SIGNAL(clicked()), this,
          SLOT(insertText()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(insertText()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(insertText()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::insertText() {
  if (ui->expression->text() != "") {
    ui->result->setText("0");
    ui->expression->setText("");
  }
  QPushButton *button = (QPushButton *)sender();
  if (ui->result->text() == "0") {
    ui->result->setText("");
    if (button->text() == "mod" || button->text() == "^" ||
        button->text() == "×" || button->text() == "÷" ||
        button->text() == ")") {
      ui->result->setText("0");
    }
  }

  QString strQ = ui->result->text().right(1);
  QString closeBraceCase = "0123456789)";
  QString operatorCase = "+-×÷";
  QString funcsCase = "+-×÷(";
  QString numsCase = "0123456789";
  bool num;
  strQ.toInt(&num, 10);
  if (ui->result->text().size() < 256) {
    if (button->text() == "(") {
      if (!num && !(ui->result->text().endsWith(')')) &&
          !(ui->result->text().endsWith('.'))) {
        ui->result->setText(ui->result->text() + button->text());
        openBraces++;
      }
    } else if (button->text() == ")") {
      if (ui->result->text().endsWith('(')) {
        ui->result->setText(ui->result->text() + "0)");
        closeBraces++;
      } else {
        if (closeBraceCase.contains(strQ, Qt::CaseSensitive) &&
            (openBraces > closeBraces)) {
          ui->result->setText(ui->result->text() + ")");
          closeBraces++;
        }
      }
    } else if (button->text() == "mod" || button->text() == "^") {
      if (num || ui->result->text().endsWith(')')) {
        ui->result->setText(ui->result->text() + button->text());
      }
    } else if (operatorCase.contains(button->text().right(1),
                                     Qt::CaseSensitive)) {
      QString symbols = "+-×÷";
      if (!(ui->result->text().endsWith('(')) &&
          !(ui->result->text().endsWith('.'))) {
        if (button->text() == "+" || button->text() == "-" ||
            button->text() == "×" || button->text() == "÷" ||
            button->text() == "^") {
          if (symbols.contains(strQ, Qt::CaseSensitive)) {
            ui->result->setText(ui->result->text().remove(-1, 1));
          }
          if (ui->result->text() == "0") {
            ui->result->setText("");
          }
          if (button->text() != "-" && button->text() != "+") {
            if (ui->result->text() == "") {
              ui->result->setText("0");
            }
          }
        }
        ui->result->setText(ui->result->text() + button->text());
      } else if (ui->result->text().endsWith('(') &&
                 (button->text() == "-" || button->text() == "+")) {
        ui->result->setText(ui->result->text() + button->text());
      }
    } else if (numsCase.contains(button->text().right(1), Qt::CaseSensitive)) {
      if (!(ui->result->text().endsWith(')'))) {
        ui->result->setText(ui->result->text() + button->text());
      }
    } else if (funcsCase.contains(strQ, Qt::CaseSensitive) ||
               ui->result->text() == "") {
      if (button->text() == "cos") {
        ui->result->setText(ui->result->text() + "cos(");
      } else if (button->text() == "acos") {
        ui->result->setText(ui->result->text() + "acos(");
      } else if (button->text() == "sin") {
        ui->result->setText(ui->result->text() + "sin(");
      } else if (button->text() == "asin") {
        ui->result->setText(ui->result->text() + "asin(");
      } else if (button->text() == "tan") {
        ui->result->setText(ui->result->text() + "tan(");
      } else if (button->text() == "atan") {
        ui->result->setText(ui->result->text() + "atan(");
      } else if (button->text() == "sqrt") {
        ui->result->setText(ui->result->text() + "sqrt(");
      } else if (button->text() == "ln") {
        ui->result->setText(ui->result->text() + "ln(");
      } else if (button->text() == "log") {
        ui->result->setText(ui->result->text() + "log(");
      }
      openBraces++;
    }
  }
  strQ = ui->result->text().right(1);
  strQ.toInt(&num, 10);
  if (!num) {
    dotFlag = 1;
  }
}

void MainWindow ::on_pushButton_dot_clicked() {
  QString numsCase = "0123456789";
  if (dotFlag &&
      numsCase.contains(ui->result->text().right(1), Qt::CaseSensitive)) {
    if (ui->result->text() == "") {
      ui->result->setText(ui->result->text() + "0");
    }
    ui->result->setText(ui->result->text() + ".");
    dotFlag = 0;
  }
}

void MainWindow::on_pushButton_all_clear_clicked() {
  ui->result->setText("0");
  ui->expression->setText("");
  openBraces = 0;
  closeBraces = 0;
  dotFlag = 1;
}

void MainWindow::on_pushButton_clear_entry_clicked() {
  int symbol = 1;
  int position = -1;
  if (ui->result->text().endsWith("mod") ||
      ui->result->text().endsWith("ln(")) {
    symbol = 3;
    position = -3;
  } else if (ui->result->text().endsWith("acos(") ||
             ui->result->text().endsWith("asin(") ||
             ui->result->text().endsWith("atan(") ||
             ui->result->text().endsWith("sqrt(")) {
    symbol = 5;
    position = -5;
  } else if (ui->result->text().endsWith("cos(") ||
             ui->result->text().endsWith("sin(") ||
             ui->result->text().endsWith("tan(") ||
             ui->result->text().endsWith("log(")) {
    symbol = 4;
    position = -4;

  } else if (ui->result->text().endsWith("(")) {
    openBraces--;
  } else if (ui->result->text().endsWith(")")) {
    closeBraces--;
  } else if (ui->result->text().endsWith(".")) {
    dotFlag = 1;
  }
  if (ui->result->text() != "0") {
    ui->result->setText(ui->result->text().remove(position, symbol));
  }
  if (ui->result->text() == "") {
    ui->result->setText("0");
  }
}

void MainWindow::on_pushButton_equal_clicked() {
  QString numbers = "0123456789";
  if ((openBraces > closeBraces) &&
      numbers.contains(ui->result->text().right(1), Qt::CaseSensitive)) {
    while ((openBraces - closeBraces) != 0) {
      ui->result->setText(ui->result->text() + ")");
      closeBraces++;
    }
  }
  openBraces = 0;
  closeBraces = 0;
  dotFlag = 1;
  ui->expression->setText(ui->result->text() + "=");
  QString str = ui->result->text();
  str.replace(QString("×"), QString("*"));
  str.replace(QString("÷"), QString("/"));
  std::string stringText = str.toStdString();
  const char *text = stringText.c_str();
  int code = 0;
  long double res = 0.0;
  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(text, &code, firstElement);
  if (!code) {
    fromReversePolish(&res, firstElement, &code, 0);
  }
  if (code == 0) {
    ui->result->setText(QString::number(res, 'g', 15));
  } else if (code == 1) {
    ui->result->setText("Incorrect input");
  } else if (code == 2) {
    ui->result->setText("Memory error");
  } else if (code == 3) {
    ui->result->setText("Division by zero");
  } else if (code == 4) {
    ui->result->setText("Square root of a negative number");
  }
  removeList(firstElement);
}

void MainWindow::on_comboBox_textActivated(const QString &arg1) {
  if (arg1 == "Graphics") {
    this->close();
    secondWindow->show();
    secondWindow->setWindowTitle("Graphics");
  } else if (arg1 == "Credit Calc") {
    this->close();
    thirdWindow->show();
    thirdWindow->setWindowTitle("Credit Calc");
  } else if (arg1 == "Debit Calc") {
    this->close();
    fourthWindow->show();
    fourthWindow->setWindowTitle("Debit Calc");
  }
}
