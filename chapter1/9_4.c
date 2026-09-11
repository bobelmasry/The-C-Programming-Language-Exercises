#include <stdio.h>

void reverse(char from[], char to[]);

void main() {
    char from[1000], to[1000];
    int c, i = 0;

    while ((c = getchar()) != EOF && i < 999) {
        from[i++] = c;
    }
    from[i] = '\0';

    reverse(from, to);
    printf("%s", to);
}


void reverse(char from[], char to[]){
    int i, j;
    for (i = 0; from[i] != '\0'; i++) {
        ;
    }
    i--;
    for (j = 0; i >= 0; j++, i--) {
        to[j] = from[i];
    }
    to[j] = '\0';
}