#include <stdio.h>

#define TABSTOP 8

void entab(char line[], char output[], int tabstop);

int main() {
    char c;
    char input[1000];
    char output[1000];
    int index = 0;

    while ((c = getchar()) != EOF) {
        input[index++] = c;
    }
    input[index] = '\0';

    entab(input, output, TABSTOP);

    printf("Output with spaces replaced by tabs and spaces:\n");
    printf("%s", output);

    return 0;
}

void entab(char line[], char output[], int tabstop) {
    int i = 0, j = 0;
    int col = 0;

    while (line[i] != '\0') {
        if (line[i] == ' ') {
            int space_count = 0;

            while (line[i] == ' ') {
                space_count++;
                i++;
                col++;
                if (col % tabstop == 0) break;
            }

            int tabs = space_count / tabstop;
            int spaces = space_count % tabstop;
            for (int t = 0; t < tabs; t++) {
                output[j++] = '\t';
                col = (col / tabstop) * tabstop;
            }
            for (int s = 0; s < spaces; s++) {
                output[j++] = ' ';
                col++;
            }
        } else {
            if (line[i] == '\n') col = -1;
            output[j++] = line[i++];
            col++;
        }
    }
    output[j] = '\0';
}
