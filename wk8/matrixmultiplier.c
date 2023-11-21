#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplyMatrices(int x, int y, int m[x][y], int n[y][x], int output[x][x])
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            output[i][j] = 0;
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < x; k++)
            {
                output[i][j] += m[k][i] * n[i][j];
            }
        }
    }
}

void renderMatrix(int x, int y, int matrix[x][y])
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%012d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void populateMatrix(int x, int y, int matrix[x][y])
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            srand(time(0) * j + i);
            matrix[i][j] = rand();
        }
    }
}

int main()
{
    int matrix_1[2][3];
    int matrix_2[3][2];
    int result[2][2];

    populateMatrix(2, 3, matrix_1);
    populateMatrix(3, 2, matrix_2);

    printf("\nMatrix 1:\n");
    renderMatrix(2, 3, matrix_1);

    printf("\nMatrix 2:\n");
    renderMatrix(3, 2, matrix_2);

    multiplyMatrices(2, 3, matrix_1, matrix_2, result);

    printf("\nMultiplied matrix:\n");
    renderMatrix(2, 2, result);

    return 0;
}