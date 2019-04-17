#include <iostream>
#include "PostIt.h"

int main()
{
    PostIt postIt1("orange", "Idea 1", "blue");
    PostIt postIt2("pink", "Awesome", "black");
    PostIt postIt3("yellow", "Superb", "green");

    std::cout << postIt1.getTextColor() << std::endl;
    return 0;
}