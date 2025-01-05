#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void remove_trailing_whitespace(char line[]);

int main() {
    char line[MAXLINE];
    int len;

    while ((len = my_getline(line, MAXLINE)) > 0) {
        remove_trailing_whitespace(line);
        if (line[0] != '\0') {
            printf("%s\n", line);
        }
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

void remove_trailing_whitespace(char line[]) {
    int i = 0;

    while (line[i] != '\0') {
        i++;
    }

    i--;
    while (i >= 0 && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')) {
        line[i] = '\0';
        i--;
    }
}
