/*
Pseudo Code:
1. Declare int a, b, c for equation:
   x^2 - 4
   1*x^2 + 0*x^1 - 4*x^0
   a = 1, b = 0, c = -4
2. Open file with 'read/write' permission
3. IF file doesn't exist, open the file with write permission (creates the file)
   Then fprintf to write a, b, c
4. If file does already exist, ask the user if the want to overwrite
   If they select no, close the file and notify user
   If they select yes, fprintf to write a, b, c
5. Close the file

*/

#include <stdio.h>
//Declare a, b, c
int a = 1;
int b = 0;
int c = -4;
int overWrite;

int main(){
    //Open the file
    FILE* myFile = fopen("myFile.txt", "r+");
    //Check if file exists. If not, then notify user & create then write the file
    if (myFile == NULL) {
        printf("File did not exist, creating & writing new file.\n");
        //create & write file
        FILE* myFile = fopen("myFile.txt", "w");
        fprintf(myFile,"%d\n%d\n%d", a, b, c);
    }
    //If file already existed, notify the user & write the file
    else {
        //Ask user if they want to overwrite the file
        printf("Existing file found. Do you want to overwrite the file?\n");
        printf("Yes: Enter 1\nNo: Enter 0\n");
        scanf("%d", &overWrite);
        //User selected yes if overWrite == 1
        if (overWrite == 1) {
            printf("Overwriting file..");
            fprintf(myFile,"%d\n%d\n%d", a, b, c);
        }
        //If user did not select yes, just close the file
        else if (overWrite == 0) {
            printf("Closing file, did not overwrite..");
        }
        else {
            printf("You did not select 1 or 0.\nClosing file, did not overwrite..");
        }
        //Close the file
        fclose(myFile);
    }

}