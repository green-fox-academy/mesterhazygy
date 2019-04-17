#include <iostream>
#include "Sharpie.h"

int main()
{
    Sharpie sharpie1("red", 0.5f);
    Sharpie sharpie2("rblue", 0.8f);
    std::cout << sharpie1.getInkAmount() << std::endl;
    sharpie1.use();
    sharpie1.use();
    std::cout << sharpie1.getInkAmount() << std::endl;

    return 0;
}