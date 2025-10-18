#include "calculator.h"

int add(int operand1, int operand2) {
    return operand1 + operand2;
}

int subtract(int operand1, int operand2) {
    return operand1 - operand2;
}

int multiply(int operand1, int operand2) {
    return operand1 * operand2;
}

double divide(int operand1, int operand2) {
    if (operand2 == 0) {
        return 0.0;
    }
    return (double)operand1 / operand2;
}
