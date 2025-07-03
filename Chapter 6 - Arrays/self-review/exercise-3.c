#define SIZE 10
#include <stdio.h>

int main(void){
    // initialize all entries to 0
    double arr[SIZE] = {0};

    // arr[4];
    
    arr[9] = 1.667;
    arr[6] = 3.333;

    printf("%.2f %.2f\n", arr[6], arr[9]);

    puts("");

    for(int i = 0; i < SIZE; i++){
        printf("arr[%d] = %.2f\n", i, arr[i]);
    }

    return (0);
}