#include "../headers/credit.h"

#include "ui_credit.h"

credit::credit(QWidget *parent) : QDialog(parent), ui(new Ui::credit) {
  ui->setupUi(this);
}

credit::~credit() { delete ui; }

void credit::on_back_clicked() {
  this->close();
  emit MainWindow();
}

void credit::on_calculate_clicked() {
  bool creditAmount, creditTerm, creditInterest;
  (ui->creditAmount->text()).toDouble(&creditAmount);
  (ui->term->text()).toInt(&creditTerm, 10);
  (ui->interest->text()).toDouble(&creditInterest);
  QString type = ui->type->currentText();

  if (creditAmount && creditTerm && creditInterest) {
    long double amount = (ui->creditAmount->text()).toDouble();
    long double term = (ui->term->text()).toDouble();
    long double rate = (ui->interest->text()).toDouble();
    long double monthlyPayment = 0.0, overpayment = 0.0, totalPayment = 0.0;
    if (type == "Annuity") {
      creditCalcAnnuity(amount, term, rate, &monthlyPayment, &overpayment,
                        &totalPayment);
      ui->monthlyPayment->setText(QString::number(monthlyPayment, 'g', 15));
    } else if (type == "Differentiated") {
      long double monthlyPaymentLast = 0.0;
      creditCalcDifferentiated(amount, term, rate, &monthlyPayment,
                               &monthlyPaymentLast, &overpayment,
                               &totalPayment);
      ui->monthlyPayment->setText(QString::number(monthlyPayment, 'g', 15) +
                                  "->" +
                                  QString::number(monthlyPaymentLast, 'g', 15));
    }
    ui->overpayment->setText(QString::number(overpayment, 'g', 15));
    ui->totalPayment->setText(QString::number(totalPayment, 'g', 15));
  } else {
    ui->label->setText("Incorrect Input");
  }
}

void credit::on_clear_clicked() {
  ui->monthlyPayment->setText("0.0");
  ui->overpayment->setText("0.0");
  ui->totalPayment->setText("0.0");
  ui->creditAmount->setText("");
  ui->term->setText("");
  ui->interest->setText("");
  ui->label->setText("");
}
