#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix_mul.h"

void parseMatrix(char *_str, int **_matrix, int _rows, int _cols)
{
    char* strCopy = strdup(_str);
    char* token = strtok(strCopy, ",");
    for(int row = 0; row < _rows; row++)
    {
        for(int col = 0; col < _cols; col++)
        {
            _matrix[row][col] = atoi(token);
            token = strtok(NULL, ",");
        }
    }
    free(strCopy);
}

int main(int argc, char *argv[])
{
    /*
    input:
        argv[0]: program name

        MatrixA:                 MatrixB:
        argv[1]: matrixA         argv[4]: matrixB
        argv[2]: matrixA_rows    argv[5]: matrixB_rows
        argv[3]: matrixA_cols    argv[6]: matrixB_cols

        fucking u lyf
    */

    if(argc != 7)
    {
        printf("Usage: %s matrix1 matrix2\n", argv[0]);
        return 1;
    }

    int ARowSize = atoi(argv[2]), AColSize = atoi(argv[3]);
    int BRowSize = atoi(argv[5]), BColSize = atoi(argv[6]);

    int** matrixA = (int**)malloc(sizeof(int*) * ARowSize);
    for(int i = 0; i < ARowSize; i++)
    {
        matrixA[i] = (int*)calloc(sizeof(int) , AColSize);
    }
    
    int** matrixB = (int**)malloc(sizeof(int*) * BRowSize);
    for(int i = 0; i < BRowSize; i++)
    {
        matrixB[i] = (int*)calloc(sizeof(int) , BColSize);
    }

    parseMatrix(argv[1], matrixA, ARowSize, AColSize);
    parseMatrix(argv[4], matrixB, BRowSize, BColSize);

    int** result = multiply(matrixA, ARowSize, AColSize, matrixB, BRowSize, BColSize);
    printf("Result:\n");
    printMatrix(result, ARowSize, BColSize);

    for(int i = 0; i < ARowSize; i++)
    {
        free(matrixA[i]);
    }
    free(matrixA);

    for(int i = 0; i < BRowSize; i++)
    {
        free(matrixB[i]);
    }
    free(matrixB);

    for(int i = 0; i < ARowSize; i++)
    {
        free(result[i]);
    }
    free(result);

    return 0;
}