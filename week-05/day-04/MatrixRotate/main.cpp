#include <iostream>
#include <bits/stdc++.h>
#define N 3

void rotateMatrix(int mat[][N]);
void displayMatrix(int mat[N][N]);

int main()
{
    int mat [N][N]= {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    rotateMatrix(mat);
    displayMatrix(mat);


    return 0;
}

void rotateMatrix(int mat[][N])
{
    // Consider all squares one by one
    for (int x = 0; x < N / 2; x++)
    {
        // Consider elements in group of 3 in
        // current square
        for (int y = x; y < N-x-1; y++)
        {
            // store current cell in temp variable
            int temp = mat[x][y];

            // move values from right to top
            mat[x][y] = mat[y][N-1-x];

            // move values from bottom to right
            mat[y][N-1-x] = mat[N-1-x][N-1-y];

            // move values from left to bottom
            mat[N-1-x][N-1-y] = mat[N-1-y][x];

            // assign temp to left
            mat[N-1-y][x] = temp;
        }
    }
    /*int tempArray[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tempArray[j][3 - i] = mat[i][j];
        }
    }*/
}

void displayMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", mat[i][j]);

        printf("\n");
    }
    printf("\n");
}