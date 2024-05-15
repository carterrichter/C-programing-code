#include <stdio.h>
#include "C_Programming.h"
#include "matrix.c"

int main() {
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

    //Matrix *C = createSubset(A, 0, 2, 0, 2);

    printMatrix(A);
    printf("\n");
    printMatrix(B);
    printf("\n");
    //printMatrix(C);

    //printf("\n");
    //getDimensions(A);
    //getDimensions(B);

    //printf("\n");
    //getMatrixElement(A, 0, 0);
    //getMatrixElement(A, 0, 1);
    //getMatrixElement(B, 0, 0);
    //getMatrixElement(B, 0, 1);
    //printf("\n");

    //setMatrixElement(A, 0, 0, 0);
    //printMatrix(A);
    //printf("\n");

    //getMatrixRow(A, 0);
    //printf("\n");
    //getMatrixColumn(A, 0);
    //printf("\n");
    //getMatrixRow(B, 0);
    //printf("\n");
    //getMatrixColumn(B, 0);

    double testForChange[3] = {0, 0, 0};
    //setMatrixRow(A, 0, testForChange);
    setMatrixColumn(A, 0, testForChange);

    //resizeMatrix(&A, 5, 5);
    //printMatrix(A);

    //Matrix *C = createSubset(A, 0, 2, 0, 2);
   // printMatrix(C);
    //setSubset(C, 0, 0, B);
    //printMatrix(C);
    //Matrix *C = addMatrices(A, B);
    //printMatrix(C);
    //Matrix *C = subMatrices(A, B);
    //printMatrix(C);

    //Matrix *C = multiplyMatrices(A, B);
    //Matrix *C = deepCopyMatrix(A);
    //printMatrix(C);


    //if (areMatricesEqual(A, B)) {
    //    printf("The Matrices are equal!\n");
    //} else {
    //    printf("The Matrices are not equal.\n");
    //}
    //if (areMatricesEqual(A, C)) {
    //    printf("The Matrices are equal!\n");
    //} else {
    //    printf("The Matrices are not equal.\n");
    //} 
    //rotateMatrix(A);
    //printMatrix(A);

    // Test freeMatrix
    printf("\nFreeing memory for the matrix:\n");
    freeMatrix(A);
    freeMatrix(B);
    //freeMatrix(C);
    printf("I will free all memory I ALLOCATE!");

    return 0;
}