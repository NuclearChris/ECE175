#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/*

!---PseudoCode---!

0. Declare variables int(age) and bool(ageAdult)
1. Scanf to enter an age
2. If age < 18 then ageAdult = false; else ageAdult = true
3. If ageAdult = true, print "You are an adult"; else print "You are not an adult"

*/


int main() {


//Declare variables

    int age;
    bool ageAdult;
    
//Scan in age
    printf("Enter your age:\n");
    scanf(" %d", &age);

//Determine if adult
    if (age < 18) {
        ageAdult = false;
    }
    else {
        ageAdult = true;
    }

//Print adult or NOT adult
    if (ageAdult == true) {
        printf("According to your age, you are an adult!");
    }
    else {
        printf("According to your age, you are NOT an adult.");
    }
    

    
    return 0;
}