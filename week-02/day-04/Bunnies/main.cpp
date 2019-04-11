#include <iostream>

int ears(int);

int main()
{
    int bunnies;
    std::cout << "How many bunnies do you have?" << std::endl;
    std::cin >> bunnies;
    std::cout << "There are " << ears(bunnies) << " ears." << std::endl;

    return 0;
}

int ears(int a)
{
    if (a > 1) {
        return 2 + ears(a - 1);
    } return 2;
}