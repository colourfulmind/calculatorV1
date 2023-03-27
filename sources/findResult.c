#include "../headers/calculation.h"

void fromReversePolish(long double *result, reversePolish *firstElement,
                       int *error, long double X) {
  long double nums[255] = {0};
  if (!firstElement) {
    *error = 2;
  }
  int numsPos = 0;
  if (!*error) {
    reversePolish *head = firstElement;
    while (head) {
      if (head->type == 1) {
        nums[numsPos] = head->num;
        numsPos++;
      } else if (head->type == 3) {
        nums[numsPos] = X;
        numsPos++;
      } else if (head->type == 2) {
        calculation(nums, &numsPos, head->operation, error);
      }
      if (*error) {
        break;
      }
      head = head->next;
    }
    *result = nums[0];
  }
}

void calculation(long double nums[255], int *numsPos, char *operation,
                 int *error) {
  if (strstr("acosasinatansqrtlnlog~", operation)) {
    calculateFunction(nums, *numsPos, operation, error);
  } else if (strstr("mod*/+-^~", operation)) {
    calculateOperation(nums, numsPos, operation, error);
  }
}

void calculateFunction(long double nums[255], int numsPos, char *operation,
                       int *error) {
  if (!strcmp(operation, "cos")) {
    nums[numsPos - 1] = cos(nums[numsPos - 1]);
  } else if (!strcmp(operation, "sin")) {
    nums[numsPos - 1] = sin(nums[numsPos - 1]);
  } else if (!strcmp(operation, "tan")) {
    nums[numsPos - 1] = tan(nums[numsPos - 1]);
  } else if (!strcmp(operation, "acos")) {
    nums[numsPos - 1] = acos(nums[numsPos - 1]);
  } else if (!strcmp(operation, "asin")) {
    nums[numsPos - 1] = asin(nums[numsPos - 1]);
  } else if (!strcmp(operation, "atan")) {
    nums[numsPos - 1] = atan(nums[numsPos - 1]);
  } else if (!strcmp(operation, "sqrt")) {
    if (nums[numsPos - 1] >= 0) {
      nums[numsPos - 1] = sqrt(nums[numsPos - 1]);
    } else {
      *error = 4;
    }
  } else if (!strcmp(operation, "ln")) {
    nums[numsPos - 1] = log(nums[numsPos - 1]);
  } else if (!strcmp(operation, "log")) {
    nums[numsPos - 1] = log10(nums[numsPos - 1]);
  } else if (!strcmp(operation, "~")) {
    nums[numsPos - 1] = nums[numsPos - 1] * -1;
  }
}

void calculateOperation(long double nums[255], int *numsPos, char *operation,
                        int *error) {
  if (!strcmp(operation, "+")) {
    nums[*numsPos - 2] = nums[*numsPos - 2] + nums[*numsPos - 1];
  } else if (!strcmp(operation, "-")) {
    nums[*numsPos - 2] = nums[*numsPos - 2] - nums[*numsPos - 1];
  } else if (!strcmp(operation, "*")) {
    nums[*numsPos - 2] = nums[*numsPos - 2] * nums[*numsPos - 1];
  } else if (!strcmp(operation, "/")) {
    if (nums[*numsPos - 1] == 0) {
      *error = 3;
    } else {
      nums[*numsPos - 2] = nums[*numsPos - 2] / nums[*numsPos - 1];
    }
  } else if (!strcmp(operation, "mod")) {
    nums[*numsPos - 2] = fmod(nums[*numsPos - 2], nums[*numsPos - 1]);
  } else if (!strcmp(operation, "^")) {
    nums[*numsPos - 2] = pow(nums[*numsPos - 2], nums[*numsPos - 1]);
  }
  *numsPos -= 1;
  nums[*numsPos] = 0.0;
}

void removeList(reversePolish *head) {
  while (head) {
    reversePolish *tmp = head->next;
    free(head);
    head = tmp;
  }
}

int resultIsOk(long double result) {
  int status = 0;
  if (result == result && result != INFINITY && result != -INFINITY) {
    if (result <= 1000000 && result >= -1000000) {
      status = 1;
    }
  }
  return status;
}
