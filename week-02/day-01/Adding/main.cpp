#include <iostream>

int main() {

    int a = 20;
    int b = 17;
    int *aPointer = &a;
    int *bPointer = &b;

    int c = *aPointer + *bPointer;
    std::cout << c << std::endl;

    return 0;
}