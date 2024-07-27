/*
Pseudo Code:
1. Declare Variables
2. Scan in a number
3. For i less than number, divide number by i and check if remainder is 0
4. If remainder is 0, then i is a factor of number --> printf(i) --> sum += i
5. When the loop ends, all factors are printed and sum is printed.
6. If sum == number --> number is a perfect number
7. Else --> number is not a perfect number
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main() {

    int i = 1;
    int r;
    int sum=0;    
    char tryAgain = 'y';

// Allows users to try another number - will ask for tryAgain value at end of loop
    while (tryAgain == 'y') {

    // Declare variables: index i, num to scan in, r for remainder, intialize sum to 0    
        i = 1;
        sum=0;
        int num;

    // Scan in a  number    
        printf("Input a number! \n");

        scanf(" %d", &num);

    /*  Print factors of number:
        If number divided by index i has remainder 0, then it's a factor of number
        printf index i (which is a factor)
        add the factor to variable 'sum'
        increment index by 1
    */
        printf("Factors of %d (excluding itself): ", num);
        while (i<num) {
            r = num % i;
            if (r == 0){
                    printf("%d ", i);
                    sum += i;
                }
            i++;
        }
    // Print the sum, which was calculated in the previous while loop
        printf("\nSum of factors: %d\n", sum);

    // If sum == number, then print 'perfect number'
    // Else, print 'not perfect number'    
        if (sum == num) {
            printf("%d is a perfect number!\n\n", num);
        }
        else {
            printf("%d is not a perfect number.\n\n", num);
        }
// Ask user: Try another number?
        printf("Try another number? \nY or N?\n");
        scanf(" %c", &tryAgain);
//Accept upper or lower case        
        tryAgain = tolower(tryAgain);
//Send termination message
        if (tryAgain == 'n') {
            printf("Terminating Program");
        }
//Send error message
        else if (tryAgain != 'y') {
            printf("Error: You did not enter Y or N - Terminating Program");
        }

    }
}