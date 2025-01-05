#include <stdio.h>
#include <ctype.h>

#define CHARACTERS 26

int main() {
    int c;
    int characterFrequencies[CHARACTERS] = {0};

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) { 
            c = tolower(c);
            characterFrequencies[c - 'a']++;
        }
    }

    printf("Histogram of Character Frequencies:\n");
    for (int i = 0; i < CHARACTERS; i++) { 
        printf("%c: ", 'a' + i);
        for (int j = 0; j < characterFrequencies[i]; j++) {
            printf("|");
        }
        printf(" (%d)\n", characterFrequencies[i]);
    }

    return 0;
}
