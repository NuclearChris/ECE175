/*
Pseudo Code:
1. Declare an array[4] (size 5, index 0-4)
2. Write a for-loop which assigns integers to array[i]
3. Write a for-loop which prints out integers from array[i]
4. Write a for-loop which prints out integers in reverse, using array[4-i]

*/

#include <stdio.h>
#include <math.h>

int i;
int array[4];

int main () {

//Start filling the array, one number at a time
    for (i=0; i<=4; i++) {
        printf("Enter an integer to your array, at index %d, or position %d.\n", i, i+1);
        scanf("%d", &array[i]);
    }
// Print out the array of numbers in normal format
    printf("\nYour entered array: ");
    for (i=0; i<=4; i++) {
// if i==4 (the final number), don't print the comma
        if (i==4){
        printf("%d", array[(i)]);
        }
// for all terms except the last one, print a comma
        else{
        printf("%d, ", array[(i)]);        
        }
    }

// Print the terms in reverse by using array[4-i]
    printf("\nYour reversed array: ");
    for (i=0; i<=4; i++) {
// Again, if i==4 then don't print the comma
        if (i==4){
        printf("%d", array[(4-i)]);
        }
// Again, for all terms except the last one, print a comma
        else{
        printf("%d, ", array[(4-i)]);        
        }
    }
}