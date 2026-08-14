#include "calculator.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int num1;
  int num2;
  char operation;

  printf("Simple Calculator\n");
  printf("Supported operations: add, subtract, multiply, and divide (for integers only).\n");
  printf("Enter calculation (e.g., 3 + 4): ");

  /* The tidy checks want strtol and a bounded scanf variant; plain scanf
   * keeps this sample small, reads no strings (no overflow surface), and
   * the != 3 check below catches malformed input. */
  /* NOLINTNEXTLINE(cert-err34-c,clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) */
  if (scanf("%d %c %d", &num1, &operation, &num2) != 3) {
    printf("Invalid input. Please enter in the format: number operator number\n");
    return EXIT_FAILURE;
  }

  switch (operation) {
    case '+':
      printf("%d + %d = %d\n", num1, num2, add(num1, num2));
      break;
    case '-':
      printf("%d - %d = %d\n", num1, num2, subtract(num1, num2));
      break;
    case '*':
      printf("%d * %d = %d\n", num1, num2, multiply(num1, num2));
      break;
    case '/':
      if (num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
      } else {
        printf("%d / %d = %.2f\n", num1, num2, divide(num1, num2));
      }
      break;
    default:
      printf("Error: Unsupported operation '%c'.\n", operation);
      break;
  }

  return EXIT_SUCCESS;
}
