#include <stdio.h>
#define RESPONSES_SIZE 20 
#define FREQUENCY_SIZE 6  

// function main begins program execution
int main(void) {
    // array initializer 
    int responses[RESPONSES_SIZE] =  {1, 2, 5, 4, 3, 5, 2, 1, 3, 1, 4, 3, 3, 3, 2, 3, 3, 2, 2, 5};

    // initialize frequency counters to 0
    int frequency[FREQUENCY_SIZE] = {0};

    // increment each frequency element
    for(size_t answer = 0; answer < RESPONSES_SIZE; answer++){
        frequency[responses[answer]]++;        
    }    

    // display result
    printf("%s%12s\n", "Rating", "Frequency");

    // output the frequency in a tabular format
    for(size_t rating = 1; rating < FREQUENCY_SIZE; rating++){
        printf("%6u%12d\n",rating, frequency[rating]);
    }

    // output the frequencies in tabular format
    return (0);
}