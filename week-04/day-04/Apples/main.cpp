#include <iostream>
#include <vector>
#include "Apple.h"

int main()
{
    std::vector<int> myVector = {1, 3, 65, 7, 23};
    std::cout << sum(myVector) << std::endl;
    return 0;
}