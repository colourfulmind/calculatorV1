#include "../headers/calculation.h"

void creditCalcAnnuity(long double amount, long double term, long double rate,
                       long double *monthlyPayment, long double *overpayment,
                       long double *totalPayment) {
  long double K = rate / 1200;
  *monthlyPayment = (int)(amount * ((K) / (1 - pow((1 + K), -term))));
  *totalPayment = *monthlyPayment * term;
  *overpayment = *totalPayment - amount;
}

void creditCalcDifferentiated(long double amount, long double term,
                              long double rate,
                              long double *monthlyPaymentFirst,
                              long double *monthlyPaymentLast,
                              long double *overpayment,
                              long double *totalPayment) {
  double months = 30.42, tmp = term;
  double payment = amount / term;
  double percent = (amount * (rate / 100) * months) / 365;
  *monthlyPaymentFirst = (int)(payment + percent);
  while (tmp != 1) {
    *totalPayment += payment + percent;
    tmp -= 1;
    amount -= payment;
    percent = (amount * (rate / 100) * months) / 365;
  }
  *monthlyPaymentLast = (int)(payment + percent);
  *totalPayment = (int)*totalPayment + *monthlyPaymentLast;
  *overpayment = (int)(*totalPayment - (amount * term));
}

void debitCalc(long double amount, long double term, long double interest,
               long double tax, int periodicity, int replenishments,
               int withdrawals, int capitalization,
               long double replenishmentsSum, long double withdrawalsSum,
               long double *percent, long double *totalTax,
               long double *totalSum) {
  float taxRate = (tax / 100) * 1000000;
  term = round(term * 30.4);
  if (!replenishments && !withdrawals && !periodicity && !capitalization) {
    *percent = (amount * interest * term / 365) / 100;
    *totalSum = *percent + amount;
  } else {
    capitalizationCase(&amount, term, interest, periodicity, replenishments,
                       withdrawals, capitalization, replenishmentsSum,
                       withdrawalsSum, percent, totalSum);
  }
  *totalSum = (int)*totalSum;
  if (capitalization && periodicity) {
    *percent = (int)(*totalSum - amount);
  } else {
    *percent = (int)*percent;
    *totalSum += *percent;
  }
  if ((*percent > taxRate)) {
    *totalTax = (int)((*percent - taxRate) * 0.13);
  }
}

void capitalizationCase(long double *amount, long double term,
                        long double interest, int periodicity,
                        int replenishments, int withdrawals, int capitalization,
                        long double replenishmentsSum,
                        long double withdrawalsSum, long double *percent,
                        long double *totalSum) {
  float periodicityDays = 0;
  if (periodicity == 1) {
    periodicityDays = 30.4;
  } else if (periodicity == 3) {
    periodicityDays = 91;
  } else if (periodicity == 12) {
    periodicityDays = 365;
  } else {
    periodicityDays = term;
  }
  *totalSum = *amount;
  if (!replenishments) {
    replenishmentsSum = 0.0;
  }
  if (!withdrawals) {
    withdrawalsSum = 0.0;
  }
  findValues(amount, term, interest, periodicity, replenishments, withdrawals,
             capitalization, replenishmentsSum, withdrawalsSum, percent,
             totalSum, periodicityDays);
}

void findValues(long double *amount, long double term, long double interest,
                int periodicity, int replenishments, int withdrawals,
                int capitalization, long double replenishmentsSum,
                long double withdrawalsSum, long double *percent,
                long double *totalSum, float periodicityDays) {
  int i = 1;
  while (term > 0) {
    if (capitalization && fmod(i, periodicity) == 0) {
      *percent = (*totalSum * interest * periodicityDays / 365) / 100;
      *totalSum += *percent;
    } else {
      *percent += (*totalSum * interest * periodicityDays / 365) / 100 / 12;
    }
    term = (int)(term - 30.4);
    if (fmod(i, replenishments) == 0) {
      *totalSum += replenishmentsSum;
      *amount += replenishmentsSum;
    }
    if (fmod(i, withdrawals) == 0) {
      *totalSum -= withdrawalsSum;
      *amount -= withdrawalsSum;
    }
    i++;
  }
}
