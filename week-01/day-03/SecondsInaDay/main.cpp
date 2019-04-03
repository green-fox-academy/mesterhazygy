#include <iostream>

int main() {

    int currentHours = 14;
    int currentMinutes = 34;
    int currenSeconds = 42;
    int seconds = 86400;
    int secondspassed = (currentHours * 3600) + (currentMinutes * 60) + currenSeconds;

    std::cout << "The remaining seconds are: " << (seconds - secondspassed) << std::endl;

    return 0;
}