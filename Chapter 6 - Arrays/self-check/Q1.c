#include <stdio.h>
#define SIZE 7

int main(void) {
    double n[SIZE]; // n is an array of seven doubles 
    
    // set array elements to 10
    for (size_t i = 0; i < SIZE; ++i) {              
       n[i] = 10;
    }

    // print current index and value
    printf("%5s%8s\n","Index", "Value"); 

    for (size_t i = 0; i < SIZE; ++i) {              
        printf("%5zu%8.2f\n",i,n[i]);        
    }

    // return statement
    return (0);
}