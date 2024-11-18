#include <iostream>
#include "constants.h"
 
double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen { myConstants::gravity * seconds * seconds / 2 };
    double heightNow { initialHeight - distanceFallen };
 
    // Проверяем, не ушли ли мы под землю
    // Если это так, устанавливаем высоту на уровне земли
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}
 
double calculateAndPrintHeight(double initialHeight, int time)
{
    double height = calculateHeight(initialHeight, time);
    std::cout << "At " << time << " seconds, the ball is at height: " << height << "\n";
    return height;
}
 
int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight;
    std::cin >> initialHeight;
	
    int seconds = 0;
    double height = initialHeight;

    do {
        height = calculateAndPrintHeight(initialHeight,seconds++);
    } while (height > 0.0);
	
    return 0;
}
