/*
Pseudo Code:
1. Declare number (width & height), and declare two indices i and j
2. Nested for loop:
        for i<n --> (this gives n rows)
            for j<n --> print # (this gives n columns)
3. add the newline character after each time i<n exits


*/

#include <stdio.h>


int n;
int i;
int j;

int main() {

    // Get input from the user
    printf("Enter the width & height of your square: ");
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf ("#");
        }
        printf("\n");
    }





}