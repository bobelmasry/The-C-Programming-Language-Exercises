#include <stdio.h>
#define MAXLINE 1000

int getline2(char line[], int maxline);
void remove2(char s[], int len);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = getline2(line, MAXLINE)) > 0) {
            remove2(line, len);
            printf("%s \n", line);
    }
    return 0;

}

int getline2(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void remove2(char s[], int len) {
    int i;

    for (i = len - 1; i >= 0; --i) {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {
            s[i + 1] = '\0';
            return;
        }
    }

    s[0] = '\0';
}