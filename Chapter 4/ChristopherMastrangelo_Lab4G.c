/*
Pseudo Code
1. Declare two player name strings, two play choice integers, int rounds, and a loop index
2. Scan in player names, and number 'rounds'
3. For each round, rand() % 3 = players choices
4. Print player choices
5. Use && AND statements to determine the winner in each case
    (use IF statements since SWITCH is not specified in instructions)

*/

#include <stdio.h>
#include <stdlib.h>

char player1[64];
char player2[64];
int player1Choice;
int player2Choice;
int rounds;
int i;

int main() {

// Scan in players' names
    printf("Enter the name of player 1: ");
    scanf("%s", player1);
    printf("Enter the name of player 2: ");
    scanf("%s", player2);

// Scan in number of rounds
    printf("How many rounds should be simulated? ");
    scanf("%d", &rounds);
    printf("\n\n");

//For each round --> Random choices for each player
    for (i=1; i <= rounds; i++) {
        player1Choice = rand() % 3;
        player2Choice = rand() % 3;
        printf("%s: %d  &  %s: %d \n", player1, player1Choice, player2, player2Choice);

    //Use AND logic to determine the winner in each possible pair of outcomes
        if (player1Choice == 0 && player2Choice == 0)
            printf("Tie! Both chose Rock.\n\n");
        if (player1Choice == 1 && player2Choice == 1)
            printf("Tie! Both chose Paper.\n\n");        
        if (player1Choice == 2 && player2Choice == 2)
            printf("Tie! Both chose Scissors.\n\n");
        if (player1Choice == 0 && player2Choice == 1)
            printf("%s wins! Paper covers rock.\n\n", player2);
        if (player1Choice == 1 && player2Choice == 2)
            printf("%s wins! Scissors cut paper.\n\n", player2);   
        if (player1Choice == 2 && player2Choice == 0)
            printf("%s wins! Rock smashes scissors.\n\n", player2);  
        if (player1Choice == 1 && player2Choice == 0)
            printf("%s wins! Paper covers rock.\n\n", player1);
        if (player1Choice == 2 && player2Choice == 1)
            printf("%s wins! Scissors cut paper.\n\n", player1);   
        if (player1Choice == 0 && player2Choice == 2)
            printf("%s wins! Rock smashes scissors.\n\n", player1);          
    }




}