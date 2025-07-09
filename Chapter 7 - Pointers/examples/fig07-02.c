// fig07_02.c
// Cube a variable using pass-by-value
#include <stdio.h>

int cubeByValue(int n); // prototype

int main(void) {
    int number = 5; // initialize number

    printf("The original value of the number is %d", number);
    number = cubeByValue(number);
    printf("\nThe new value of number is %d\n", number);

    return (0);
}

// calculate and return cube of integer argument
int cubeByValue(int n) {
    return n * n * n; // cube local variable n and return result
}