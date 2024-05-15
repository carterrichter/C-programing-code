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
void setMatrixData(Matrix *mat, double data[][mat->columns]);
int getDimensions(Matrix *mat);
double getMatrixElement(Matrix *mat, int row, int column);
void setElement(Matrix *mat, int row, int column, double value);

#endif