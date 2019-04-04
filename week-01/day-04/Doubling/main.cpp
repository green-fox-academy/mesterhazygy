#include <iostream>

int doubling(int);

int main() {

    int basenum = 123;
    int b = doubling(basenum);
    std::cout << b << std::endl;


    return 0;
}

int doubling(int basenum) {
    int a;
    a = basenum * 2;
    return a;
}