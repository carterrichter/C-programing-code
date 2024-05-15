//includes the header file so the definition of a Matrix structure and declarations of all functions can be accessed
#include "C_Programming.h"

//library header for input/output
#include <stdio.h>

//library header for memory allocation
#include <stdlib.h>

/*function used to take in two arguments (rows and columns), and returnsa pointer to a matrix structure
  as well as that this function will allocate memory to be used for a matrix and data of the matrix*/
Matrix* createMatrix(int rows, int columns) {
    //allocates memory for Matrix struct, and returns a pointer to said allocated memory named mat
    Matrix *mat = (Matrix*)malloc(sizeof(Matrix));

    //checks if the malloc failed and exits if true
    if (mat == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    
    //assigns the rows and columns of the matrix
    mat->rows = rows;
    mat->columns = columns;
    
    // Allocates memory for array of pointers, each pointing to a different row
    mat->data = (double**)malloc(rows * sizeof(double*));
    //checks again if malloc failed or not
    if (mat->data == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    
    //allocates memory for each row based off values from columns. Check for failure within each allocation
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (double*)malloc(columns * sizeof(double));
        if (mat->data[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }
    //returns the concrete pointer to the newly created matrix
    return mat;
}

//function created to fill out a matrix with 0's given the pointer of a Matrix
//main use for this function is to bring back the matrices to 0's and make sure I'm starting from a neutral beginning 
void initializeMatrixZeros(Matrix *mat) {
    //quick nested loop that replaces the data of each element of a matrix with 0's
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->columns; j++) {
            mat->data[i][j] = 0.0;
        }
    }
}

//function created to iterate through a matrix given its pointer, and print its elements up to 2 decimal places (for simplicity) with a new line between each row
void printMatrix(Matrix *mat) {
    //nested loop that finds each element of the matrix and prints it out
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->columns; j++) {
            printf("%.2f\t", mat->data[i][j]);
        }
        //creates a new line between rows
        printf("\n");
    }
}

//function to call when all is said and done to free the allocated memory for the matrices given their pointer
void freeMatrix(Matrix *mat) {
    //freeing each row of the matrix
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    //freeing the memory used for the row pointers
    free(mat->data);
    //freeing the memory used for the pointer of the matrix
    free(mat); 
}

void setMatrixData(Matrix *mat, double data[][mat->columns]) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->columns; j++) {
            mat->data[i][j] = data[i][j];
        }
    }
}

int getDimensions(Matrix *mat){
    //check for if mat is viable
    if (mat == NULL){
        fprintf(stderr, "Error: Matrix not found\n");
        return -1;
    }
    else{
        printf("Dimensions of specified Matrix: %d rows x %d columns\n", mat->rows, mat->columns);
        return mat -> rows, mat -> columns;
    }
}

double getMatrixElement(Matrix *mat, int row, int column){
    //check for if mat is viable
    if (mat == NULL){
        fprintf(stderr, "Error: Matrix not found\n");
        return -1;
    }
    if (row >= 0 && row < mat->rows && column >= 0 && column < mat->columns){
        printf("Element at specified location of specified matrix: %.2f\n", mat->data[row][column]);
        return mat->data[row][column];
    } else{
        fprintf(stderr, "Error: Chosen location out of bounds (row = %d, column = %d)", row, column);
        return -1;
    }
}

void setMatrixElement(Matrix *mat, int row, int column, double value){
    if(mat == NULL){
        fprintf(stderr, "Error: Matrix not found\n");
    }
    if (row >= 0 && row < mat->rows && column >= 0 && column < mat->columns){
        printf("*Changing specified element*\n");
        printf("****************************\n");
        mat->data[row][column] = value;
    }else{
        fprintf(stderr, "Error: Position not found\n");
    }
}

void getMatrixRow(Matrix *mat, int row) {
    if(mat == NULL || row < 0 || row >= mat->rows){
        fprintf(stderr, "Error: Argument error");
    }
    for(int j = 0; j < mat->columns; j++){
        printf("%.2f\t", mat->data[row][j]);
    }
    printf("\n");
}

void getMatrixColumn(Matrix *mat, int column){
    if(mat == NULL || column < 0 || column >= mat->columns){
        fprintf(stderr, "Error: Argument error");
    }
    for(int i = 0; i < mat->rows; i++){
        printf("%.2f\n", mat->data[i][column]);
    }
    printf("\n");
}

void setMatrixRow(Matrix *mat, int row, double values[]){
    if(mat == NULL || row < 0 || row >= mat->rows){
        fprintf(stderr,"Error: Argument error\n");
    }
    printf("New row down below\n");
    for(int j = 0; j < mat->columns; j++){
        mat->data[row][j] = values[j];
        printf("%.2f\t", mat->data[row][j]);
    }
}
void setMatrixColumn(Matrix *mat, int column, double values[]){
    if(mat == NULL || column < 0 || column >= mat->columns){
        fprintf(stderr, "Error: Argument error");
    }
    printf("New row down below\n");
    for(int i = 0; i < mat->rows; i++){
        mat->data[i][column] = values[i];
        printf("%.2f\n", mat->data[i][column]);
    }
}

