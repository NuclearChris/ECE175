/*
Pseudo Code
1. Declare variables
2. Declare function newPow
    use a for loop --> for index less than exponent, multiply a*base
    store result in a, next iteration multiply again by base
    after loop ends, return a
3. Scanf to get base and exponent from user
4. call function newPow
5. printf the result
*/

#include <stdio.h>
#include <math.h>


int i = 0; //loop index
double a;  //scan in base number, later used to store a value in loop iterations
double b;  //scan in exponent
double result; // function result
double base; // equal to the scanned in number (variable a)

// the following function multiplies iterates a=base*a, b iterations
double newPow (double a, double b) {
    base = a;
    for (i=2; i<=b; i++) {
        a = base*a;
    }
    return a;
}

int main () {
    //Scan in the base and exponent as a & b
    printf("Enter your base number: \n");
    scanf("%lf", &a);
    printf("Enter your exponent: \n");
    scanf("%lf", &b);
    //Call the function
    result = newPow(a,b);
    //Print the result
    printf("Result Using UDF: %lf\n", result);
    printf("Result using math.h pow(): %lf\n", pow(a,b));


    }
    

