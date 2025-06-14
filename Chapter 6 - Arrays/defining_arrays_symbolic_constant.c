// fig06_03.c
// Initializing the elements of array s to the even integers from 2 to 10.
#include <stdio.h>
#define SIZE 5 // maximum size array

int main(void){
    int s[SIZE] = {0};

    for (size_t j = 0; j < SIZE; j++){
        // array of even elements 
        s[j] = 2 + 2 * j;
    }

    printf("%s%8s\n", "Element", "Value");

    for (size_t i = 0; i < SIZE; i++){
        printf("%7zu%8d\n",i,s[i]); 
    }

    return (0);
}