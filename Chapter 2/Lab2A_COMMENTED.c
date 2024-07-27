#include <stdio.h>
#include <math.h>

/*

!---PseudoCode---!

1. Declare variables
2. Scanf hours & weeks
    print out to be sure
3. Multiply hours*weeks*rate for annual salary
4. Divide annual by 12 for monthly
*/


int main() {

    int w = 0;
    int h = 0 ;
    double salary = 0;
    double rate = 15.75;

//  Scan in variables
    printf("Enter the number of hours worked, per week: \n");
    scanf("%d", &h);
    printf("Enter the number of weeks worked, per year: \n");
    scanf("%d", &w);

// Print out variables to be sure that scanf worked

    printf("Hours: %d \n", h);
    printf("Weeks: %d \n", w);

//Calculate salaries, and print out

    salary = h*w*rate;
    printf("Annual Salary: $%.2f \n", salary);
    printf("Monthly Salary: $%.2f \n", salary/12);
}