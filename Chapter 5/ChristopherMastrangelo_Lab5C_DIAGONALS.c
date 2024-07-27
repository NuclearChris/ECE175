/*
Pseudo Code
1. Create & scan in a single matrix, similar to addition/subtraction/multiplication
2. For i=0 i<3 sum the diagonal terms
3. Unsure which is the RIGHT diagonal, so I'll sum both diagonals
*/

#include <stdio.h>

int main() {
    int matrix[3][3];
    int sum = 0;
    int sumStandard = 0;

    // Getting input for the matrix
    printf("Enter the elements of the 3x3 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculating the sum of the right diagonal elements (top right -> bottom left)
    for (int i = 0; i < 3; i++) {
        sum += matrix[i][2 - i];
    }
    // Calculating the sum of the right diagonal elements (top left -> bottom right)
    for (int i = 0; i < 3; i++) {
        sumStandard += matrix[i][i];
    }

    // Printing the result
    printf("The sum of the top-right to bottom-left (RIGHT) diagonal elements is: %d\n", sum);
    printf("The sum of the top-left to bottom-right diagonal elements is: %d\n", sumStandard);

    return 0;
}