/*
Pseudo Code:
1. Define a function that accepts an array as argument
   For each element of the array, sum += array[i]
2. Int Main
3.  Define the array of doubles
4.  Call the function, pass the array
5.  print the sum returned by the function inside Main

*/

#include <stdio.h>

//User defined function that takes an array of doubles and sums elements
double arrayFunction (double array[]) {
    int i = 0;
    double sum = 0;
    printf("The array of doubles: ");
    for (i=0; i<6; i++) {
        printf("%.1lf ", array[i]);
        sum += array[i];
    }
    printf("\n");
    return sum;
}


int main() {
//Define array
    double ageArray[6] = {23.4, 55, 22.6, 3, 40.5, 18};

//Call function, pass array
    double arraySum = arrayFunction(ageArray);  
//Print the sum
    printf("The sum of the array is: %.1lf", arraySum);

}