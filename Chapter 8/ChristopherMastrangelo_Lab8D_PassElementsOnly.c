/*
Pseudo Code:
1. Define a function that accepts an array as argument
   printf elements two & 3
2. Int Main
3.  Define the array
4.  Call the function, pass the array

*/

#include <stdio.h>

//User defined function that takes array elements as arguments and prints
int arrayFunction (int element1, int element2) {
    printf("Element Two: %d \nElement Three: %d\n", element1, element2);
}


int main() {
//Define array
    int ageArray[4] = {2, 8, 4, 12};
//Call function, pass array elements
    arrayFunction(ageArray[1], ageArray[2]);  

}