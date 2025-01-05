#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);

int main() {
    int len;
    int max = 0;
    int current_length = 0;
    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0) {
        current_length += len; 

        if (line[len - 1] != '\n') {
            continue;
        }

        if (current_length > max) {
            max = current_length;
            for (int i = 0; i < len; i++) {
                longest[i] = line[i];
            }
            longest[len] = '\0';
        }

        current_length = 0;
    }

    if (max > 0) {
        printf("Length of longest line: %d\n", max);
        printf("Longest line (as much as fits in buffer):\n%s\n", longest);
    }

    return 0;
}

int my_getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}
