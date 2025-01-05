#include <stdio.h>

float getTemperature(int fahr){
    return (fahr - 32) * (5.0/9);
}

int main() {
    
    for (int i = 0; i <= 200; i+= 20)
    printf("%0.2f\n", getTemperature(i));

    return 0;
}
