#include <iostream>

int main() {

    int a;
    int b;
    std::cout << "Hi, give me a number" << std::endl;
    std::cin >> a;
    for (b = 1; b < 11; b++) {
        std::cout << b << " * " << a << " = " << b * a << std::endl;
    }


    return 0;
}