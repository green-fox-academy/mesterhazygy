#include <iostream>

void appendAFunc (std::string);

int main() {

    std::string typo = "Chinchill";
    appendAFunc(typo);

    return 0;
}

void appendAFunc (std::string a) {
    std::cout << a << "a" << std::endl;
}