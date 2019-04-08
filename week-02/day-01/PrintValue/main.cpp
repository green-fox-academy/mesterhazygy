#include <iostream>

int main() {

    int age = 31;
    int *agePointer = &age;
    std::cout << "The value of age is: " << *agePointer << std::endl;

    return 0;
}