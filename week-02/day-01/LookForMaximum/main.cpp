#include <iostream>

int main() {
    std::cout << "give me the size of the array" << std::endl;
    int arraySize;
    std::cin >> arraySize;
    int userNumbers [arraySize];
    std::cout << "Give me " << arraySize << " numbers" << std::endl;
    for (int i = 0; i < arraySize; i ++) {
        std::cin >> userNumbers[i];
    }
    int *x = &userNumbers[0];
    for (int k = 0; k < arraySize; k ++){
        if (userNumbers[k] > *x) {
            x = &userNumbers[k];
        }
    }
    std::cout << "The biggest number is: " << *x << std::endl;
    std::cout << "The memory address of this number is: " << x << std::endl;
    return 0;
}