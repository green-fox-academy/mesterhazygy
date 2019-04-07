#include <iostream>

int main() {

    int usernum;
    std::cout << "Hi, give me a number please:" << std::endl;
    std::cin >> usernum;
    for (int i = 0; i < usernum; i++) {
        for (int j = 0; j < usernum; j++) {
            if ((i == 0) || (j == 0) || (j == usernum - 1)) {
                std::cout << "%";
            } else if ((i < (usernum - 1)) && (j == i)) {
                std::cout << "%";
            } else if (i == (usernum - 1)) {
                std::cout << "%";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}