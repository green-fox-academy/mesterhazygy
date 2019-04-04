#include <iostream>

void swap(int &, int &);

int main() {
    int a = 15;
    int b = 23;
    std::cout << "original a: " << a << ", original b: " << b << std::endl;
    swap(a, b);
    std::cout << "new b: " << b << ", new a: " << a << std::endl;

    return 0;
}

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}