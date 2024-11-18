#include "io.h"
#include <iostream>

int readNumber() {
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    return number;
}

void writeAnswer(int number) {
    std::cout << "Answer: " << number << "\n";
}
