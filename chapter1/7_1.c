#include <stdio.h>

float celsius_to_fahr(int celsius);
float fahr_to_celsius(int fahr);

void main() {
    int num1, num2;
    
    num1 = celsius_to_fahr(40);
    num2 = fahr_to_celsius(100);

    printf("%d %d\n", num1, num2);
}

float celsius_to_fahr(int celsius){
    return (9.0/5.0 * celsius) + 32;
}

float fahr_to_celsius(int fahr){
    return 5.0 * (fahr - 32) / 9.0;
}