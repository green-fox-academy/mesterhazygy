#include <iostream>

int gcd(int, int);

int main()
{
    int a, b;
    std::cout << "give me a number" << std::endl;
    std::cin >> a;
    std::cout << "give me another one" << std::endl;
    std::cin >> b;
    std::cout << "The greatest common divisor of these numbers is: " << gcd(a, b) << std::endl;
    return 0;
}

int gcd(int a, int b)
{
    if (a != 0 && b != 0) {
        return (gcd(b, a % b));
    }
}