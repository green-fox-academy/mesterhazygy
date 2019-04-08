#include <iostream>

int main() {

    float temperature = 21.3;
    float *temperaturePointer = &temperature;
    *temperaturePointer = 30;
    std::cout << *temperaturePointer << std::endl;

    return 0;
}