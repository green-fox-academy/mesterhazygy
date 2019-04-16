#include <iostream>

int divider(int);

int main()
{
    try {
        int userNum;
        std::cout << "give me a number" << std::endl;
        std::cin >> userNum;
        if (userNum == 0) {
            throw std::string("fail");
        }
        std::cout << divider(userNum) << std::endl;
    }
    catch (std::string &e) {
        std::cout << e << std::endl;
    }
    return 0;
}

int divider(int userNum)
{
    int b = 10 / userNum;
    return b;
}