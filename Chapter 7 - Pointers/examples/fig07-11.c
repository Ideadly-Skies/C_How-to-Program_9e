// fig07_11.c
// putting values into an array, sorting the values into
// ascending order and printing the resulting array
#include <stdio.h>
#define SIZE 10

// the address stored in the array cannot be changed
// but the data at that address (*array or array[i]) can be modified
void bubbleSort(int * const array, size_t size); // prototype

int main(void) {
    // initialize array a
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37}; 

    puts("Data items in original order");

    // loop through array a
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%4d", a[i]);
    }

    bubbleSort(a, SIZE); // sort the array

    puts("\nData items in ascending order");

    // loop through array a
    for (size_t i = 0; i < SIZE; ++i){
        printf("%4d", a[i]);
    }

    puts("");
}

// sort an array of integers using bubble sort algorithm
void bubbleSort(int * const array, size_t size) {
    void swap(int *element1Ptr, int *element2Ptr); // prototype

    // loop to control passes
    for (int pass = 0; pass < size - 1; ++pass){
        // loop to control comparison during each pass
        for (size_t j = 0; j < size - 1; ++j) {
            // swap adjacent elements if they're out of order
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

// swap values at memory locations at which element1Ptr and
// element2Ptr points
void swap(int *element1Ptr, int *element2Ptr) {
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}