#include <iostream>

int main() {

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    int *integerPointer = &a;
    double *doublePointer = &b;
    std::string *stringPointer = &name;

    std::cout << integerPointer << " " << *integerPointer << std::endl;
    std::cout << doublePointer << " " << *doublePointer << std::endl;
    std::cout << stringPointer << " " << *stringPointer <<  std::endl;

    return 0;
}