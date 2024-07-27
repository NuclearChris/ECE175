#include <stdio.h>
#include <math.h>

/*

!---PseudoCode---!

1. Declare variables
2. radius
    print out to be sure
3. Print power(radius,2)*pi --- This is the area
4. Print 2*pi*radius ---------- This is the circumference
5. Print 2*radius ------------- This is the diameter
*/


int main() {

    double radius;
    double area;
    double circumference;
    double pi = acos(-1);

// Scan in radius

    printf("Enter the radius: \n");
    scanf("%lf", &radius);

// Calculations are within the print statements

    printf("The radius is: %lf \n", radius);
    printf("The area is: %.2f \n", pow(radius,2)*pi);   
    printf("The circumference is %.2f \n", radius*2*pi);
    printf("The diameter is: %.2f \n", 2*radius);



    return 0;
}