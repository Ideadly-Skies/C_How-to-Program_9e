// fig07_03.c
// Cube a variable using pass-by-reference with a pointer argument
#include <stdio.h>
#include <stdlib.h>

// cube by reference prototype
void cubeByReference(int *n);

int main(void) {
    int number = 5; // initialize number 

    printf("The original value of number is %d\n", number);
    cubeByReference(&number);
    printf("The new value of number is %d\n", number);

    return (0);
}

void cubeByReference(int *n) {
    // dereference operations done on variable n 
    *n = *n * *n * *n;        
}