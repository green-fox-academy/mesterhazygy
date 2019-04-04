#include <iostream>

int main() {

    int a;
    std::cout << "Give me the size of the matrix" << std::endl;
    std::cin >> a;

    int mymatrix[a][a];

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (i == j) {
                mymatrix[i][j] = 1;
            } else {
                mymatrix[i][j] = 0;
            } std::cout << mymatrix [i][j];
        } std::cout << " " << std::endl;
    }


    return 0;
}