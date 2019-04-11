#include <iostream>

int sumDigit(int);

int main()
{
    int a;
    std::cout << "give me number" << std::endl;
    std::cin >> a;
    std::cout << sumDigit(a) << std::endl;

    return 0;
}

int sumDigit(int n)
{
    if (n > 0) {
        return n % 10 + sumDigit(n / 10);
    }
}