#include <iostream>

int main() {
    std::cout << "Give me a number" << std::endl;
    int usernum;
    std::cin >> usernum;
    if (usernum <= 0) {
        std::cout << "Not enough" << std::endl;
    } else if (usernum == 1) {
        std::cout << "One" << std::endl;
    } else if (usernum == 2) {
        std::cout << "Two" << std::endl;
    } else {
        std::cout << "A lot" << std::endl;
    }

    return 0;
}