#include <iostream>

int main() {

    int userNum, userNumbers;
    int sumOfNumbers = 0;
    std::cout << "How many numbers do you want to work with?" << std::endl;
    std::cin >> userNum;
    for (int i = 0; i < userNum; i ++) {
        std::cout << "number " << i + 1 << " = ";
        std::cin >> userNumbers;
        sumOfNumbers += userNumbers;
        std::cout << std::endl;
    }
    std::cout << sumOfNumbers << std::endl;

    return 0;
}