#include <iostream>

int main() {

    double a = 10;
    double b = 20;
    double c = 40;

    std::cout << "Surface Area = " << ((a * b) * 2) + ((a * c) * 2) + ((b * c) * 2) << std::endl;
    std::cout << "Volume = " << a * b * c << std::endl;


    return 0;
}