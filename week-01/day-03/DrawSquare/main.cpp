#include <iostream>

int main() {

    std::cout << "give me a number" << std::endl;
    int usernum;
    std::cin >> usernum;

    for (int i = 0; i < usernum; i++) {
        for (int j = 0; j < usernum; j++) {
            if (i == 0) {                        //elso sor
                std::cout << "%";
            } else if ((i > 0) && (i < (usernum - 1)))    //koztes sorok
            {
                if ((j == 0) || (j == (usernum - 1))) {
                    std::cout << "%";
                } else {
                    std::cout << "0";
                }

            } else if (i == (usernum - 1)) {
                std::cout << "%";
            }

        }
        std::cout << std::endl;
    }

    return 0;
}