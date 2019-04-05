#include <iostream>

int main() {
    double a = 24;
    int out = 0;
    if ((int(a) % 2) == 0) {
        std::cout << ++out << std::endl;
    }

    int b = 13;
    std::string out2 = "";

    if ((b > 10) && (b < 20)) {
        out2 = "sweet";
    } else if (b < 10) {
        out2 = "less";
    } else if (b > 20) {
        out2 = "more";
    }
    std::cout << out2 << std::endl;

    int c = 123;
    int credits = 100;
    bool isBonus = false;
    if ((credits >= 50) && (isBonus == false)) {
        std::cout << c - 2 << std::endl;
    } else if ((credits < 50) && (isBonus = false)) {
        std::cout << c - 1 << std::endl;
    } else if (isBonus = true) {
        std::cout << c << std::endl;
    }

    int d = 8;
    int time = 120;
    std::string out3 = "";
    if (((d % 4) == 0) && (time < 200)) {
        out3 = "check";
    } else if (time > 200) {
        out3 = "time out";
    } else {
        out3 = "run forest run";
    }
    std::cout << out3 << std::endl;



    return 0;
}