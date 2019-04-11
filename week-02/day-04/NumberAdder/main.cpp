#include <iostream>

int numAdder(int);

int main()
{
    int n;
    std::cout << "give me a number" << std::endl;
    std::cin >> n;
    std::cout << numAdder(n) << std::endl;
    return 0;
}

int numAdder(int n)
{
    if (n != 0) {
        return n + numAdder(n - 1);
    } return 0;


}