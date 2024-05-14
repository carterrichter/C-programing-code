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
    mat -> rows = rows;
    mat -> columns = columns;
    
    // Allocates memory for array of pointers, each pointing to a different row
    mat -> data = (double**)malloc(rows * sizeof(double*));
    //checks again if malloc failed or not
    if (mat -> data == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    
    //allocates memory for each row based off values from columns. Check for failure within each allocation
    for (int i = 0; i < rows; i++) {
        mat -> data[i] = (double*)malloc(columns * sizeof(double));
        if (mat -> data[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }
    //returns the concrete pointer to the newly created matrix
    return mat;
}

//function created to fill out a matrix with 0's given the pointer of a Matrix
void initializeMatrixZeros(Matrix *mat) {
    //quick nested loop that replaces the data of each element of a matrix with 0's
    for (int i = 0; i < mat -> rows; i++) {
        for (int j = 0; j < mat -> columns; j++) {
            mat->data[i][j] = 0.0;
        }
    }
}

//function created to iterate through a matrix given its pointer, and print its elements up to 2 decimal places (for simplicity) with a new line between each row
void printMatrix(Matrix *mat) {
    //nested loop that finds each element of the matrix and prints it out
    for (int i = 0; i < mat -> rows; i++) {
        for (int j = 0; j < mat -> columns; j++) {
            printf("%.2f\t", mat -> data[i][j]);
        }
        //creates a new line between rows
        printf("\n");
    }
}

//function to call when all is said and done to free the allocated memory for the matrices given their pointer
void freeMatrix(Matrix *mat) {
    //freeing each row of the matrix
    for (int i = 0; i < mat -> rows; i++) {
        free(mat -> data[i]);
    }
    //freeing the memory used for the row pointers
    free(mat -> data);
    //freeing the memory used for the pointer of the matrix
    free(mat); 
}