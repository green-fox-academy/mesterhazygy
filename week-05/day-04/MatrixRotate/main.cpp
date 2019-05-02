#include <iostream>
#include <bits/stdc++.h>

#define N 3

void rotateMatrix(int mat[][N]);

int main()
{
    int mat[N][N] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    rotateMatrix(mat);

    return 0;
}

void rotateMatrix(int mat[][N])
{
    int temp[N][N] = {};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            temp[j][N - 1 - i] = mat[i][j];
        }
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            std::cout << temp[k][i] << ", ";
        }
        std::cout << std::endl;
    }
}