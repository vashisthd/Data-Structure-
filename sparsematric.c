#include <stdio.h>
#define max 10
int isSparseMatrix(int matrix[max][max], int rows, int cols) {
    int nonZeroCount = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }
    if (nonZeroCount < (rows * cols) / 2) {
        return 1; // condition for Sparse matrix
    }
    else {
        return 0; 
    }
}

int main() {
    int rows, cols;
    int matrix[max][max];
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    if (isSparseMatrix(matrix, rows, cols)) {
        printf("The matrix is sparse.\n");
    } 
    else{
        printf("The matrix is not sparse.\n");
    }
    return 0;
}
