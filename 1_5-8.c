#include <stdio.h>

int main() {
    int c;
    int blanks = 0, lines = 0, tabs = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
        } else if (c == '\n') {
            ++lines;
        } else if (c == '\t') {
            ++tabs;
        }
    }

    printf("blanks: %d, lines: %d, tabs: %d\n", blanks, lines, tabs);

    return 0;
}
