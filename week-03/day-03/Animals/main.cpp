#include <iostream>
#include "Animal.h"

int main()
{
    Animal dog(50, 50);
    Animal cat(40, 40);
    Animal cheetah(50, 60);
    cheetah.play();
    std::cout << cheetah.getHunger() << std::endl;
    return 0;
}