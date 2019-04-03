#include <iostream>

int main() {

    int a = 3;
    a += 10;
    std::cout << a << std::endl;

    int b = 100;
    b -= 7;
    std::cout << b << std::endl;

    int c = 44;
    c *= 2;
    std::cout << c << std::endl;

    int d = 125;
    d /= 5;
    std::cout << d << std::endl;

    int e = 8;
    std::cout << e * e * e << std::endl;

    int f1 = 123;
    int f2 = 345;
    bool isbigger;
    if (f1 > f2) {
        isbigger = true;
    }
    std::cout << isbigger << std::endl;

    int g1 = 350;
    int g2 = 200;
    bool isbigger2;
    if ((g2 * 2) > g1) {
        isbigger2 = true;
    }
    std::cout << isbigger2 << std::endl;

    int h = 135798745;
    int dd = h % 11;
    bool isdivisor;
    if (dd > 0) {
        isdivisor = false;
    }
    std::cout << isdivisor << std::endl;

    int i1 = 10;
    int i2 = 3;

    bool issmaller;
    if (i1 > (i2 * i2)) {
        if (i1 < (i2 * i2 * i2)) {
            issmaller = true;
        }
    }
    std::cout << issmaller << std::endl;

    int j = 1521;
    bool isdividable;
    if ((j % 3) > 0) {
        isdividable = true;
    } else {
        if ((j % 5) > 0) {
            isdividable = true;
        }
    }
    std::cout << isdividable << std::endl;


    return 0;
}