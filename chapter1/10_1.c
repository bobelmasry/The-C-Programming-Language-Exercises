#include <stdio.h>

int main() {
    char currentString[100];
    int tabSpaces = 4;
    int currentPosition = 0;
    char c;
    while ((c = getchar()) != EOF){
        if (c == '\n'){
            currentPosition = 0;
        }
        currentString[currentPosition] = c;
        currentPosition += 1;
    }
    printf("\n");
    for (int i = 0; i < currentPosition; ++i){
        if (currentString[i] == '\t'){
            for (int j = 0; j < tabSpaces; ++j){
                printf(" ");
            }
        }
        else {
            printf("%c", currentString[i]);
        }
    }
    return 0;
}