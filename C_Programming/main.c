#include "C_Programming.h"

int main() {
    // Example usage
    Matrix *A = createMatrix(3, 3);
    initializeMatrixZeros(A);
    printMatrix(A);
    freeMatrix(A);
    return 0;
}