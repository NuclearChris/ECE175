#include <stdio.h>
#include <math.h>
#include <string.h>

/*

!---PseudoCode---!

0. Declare variables
1. Scanf to select an operation. +  -  *  /
2. Switch statement to print out what the user selected
3. Scanf to take in two numbers (floating point)
4. Switch statement to perform the operation on these numbers
5. Print answer

*/


int main() {


//Declare variables

    double number1;
    double number2;
    double answer;
    char operation;
    
//Scan in operation type
    printf("Enter your operation type: \n Multiply \n Divide \n Add \n Subtract \n\n");
    scanf("%s", &operation);
    printf("%s\n", operation);

/*
//This switch statement just prints out the user's selection.
    switch (operation) {
        case "Add":
            printf("You've selected addition!\n");
            break;
        case "Subtract":
            printf("You've selected subtraction!\n");
            break;
        case "Multiply":
            printf("You've selected multiplication!\n");
            break;
        case "Divide":
            printf("You've selected division!\n");
            break;
        default:
            printf("You did not select a supported operation.\n");
            break;
    }

 //Scan in two numbers to perform operation on   
    printf("Enter two numbers to perform the operation on.\nEnter your first number:\n");
    scanf("%lf", &number1);
    printf("Enter your second number:\n");
    scanf("%lf", &number2);

//This switch statement performs the mathematical operation
    switch (operation) {
        case '+':
            answer = number1+number2;
            break;
        case '-':
            answer = number1-number2;
            break;
        case '*':
            answer = number1*number2;
            break;
        case '/':
            answer = number1/number2;
            break;
        default:
            break;
    }

//Print out the answer
    printf("The answer is: %.3lf \n", answer);
*/
    return 0;
}