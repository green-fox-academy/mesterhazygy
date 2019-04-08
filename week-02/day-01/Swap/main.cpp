#include <iostream>

void swapValues (int *, int *);

int main() {
    int a = 10;
    int b = 316;
    swapValues (&a, &b);
    std::cout << a << " " << b << std::endl;
    return 0;
}

void swapValues (int *firstNum, int *secondNum)
{
    int vari = *firstNum;
    *firstNum = *secondNum;
    *secondNum = vari;
}