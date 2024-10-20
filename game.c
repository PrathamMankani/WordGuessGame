#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two characters
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Function to shuffle the letters of a word (scramble)
void shuffleWord(char *word) {
    int len = strlen(word);
    for (int i = len - 1; i > 0; i--) {
        // Generate a random index
        int j = rand() % (i + 1);
        // Swap the characters at i and j
        swap(&word[i], &word[j]);
    }
}

int main() {
    // Predefined list of words
    const char *wordList[] = {"programming", "engineer", "computer", "data", "science", "algorithm"};
    int wordCount = sizeof(wordList) / sizeof(wordList[0]);
    
    // Initialize random number generator
    srand(time(0));

    // Pick a random word from the list
    int randomIndex = rand() % wordCount;
    const char *selectedWord = wordList[randomIndex];
    
    // Create a copy of the selected word to scramble it
    char scrambledWord[100];
    strcpy(scrambledWord, selectedWord);
    
    // Scramble the selected word
    shuffleWord(scrambledWord);

    printf("Welcome to the Word Scramble Game!\n");
    printf("Here is your scrambled word: %s\n", scrambledWord);

    char guess[100];
    int attempts = 0;

    // Allow the player to guess the word
    while (1) {
        printf("Enter your guess: ");
        scanf("%s", guess);
        attempts++;

        // Check if the guessed word matches the original word
        if (strcmp(guess, selectedWord) == 0) {
            printf("Congratulations! You guessed the word correctly in %d attempts.\n", attempts);
            break;
        } else {
            printf("Incorrect guess. Try again!\n");
        }
    }

    return 0;
}
