#ifndef C_PROGRAMMING_H
#define C_PROGRAMMING_H

//structure that defines what a matrix is
typedef struct {
    int rows;
    int columns;
    double **data;
} Matrix;

//function prototypes
Matrix* createMatrix(int rows, int columns);
void initializeMatrixZeros(Matrix *mat);
void printMatrix(Matrix *mat);
void freeMatrix(Matrix *mat);

#endif /* C_PROGRAMMING_H plea*/