#include <stdio.h>

#define breakLength 50

int main() {
    char str[1000];
    int totalLength = 0;
    char currentStr[100];
    char c;

    while ((c = getchar()) != EOF){
        str[totalLength] = c;
        totalLength ++;
    }

    int currentLength = 0;
    for(int i = 0; i < totalLength; ++i){
        if ((str[i] == ' ' || str[i] == '\t') && (currentLength > breakLength)){
            currentStr[currentLength] = '\0';
            printf("%s\n", currentStr);
            currentLength = 0;
        }
        else {
            currentStr[currentLength] = str[i];
            currentLength ++;
        }
    }
    currentStr[currentLength] = '\0';
    printf("%s\n", currentStr);

    return 0;
}