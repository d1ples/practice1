#include <iostream>

int main() {
    double a, b;
    char operation;

    std::cout << "Enter a double value: ";
    std::cin >> a;

    std::cout << "Enter a double value: ";
    std::cin >> b;

    std::cout << "Enter one of the following: +, -, *, or /:  ";
    std::cin >> operation;

    switch (operation) {
    case '+':
        std::cout << a << " + " << b << " is " << a + b << "\n";
        break;
    case '-':
        std::cout << a << " - " << b << " is " << a - b << "\n";
        break;
    case '*':
        std::cout << a << " * " << b << " is " << a * b << "\n";
        break;
    case '/':
        std::cout << a << " / " << b << " is " << a / b << "\n";
        break;
    }

    return 0;
}
