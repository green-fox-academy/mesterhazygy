#include <iostream>

int main() {
    double massInKg = 76.3;
    double heightInM = 1.66;
    double bmi = massInKg / (heightInM * heightInM);
    std::cout << "Body mass index = " << bmi << std::endl;

    return 0;
}