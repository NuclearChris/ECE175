/*
Pseudo Code:
1. Declare string
2. Try to open a file
3. Check it if exists
   If exists 
        fscanf the string
        print the string
   else, error out
4. Close the file
*/

#include <stdio.h>


//Declare string to scan into.
// I think 256 characters is plenty

char string[256];

int main(){
// Open the file
    FILE* myFile = fopen("myFile.txt", "r");
    //Check if it exists
    if (myFile == NULL) {
        printf("Error!  Not able to read input file.\n");
    }
    else {    
        //Read one line
        fgets(string, 256 , myFile);

        //Print the string
        printf("The file's string is: %s", string);

    }
    //close the file
    fclose(myFile);
}