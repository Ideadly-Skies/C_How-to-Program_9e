// fig07_09.c
// Attempting to modify a constant pointer to non-constant data
#include <stdio.h>

int main(void) {
    int x = 0; // define x
    int y = 0; // define y

    // ptr is a constant pointer to an integer that can be modified
    // through ptr, but ptr always points to the same memory location
    int * const ptr = &x;
    
    printf("value of x before the modification: %d\n", x);    

    // x value changes
    *ptr = 7;
    // ptr = &y; // error: ptr is const; cannot assign new address

    printf("value of x after the modification: %d\n", x);    

    return (0);
}