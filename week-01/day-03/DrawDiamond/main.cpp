#include <iostream>

int main() {

    int a;
    std::cout << "give me a number" << std::endl;
    std::cin >> a;

    for (int i = 0; i < a / 2 + 1; i ++) {
        for (int j = 0; j < ((a / 2) - i) + 1; j ++) {
            std::cout << " ";
        }
        for (int k = 0; k < (2 * i) + 1; k ++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < a / 2; i ++) {          //sorok száma alul jó
        for (int j = 0; j < i + 2; j ++) {      //space-ek száma jó
            std::cout << " ";
        }
        for (int k = 0; k < a - (i + 1) * 2; k ++) {
            std::cout << "*";
        }

        std::cout << std::endl;

    }


    return 0;
}