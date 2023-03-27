/*! \mainpage CalculatorV1 Documentation
 *
 * \section Project Description
 * In this project there is implemented an extended version of the usual
 * calculator, which can be found in the standard applications of each operating
 * system in the C programming language using structured programming. In
 * addition to basic arithmetic operations such as add/subtract and
 * multiply/divide, there is supplemented the calculator with the ability to
 * calculate arithmetic expressions by following the order, as well as some
 * mathematical functions (sine, cosine, logarithm, etc.). Besides calculating
 * expressions, it also supports the use of the x variable and the graphing of
 * the corresponding function. Also there are a credit and a deposit
 * calculators.
 *
 * \section Commands
 * Run "make" or "make all" to build the calculator.\n
 * Run "make install" to install the application on your PC.\n
 * Run "make dvi" to get this documentation.\n
 * Run "make test" to run the tests.\n
 * Run "make gcov_report" to get the coverage report.
 */

/*!
\file
This file contains definitions of all C functions used in project.
*/

#ifndef CALCULTAOR_V1_0_0_CALCULATION_H
#define CALCULTAOR_V1_0_0_CALCULATION_H

#include <math.h>
#include <stdlib.h>
#include <string.h>

/**
 * Structure used for storing the final expression.
 */
typedef struct reversePolish {
  //! Tells the type of the stored value:\n
  //!    1 - number;\n
  //!    2 - operation;\n
  //!    3 - x.
  int type;
  //! Numeric value. Equals zero if a current element is an operator.
  long double num;
  //! Operator value. Equals NULL if number is stored.
  char operation[4];
  //! Placeholder for numeric value stored in functions.
  char X;
  //! Next element of the stack. Equals NULL for the last element.
  struct reversePolish *next;
} reversePolish;

/**
 * Check if there are memory errors.
 */
void toReversePolish(const char *expression, int *error,
                     reversePolish *firstElement);

/**
 * According to a current symbol decide where to put the part of the expression:
 * to the stack or to the struct.
 */
void parseExpression(const char *expression, int *error, reversePolish *head);

/**
 * Add a numeric value or X to the struct.
 */
void addNumToHead(const char *expression, int *i, int *error,
                  reversePolish *head);

/**
 * Convert "char *" type to "long double".
 */
long double toDouble(const char *str);

/**
 * Add operation to the struct.
 */
void addOperationToHead(char stack[255][255], int stackPos,
                        reversePolish *head);

/**
 * Check if "+" or "-" is an unary.
 */
int isUnary(const char *expression, int i);

/**
 * Fill stack with an operation or
 * add an operation to the struct
 * if the precedence of the element at the top of the stack is greater
 * than the current value.
 */
void fillStack(const char *expression, int *i, char stack[255][255],
               int *stackPos, int *error, reversePolish *head);

/**
 * Compare the precedence of elements.
 */
int checkPriority(char *value1, char *value2);

/**
 * Return the precedence of the element.
 */
int getPriority(char *value);

/**
 * Add operation to the temporary value to compare with operation on the top of
 * the stack.
 */
int addOperation(const char *expression, int i, char *operation, int *error);

// void addCurrentValue(char stack[255][255], int stackPos, char *current,
//                      int *error);

/**
 * Empty stack if there are no more values in the input.
 */
void emptyStack(char stack[255][255], int *stackPos, int *error,
                reversePolish *head);

/**
 * Check if the current value is a function.
 */
int isFunc(char *value);

/**
 * Empty stack until the open brace is found. Return "wrong expression error"
 * if open brace was not found.
 */
void closeBrace(int *flag, int *error, char stack[255][255], int *stackPos,
                reversePolish *head);

/**
 * Replace "-" with "~".
 */
void unary(const char *expression, int i, char stack[255][255], int *stackPos);

/**
 * Check if there are memory errors. Add numbers from the struct to the stack.
 */
void fromReversePolish(long double *result, reversePolish *firstElement,
                       int *error, long double X);

/**
 * Find out if there are one or two values needed to calculate the operation.
 */
void calculation(long double nums[255], int *numsPos, char *operation,
                 int *error);

/**
 * Calculate operations with one value needed.
 */
void calculateFunction(long double nums[255], int numsPos, char *operation,
                       int *error);

/**
 * Calculate operations with two values needed.
 */
void calculateOperation(long double nums[255], int *numsPos, char *operation,
                        int *error);

/**
 * Empty the struct.
 */
void removeList(reversePolish *head);

/**
 * Find out if result is a proper value. Needed by graphicwindow.cpp.
 */
int resultIsOk(long double result);

/**
 * Calculate annuity payments.
 */
void creditCalcAnnuity(long double amount, long double term, long double rate,
                       long double *monthlyPayment, long double *overpayment,
                       long double *totalPayment);

/**
 * Calculate differentiated payments.
 */
void creditCalcDifferentiated(long double amount, long double term,
                              long double rate,
                              long double *monthlyPaymentFirst,
                              long double *monthlyPaymentLast,
                              long double *overpayment,
                              long double *totalPayment);

/**
 * Calculate the benefit on the deposit.
 */
void debitCalc(long double amount, long double term, long double interest,
               long double tax, int periodicity, int replenishments,
               int withdrawals, int capitalization,
               long double replenishmentsSum, long double withdrawalsSum,
               long double *percent, long double *totalTax,
               long double *totalSum);

/**
 * Calculate the benefit on the deposit if replenishments or withdrawals were
 * chosen.
 */
void capitalizationCase(long double *amount, long double term,
                        long double interest, int periodicity,
                        int replenishments, int withdrawals, int capitalization,
                        long double replenishmentsSum,
                        long double withdrawalsSum, long double *percent,
                        long double *totalSum);

/**
 * Calculate the values of the benefit on the deposit.
 */
void findValues(long double *amount, long double term, long double interest,
                int periodicity, int replenishments, int withdrawals,
                int capitalization, long double replenishmentsSum,
                long double withdrawalsSum, long double *percent,
                long double *totalSum, float periodicityDays);

#endif  // CALCULATOR_V1_0_0_CALCULATION_H
