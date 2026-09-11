#include <stdio.h>

#define tabLength 4

void entab(const char* str, int length);

int main() {
    char currentString[100];
    char c;
    int currentPosition = 0;

    while ((c = getchar()) != EOF){
        if (c == '\n'){
            entab(currentString, currentPosition);
            currentPosition = 0;
        }
        currentString[currentPosition] = c;
        currentPosition += 1;
    }

    return 0;
}

void entab(const char* str, int length) {
    int numTabs = 0;
    int numSpaces = 0;

    for (int i = 0; i < length; ++i) {
        if (str[i] == ' ') {
            numSpaces++;
            if (numSpaces == tabLength) {
                numTabs++;
                numSpaces = 0;
            }
        } else {
            for (int j = 0; j < numTabs; ++j) {
                printf("\t");
            }
            for (int j = 0; j < numSpaces; ++j) {
                printf(" ");
            }
            printf("%c", str[i]);
            numTabs = 0;
            numSpaces = 0;
        }
    }
}