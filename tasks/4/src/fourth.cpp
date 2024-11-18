#include "constants.h"
#include <iostream>

void print_free_fall_acceleration(double input_height) {
    unsigned int t = 0;
    
    double height = input_height;

    while(height > 0) {
        std::cout << "At " << t << " seconds, the ball is at height: " << height << " meters\n";
        t++;
        height = input_height - FREE_FALL_ACCELERATION * t * t / 2;
    }

    std::cout << "At " << t << " seconds, the ball is on the ground\n";

    return;
}

int main() {
    print_free_fall_acceleration(100);

    return 0;
}
