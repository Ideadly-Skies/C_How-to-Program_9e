// fig06_09.c
// Static arrays are initialized to zero if not explicitly initialized
#include <stdio.h>
#define SIZE 3

void staticArrayInit(void);     // function prototype
void automaticArrayInit(void);  // function prototype

// function main begins program execution
int main(){
    // both arrays initialized first in here
    puts("First call to each function:");
    staticArrayInit();
    automaticArrayInit();

    // static arrays use previously defined values
    // automatic arrays re-initialize elements when function is invoked again 
    puts("\n\nSecond call to each function:");
    staticArrayInit();
    automaticArrayInit();    
    puts("");

    // return statement
    return(0);
}

// function to demonstrate a static local array
void staticArrayInit(void){
    // initializes elements to 0 before the function is called
    static int array1[SIZE]; 

    puts("\nValues on entering staticArrayInit:");

    // output contents of array1
    for (size_t i = 0; i <= 2; i++){
        printf("array1[%zu] = %d ", i, array1[i]);
    }

    puts("\nValues on exiting staticArrayInit:");

    // modify and output the content of array1
    for (size_t i = 0; i <= 2; i++){
        printf("array1[%zu] = %d ", i, array1[i] += 5);
    }
}

// function to demonstrate automatic local array
void automaticArrayInit(void){
    // initializes elements to 0 before the function is called
    static int array2[SIZE]; 

    puts("\nValues on entering automaticArrayInit:");

    // output contents of array1
    for (size_t i = 0; i <= 2; i++){
        printf("array1[%zu] = %d ", i, array2[i]);
    }

    puts("\nValues on exiting staticArrayInit:");

    // modify and output the content of array1
    for (size_t i = 0; i <= 2; i++){
        printf("array1[%zu] = %d ", i, array2[i] += 5);
    }
}