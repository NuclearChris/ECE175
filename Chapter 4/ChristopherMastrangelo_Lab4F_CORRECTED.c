/*
Pseudo Code:
1. Declare n, and declare two indices i and j, plus an numberInstance & numberTotal(sum)
2. Nested for loop:
        for j<n --> (this determines the number of terms to sum)
            for i<=n --> print # (this loop provides a number, composed of of n-j 9's)
            add this number to the total sum (instanceTotal)
3. For some reason, the test case of Input:0 is supposed to return "No Output" instead of the sum "0"
    add an If statement --> if 0, output "no output", otherwise output the sum


*/

#include <stdio.h>
#include <math.h>

int i;
int j;
int n;
int numberInstance = 0;
int numberTotal = 0;

int main() {

    // Get input from the user
    printf("Enter the amount of digits for your number of repetitive 9's: ");
    scanf("%d", &n);

    for (j=0; j<n; j++) {
        numberInstance = 0;
        for (i=1; i<=n; i++) {
            numberInstance += 9*pow(10, n-(i+j));

        }
        numberTotal += numberInstance;
        if (n-j ==1) {
            printf("%d ", numberInstance);
        }
        else {
            printf("%d + ", numberInstance);
        }
    }

    if (n == 0) {
        printf("You entered zero --> No Output");
    }

    else{
        printf("= %d", numberTotal);
    }




}