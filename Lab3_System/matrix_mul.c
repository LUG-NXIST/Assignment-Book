#include <stdio.h>
#include <stdlib.h>

#include "matrix_mul.h"

int** multiply(int** _matrixA, int _ARowSize, int _AColSize,
               int** _matrixB, int _BRowSize, int _BColSize)
{
    if(_AColSize != _BRowSize)
    {
        printf("Error: matrix size mismatch\n");
        return NULL;
    }
    int** resultMatrix = (int**)malloc(_ARowSize * sizeof(int*));

    for(int i = 0; i < _ARowSize; i++)
    {
        resultMatrix[i] = (int*)calloc(_BColSize, sizeof(int));
    }

    ///////////////////////////////////////////////////////////////////
    /*在这里补全代码 实现矩阵A与矩阵B的乘积*/

    


    ///////////////////////////////////////////////////////////////////

    return resultMatrix;
}

void printMatrix(int **_matrix, int _rows, int _cols)
{
    for(int i = 0; i < _rows; i++)
    {
        for(int j = 0; j < _cols; j++)
        {
            printf("%d ", _matrix[i][j]);
        }
        printf("\n");
    }
}