#include <math.h>
#include <stdio.h>

int main(){

    int num;        // user input
    int x;          // loop index
    int multResult; // multiplication of num*x

// User input
    printf("Enter an integer!\n");
    scanf(" %d", &num);

// Do-while x<=10
// Multiply number and x (index) to construct multipication table

    do {
        multResult = num*x;
        printf("\n%d x %d = %d", num, x, multResult);
        x++; //increment x by 1

    } while (x<=10);
}