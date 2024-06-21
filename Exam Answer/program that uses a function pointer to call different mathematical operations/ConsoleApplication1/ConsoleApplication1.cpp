#include <iostream>

int add(int, int);
int subtract(int, int);
int multiply(int, int);

int main() {
    int num1, num2;
    char operation;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    std::cout << "Enter operation (+, -, *): ";
    std::cin >> operation;

    int (*operationPtr)(int, int);

    switch (operation) {
    case '+':
        operationPtr = add;
        break;
    case '-':
        operationPtr = subtract;
        break;
    case '*':
        operationPtr = multiply;
        break;
    default:
        std::cout << "Invalid operation. Exiting." << std::endl;
        return 1;
    }

    int result = operationPtr(num1, num2);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}