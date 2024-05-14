#include <stdio.h>
#include "C_Programming.h"

int main() {
    // Test createMatrix and initializeMatrixZeros
    printf("Creating a 3x3 matrix initialized with zeros:\n");
    Matrix *A = createMatrix(3, 3);
    initializeMatrixZeros(A);
    printMatrix(A);

    // Test freeMatrix
    printf("\nFreeing memory for the matrix:\n");
    freeMatrix(A);

    return 0;
}
