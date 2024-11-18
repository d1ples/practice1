#include <iostream>

int main() {
    const char* str = "Hello, world!";

    do {
        std::cout << *str << "\n";
        ++str;
    } while (*str != '\0');

    return 0;
}
