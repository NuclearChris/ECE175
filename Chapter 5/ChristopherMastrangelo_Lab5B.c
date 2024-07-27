/*
Pseudo Code:
1. Declare ints for upper and lower bounds, and sum, plus two indices
2. Scanf upper and lower bounds
3. declare int array[] with memory size iUpper-iLower
4. Write a for-loop with bounds iLower to iUpper, and each iteration assign array[i] = i*i+1
5. Write another for-loop to print out each term of the sum
    each iteration, sum += array[i]
6. Once the for-loop ends, print the final sum
*/

#include <stdio.h>
#include <math.h>

int iLower;
int iUpper;
int q;
int i;
int sum = 0;

int main() {

// Scan in upper and lower bounds
    printf("Enter a lower bound of variable i for the sum of terms i*(i+1): ");
    scanf("%d", &iLower);

    printf("Enter an upper bound of variable i for the sum of terms i*(i+1): ");
    scanf("%d", &iUpper);  

// Create an array of size upperBound - lowerBound
   int array[iUpper-iLower];

// Fill the array with terms i*(i+1) but here I used index q instead of i
    for (q=iLower; q<=iUpper; q++) {
        array[q-iLower] = q*(q+1);
        }

// Print out the terms of the sum
    printf("The terms of this sum are: ");
    for (q=iLower; q<=iUpper; q++) {
        if (iUpper-q != 0){
        printf("%d, ", array[q-iLower]);
        }
// For the final term of the sum, don't print the comma       
        else{
        printf("%d", array[q-iLower]);           
        }
// Each iteration of this loop, add the term to the final sum       
        sum += array[q-iLower];
    }
// Print the final sum
    printf("\nThe sum of this array is: %d", sum);


}
