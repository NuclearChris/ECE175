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

    char sandwich1[256];
    char sandwich2[256];

    printf("Enter your favorite sandwich! \n");
    scanf("%s%s", &sandwich1, &sandwich2);
    printf("%s%s is a great sandwich! \n", sandwich1, sandwich2);

    return 0;
}