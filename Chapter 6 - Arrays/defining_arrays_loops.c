// fig06_01.c
// Initializing the elements of an array to zeros
#include <stdio.h>

int main(void){
    int n[5]; // n is an array of five integers

    // loop to set array's element values
    for (size_t i = 0; i < 5; i++){
        n[i] = 0;
    }

    // printf format specifier 
    printf("%s%8s\n", "Element", "Value");

    // %zu is format specifier for size_t
    for(size_t i = 0; i < 5; i++){
        printf("%7zu%8d\n", i, n[i]);
    }

    // return statement
    return (0);
}