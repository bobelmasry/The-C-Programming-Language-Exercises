#include <stdio.h>
#define IN 1
#define OUT 0

// horizontal histogram of word lengths

void main() {
    int c, state, nc;

    state = IN;
    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
            for (int i = 0; i < nc; ++i){
                printf("-");
            }
        }
        else if (state == OUT){
            state = IN;
            printf("\n");
            nc = 1;
        }
        else {
            nc += 1;
        }
    }
}