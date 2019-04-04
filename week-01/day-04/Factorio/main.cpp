#include <iostream>

void factorio (int, int&);

int main() {

    int usernum;
    int b;
    std::cout << "give me a number:" << std::endl;
    std::cin >> usernum;

    factorio (usernum, b);
    // std::cout << b << std::endl;
    return 0;
}

void factorio (int a, int& b) {
    int c = 1;
    for (int i = 1 ; i <= a; i++){
        c *= i;
    }
    b = c;
}