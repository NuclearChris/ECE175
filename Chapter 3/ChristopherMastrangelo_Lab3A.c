#include <stdio.h>
#include <math.h>

/*

!---PseudoCode---!

1. Scanf in a string
2. Divide by 2, use modulus operator to know if remainder is zero
3. if variable % 2 = 0, then printf "%d is even, variable"
4. else, print odd


*/


int main() {


//Declare variable
    int number;
//Scan in number
    printf("Enter a number! \n");
    scanf("%d", &number);

//Check if even
    if (number % 2 == 0) {
        printf("%d is even!", number);
    }
//else print "odd"
    else {
        printf("%d is odd!", number);
    }




    return 0;
}