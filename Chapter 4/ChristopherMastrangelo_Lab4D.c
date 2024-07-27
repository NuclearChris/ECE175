/*
Pseudo Code:
1. Declare number and sum
2. Scan in number
3. Add functionality for negative or positive numbers
4. Add variables from right to left --> use number % 10 to get the right-most digit
5. Add the right-most digit to sum, then number /= 10 to erase the right-more digit
6. Put steps 4 & 5 into a while loop, continue while number > 0
7. After the loop exits, print the sum 
*/

#include <stdio.h>


int number;
int sum = 0;

int main() {

    // Get input from the user
    printf("Enter an integer: ");
    scanf("%d", &number);

    // Ensure the number is positive
    if (number < 0) {
        number = -number;
    }

    // Calculate the sum of the digits
    while (number > 0) {
        // the mod operator gives us the right-most digit
        sum += number % 10;
        // after adding the right-most digit to 'sum', we erase it with /=10
        number /= 10;
    }

    // Print the result
    printf("The sum is: %d\n", sum);
}