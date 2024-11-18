#include <iostream>
#include <string>

template<typename T>
void swap(T& a, T& b) {
    T c = a;

    a = b;
    b = c;
}

int main() {
    int a = 10;
    int b = 20;
  
    std::cout << a << "\n" << b << "\n";

    swap(a, b);
    
    std::cout << a << "\n" << b << "\n";

    std::string c = "One";
    std::string d = "Two";
    
    
    std::cout << c << "\n" << d << "\n";

    swap(c, d);
    
    std::cout << c << "\n" << d << "\n";
}
