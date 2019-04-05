#include <iostream>

void reverse(int[]);

int main() {

    int aj [] = {3, 4, 5, 6, 7};

    int k = aj[0];
    int l = aj[1];
    aj[0] = aj[4];
    aj[1] = aj[3];
    aj[4] = k;
    aj[3] = l;
    std::cout << aj[0] << aj[1] << aj[2] << aj[3] << aj[4] << std::endl;

    return 0;
}