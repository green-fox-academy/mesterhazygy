#include <iostream>

int main() {
    int a = 22;
    int b = 13;

    int sum = a + b;
    std::cout << sum << std::endl;
    int sub = a - b;
    std::cout << sub << std::endl;
    int mult = a * b;
    std::cout << mult << std::endl;
    double divide = (double) a / b;
    std::cout << divide << std::endl;
    int dividedinteger = a / b;
    std::cout << dividedinteger << std::endl;
    int remainder = a % b;
    std::cout << remainder << std::endl;

    return 0;
}