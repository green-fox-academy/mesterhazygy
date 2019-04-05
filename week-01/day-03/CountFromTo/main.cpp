#include <iostream>

int main() {

    int a, b;
    std::cout << "give me a number" << std::endl;
    std::cin >> a;
    std::cout << "give me another number" << std::endl;
    std::cin >> b;

    if (a > b) {
        std::cout << "the second number should be bigger!" << std::endl;
    } else {
        for (int i = a; (i < (b + 1)); i++) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}