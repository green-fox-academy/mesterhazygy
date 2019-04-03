#include <iostream>

int main() {

    int num1, num2, num3, num4, num5;
    std::cout << "Add number 1 " << std::endl;
    std::cin >> num1;
    std::cout << "Add number 2 " << std::endl;
    std::cin >> num2;
    std::cout << "Add number 3 " << std::endl;
    std::cin >> num3;
    std::cout << "Add number 4 " << std::endl;
    std::cin >> num4;
    std::cout << "Add number 5 " << std::endl;
    std::cin >> num5;

    std::cout << "Sum: " << num1 + num2 + num3 + num4 + num5 << std::endl;
    std::cout << "Average: " << (num1 + num2 + num3 + num4 + num5) / 5.0 << std::endl;

    return 0;
}