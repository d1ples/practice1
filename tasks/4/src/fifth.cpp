#include <iostream>
 
constexpr int DRIVING_AGE = 16;

int main()
{
  std::cout << "How old are you?\n";
 
  int age{};
  std::cin >> age;
 
  std::cout << "Allowed to drive a car in Texas [";
 
  if (age >= DRIVING_AGE)
    std::cout << 'x';
  else
    std::cout << ' ';
 
  std::cout << "]\n";
 
  return 0;
}
