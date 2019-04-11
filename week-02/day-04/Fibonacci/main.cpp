#include <iostream>

int fibonacci(int);

int main()
{
    int a;
    std::cout << "give me a number for this awesome fibonacci sequence" << std::endl;
    std::cin >> a;
    std::cout << fibonacci(a) << std::endl;
    return 0;
}

int fibonacci(int a)
{
    if (a == 0 || a == 1){
        return a;
    } else {
        return fibonacci(a - 1) + fibonacci(a - 2);
    }
}