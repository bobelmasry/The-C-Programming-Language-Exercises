#include <stdio.h>
#include <ctype.h>

#define MAX_WORDS 100

int main() {
    int c, currentWordLength = 0, wordCount = 0;
    int wordLengths[MAX_WORDS] = {0};

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            currentWordLength++;
        } else if (currentWordLength > 0) {
            if (wordCount < MAX_WORDS) {
                wordLengths[wordCount++] = currentWordLength;
            }
            currentWordLength = 0;
        }
    }

    printf("\nHistogram of Word Lengths (Horizontal):\n");
    for (int i = 0; i < wordCount; i++) {
        printf("Word %d: ", i + 1);
        for (int j = 0; j < wordLengths[i]; j++) {
            printf("|");
        }
        printf("\n");
    }

    return 0;
}
