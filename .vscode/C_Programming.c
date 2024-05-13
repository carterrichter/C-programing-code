#include<stdio.h>
#include<stdlib.h>

//structure that defines matrices used in further creation of code
typedef struct{
    int rows;
    int columns;
    double **data;     
} Matrix;

//function that dynamically allocates memory based on # of rows/columns
Matrix* createMatrix(int rows, int columns){
    //mat is short for the current matrix being worked on
    Matrix *mat = (Matrix*)malloc(sizeof(Matrix));
    if(mat == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    mat -> rows = rows;
    mat -> columns = columns;

    //Allocating memory for matrix's data
    mat -> data = (double**)malloc(rows * sizeof(double*));
    if (mat -> data == NULL){
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++){
        mat -> data [i] = (double*)malloc(columns * sizeof(double));
        if (mat -> data[i] == NULL){
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }
    return mat;
}


int main(){
    printf("Hello World");
    return 0;
}