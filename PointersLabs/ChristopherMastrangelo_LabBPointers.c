/*
Pseudo Code
1. Define function which accepts an int array, and stores the sum of values in int sum
2. while loop which stops at after n iterations, executing sum+=*ptr for each value
3. this function uses pointer addresses, starting at the first address in a given array
   for each iteration, and it increments the pointer address
4. After functions are defined, create main function and test array {1,2,3,4,5}
5. call the function passing the test array as parameter, print the sum
*/

#include <stdio.h>

/* User defined function uses a while loop through each address location, starting with the 
   first of the test array until it reaches the array size n, executing sum+=*ptr each time.
   once the function reaches the i=n, it exits the while loop and returns int sum.
*/
int calculateArraySum(const int* array) {
    const int* ptr = array;
    int sum = 0;
    int n = 5;
    int i = 0;

    while (i<n) {
        printf("Pointer %d has address %p\n", *ptr, (void*)ptr);
        sum+=*ptr;
        ptr++;
        i++;
    }

    return sum;
}


int main() {
    //Create two test strings
    int array[5] = {8, 2, 7, 4, 6};

    //Call the calculateArraySum function, passing parameter array (which returned int sum)
    printf("The sum of the array is %d\n", calculateArraySum(array));


    return 0;
}