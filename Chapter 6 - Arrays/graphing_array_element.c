// fig06_06.c
// displaying a bar chart
#include <stdio.h>
#define SIZE 5

int main(void){
    // use initializer list to initialize array n
    int n[SIZE] = {19, 3, 15, 7, 11};

    printf("%s%13s%17s\n","Element", "Value", "Bar Chart");

    // for each element of array n, output a bar chart
    for(size_t i = 0; i < SIZE; ++i){
        // print element, value, and empty barchart 
        printf("%7zu%13d%8s",i,n[i],"");

        for(int j = 1; j <= n[i]; ++j) {
            printf("%c", '*');
        }

        // end bar with newline
        puts("");
    }

    return (0);
}