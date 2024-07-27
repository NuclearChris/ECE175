/*
Pseudo Code
1. Declare variables a,b,c for the cube 
   cylRadius & cylHeight for the cylinder
   hemiRadius for the hemisphere
   result to store return values to print in main function
2. Declare double cube()
   scan in sides a,b,c
   return 2*a*c + 2*a*b + 2*b*c
3. Declare double cylinder()
   scan in radius and height
   2*pi*r*h for the shell, 2*pi*r*r where I used acos(-1) for pi
   add a print statement to the function for cylinder only
4. Declare double hemisphere()
   scan in radius
   scan in a selection to calculate volume or surface area
   switch case based on volume or surface area selection
   if volume, do the volume calculation & return volume
   if surface area, do SA calculation & return SA
5. In main()
   Switch case to select which function to call: cube, cylinder, or hemisphere
   In the cube & hemisphere case, add a print statement (cylinder prints in the function itself)
   break

*/

#include <stdio.h>
#include <math.h>

int shape;

double a;  //scan in length a
double b;  //scan in width b
double c;  //scan in height c
double areaCube;

double cylRadius;
double cylHeight;

double hemiRadius;

double Result;



// returns the surface area of a cube, sides a, b, and c
double cube () {
    printf("Enter side length A: \n");
    scanf("%lf", &a);
    printf("Enter side length B: \n");
    scanf("%lf", &b);
    printf("Enter side length C: \n");
    scanf("%lf", &c);
    areaCube = 2*a*b + 2*a*c + 2*b*c;
    return areaCube;
}

// returns the surface area of a cylinder, radius R and height H
double cylinder () {
    printf("Enter the radius R: \n");
    scanf("%lf", &cylRadius);
    printf("Enter the height H: \n");
    scanf("%lf", &cylHeight);
// 2*pi*r^2 (top & bottom) + 2*pi*r*h (cyl shell)
    printf("The surface area of the cylinder is %lf", 2*acos(-1)*cylRadius*(cylRadius+cylHeight));
}

double hemisphere() {
    int hemiCase;
    double hemiResult;
    printf("Enter '1' to calculate volume.\nEnter '2' to calculate area.\n");
    scanf("%d", &hemiCase);
    printf("Enter the radius R: \n");
    scanf("%lf", &hemiRadius);
    switch (hemiCase) {
        case 1:
            hemiResult = 2*acos(-1)*pow(hemiRadius,3)/3;
            printf("The hemisphere volume is: ");
            break;
        case 2:
            hemiResult = 2*acos(-1)*pow(hemiRadius,2);
            printf("The hemisphere surface area is: ");
            break;
    }       
    return hemiResult;
}

int main (void) {
//The user enters an integer to select the shape
    printf("Enter an integer to select a shape:\n1. Cube\n2. Cylinder\n3. Hemisphere\n");
    scanf("%d", &shape);

//The switch case calls a function depending on which shape was selected.
    switch (shape) {
        case 1:
            Result = cube();
            printf("%lf", Result);
            break;
        case 2: 
            Result = cylinder();
            break;
        case 3:
            Result = hemisphere();
            printf("%lf", Result);
            break;
        default:
            break;

    }

    }
    

