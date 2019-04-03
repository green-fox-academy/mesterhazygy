#include <iostream>

int main() {
    int dailyhours = 6;
    int weeknumbers = 17;
    int workdaysperweek = 5;
    int workinghours1 = dailyhours * workdaysperweek * weeknumbers;
    int averageworkinghours = 52;
    double percent = (((double) dailyhours * workdaysperweek) / averageworkinghours) * 100;

    std::cout << workinghours1 << std::endl;
    std::cout << percent << std::endl;


    return 0;
}