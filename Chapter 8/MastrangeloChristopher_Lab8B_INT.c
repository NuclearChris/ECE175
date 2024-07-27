/*
Pseudo Code
1. Declare variables
2. Declare function quotient
    return a/b
3. Declare function remainder
    while a>b (or a/b > 1)
        a=a-b to keep removing b from a
        when a is no longer greater than b, it can't be divided again
        return a because that's the remainder
3. Scanf to get base and exponent from user
4. call function 'quotient'
5. printf the result
6. call function 'remainder'
7. printf the result
*/

#include <stdio.h>


int i = 0; //loop index
int a;  //scan in first number
int b;  //scan in second number
int qResult; // quotient result
int rResult; // remainder result

// the following function simply divides a by b
int quotient (int a, int b) {
    return a/b;
}

//the following function depletes a by iteratively subtracting b
//When a is no longer greater than b, it can't be divided again
//then we return a, because that's the remainder
int remain (int a, int b) {
    while (a>b) {
        a = a-b;
    }
    return a;
}

int main (void) {
    //Scan in the base and exponent as a & b
    printf("Enter a numerator: \n");
    scanf("%d", &a);
    printf("Enter a divisor: \n");
    scanf("%d", &b);
    //Call the quotient function
    qResult = quotient(a,b);
    //Print the result
    printf("Quotient Result: %d\n", qResult);

    //Call the remainder function
    rResult = remain(a,b);
    printf("Remainder Result: %d\n", rResult);


    }
    

