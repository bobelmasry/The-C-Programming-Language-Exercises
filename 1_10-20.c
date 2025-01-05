#include <stdio.h>

#define TABSTOP 8

void detab(char line[], char output[], int tabstop);

int main() {
    char c;
    char input[1000];
    char output[2000];
    int index = 0;

    while ((c = getchar()) != EOF) {
        input[index++] = c;
    }
    input[index] = '\0';

    detab(input, output, TABSTOP);

    printf("Output with tabs replaced by spaces:\n");
    printf("%s", output);

    return 0;
}

void detab(char line[], char output[], int tabstop) {
    int i = 0, j = 0;
    int col = 0;

    while (line[i] != '\0') {
        if (line[i] == '\t') {
            int spaces = tabstop - (col % tabstop);
            for (int k = 0; k < spaces; k++) {
                output[j++] = ' ';
                col++;
            }
        } else {
            output[j++] = line[i];
            if (line[i] == '\n') {
                col = 0;
            } else {
                col++;
            }
        }
        i++;
    }
    output[j] = '\0';
}
