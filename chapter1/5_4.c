#include <stdio.h>

void main() {
    int nc, c; // next char, current char

    while ((c = getchar()) != EOF){
        nc = getchar();
        if (c != ' '){
            putchar(c);
            putchar(nc);
        }
        if (c == ' ' && nc != ' '){
            putchar(c);
        }
    }
}