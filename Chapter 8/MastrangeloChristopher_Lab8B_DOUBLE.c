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
double a;  //scan in first number
double b;  //scan in second number
double qResult; // quotient result
double rResult; // remainder result

// the following function simply divides a by b
double quotient (double a, double b) {
    return a/b;
}

//the following function depletes a by iteratively subtracting b
//When a is no longer greater than b, it can't be divided again
//then we return a, because that's the remainder
double remainder (double a, double b) {
    while (a/b>1) {
        a = a-b;
    }
    return a;
}

int main (void) {
    //Scan in the base and exponent as a & b
    printf("Enter a numerator: \n");
    scanf("%lf", &a);
    printf("Enter a divisor: \n");
    scanf("%lf", &b);
    //Call the quotient function
    qResult = quotient(a,b);
    //Print the result
    printf("Quotient Result: %lf\n", qResult);

    //Call the remainder function
    rResult = remainder(a,b);
    printf("Remainder Result: %lf\n", rResult);


    }
    

