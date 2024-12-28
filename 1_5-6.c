#include <stdio.h>

int main() {
    int c;

    c = getchar();
    printf("%d", c == EOF);
    
    return 0;
}
