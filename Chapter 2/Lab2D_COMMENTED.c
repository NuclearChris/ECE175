#include <stdio.h>
#include <math.h>

/*

!---PseudoCode---!

1. Declare string array
2. Scanf favorite sandwich type
3. Print out favorite sandwich type

*/


int main() {

/*
Here I allocated 256 for memory, since without that value it returns an error
due to undefined array size 
*/

    char sandwich[256];

    printf("Enter your favorite sandwich! \n");
    scanf("%s", &sandwich);
    printf("%s is a great sandwich! \n", sandwich);




    return 0;
}