/*
Pseudo Code
1. Nested for-loop to scan in elements of matrix 1
2. Nested for-loop to scan in elements of matrix 2
3. Nested for-loop to subtract M2 from M1
4. Nested for-loop to print elements
*/

#include <stdio.h>

int main() {
    int matrix1[3][3], matrix2[3][3], result[3][3];

    // Getting input for the first matrix
    printf("Enter the elements of the first 3x3 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Getting input for the second matrix
    printf("Enter the elements of the second 3x3 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Subtract Matrix 2 from Matrix 1
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    // Printing the result
    printf("The resulting matrix after addition is:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}