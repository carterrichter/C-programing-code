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
    //creation of two Matrices
    Matrix *A = createMatrix(3, 3);
    Matrix *B = createMatrix(3, 3);
    
    //initializing matrices with arrays above
    setMatrixData(A, firstMatrix);
    setMatrixData(B, secondMatrix);

    //printing matrices
    printf("Matrix A and B are as follows:\n");
    printMatrix(A);
    printf("\n");
    printMatrix(B);
    printf("\n");

    //showing dimensions
    printf("\nDimensions of A and B are as follows:\n");
    getDimensions(A);
    getDimensions(B);

    //showing getting element
    printf("\nFinding elements within A two times and B two times:\n");
    getMatrixElement(A, 0, 0);
    getMatrixElement(A, 2, 2);
    printf("\n");
    getMatrixElement(B, 0, 0);
    getMatrixElement(B, 2, 2);

    //setting specific elements
    printf("\nSetting of elements in A two times and B two times\n");
    setMatrixElement(A, 0, 0, 0);
    printMatrix(A);
    printf("\n");
    setMatrixElement(A, 2, 2, 0);
    printMatrix(A);
    printf("\n");
    setMatrixElement(B, 0, 0, 0);
    printMatrix(B);
    printf("\n");
    setMatrixElement(B, 2, 2, 0);
    printMatrix(B);

    //resetting matrices
    setMatrixData(A, firstMatrix);
    setMatrixData(B, secondMatrix);

    //getting matrix row
    printf("\n");
    printf("Getting matrix rows of A two times, and B two times:\n");
    getMatrixRow(A, 0);
    getMatrixRow(A, 2);
    getMatrixRow(B, 0);
    getMatrixRow(B, 2);

    //getting matrix columns
    printf("\n");
    printf("Getting matrix columns of A two times, and B two times:\n");
    getMatrixColumn(A, 0);
    getMatrixColumn(A, 2);
    getMatrixColumn(B, 0);
    getMatrixColumn(B, 2);
    printf("\n");

    //setting matrix rows
    double newValues[3] = {0, 0, 0};
    printf("Setting matrix rows of A two times, and B two times:\n");
    setMatrixRow(A, 0, newValues);
    printf("\n New Matrix\n");
    printMatrix(A);
    printf("\n");
    setMatrixRow(A, 2, newValues);
    printf("\n New Matrix\n");
    printMatrix(A);
    printf("\n");
    setMatrixRow(B, 0, newValues);
    printf("\n New Matrix\n");
    printMatrix(B);
    printf("\n");
    setMatrixRow(B, 2, newValues);
    printf("\n New Matrix\n");
    printMatrix(B);
    printf("\n");

    //resetting matrices
    setMatrixData(A, firstMatrix);
    setMatrixData(B, secondMatrix);

    //setting matrix columns
    printf("Setting matrix columns of A two times, and B two times:\n");
    setMatrixColumn(A, 0, newValues);
    printf("\n New Matrix\n");
    printMatrix(A);
    printf("\n");
    setMatrixColumn(A, 2, newValues);
    printf("\n New Matrix\n");
    printMatrix(A);
    printf("\n");
    setMatrixColumn(B, 0, newValues);
    printf("\n New Matrix\n");
    printMatrix(B);
    printf("\n");
    setMatrixColumn(B, 2, newValues);
    printf("\n New Matrix\n");
    printMatrix(B);
    printf("\n");

    //resetting matrices
    setMatrixData(A, firstMatrix);
    setMatrixData(B, secondMatrix);

    //creating subset
    printf("Creating a subset of the first two rows and columns of A:\n");
    Matrix *C = createSubset(A, 0, 1, 0, 1);
    printMatrix(C);
    freeMatrix(C);
    printf("Creating a subset of the first two rows and columns of B:\n");
    Matrix *D = createSubset(B, 0, 1, 0, 1);
    printMatrix(D);
    freeMatrix(D);

    //setting subset
    printf("setting a subset of A to the values of B\n");
    Matrix *E = createSubset(A, 0, 2, 0, 2);
    printf("Before set:\n");
    printMatrix(E);
    printf("After set:\n");
    setSubset(E, 0, 0, B);
    printMatrix(E);
    freeMatrix(E);

    //resizing matrix
    printf("\nResizing Matrix:\n Before resize:\n");
    Matrix *F = createSubset(A, 0, 2, 0, 2);
    printMatrix(F);
    printf("After resize:\n");
    resizeMatrix(&F, 5, 5);
    printMatrix(F);
    freeMatrix(F);

    //adding matrices
    printf("\nAdding matrices A and B:\n");
    Matrix *G = addMatrices(A, B);
    printMatrix(G);
    freeMatrix(G);

    //subtracting matrices
    printf("\nSubtracting matrix A from B:\n");
    Matrix *H = subMatrices(A, B);
    printMatrix(H);
    freeMatrix(H);

    //multiplying matrices
    printf("\nMultiplying Matrix A and B:\n");
    Matrix *I = multiplyMatrices(A, B);
    printMatrix(I);
    freeMatrix(I);

    //creating a deepcopy matrix
    printf("\nCreating a deepcopy of A");
    Matrix *J = deepCopyMatrix(A);
    printf("\nDeep Copy:\n");
    printMatrix(J);

    //testing if matrices are equal
    printf("\nTesting if A and B are equal\n");
    if (areMatricesEqual(A, B)) {
        printf("Matrices are equal!\n");
    } else {
        printf("Matrices are not equal.\n");
    }
    printf("\nTesting if A and J (The deep copy) are equal\n");
    if (areMatricesEqual(A, J)) {
        printf("Matrices are equal!\n");
    } else {
        printf("Matrices are not equal.\n");
    }
    freeMatrix(J);

    //finally, rotating matrixes
    printf("\nRotating A\n");
    rotateMatrix(A);
    printMatrix(A);
    printf("\nRotating B\n");
    rotateMatrix(B);
    printMatrix(B);

    printf("\nFreeing memory for the matrix:\n");
    freeMatrix(A);
    freeMatrix(B);
    printf("I will free all memory I ALLOCATE!");

}