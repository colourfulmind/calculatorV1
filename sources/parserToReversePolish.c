#include "../headers/calculation.h"

void toReversePolish(const char *expression, int *error,
                     reversePolish *firstElement) {
  if (!firstElement) {
    *error = 2;
  }
  if (!*error) {
    reversePolish *head = firstElement;
    parseExpression(expression, error, head);
  }
}

void parseExpression(const char *expression, int *error, reversePolish *head) {
  char stack[255][255];
  int len = (int)strlen(expression), stackPos = -1;
  if (len > 0 && strchr("*/^m", expression[0])) {
    *error = 1;
  }
  for (int i = 0; i < len; ++i) {
    if ((expression[i] > 47 && expression[i] < 58) || expression[i] == 'x' ||
        expression[i] == 'X') {
      addNumToHead(expression, &i, error, head);
      head = head->next;
    } else if (expression[i] == '.') {
      *error = 1;
    } else {
      int flag = 0;
      if (expression[i] == ')') {
        closeBrace(&flag, error, stack, &stackPos, head);
      } else {
        if (isUnary(expression, i)) {
          unary(expression, i, stack, &stackPos);
        } else if (stackPos == -1 || expression[i] == '(') {
          stackPos++;
          i = addOperation(expression, i, stack[stackPos], error);
        } else {
          fillStack(expression, &i, stack, &stackPos, error, head);
        }
      }
      while (head->type) {
        head = head->next;
      }
      if (flag && stackPos >= 0) {
        if (strstr("acosasinatansqrtlnlog", stack[stackPos])) {
          addOperationToHead(stack, stackPos, head);
          head = head->next;
          stackPos--;
        }
      }
    }
    if (!head) {
      *error = 2;
    }
  }
  if (stackPos >= 0) {
    emptyStack(stack, &stackPos, error, head);
  }
}

void addNumToHead(const char *expression, int *i, int *error,
                  reversePolish *head) {
  if (expression[*i] > 47 && expression[*i] < 58) {
    char *tmp = (char *)calloc(1, sizeof(char));
    int k = 0;
    while ((expression[*i] > 47 && expression[*i] < 58) ||
           expression[*i] == '.') {
      tmp[k++] = expression[*i];
      *i += 1;
      tmp = (char *)realloc(tmp, sizeof(char) * (k + 1));
    }
    tmp[k] = '\0';
    if (tmp[strlen(tmp) - 1] == '.') {
      *error = 1;
    } else {
      *i -= 1;
      head->type = 1;
      head->num = toDouble(tmp);
    }
    free(tmp);
  } else {
    head->type = 3;
    head->X = expression[*i];
  }
  head->next = (reversePolish *)calloc(1, sizeof(reversePolish));
}

long double toDouble(const char *str) {
  int i = 0;
  long double res = 0.0;
  while ('0' <= str[i] && str[i] <= '9') {
    res = res * 10 + ((int)str[i] - '0');
    i++;
  }
  int precision = 0;
  if (str[i] == '.') {
    i++;
    while ('0' <= str[i] && str[i] <= '9') {
      res = res * 10 + ((int)str[i] - '0');
      i++;
      precision++;
    }
  }
  res /= pow(10, precision);
  return res;
}

void addOperationToHead(char stack[255][255], int stackPos,
                        reversePolish *head) {
  head->type = 2;
  int k = 0;
  while (stack[stackPos][k]) {
    head->operation[k] = stack[stackPos][k];
    k++;
  }
  head->next = (reversePolish *)calloc(1, sizeof(reversePolish));
}

int isUnary(const char *expression, int i) {
  int res = 0;
  if ((i == 0) && (expression[i] == '-' || expression[i] == '+')) {
    res = 1;
  } else if ((expression[i - 1] == '(') &&
             (expression[i] == '-' || expression[i] == '+')) {
    res = 1;
  }
  return res;
}

void fillStack(const char *expression, int *i, char stack[255][255],
               int *stackPos, int *error, reversePolish *head) {
  char *tmp = (char *)calloc(1, sizeof(char) * 255);
  char *current = stack[*stackPos];
  *i = addOperation(expression, *i, tmp, error);
  while (checkPriority(current, tmp)) {
    addOperationToHead(stack, *stackPos, head);
    *stackPos -= 1;
    if (*stackPos == -1) {
      break;
    }
    current = stack[*stackPos];
    head = head->next;
  }
  int k = 0, j = 0;
  *stackPos += 1;
  while (tmp[k]) {
    stack[*stackPos][j++] = tmp[k++];
  }
  stack[*stackPos][j] = '\0';
  free(tmp);
}

int checkPriority(char *value1, char *value2) {
  int result = getPriority(value1) > getPriority(value2);
  if ((getPriority(value1) == getPriority(value2)) &&
      getPriority(value1) == 3) {
    result = 1;
  }
  return result;
}

int getPriority(char *value) {
  int priority = 0;
  if (value[0] == '-' || value[0] == '+') {
    priority = 1;
  } else if (value[0] == '*' || value[0] == '/' || !strcmp("mod", value)) {
    priority = 2;
  } else if (isFunc(value)) {
    priority = 3;
  } else if (value[0] == '^' || value[0] == '~') {
    priority = 3;
  }
  return priority;
}

int addOperation(const char *expression, int i, char *operation, int *error) {
  int j = 0;
  if (strchr("(*/+-^~", expression[i])) {
    operation[j++] = expression[i++];
  } else {
    while (strchr("acdgilmnoqrst", expression[i])) {
      operation[j++] = expression[i++];
    }
  }
  operation[j] = '\0';
  if (!strstr("acosasinatansqrtlnlogmod(*/+-^~", operation)) {
    *error = 1;
  }
  return i - 1;
}

void emptyStack(char stack[255][255], int *stackPos, int *error,
                reversePolish *head) {
  while (*stackPos >= 0 && !*error) {
    if (stack[*stackPos][0] != '(') {
      addOperationToHead(stack, *stackPos, head);
      *stackPos -= 1;
      head = head->next;
    } else {
      *error = 1;
      break;
    }
  }
}

int isFunc(char *value) {
  int result = 0;
  if (!strcmp("cos", value) || !strcmp("sin", value) || !strcmp("tan", value) ||
      !strcmp("acos", value) || !strcmp("asin", value) ||
      !strcmp("atan", value) || !strcmp("ln", value) || !strcmp("log", value) ||
      !strcmp("sqrt", value)) {
    result = 1;
  }
  return result;
}

void closeBrace(int *flag, int *error, char stack[255][255], int *stackPos,
                reversePolish *head) {
  *flag = 1;
  while (stack[*stackPos][0] != '(') {
    addOperationToHead(stack, *stackPos, head);
    head = head->next;
    *stackPos -= 1;
    if (*stackPos == -1) {
      *error = 1;
      break;
    }
  }
  if (stack[*stackPos][0] != '(') {
    *error = 1;
    *flag = 0;
  }
  if (!*error) {
    *stackPos -= 1;
  }
}

void unary(const char *expression, int i, char stack[255][255], int *stackPos) {
  if (expression[i] == '-') {
    *stackPos += 1;
    stack[*stackPos][0] = '~';
    stack[*stackPos][1] = '\0';
  }
}
