// fig07_13.c
// Using operator sizeof to determine standard type sizes.
#include <stdio.h>

// function main begins function execution
int main(void){
    char c = '\0';
    short s = 0;
    int i = 0;
    long l = 0;
    long long ll = 0;
    float f = 0.0F;
    double d = 0.0;
    long double ld = 0.0;
    int array[20] = {0}; // create array of 20 int elements
    int *ptr = array;    // create pointer to array
    
    printf("     sizeof c = %zu\t     sizeof(char) = %zu\n",
        sizeof(c) , sizeof(char));
    printf("     sizeof s = %zu\t     sizeof(short) = %zu\n",
        sizeof(s) , sizeof(short));
    printf("     sizeof i = %zu\t     sizeof(int) = %zu\n",
        sizeof(i) , sizeof(int));
    printf("     sizeof l = %zu\t     sizeof(long) = %zu\n",
        sizeof(l) , sizeof(long));
    printf("     sizeof ll = %zu\t     sizeof(long long) = %zu\n",
        sizeof(ll) , sizeof(long long));
    
    printf("     sizeof f = %zu\t     sizeof(float) = %zu\n",
        sizeof(f) , sizeof(float));
    printf("     sizeof d = %zu\t     sizeof(double) = %zu\n",
        sizeof(d) , sizeof(double));
    printf("     sizeof ld = %zu\t     sizeof(long double) = %zu\n",
        sizeof(ld) , sizeof(long double));
    printf("     sizeof array = %zu\t     sizeof(ptr) = %zu\n",
        sizeof(array) , sizeof(ptr));
    
    // when computing the array elements do not use sizeof(ptr)
    // you will mistake this with the size of the pointer and not
    // the size of the array first element 
    printf("     How many elements are there: %d\n",
        (int) (sizeof(array) / (sizeof(array[0]))));
        
    return (0);
}