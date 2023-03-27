#include "../headers/debit.h"

#include "ui_debit.h"

debit::debit(QWidget *parent) : QDialog(parent), ui(new Ui::debit) {
  ui->setupUi(this);
}

debit::~debit() { delete ui; }

void debit::on_back_clicked() {
  this->close();
  emit MainWindow();
}

void debit::on_calculate_clicked() {
  bool creditAmount, creditTerm, creditInterest, creditTaxRate,
      creditReplenishmentSum, creditWithdrawalsSum;
  (ui->creditAmount->text()).toDouble(&creditAmount);
  (ui->term->text()).toInt(&creditTerm, 10);
  (ui->interest->text()).toDouble(&creditInterest);
  (ui->taxRate->text()).toDouble(&creditTaxRate);
  (ui->replenishmentSum->text()).toDouble(&creditReplenishmentSum);
  (ui->withdrawalsSum->text()).toDouble(&creditWithdrawalsSum);

  if (creditAmount && creditTerm && creditInterest && creditTaxRate &&
      creditReplenishmentSum && creditWithdrawalsSum) {
    long double amount = (ui->creditAmount->text()).toDouble();
    long double term = (ui->term->text()).toDouble();
    long double interest = (ui->interest->text()).toDouble();
    long double tax = (ui->taxRate->text()).toDouble();
    long double replenishmentSum = (ui->replenishmentSum->text()).toDouble();
    long double withdrawalsSum = (ui->withdrawalsSum->text()).toDouble();
    QString periodicityString = ui->periodicity->currentText();
    int periodicity = 0;
    QString replenishmentsString = ui->replenishmentsList->currentText();
    int replenishments = 0;
    QString withdrawalsString = ui->partialWithdrawals->currentText();
    int withdrawals = 0;
    int capitalization = ui->capitalization->isChecked();
    long double percent = 0.0;
    long double totalTax = 0.0;
    long double totalSum = 0.0;

    if (periodicityString == "once a month") {
      periodicity = 1;
    } else if (periodicityString == "once a quarter") {
      periodicity = 3;
    } else if (periodicityString == "once a year") {
      periodicity = 12;
    }

    if (replenishmentsString == "once a month") {
      replenishments = 1;
    } else if (replenishmentsString == "once a quarter") {
      replenishments = 3;
    } else if (replenishmentsString == "once a year") {
      replenishments = 12;
    }

    if (withdrawalsString == "once a month") {
      withdrawals = 1;
    } else if (withdrawalsString == "once a quarter") {
      withdrawals = 3;
    } else if (withdrawalsString == "once a year") {
      withdrawals = 12;
    }

    debitCalc(amount, term, interest, tax, periodicity, replenishments,
              withdrawals, capitalization, replenishmentSum, withdrawalsSum,
              &percent, &totalTax, &totalSum);

    ui->accruedInterest->setText(QString::number(percent, 'g', 15));
    ui->taxAmount->setText(QString::number(totalTax, 'g', 15));
    ui->depositAmount->setText(QString::number(totalSum, 'g', 15));
  } else {
    ui->label->setText("Incorrect Input");
  }
}

void debit::on_clear_clicked() {
  ui->accruedInterest->setText("0.0");
  ui->taxAmount->setText("0.0");
  ui->depositAmount->setText("0.0");
  ui->creditAmount->setText("");
  ui->term->setText("");
  ui->interest->setText("");
  ui->taxRate->setText("");
  ui->label->setText("");
}
