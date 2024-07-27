/*
1. Define str1 and str2
2. Printf str1 and str2
3. printf entire string, using strcat() from string.h
*/

#include <stdio.h>
#include <string.h>

int main (){
    char str1[] = {"My name "};
    char str2[] = {"is Christopher"};
    char string[256];

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("Entire String: %s", strcat(str1, str2));

}