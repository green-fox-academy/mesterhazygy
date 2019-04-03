#include <iostream>

int main() {
    std::cout << "What's your name?" << std::endl;
    std::string usersname;
    std::cin >> usersname;
    std::cout << "Hello " << usersname << std::endl;

    return 0;
}