#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int recursiveMinimum(int *arr, int size);

int main(void) {
    int a[SIZE] = {5, 3, 2, 4, 1}; 
    int min = recursiveMinimum(a, SIZE);
    printf("minimum value: %d\n", min);

    return (0);
}

int recursiveMinimum(int *arr, int size){
    if (size == 1) return arr[0];

    int num2 = recursiveMinimum(arr+1, size-1);       

    if (*arr < num2) return *arr;
    else return num2;
}