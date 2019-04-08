#include <iostream>

int lookForVal(int userArray[], int length, int userNum);

int main() {
    int userNum = 67;
    int userArray[] = {13, 55, 2, 67, 3, 87};
    int length = sizeof(userArray) / sizeof(userArray[0]);
    std::cout << lookForVal(userArray, length, userNum) << std::endl;
    return 0;
}

int lookForVal(int userArray[], int length, int userNum) {
    for (int i = 0; i < length; i++) {
        if (userNum == userArray[i]) {
            return i;
        }
    }
    return -1;
}