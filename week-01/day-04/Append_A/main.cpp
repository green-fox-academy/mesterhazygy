#include <iostream>

int main() {

    std::string animals [] = {"koal", "pand", "zebr"};
    for (int i = 0; i < 3; i++) {
            animals[i] += "a";
        std::cout << animals[i] << std::endl;
    }

    return 0;
}