#include <stdio.h>

void main() {
    int c;
    int isTrue;

    while ((c = getchar()) != EOF){
        putchar(c);
        isTrue = (c != EOF);
        printf("%d\n", isTrue);
    }
    printf("%d\n", isTrue);
}

// isTrue is either 0 or 1
// this code works for both 5_1 and 5_2