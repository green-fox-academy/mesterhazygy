#include <iostream>

int sum (int);

int main() {
    int usernum;
    std::cout << "give me a number:" << std::endl;
    std::cin >> usernum;

    std::cout << "sum of numbers is: " << sum (usernum) << std::endl;

    return 0;
}

int sum (int a) {
    int c = 0;
    for (int i = 0 ; i <= a; i++){
        c += i;
    }
    return c;
}