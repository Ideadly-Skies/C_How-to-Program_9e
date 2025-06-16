// fig06_11.c
// passing arrays and individual elements to functions
#include <stdio.h>
#define SIZE 5

// function prototype
void modifyArray(int b[], size_t size);
void modifyElements(int e);

int main(void){
    int a[SIZE] = {0, 1, 2, 3, 4}; // initialize array a

    puts("Effects of passing entire array by reference:\n\nThe "
    "values of the original array are");
    
    // output original array
    for (size_t i = 0; i < SIZE; i++){
        printf("%3d",a[i]);
    }

    // prints a newline
    puts("");

    modifyArray(a, SIZE); // pass array a to modifyArray by reference
    puts("The values of the modified array are:");

    // output modified array
    for(size_t i = 0; i < SIZE; i++){
        printf("%3d", a[i]);
    }

    // output value of a[3]
    printf("\n\nEffects of passing array element "
    "by value:\n\nThe value of a[3] is %d\n", a[3]);

    modifyElements(a[3]); // pass array element a[3] by value
    
    // output the value of a[3]
    printf("The value of a[3] is %d\n", a[3]);
    
    return (0);
}

// pass by reference
void modifyArray(int b[], size_t size){
    for(size_t i = 0; i < size; i++){
        b[i] *= 2; // actually modify the actual array 
    }
}

// pass by value
void modifyElements(int e){
    e *= 2; // multiply parameter by 2
    printf("Value in modifyElement is %d\n", e);
}