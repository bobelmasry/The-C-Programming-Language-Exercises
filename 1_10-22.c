#include <stdio.h>

#define MAXLINE 1000
#define FOLD_COLUMN 80

void fold_line(char input[], int fold_col);

int main() {
    char c, input[MAXLINE];
    int index = 0;

    while ((c = getchar()) != EOF && index < MAXLINE - 1) {
        input[index++] = c;
    }
    input[index] = '\0';

    printf("\nFolded text:\n");
    fold_line(input, FOLD_COLUMN);

    return 0;
}

void fold_line(char input[], int fold_col) {
    int col = 0, last_blank = -1, i = 0;

    while (input[i] != '\0') {
        if (input[i] == ' ' || input[i] == '\t') {
            last_blank = i;
        }

        if (input[i] == '\n') {
            putchar(input[i]);
            col = 0;
            last_blank = -1;
        } else {
            putchar(input[i]);
            col++;
        }

        if (col == fold_col) {
            if (last_blank >= 0) {
                putchar('\n');
                col = i - last_blank;
                last_blank = -1;
            } else {
                putchar('-');
                putchar('\n');
                col = 0;
            }
        }
        i++;
    }
}
