#include <iostream>

int main() {

    int a;
    for (a = 0; a < 501; a++) {
        if ((a % 2) == 0) {
            std::cout << a << std::endl;
        }
    }

    return 0;
}