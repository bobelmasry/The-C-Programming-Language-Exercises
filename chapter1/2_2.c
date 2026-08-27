#include <stdio.h>

void main(){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    printf("Celsius to Fahrenheit converter\n \n");
    while (celsius <= upper){
        fahr = (9.0/5.0 * celsius) + 32;
        printf("%10.0f %13.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}