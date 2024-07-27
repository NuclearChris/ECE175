/*
1. Define char input, the variable where we store the user input
2. ask user for input, scanf to variable 'input'
3. if isalpha(input)  --> letter --> print "input is letter"
4. if isdigit(input)  --> number --> print "input is number"

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main () {
    char input;
//Scan input
    printf("Input a single character or single digit! \n");
    scanf("%c", &input);
 
//Check is char input is a letter
    if (isalpha(input)) {
        printf("Your input is a letter");
    }
//Check is char input is a number
    if (isdigit(input)) {
        printf("Your input is a number");
    }
}