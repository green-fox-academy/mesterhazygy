#include <iostream>
#include <string>
#include <vector>

void swap (int& a, int& b) {
    int s = a;
    a = b;
    b = s;
}

int bubble (int array[], int size) {
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
            }
        }
    }
}

int unique (int array[], int size) {
    std::vector <int> myVector;
    for (int i = 0; i < size; i++) {
        if (array[i] != array[i + 1]) {
            myVector.push_back(array[i]);
        }
    }
    for (int j = 0; j < myVector.size(); j++) {
        std::cout << myVector[j] << std::endl;
    }
}

int main(int argc, char* args[]) {
    int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};

    int size = sizeof(numbers) / sizeof(int);

    bubble(numbers, size);

    unique(numbers, size);

    return 0;
}
