#include <iostream>
#include "dice_set.h"

int main()
{
    DiceSet set1;
    set1.roll();
    int sum = 0;
    int counter = 0;
    while (sum != 6) {
        set1.roll();
        for (int i = 0; i < 6; i++) {
            if (set1.getCurrent(i) == 6) {
                sum++;
            } else {
                set1.roll();
                sum = 0;
            }
            std::cout << set1.getCurrent(i) << " ";
            counter ++;
        }
        std::cout << std::endl;
    }
    std::cout << counter << std::endl;

    /*std::cout << std::endl;
    for (int j = 0; j < 6; j++) {
        std::cout << set1.getCurrent(j) << std::endl;
    }*/
    return 0;
}