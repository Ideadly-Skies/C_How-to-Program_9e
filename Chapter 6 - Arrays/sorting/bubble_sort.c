#include <stdio.h>
#define SIZE 10

// on the first pass -> largest element
// second pass       -> second-largest element
// third pass        -> third-largeest element
// ...               -> ...
// n-1 pass          -> n-1 largest element 
int main(void){
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

    puts("Data items in original order");

    // output original array
    for(size_t i = 0; i < SIZE; ++i){
        printf("%4d", a[i]);
    }

    // bubble sort
    // loop to control number of passes
    for(size_t pass = 1; pass < SIZE; pass++){
        // loop to control number of comparison per pass
        for(size_t i = 0; i < SIZE-1; ++i){
            // compare adjacent elements and swap them if first
            // element is greater than second element
            if (a[i] > a[i+1]){
                int hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;
            }
        }
    }

    // output data in ascending order
    puts("\nData items in ascending order");

    // print each array element
    for(size_t i = 0; i < SIZE; i++){ 
        printf("%4d", a[i]);
    }

    // newline character
    puts("");

    return (0);
}