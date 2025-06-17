// fig06_14.c
// Linear search of an array 
#include <stdio.h>
#define SIZE 100

// function prototype
int linearSearch(const int array[], int key, size_t size);

// function main begins program invocation
int main(void){
    int a[SIZE] = {0}; // create array a 

    // create some data
    for (size_t x = 0; x < SIZE; ++x){
        a[x] = 2 * x;
    }

    printf("Enter integer search key: ");
    int searchKey = 0;
    scanf("%d", &searchKey);

    // attempt to locate SearchKey in array a 
    int subscript = linearSearch(a, searchKey, SIZE);

    // display results
    if (subscript != -1){
        printf("Found value at subscript %d\n", subscript);
    } else {
        puts("Value not found");
    }

    // return 0
    return (0);
}

int linearSearch(const int array[], int key, size_t size){
    
    // iterate through the entire array
    for(size_t i = 0; i < size; i++){
        // key found 
        if (array[i] == key){
            // return index 
            return i;
        } 
    }

    // return -1 if not found
    return -1;
}