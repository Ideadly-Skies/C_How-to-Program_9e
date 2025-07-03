#include <stdio.h>
#define SIZE 3

int main(void){
    int total = 0;
    int arr[SIZE][SIZE];

    for(int row = 0; row < SIZE; row++){
        for (int col = 0; col < SIZE; col++){
            arr[row][col] = row + col;    
            total += 1;
        }
    }

    int table[SIZE][SIZE] = {{1, 8}, {2, 4, 6}, {5}};
    for(int row = 0; row < SIZE; row++){
        for(int col = 0; col < SIZE; col++){
            printf("table[%d][%d] = %d\n", row, col, table[row][col]);
        }
    }

    // printf("There are %d total number of elements\n",total);

    return (0);
}