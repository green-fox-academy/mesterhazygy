#include <iostream>

int ears(int);

int main()
{
    int bunnies;
    std::cout << "how many bunnies do you have?" << std::endl;
    std::cin >> bunnies;
    std::cout << "There are " << ears(bunnies) << " ears" << std::endl;
    return 0;
}

int ears(int bunnies)
{
    if (bunnies >= 1) {
        if (bunnies % 2 != 0) {
            return 2 + ears(bunnies - 1);
        }
        return 3 + ears(bunnies - 1);
    }
}