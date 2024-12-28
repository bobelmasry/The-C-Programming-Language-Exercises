#include <stdio.h>

int main() {
    int c;
    int lastWasSpace = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (!lastWasSpace) {
                putchar(c);
                lastWasSpace = 1;
            }
        } else {
            putchar(c);
            lastWasSpace = 0;
        }
    }

    return 0;
}
