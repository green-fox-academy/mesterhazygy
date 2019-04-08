#include <iostream>

int main() {

    int usersArray[5] = {};

    std::cout << "Hi, give me 5 numbers!" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cin >> usersArray[i];
    }
    for (int j = 0; j < 5; j++) {
        std::cout << &usersArray[j] << std::endl;
    }
    return 0;
}