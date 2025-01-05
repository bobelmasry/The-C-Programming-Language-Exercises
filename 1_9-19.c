#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void reverse(char s[]);

int main() {
    char line[MAXLINE];

    while (my_getline(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
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

void reverse(char s[]) {
    int i, j;
    char temp;

    for (i = 0; s[i] != '\0'; i++);
    i--;

    if (s[i] == '\n') {
        i--;
    }

    for (j = 0; j < i; j++, i--) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}
