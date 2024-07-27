#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

/*

!---PseudoCode---!

0. Declare variables, including an array of known vowels, set isVowel to false
1. Enter the letter using getchar()
2. For each letter in vowels[] array, check if letter matches
3. if letter matches an element of vowels[] array, isVowel=true
4. if isVowel=true --> print "letter is a vowel!"; else --> print "not a vowel"

*/


int main() {


//Declare variables

    char letter;
    char vowels[10] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
    int length;
    int i;
    bool isVowel = false;

//Scan in letter
    printf("Enter your letter:\n ");
    letter = getchar();
    //printf("%c\n", letter);
    //printf("%s", vowels);

/*Run a for-loop. For each element in vowels[] compare if letter matches.
  If the letter matches, isVowel=true, else isVowel remains false
  */
    length = sizeof(vowels);
    for (i=0; i < length; i++) {
    //    printf ("%c\n", vowels[i]);
        if (letter == vowels[i]) {
            isVowel = true;
        }
    }

//If isVowel=true --> print "letter is a vowel!";
//else --> print "letter is not a vowel"
    if (isVowel == true) {
        printf("%c is a vowel!", letter);
    }
    else {
        printf("%c is not a vowel.", letter);
    }


    return 0;
}