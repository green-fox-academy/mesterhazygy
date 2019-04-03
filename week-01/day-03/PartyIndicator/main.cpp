#include <iostream>

int main() {
    int girls, boys;
    std::cout << "How many girls?" << std::endl;
    std::cin >> girls;
    std::cout << "How many boys?" << std::endl;
    std::cin >> boys;

    if ((girls == boys) && ((girls + boys)) >= 20) {
        std::cout << "The party is excellent!" << std::endl;
    } else if ((girls != boys) && ((girls + boys) >= 20)) {
        std::cout << "Quite cool party!" << std::endl;
    } else if ((girls + boys) < 20) {
        std::cout << "Average party" << std::endl;
    } else if (girls == 0) {
        std::cout << "Sausage party" << std::endl;
    }

    return 0;
}