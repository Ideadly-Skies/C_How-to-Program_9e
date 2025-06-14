#include <stdio.h>

// main function
int main(void){
    // initialize with initializer list
    int n[5] = {32, 27, 64, 18, 95};

    // print the header for the element and value
    printf("%s%8s\n", "Element", "Value");

    // output contents of array in tabular format
    for (size_t i = 0; i < 5; ++i){
        printf("%7u%8d\n",i,n[i]);
    }

    // return statement
    return (0);
}