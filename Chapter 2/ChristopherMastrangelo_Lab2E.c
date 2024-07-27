#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*

!---PseudoCode---!

1. Enter number of times you want to roll dice (number)
2. for (i=1; i<number; i++) roll dice
3. print d1, d2, sum

*/


int main() {


    char number;
    int i;
    int d1;
    int d2;
    int sum;
//Scan in number of times to roll
    printf("Enter the number of times to roll dice! \n");
    scanf(" %d", &number);
    printf("we'll roll %d times! \n\n", number);

//For number of times to roll, generate random 1-6 for d1 and d2
//sum the values together
//then print Roll, D1, D2, Sum each time
    for (i=1; i<=number; i++){

        d1 = rand() % 7;
        d2 = rand() % 7;
        sum = d1+d2;
        printf("Roll:%d, D1:%d, D2:%d, Sum:%d \n", i, d1, d2, sum);
    }

    return 0;
}