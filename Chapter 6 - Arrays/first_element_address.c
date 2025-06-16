#include <stdio.h>

// main function
int main(void) {
    // empty string
    char array[5] = "";

    // print array address
    printf("    array = %p\n&array[0] = %p\n&array = %p\n", array, &array[0], &array);    

    // return statement
    return (0);
}