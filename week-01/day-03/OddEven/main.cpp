#include <iostream>

int main() {
    std::cout << "Give me a number " << std::endl;
    int usernum;
    std::cin >> usernum;
    if ((usernum % 2) > 0) {
        std::cout << "Odd" << std::endl;
    } else {
        std::cout << "Even" << std::endl;
    }

    return 0;
}