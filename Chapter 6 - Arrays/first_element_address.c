// fig06_10.c
// Array name is the same as the address of the array's first element
#include <stdio.h>

// main function
int main(void) {
    // empty string
    char array[5] = "";

    // pointing to the same memory address location
    printf("    array = %p\n&array[0] = %p\n   &array = %p\n", array, &array[0], &array);    

    // return statement
    return (0);
}