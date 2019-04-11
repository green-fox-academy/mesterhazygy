#include <iostream>

int power(int, int);

int main()
{
    int base, x;
    std::cout << "give me a number" << std::endl;
    std::cin >> base;
    std::cout << "give me the power" << std::endl;
    std::cin >> x;
    std::cout << power(base, x) << std::endl;
    return 0;
}

int power (int base, int x)
{
    if (x > 1){
        return (base * power(base, x-1));
    } if (x == 1) {
        return base;
    }
}