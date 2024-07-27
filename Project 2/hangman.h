// hangman.h
#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdbool.h>

#define WORD_LENGTH 8
#define NUM_WORDS 50
#define NUM_MATCHES 3
#define MAX_TRIES 6

//Define the player progress structure
typedef struct {
    char guessed_letters[26];
    int wins;
    int losses;
    int attempts;
} Player;

//Define the game structure, where we store random word, guessed word, attempts
typedef struct {
    char guessed_word[WORD_LENGTH + 1];
    int attempts_left;
    char random_words[NUM_MATCHES][WORD_LENGTH + 1];
} Hangman;


//Welcome!
void displayWelcomeMessage(void) {
    printf("Let's play Hangman!\n");
}

//Checks if the user's input letter is within the random word
bool checkUserAnswer(char letter, const char* word) {
    return strchr(word, letter) != NULL;
}

//Prints the hangman using ASCII art method depending on how many attempts are left
void printHangman(int attempts_left) {
    //print regardless of attempts_left
    printf("_______\n");
    //this conditional print statement basically says -> if attempts left <= 5, print the head 'O'
    printf("|     %s\n", attempts_left <= 5 ? "O" : " ");
    //if attempts left..... print the body parts
    printf("|    %s%s%s\n", attempts_left <= 4 ? "/" : " ", attempts_left <= 3 ? "|" : " ", attempts_left <= 2 ? "\\" : " ");
    printf("|    %s %s\n", attempts_left <= 1 ? "/" : " ", attempts_left <= 0 ? "\\" : " ");
    printf("|\n");
    printf("_______\n");
}

//Prints this message when you win or lose
void printExitMessage(void) {
    printf("Thanks for playing Hangman! Goodbye!\n");
}

//Initializes the game using pointers for player and game
//initializing game makes wins, losses, & attempts all zero
void initializeGame(Player* player, Hangman* game) {
    player->wins = 0;
    player->losses = 0;
    player->attempts = 0;
    memset(player->guessed_letters, 0, sizeof(player->guessed_letters));
    //initializing game also resets attempts_left to Max tries
    game->attempts_left = MAX_TRIES;
    //initializing game also resets the guessed word
    memset(game->guessed_word, '_', WORD_LENGTH);
    game->guessed_word[WORD_LENGTH] = '\0';
}

//Selects random words from the given file
void selectRandomWords(Hangman* game) {
    //double array has a character array(string) dimension for word length, and also stores all the words
    char words[NUM_WORDS][WORD_LENGTH + 1];
    int i = 0;

    // Open file and read words
    FILE* file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error opening words.txt\n");
        return;
    }
//copy words to array, as long as the line isn't an empty string
//for some reason I had issues with empty lines.. so implemented the if(strlen(line) > 0) part to fix that
    while (i < NUM_WORDS) {
        char line[WORD_LENGTH + 1];
        if (fgets(line, sizeof(line), file) != NULL) {
            line[strcspn(line, "\n")] = '\0'; // Remove newline character
            if (strlen(line) > 0) { // Check if line is not empty
                strcpy(words[i], line);
                /*Debug statement to print each word read from file
                printf("Read word: %s\n", words[i]);
                */
                i++;
                
            }
        } else {
            break; // Exit loop if fgets fails (e.g., end of file)
        }
    }
    //close the file
    fclose(file);
//Random number generator to select 3 words from the array of possible words
    srand(time(NULL));
    for (i = 0; i < NUM_MATCHES; i++) {
        int random_index = rand() % NUM_WORDS;
        strcpy(game->random_words[i], words[random_index]);
        // Debug statement to print each selected word
        // printf("Selected random word for match %d: %s\n", i, game->random_words[i]);
    }
}
//This segment modifies the revealed word to show any guessed letters that match the random word
void revealWord(const char* word, const char* guessed_letters, char* revealed_word) {
    //for each character in random word, check if any guessed letters match
    for (int i = 0; i < WORD_LENGTH; i++) {
        //if the match, replace the _ character with the letter
        if (strchr(guessed_letters, word[i])) {
            revealed_word[i] = word[i];
        } else {
            revealed_word[i] = '_';
        }
    }
    revealed_word[WORD_LENGTH] = '\0';
}

//check to see if the user has won or not
bool isWordGuessed(const char* word, const char* revealed_word) {
    return strcmp(word, revealed_word) == 0;
}


#endif
