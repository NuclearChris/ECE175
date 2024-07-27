/*
Pseudo Code:
1. Declare & Scan in variables
2. Declare & Set pointers to the variables
3. Use the pointers to multiply the variables by 10
4. Print the new value of var1 and var2, their memory locations, and the pointer values

*/


#include <stdio.h>

int main() {
    // Declare two double variables
    double var1, var2;

    // Get input from the user
    printf("Enter the first double value (var1): ");
    scanf("%lf", &var1);
    printf("Enter the second double value (var2): ");
    scanf("%lf", &var2);

    // Declare pointers to the double variables
    double *pt1 = &var1;
    double *pt2 = &var2;

    // Multiply the values by 10 using the pointers
    *pt1 *= 10;
    *pt2 *= 10;

    // Print the new values and their addresses
    printf("var1 = %.2f\n", var1);
    printf("var2 = %.2f\n", var2);
    printf("var1 has address %p\n", (void*)&var1);
    printf("var2 has address %p\n", (void*)&var2);

    // Print the values using the pointers
    printf("pt1 has value %.2f\n", *pt1);
    printf("pt2 has value %.2f\n", *pt2);

    return 0;
}