#include <check.h>

#include "../headers/calculation.h"

//    0 - ok
//    1 - wrong expression
//    2 - memory error
//    3 - incorrect operation

START_TEST(cosTest1) {
  const char *expression = "cos(6*3)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - cos((6 * 3)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(cosTest2) {
  const char *expression = "cos(0.4952035745)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (cos(0.4952035745)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(cosTest3) {
  const char *expression = "cos(-0.286350935mod3)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (cos(fmod(-0.286350935, 3))), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(sinTest1) {
  const char *expression = "sin(42*21^2)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (sin(42 * pow(21, 2))), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(sinTest2) {
  const char *expression = "sin(-0.286350935mod3)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (sin(fmod(-0.286350935, 3))), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(sinTest3) {
  const char *expression = "sin(0.4952035745)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (sin(0.4952035745)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(tanTest1) {
  const char *expression = "tan(42*21^2)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (tan(42 * pow(21, 2))), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(tanTest2) {
  const char *expression = "tan(-0.286350935mod3)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (tan(fmod(-0.286350935, 3))), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(tanTest3) {
  const char *expression = "tan(0.4952035745)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (tan(0.4952035745)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(acosTest1) {
  const char *expression = "acos(11-21/2)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  //    printf("%f\n", acos(11-21/2));
  //    printf("%Lf\n", result);
  ck_assert_int_eq(result - (acos(0.5)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(acosTest2) {
  const char *expression = "acos(-0.286350935^3)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (acos(pow(-0.286350935, 3))), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(acosTest3) {
  const char *expression = "acos(0.4952035745)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (acos(0.4952035745)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(asinTest1) {
  const char *expression = "asin(0.42*0.21)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (asin(0.42 * 0.21)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(asinTest2) {
  const char *expression = "asin(-0.286350935mod3)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (asin(fmod(-0.286350935, 3))), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(asinTest3) {
  const char *expression = "asin(0.4952035745)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (asin(0.4952035745)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(atanTest1) {
  const char *expression = "atan(42*21^2)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (atan(42 * pow(21, 2))), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(atanTest2) {
  const char *expression = "atan(-0.286350935mod3)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (atan(fmod(-0.286350935, 3))), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(atanTest3) {
  const char *expression = "atan(0.4952035745)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (atan(0.4952035745)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(sqrtTest1) {
  const char *expression = "sqrt(42*21^2)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (sqrt(42 * pow(21, 2))), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(sqrtTest2) {
  const char *expression = "sqrt(0.286350935mod3)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (sqrt(fmod(0.286350935, 3))), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(sqrtTest3) {
  const char *expression = "sqrt(0.4952035745)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (sqrt(0.4952035745)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(lnTest1) {
  const char *expression = "ln(42*21^2)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (log(42 * pow(21, 2))), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(lnTest2) {
  const char *expression = "ln(0.286350935mod3)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (log(fmod(0.286350935, 3))), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(lnTest3) {
  const char *expression = "ln(0.4952035745)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (log(0.4952035745)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(logTest1) {
  const char *expression = "log(42*21^2)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (log10(42 * pow(21, 2))), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(logTest2) {
  const char *expression = "log(0.286350935mod3)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (log10(fmod(0.286350935, 3))), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(logTest3) {
  const char *expression = "log(0.4952035745)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (log10(0.4952035745)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(modTest1) {
  const char *expression = "42mod21^2";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (fmod(42, pow(21, 2))), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(modTest2) {
  const char *expression = "-0.286350935mod3";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (fmod(-0.286350935, 3)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(modTest3) {
  const char *expression = "4952035745mod0.49";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (fmod(4952035745, 0.49)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(plusTest1) {
  const char *expression = "42+21^2";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (42 + pow(21, 2)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(plusTest2) {
  const char *expression = "-0.286350935+3";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (-0.286350935 + 3), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(plusTest3) {
  const char *expression = "4952035745+0.49";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (4952035745 + 0.49), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(minusTest1) {
  const char *expression = "42-21^2";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (42 - pow(21, 2)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(minusTest2) {
  const char *expression = "-0.286350935-3";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (-0.286350935 - 3), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(minusTest3) {
  const char *expression = "4952035745-0.49";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (4952035745 - 0.49), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(multTest1) {
  const char *expression = "42*21^2";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (42 * pow(21, 2)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(multTest2) {
  const char *expression = "-0.286350935*3";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (-0.286350935 * 3), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(multTest3) {
  const char *expression = "4952035745*0.49";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (4952035745 * 0.49), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(divTest1) {
  const char *expression = "42/21^2";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (2 / pow(21, 2)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(divTest2) {
  const char *expression = "-0.286350935/3";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (-0.286350935 / 3), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(divTest3) {
  const char *expression = "4952035745/0.49";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (4952035745 / 0.49), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(powTest1) {
  const char *expression = "21^2";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (pow(21, 2)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(powTest2) {
  const char *expression = "-0.286350935^3";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (pow(-0.286350935, 3)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(powTest3) {
  const char *expression = "4952035745^0.49";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (pow(4952035745, 0.49)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(unaryTest1) {
  const char *expression = "(-42)-21^2";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - ((-42) - pow(21, 2)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(unaryTest2) {
  const char *expression = "-(0.286350935-3)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (-(0.286350935 - 3)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(unaryTest3) {
  const char *expression = "4952035745-(-0.49)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_int_eq(result - (4952035745 - (-0.49)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(expression1) {
  const char *expression = "-(3.0-sin(2*log(5)+2))mod2";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_uint_eq(-1.25354896534 - result, 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(expression2) {
  const char *expression = "tan(-2)^2/cos(5.876*(-12))mod3.4+(+2)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_uint_eq(
      pow(tan(-2), 2) / fmod(cos(5.876 * (-12)), 3.4) + (+2) - result, 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(wrongCase1) {
  const char *expression = "tan(-2)^2/cs(5.876*(-12))mod3.4+(+2)";
  int errorCode = 0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);

  ck_assert_uint_eq(errorCode, 1);

  removeList(firstElement);
}

END_TEST

START_TEST(wrongCase2) {
  const char *expression = "tan(-2)^2/cos(.876*(-12))mod3.4+(+2)";
  int errorCode = 0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);

  ck_assert_uint_eq(errorCode, 1);

  removeList(firstElement);
}

END_TEST

START_TEST(wrongCase3) {
  const char *expression = "(tan(-2)^2/cos(0.876*(-12))mod3.4+(+2)";
  int errorCode = 0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);

  ck_assert_uint_eq(errorCode, 1);

  removeList(firstElement);
}

END_TEST

START_TEST(wrongCase4) {
  const char *expression = "3.4+2)";
  int errorCode = 0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);

  ck_assert_uint_eq(errorCode, 1);

  removeList(firstElement);
}

END_TEST

START_TEST(wrongCase5) {
  const char *expression = "*5";
  int errorCode = 0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);

  ck_assert_uint_eq(errorCode, 1);

  removeList(firstElement);
}

END_TEST

START_TEST(wrongCase6) {
  const char *expression = "1.+5";
  int errorCode = 0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);

  ck_assert_uint_eq(errorCode, 1);

  removeList(firstElement);
}

END_TEST

START_TEST(wrongCase7) {
  const char *expression = "1+.5";
  int errorCode = 0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);

  ck_assert_uint_eq(errorCode, 1);

  removeList(firstElement);
}

END_TEST

START_TEST(wrongCase8) {
  const char *expression = "1/0";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_uint_eq(errorCode, 3);

  removeList(firstElement);
}

END_TEST

START_TEST(wrongCase9) {
  const char *expression = "sqrt(-7)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_uint_eq(errorCode, 4);

  removeList(firstElement);
}

END_TEST

START_TEST(wrongCase10) {
  const char *expression = "sqrt(-7)";
  int errorCode = 0;

  toReversePolish(expression, &errorCode, 0);
  ck_assert_uint_eq(errorCode, 2);
}

END_TEST

START_TEST(wrongCase11) {
  int errorCode = 0;
  long double result = 0.0;

  fromReversePolish(&result, 0, &errorCode, 0);
  ck_assert_uint_eq(errorCode, 2);
}

END_TEST

START_TEST(parseX1) {
  const char *expression = "3.0-sin(x*log(5)+2)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_uint_eq(result - (3.0 - sin(1 * log10(5) + 2)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(parseX2) {
  const char *expression = "3.0-sin(X*log(5)+2)";
  int errorCode = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);
  if (!errorCode) {
    fromReversePolish(&result, firstElement, &errorCode, 0);
  }

  ck_assert_uint_eq(result - (3.0 - sin(1 * log10(5) + 2)), 0);
  ck_assert_uint_eq(errorCode, 0);

  removeList(firstElement);
}

END_TEST

START_TEST(resultIsOkTest) {
  const char *expression = "3.0-sqrt(X)";
  int errorCode = 0;
  int status = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);

  if (!errorCode) {
    for (double X = 0; X <= 20; X += 0.1) {
      fromReversePolish(&result, firstElement, &errorCode, X);
      if (!errorCode) {
        status = resultIsOk(result);
      }
    }
  }
  ck_assert_int_eq(status, 1);
  removeList(firstElement);
}

END_TEST

START_TEST(resultIsNotOkTest) {
  const char *expression = "3.0-sqrt(-X)";
  int errorCode = 0;
  int status = 0;
  long double result = 0.0;

  reversePolish *firstElement =
      (reversePolish *)calloc(1, sizeof(reversePolish));
  toReversePolish(expression, &errorCode, firstElement);

  if (!errorCode) {
    for (double X = 0; X <= 20; X += 0.1) {
      fromReversePolish(&result, firstElement, &errorCode, X);
      status = resultIsOk(result);
    }
  }
  ck_assert_int_eq(status, 1);
  removeList(firstElement);
}

END_TEST

START_TEST(creditCalcAnnuityTest) {
  long double monthlyPayment = 0.0, overpayment = 0.0, totalPayment = 0.0;
  creditCalcAnnuity(20000, 36, 12, &monthlyPayment, &overpayment,
                    &totalPayment);
  ck_assert_uint_eq(monthlyPayment - 664, 0);
  ck_assert_uint_eq(overpayment - 3904, 0);
  ck_assert_uint_eq(totalPayment - 23904, 0);
}

END_TEST

START_TEST(creditCalcDifferentiatedTest) {
  long double monthlyPaymentFirst = 0.0, monthlyPaymentLast = 0.0,
              overpayment = 0.0, totalPayment = 0.0;
  creditCalcDifferentiated(300000, 36, 7.9, &monthlyPaymentFirst,
                           &monthlyPaymentLast, &overpayment, &totalPayment);
  ck_assert_uint_eq(monthlyPaymentFirst - 10308, 0);
  ck_assert_uint_eq(monthlyPaymentLast - 8388, 0);
  ck_assert_uint_eq(overpayment - 36541, 0);
  ck_assert_uint_eq(totalPayment - 336541, 0);
}

END_TEST

START_TEST(debitCalcTest1) {
  long double percent = 0.0, totalTax = 0.0, totalSum = 0.0;
  debitCalc(800000, 12, 10, 7.5, 0, 1, 3, 1, 10000, 5000, &percent, &totalTax,
            &totalSum);
  ck_assert_uint_eq(percent - 84750, 0);
  ck_assert_uint_eq(totalTax - 1267, 0);
  ck_assert_uint_eq(totalSum - 984750, 0);
}

END_TEST

START_TEST(debitCalcTest2) {
  long double percent = 0.0, totalTax = 0.0, totalSum = 0.0;
  debitCalc(800000, 12, 10, 7.5, 0, 0, 0, 0, 0, 0, &percent, &totalTax,
            &totalSum);
  ck_assert_uint_eq(percent - 80000, 0);
  ck_assert_uint_eq(totalTax - 650, 0);
  ck_assert_uint_eq(totalSum - 960000, 0);
}

END_TEST

START_TEST(debitCalcTest3) {
  long double percent = 0.0, totalTax = 0.0, totalSum = 0.0;
  debitCalc(800000, 12, 10, 7.5, 1, 0, 0, 1, 0, 0, &percent, &totalTax,
            &totalSum);
  ck_assert_uint_eq(percent - 83722, 0);
  ck_assert_uint_eq(totalTax - 1133, 0);
  ck_assert_uint_eq(totalSum - 883722, 0);
}

END_TEST

START_TEST(debitCalcTest4) {
  long double percent = 0.0, totalTax = 0.0, totalSum = 0.0;
  debitCalc(800000, 12, 10, 7.5, 3, 0, 0, 1, 0, 0, &percent, &totalTax,
            &totalSum);
  ck_assert_uint_eq(percent - 82814, 0);
  ck_assert_uint_eq(totalTax - 1015, 0);
  ck_assert_uint_eq(totalSum - 882814, 0);
}

END_TEST

START_TEST(debitCalcTest5) {
  long double percent = 0.0, totalTax = 0.0, totalSum = 0.0;
  debitCalc(800000, 12, 10, 7.5, 12, 0, 0, 1, 0, 0, &percent, &totalTax,
            &totalSum);
  ck_assert_uint_eq(percent - 80000, 0);
  ck_assert_uint_eq(totalTax - 650, 0);
  ck_assert_uint_eq(totalSum - 880000, 0);
}

END_TEST

Suite *

smartCalc_suite(void) {
  Suite *suite;

  suite = suite_create("SmartCalc");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, cosTest1);
  tcase_add_test(tcase_core, cosTest2);
  tcase_add_test(tcase_core, cosTest3);

  tcase_add_test(tcase_core, sinTest1);
  tcase_add_test(tcase_core, sinTest2);
  tcase_add_test(tcase_core, sinTest3);

  tcase_add_test(tcase_core, tanTest1);
  tcase_add_test(tcase_core, tanTest2);
  tcase_add_test(tcase_core, tanTest3);

  tcase_add_test(tcase_core, acosTest1);
  tcase_add_test(tcase_core, acosTest2);
  tcase_add_test(tcase_core, acosTest3);

  tcase_add_test(tcase_core, asinTest1);
  tcase_add_test(tcase_core, asinTest2);
  tcase_add_test(tcase_core, asinTest3);

  tcase_add_test(tcase_core, atanTest1);
  tcase_add_test(tcase_core, atanTest2);
  tcase_add_test(tcase_core, atanTest3);

  tcase_add_test(tcase_core, sqrtTest1);
  tcase_add_test(tcase_core, sqrtTest2);
  tcase_add_test(tcase_core, sqrtTest3);

  tcase_add_test(tcase_core, lnTest1);
  tcase_add_test(tcase_core, lnTest2);
  tcase_add_test(tcase_core, lnTest3);

  tcase_add_test(tcase_core, logTest1);
  tcase_add_test(tcase_core, logTest2);
  tcase_add_test(tcase_core, logTest3);

  tcase_add_test(tcase_core, modTest1);
  tcase_add_test(tcase_core, modTest2);
  tcase_add_test(tcase_core, modTest3);

  tcase_add_test(tcase_core, plusTest1);
  tcase_add_test(tcase_core, plusTest2);
  tcase_add_test(tcase_core, plusTest3);

  tcase_add_test(tcase_core, minusTest1);
  tcase_add_test(tcase_core, minusTest2);
  tcase_add_test(tcase_core, minusTest3);

  tcase_add_test(tcase_core, multTest1);
  tcase_add_test(tcase_core, multTest2);
  tcase_add_test(tcase_core, multTest3);

  tcase_add_test(tcase_core, divTest1);
  tcase_add_test(tcase_core, divTest2);
  tcase_add_test(tcase_core, divTest3);

  tcase_add_test(tcase_core, powTest1);
  tcase_add_test(tcase_core, powTest2);
  tcase_add_test(tcase_core, powTest3);

  tcase_add_test(tcase_core, unaryTest1);
  tcase_add_test(tcase_core, unaryTest2);
  tcase_add_test(tcase_core, unaryTest3);

  tcase_add_test(tcase_core, expression1);
  tcase_add_test(tcase_core, expression2);

  tcase_add_test(tcase_core, wrongCase1);
  tcase_add_test(tcase_core, wrongCase2);
  tcase_add_test(tcase_core, wrongCase3);
  tcase_add_test(tcase_core, wrongCase4);
  tcase_add_test(tcase_core, wrongCase5);
  tcase_add_test(tcase_core, wrongCase6);
  tcase_add_test(tcase_core, wrongCase7);
  tcase_add_test(tcase_core, wrongCase8);
  tcase_add_test(tcase_core, wrongCase9);
  tcase_add_test(tcase_core, wrongCase10);
  tcase_add_test(tcase_core, wrongCase11);

  tcase_add_test(tcase_core, parseX1);
  tcase_add_test(tcase_core, parseX2);

  tcase_add_test(tcase_core, resultIsOkTest);
  tcase_add_test(tcase_core, resultIsNotOkTest);

  tcase_add_test(tcase_core, creditCalcAnnuityTest);
  tcase_add_test(tcase_core, creditCalcDifferentiatedTest);
  tcase_add_test(tcase_core, debitCalcTest1);
  tcase_add_test(tcase_core, debitCalcTest2);
  tcase_add_test(tcase_core, debitCalcTest3);
  tcase_add_test(tcase_core, debitCalcTest4);
  tcase_add_test(tcase_core, debitCalcTest5);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  Suite *suite = smartCalc_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
