#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void shuffle(char *word) {
    for (int i = strlen(word) - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
}

int main() {
    const char *words[] = {"programming", "engineer", "computer", "data", "science", "algorithm"};
    srand(time(0));
    const char *word = words[rand() % (sizeof(words) / sizeof(words[0]))];
    char scrambled[100];
    strcpy(scrambled, word);
    shuffle(scrambled);

    printf("Scrambled: %s\n", scrambled);

    char guess[100];
    int attempts = 0;
    do {
        printf("Guess: ");
        scanf("%s", guess);
        attempts++;
    } while (strcmp(guess, word) != 0);

    printf("Correct! Attempts: %d\n", attempts);
    return 0;
}
