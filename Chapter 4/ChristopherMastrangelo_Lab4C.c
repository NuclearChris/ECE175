/*
Pseduo Code:
1. Initialize sum to zero. Declare variable x.
2. for each iteration, 1 to 10, add the value of the term 3x-7 to 'sum'
3. print 'sum' variable
*/

#include <math.h>
#include <stdio.h>

int main() {
//Initialize sum to zero
    int x;
    int sum = 0;

//for each iteration starting at x=1 and ending at x=10, add the result to sum 
    for (x=1; x<=10; x++) {
        sum += 3*x-7;
    }
//print sum
    printf("\nThe total sum is: %d", sum);
}