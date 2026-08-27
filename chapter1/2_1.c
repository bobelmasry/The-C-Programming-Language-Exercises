#include <stdio.h>

void main(){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("Fahrenheit to Celsius converter\n \n");
    while (fahr <= upper){
        celsius = 5.0 * (fahr - 32) / 9.0;
        printf("%10.0f %13.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}