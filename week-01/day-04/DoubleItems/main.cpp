#include <iostream>

int doubler(int);

int main() {

    int numlist[] = {3, 4, 5, 6, 7};
    for (int i = 0; i < sizeof(numlist) / (sizeof(numlist[0])); i++) {
        int c = doubler(numlist[i]);
        std::cout << c << std::endl;
    }
    return 0;
}

int doubler(int c) {
    int a;
    a = c * 2;
    return a;
}