#include <iostream>

int main() {

    int a;
    for (a = 1; a < 101; a++) {
        if (((a % 3) == 0) && ((a % 5) == 0)) {
            std::cout << "FizzBuzz" << std::endl;
        } else if ((a % 3) == 0) {
            std::cout << "Fizz" << std::endl;
        } else if ((a % 5) == 0) {
            std::cout << "Buzz" << std::endl;
        }else {
            std::cout << a << std::endl;
        }
    }

    return 0;
}