#include <iostream>

int *findMax(int [], int);

int main() {
    std::cout << "Give me the size of the array" << std::endl;
    int arraySize;
    std::cin >> arraySize;
    int numbers[arraySize];
    std::cout << "Give me " << arraySize << "numbers" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        std::cin >> numbers[i];
    }
    std::cout << "The biggest number in the array is: " << std::endl;
    std::cout << *findMax(numbers, arraySize) << std::endl;
    std::cout << "The memory address of this number is: " << std::endl;
    std::cout << findMax(numbers, arraySize) << std::endl;
    return 0;
}

int *findMax(int userArray[], int length) {
    int *x = &userArray[0];
    for (int i = 1; i < length; i++) {
        if (userArray[i] > *x) {
            x = &userArray[i];
        }
    }
    return x;
}