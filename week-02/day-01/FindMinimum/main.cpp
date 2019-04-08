#include <iostream>

int *findMin (int array[], int);

int main() {

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    std::cout << findMin (numbers, length) << std::endl;
    std::cout << *findMin (numbers, length) << std::endl;

    return 0;
}

int *findMin (int array[], int length) {
    int *x = &array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] < *x) {
            x = &array[i];
        }
    } return x;
}