#include <iostream>

int sum (int[], int);

int main() {

    int ai [] = {3, 4, 5, 6, 7};
    std::cout << sum (ai, sizeof(ai) / sizeof(ai[0])) << std::endl;
    return 0;
}

int sum (int a[], int b) {
    int c = 0;
    for (int i = 0 ; i < b; i++){
        c += a[i];
    }
    return c;
}