#include <iostream>

int main() {

    for (int i = 0; i < 8; i ++) {
        for (int j = 0; j < 8; j++) {
            if (((i + 1) % 2 != 0) && ((j + 1) % 2 != 0)) {
                std::cout << "%";
            } else if (((i + 1) % 2 == 0) && ((j + 1) % 2 == 0)){
                std::cout << "%";
            } else {
                std::cout << " ";
            }
        }std::cout << std::endl;
    }

    return 0;
}