// fig06_16.c
// init multidimensional array
#include <stdio.h>
#define ROW 2
#define COL 3

void printArray(int a[ROW][COL]); // function prototype

// function main begins program execution
int main(){
    int array1[ROW][COL] = {{1,2,3}, {4,5,6}};
    puts("values in array1 by row are");
    printArray(array1);

    return (0);
}

void printArray(int a[][3]){
    // loop through rows
    for (size_t i = 0; i < ROW; i++){
        // output column values 
        for (size_t j = 0; j < COL; j++){
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
}