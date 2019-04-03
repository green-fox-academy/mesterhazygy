#include <iostream>

int main() {
    std::cout << "How many kilometres?" << std::endl;
    double input;
    std::cin >> input;
    std::cout << "That's " << input / 1.6 << "miles " << std::endl;

    return 0;
}