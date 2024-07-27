#include <stdio.h>
#include <math.h>

/*

!---PseudoCode---!

Print the word "Cat"

1. Declare variables; first, second third and assign ASCII numbers for letters C a t
2. printf all three variables

*/


int main() {

    char first = 67;
    char second = 97;
    char third = 116;

    printf("The word is: %c%c%c \n", first, second, third);

    char C = (int)'C';
    char a = (int)'a';
    char t = (int)'t';

    printf("The ASCII values of C, a, t are: \n %d \n %d\n %d\n", C, a, t);


    return 0;
}