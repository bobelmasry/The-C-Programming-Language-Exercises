#include <stdio.h>
#include <ctype.h>

int main() {
    int c;
    int inWord = 0;

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            putchar(c);
            inWord = 1;
        } else {
            if (inWord) {
                putchar('\n');
                inWord = 0;
            }
        }
    }

    return 0;
}
