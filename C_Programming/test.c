#include <stdio.h>
#include "C_Programming.h"
#include "matrix.c"

int main() {
    // Test createMatrix and initializeMatrixZeros

    double firstMatrix[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    double secondMatrix[3][3] = {
        {9,8,7},
        {6,5,4},
        {3,2,1}
    };
    Matrix *A = createMatrix(3, 3);
    Matrix *B = createMatrix(3, 3);

    setMatrixData(A, firstMatrix);
    setMatrixData(B, secondMatrix);
    printMatrix(A);
    printf("\n");
    printMatrix(B);

    printf("\n");
    getDimensions(A);
    getDimensions(B);

    // Test freeMatrix
    printf("\nFreeing memory for the matrix:\n");
    freeMatrix(A);
    freeMatrix(B);
    printf("I will free all memory I ALLOCATE!");

    return 0;
}
