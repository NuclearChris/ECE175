#include <stdio.h> //header file provides you access to input/output functions (printf scanf)
#include <math.h>

int main()
{
   
    double x = 0;
    double y = 0;
    double z = 0;
    double A;

//Calculate the missing sides
    double H;
    double h;


//Scan in x, y z
    printf("Enter the value of x: \n");
    scanf("%lf", &x); 
    printf("Enter the value of y: \n");
    scanf("%lf", &y);
    printf("Enter the value of z: \n");
    scanf("%lf", &z);

//Calculate the H and h values
    H = sqrt(pow(y,2) - pow(x,2));
    h = sqrt(pow(z,2) - pow(x,2));
    A = x*(h+H);

//Print missing sides, plus the area
    printf("H is \n %lf \n", H);
    printf("h is \n %lf \n", h);
    printf("A is: %lf", A);

    return 0;
}

