#include <iostream>

int main() {

    int userNumbers [5] = {};
    int *numPointers = userNumbers;
    std::cout << "Give me 5 numbers" << std::endl;
    for (int i = 0; i < 5; i ++) {
        std::cin >> userNumbers[i];
    }
    for (int j = 0; j < 5; j ++) {
        std::cout << numPointers[j] << " ";
    } std::cout << std::endl;

    return 0;
}