#include <iostream>

int main() {

    int a;
    std::cout << "give me a number" << std::endl;
    std::cin >> a;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < (i + 1); j++) {
            std::cout << a;

        }
        std::cout << std::endl;
    }

    return 0;
}