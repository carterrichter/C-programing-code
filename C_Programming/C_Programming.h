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
void setMatrixElement(Matrix *mat, int row, int column, double value);
void getMatrixRow(Matrix *mat, int row);
void getMatrixColumn(Matrix *mat, int column);
void setMatrixRow(Matrix *mat, int row, double values[]);
void setMatrixColumn(Matrix *mat, int column, double values[]);
Matrix* createSubset(Matrix *mat, int startRow, int endRow, int startColumn, int endColumn);
void setSubset(Matrix *dest, int startRow, int startColumn, Matrix *src);
void resizeMatrix(Matrix **mat, int newRows, int newColumns);
Matrix* addMatrices(const Matrix *mat1, const Matrix *mat2);
Matrix* subMatrices(const Matrix *mat1, const Matrix *mat2);
Matrix* multiplyMatrices(const Matrix *mat1, const Matrix *mat2);
Matrix* deepCopyMatrix(const Matrix *src);
int areMatricesEqual(const Matrix *mat1, const Matrix *mat2);
void rotateMatrix(Matrix *mat);

#endif