Matrix* createSubset(Matrix *mat, int startRow, int endRow, int startColumn, int endColumn){
    if (mat == NULL){
        fprintf(stderr, "Error: Matrix not found");
        return NULL;
    }
    if (startRow < 0 || startRow >= mat->rows || endRow < startRow || endRow >= mat->rows ||
        startColumn < 0 || startColumn >= mat->columns || endColumn < startColumn || endColumn >= mat->columns){
            fprintf(stderr, "Error: arguments invalid");
            return NULL;
    }

    int newRows = endRow - startRow + 1;
    int newColumns = endColumn - startColumn + 1;
    Matrix *subMatrix = createMatrix(newRows, newColumns);
    for(int i = startRow, ni = 0; i <= endRow; i++, ni++){
        for(int j = startColumn, nj = 0; j <= endColumn; j++, nj++){
            subMatrix->data[ni][nj] = mat->data[i][j];
        }
    }
    return subMatrix;
}

//nonfunctional and I do not know how to fix...
void setSubset(Matrix *dest, int startRow, int startColumn, Matrix *src){
    if (!dest || !src){
        fprintf(stderr, "Error: Wrong pointer");
        return;
    }
    if(startRow < 0 || startRow>= dest->rows || startColumn < 0 || startColumn >= dest->columns){
        fprintf(stderr, "Error: Start position out of bounds");
        return;
    }
    if(startRow + src->rows > dest->rows || startColumn + src->columns > dest->columns){
        fprintf(stderr, "Error: Source Matrix does not fit in destination matrix");
        return;
    }
    for(int i = 0; i < src->rows; i++){
        for(int j = 0; j < src->columns; j++){
            dest->data[startRow + i][startColumn + 1] = src->data[i][j];
        }
    }
}

void resizeMatrix(Matrix **mat, int newRows, int newColumns){
    if(!mat || !(*mat)){
        fprintf(stderr, "Error: Wrong pointer provided");
        return;
    }
    Matrix *newMat = createMatrix(newRows, newColumns);
    if(!newMat){
        fprintf(stderr, "Memory allocation failed");
        return;
    }
    
    int minRows = (newRows < (*mat)->rows) ? newRows : (*mat)->rows;
    int minColumns = (newColumns < (*mat)->columns) ? newColumns : (*mat)->columns;

    for(int i = 0; i < minRows; i++){
        for(int j = 0; j < minColumns; j++){
            newMat->data[i][j] = (*mat)->data[i][j];
        }
    }
    freeMatrix(*mat);
    *mat = newMat;
}

Matrix* addMatrices(const Matrix *mat1, const Matrix *mat2){
    if(!mat1 || !mat2){
        fprintf(stderr, "Error: Wrong Pointers");
        return NULL;
    }
    if(mat1->rows != mat2->rows || mat1->columns != mat2->columns){
        fprintf(stderr, "Error: not matching dimensions");
        return NULL;
    }
    Matrix *result = createMatrix(mat1->rows, mat1->columns);
    if(!result){
        fprintf(stderr, "Error: Memory allocation failed");
        return NULL;
    }
    for(int i = 0; i < mat1->rows; i++){
        for(int j = 0; j < mat1->columns; j++){
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return result;
}

Matrix* subMatrices(const Matrix *mat1, const Matrix *mat2){
    if(!mat1 || !mat2){
        fprintf(stderr, "Error: Wrong Pointers");
        return NULL;
    }
    if(mat1->rows != mat2->rows || mat1->columns != mat2->columns){
        fprintf(stderr, "Error: not matching dimensions");
        return NULL;
    }
    Matrix *result = createMatrix(mat1->rows, mat1->columns);
    if(!result){
        fprintf(stderr, "Error: Memory allocation failed");
        return NULL;
    }
    for(int i = 0; i < mat1->rows; i++){
        for(int j = 0; j < mat1->columns; j++){
            result->data[i][j] = mat1->data[i][j] - mat2->data[i][j];
        }
    }
    return result;
}

Matrix* multiplyMatrices(const Matrix *mat1, const Matrix *mat2){
    if (!mat1 || !mat2) {
        fprintf(stderr, "Error: One or more matrix pointers are NULL.\n");
        return NULL;
    }

    if (mat1->columns != mat2->rows) {
        fprintf(stderr, "Error: Incompatible dimensions for matrix multiplication.\n");
        return NULL;
    }

    Matrix *result = createMatrix(mat1->rows, mat2->columns);
    if (!result) {
        fprintf(stderr, "Failed to allocate memory for the result matrix.\n");
        return NULL;
    }

    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
            result->data[i][j] = 0; // Initialize result matrix element
            for (int k = 0; k < mat1->columns; k++) { // or use mat2->rows
                result->data[i][j] += mat1->data[i][k] * mat2->data[k][j];
            }
        }
    }

    return result;
}