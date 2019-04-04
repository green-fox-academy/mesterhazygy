#include <iostream>

int main() {

    int p1[] = {1, 2, 3};
    int p2[] = {4, 5};
    if (sizeof (p2) > sizeof (p1)) {
        std::cout << "yes" << std::endl;
    } else std::cout << "nope" << std::endl;

    return 0;
}