#include <iostream>

int main() {
    int a, b;

    std::cout << "Give me a number" << std::endl;
    std::cin >> a;
    std::cout << "Give me another number" << std::endl;
    std::cin >> b;

    if (a > b) {
        std::cout << "The bigger number is: " << a << std::endl;
    } else {
        std::cout << "The bigger number is: " << b << std::endl;
    }
    return 0;
}