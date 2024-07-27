/*
Pseudo Code:
1. Declare integers
2. Try to open a file
3. Check it if exists
   If exists 
        fscanf three integers
        print the integers
        do some math
        print the roots
   else, error out
4. Close the file
*/

#include <stdio.h>
#include <math.h>

//Declare integers to scan into

int a;
int b;
int c;
// Declare doubles for positive and negative zeros
double posZero;
double negZero;

int main(){
// Open the file
    FILE* myFile = fopen("myFile.txt", "r");
    //Check if it exists
    if (myFile == NULL) {
        printf("Error!  Not able to read input file.\n");
    }
    else {    
        //Read one line at a time
        fscanf(myFile,"%d", &a);
        fscanf(myFile,"%d", &b);
        fscanf(myFile,"%d", &c);
        //Confirm the numbers in the text file
        printf("a = %d\n", a);
        printf("b = %d\n", b);
        printf("c = %d\n", c);
        //Do some math using quadratic formula
        negZero = (-b-sqrt(pow(b,2)-4*a*c))/(2*a);
        posZero = (-b+sqrt(pow(b,2)-4*a*c))/(2*a);
        //print positive and negative roots
        printf("Positive Root: %lf\n", posZero);
        printf("Negative Root: %lf\n", negZero);
    }
    //close the file
    fclose(myFile);
}