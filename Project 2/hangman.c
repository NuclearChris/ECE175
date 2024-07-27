// hangman.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hangman.h"


int main() {
    //initiate the structures 'player' and 'game'
    Player player;
    Hangman game;
    char play_again;
    //call the initializeGame function to reset progress
    initializeGame(&player, &game);
    //select the words -> see hangmanM.h for more details
    selectRandomWords(&game);
    //ask user if they're ready to start
    displayWelcomeMessage();
    printf("Type Y if you are ready to begin: ");
    scanf(" %c", &play_again);

    if (play_again != 'Y' && play_again != 'y') {
        printExitMessage();
        return 0;
    }
    //these set-to-zero statements may not be necessary, but needed them during debugging
    player.wins = 0;
    player.losses = 0;
    //initialize the guessed word to '________' and reset the 'guessed_letters' array
    for (int match = 0; match < NUM_MATCHES; match++) {
        game.attempts_left = MAX_TRIES;
        memset(game.guessed_word, '_', WORD_LENGTH);
        game.guessed_word[WORD_LENGTH] = '\0';
        memset(player.guessed_letters, 0, sizeof(player.guessed_letters));
        player.attempts = 0;
        /*
        The code below was used to be sure that the program initialized properly

        printf("\nAttempts left: %d \n", game.attempts_left);
        printf("You've won %d rounds!\n", player.wins);
        printf("You've lost %d rounds.\n\n", player.losses);
 
        //For testing, to be commented out later
        printf("Match Word: %s\n\n", game.random_words[match]);

        */


//Displays the user's progress toward the word
        printf("Your word progress: %s\n", game.guessed_word);
        printHangman(game.attempts_left);
//User interaction -> while loop for 6 attempts
//Ask the user to input a letter
        while (game.attempts_left > 0) {
            char guess;
            printf("Guess a letter: ");
            scanf(" %c", &guess);
//Check the user's answer to see if it matches. 
//To know more about this function, see hangmanM.h
            if (checkUserAnswer(guess, game.random_words[match])) {
                printf("You are right!\n");
                printf("Attempts left: %d \n\n", game.attempts_left);
            } else {
                printf("You are wrong, try again\n");
                //if the user doesn't match the value, decrease attempts_left by 1.
                game.attempts_left--;
                printf("Attempts left: %d \n\n", game.attempts_left);
            }

            player.guessed_letters[player.attempts++] = guess;
            //update the word to be shown to the user
            revealWord(game.random_words[match], player.guessed_letters, game.guessed_word);
            //show to word to the user
            printf("Current word: %s\n", game.guessed_word);
//using the 'isWordGuessed' function, check to see if the user has solved it
            if (isWordGuessed(game.random_words[match], game.guessed_word)) {
                printf("Congratulations! You've guessed the word!\n");
                player.wins++;
                printf("You've won %d rounds!\n", player.wins);
                printf("You've lost %d rounds.\n\n", player.losses);
                break;
            }
//If the game.attempts_left value goes to zero, then the user is out of tries and loses
            if (game.attempts_left == 0) {
                printf("You lost this round. The word was: %s\n", game.random_words[match]);
                player.losses++;
                printf("You've won %d round!\n", player.wins);
                printf("You've lost %d rounds.\n\n", player.losses);
            }
        }
//if player wins 2 matches, they win the game
        if (player.wins == 2) {
            printf("Congratulations! You've won the game!\n");
            break;
//if player loses 2 matches, they lose the game
        } else if (player.losses == 2) {
            printf("Sorry, you've lost the game. Better luck next time!\n");
            break;
        }
    }
//exit the game -> 'thanks for playing'
    printExitMessage();
    return 0;
}
