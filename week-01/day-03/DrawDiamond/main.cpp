#include <iostream>

int main() {

    int a;
    std::cout << "give me a number" << std::endl;
    std::cin >> a;

    for (int i = 0; i < a; i ++) {
        for (int j = 0; j < ((a / 2) - i) + 1; j ++) {
            std::cout << " ";
        }
        for (int k = 0; k < (2 * i) + 1; k ++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }


    return 0;
}