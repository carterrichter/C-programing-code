#include "C_Programming.h"
#include "matrix.c"

int main() {
    // Example usage
    Matrix *A = createMatrix(3, 3);
    initializeMatrixZeros(A);
    printMatrix(A);
    freeMatrix(A);
    return 0;
}