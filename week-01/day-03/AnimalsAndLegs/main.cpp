#include <iostream>

int main() {
    std::cout << "How many chickens?" << std::endl;
    int chickens;
    int pigs;
    std::cin >> chickens;
    std::cout << "How many pigs?" << std::endl;
    std::cin >> pigs;

    std::cout << chickens + pigs << std::endl;


    return 0;
}