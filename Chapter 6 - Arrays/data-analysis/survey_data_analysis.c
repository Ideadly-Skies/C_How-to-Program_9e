// fig06_13.c
// Survey data analysis with arrays:
// computing the mean, median, and mode of the data
#include <stdio.h>
#define SIZE 99

// function prototype
void mean(const int answer[]);
void median(int answer[]);
void mode(int freq[], const int answer[]);
void bubbleSort(int a[]);
void printArray(const int a[]);

// function main begins program execution
int main(void){
    // 1 - 9, skipping the 0th element 
    int frequency[10] = {};

    // initialize array response
    int response[SIZE] =
        {6,7,8,9,8,7,8,9,8,9,
        7,8,9,5,9,8,7,8,7,8,
        6,7,8,9,3,9,8,7,8,7,
        7,8,9,8,9,8,9,7,8,9,
        6,7,8,7,8,7,9,8,9,2,
        7,8,9,8,9,8,9,7,5,3,
        5,6,7,2,5,3,9,4,6,4,
        7,8,9,6,8,7,8,9,7,8,
        7,4,4,2,5,3,8,7,5,6,
        4,5,6,1,6,5,7,8,7};

    // process responses
    mean(response);
    median(response);
    mode(frequency, response);
}

// calculate average of all response values
void mean(const int answer[]){
    printf("%s \n%s\n%s\n", "--------", " Mean", "--------");
    
    int total = 0;

    for(size_t i = 0; i < SIZE; i++){
        total += answer[i];
    }

    printf("The mean is the average value of the data\n"
           "items. The mean is equal to the total of\n"
           "all data items (%u). The mean value for\n"
           "the run is: %u / %u = %.4f\n\n",
            SIZE, total, SIZE, (double) total / SIZE
    );
}

// sort array and determine median element's value
void median(int answer[]){
    printf("\n%s\n%s\n%s\n%s", "--------", " Median", "--------", 
           "The unsorted array of response is");
    
    printArray(answer); // output unsorted array
    bubbleSort(answer); // sort array
    
    printf("%s", "\n\nThe sorted array is");
    printArray(answer); // output sorted array
    
    printf("\n\nThe median is element %u of\n"
           "the sorted %u element array.\n"
           "For this run the median is %u\n\n",
           SIZE / 2, SIZE, answer[SIZE / 2]
    );
}

// determine the most frequent response
void mode(int freq[], const int answer[]){
    printf("\n%s\n%s\n%s\n", "--------", " Mode", "--------");

    // initialize frequencies to 0
    for(size_t i = 1; i <= 9; i++){
        freq[i] = 0;
    }
    
    // increment frequencies
    for(size_t j = 0; j < SIZE; j++){
        ++freq[answer[j]];
    } 

    // output headers for result columns
    printf("%s%11s%19s\n\n%54s\n%54s\n\n",
           "Response", "Frequency", "Bar Chart",
           "1    1    2    2","5    0    5    0    5");
    
    // output results
    int largest = 0;  // represents largest frequency
    int modeValue = 0; // represents most frequency response

    for (size_t rating = 1; rating <= 9; ++rating){
        printf("%8zu%11d          ", rating, freq[rating]);

        // keep track of mode values and largest frequency value
        if (freq[rating] > largest){
            largest = freq[rating]; 
            modeValue = rating;
        }

        // output bar representing frequency value
        for (int h = 1; h <= freq[rating]; ++h){
            printf("%s", "*");
        }

        puts(""); // being new line of output
    }
}

// sorts an array with bubble sort algorithm
void bubbleSort(int a[]){
    // loop to control the number of passes
    for (size_t pass = 1; pass < SIZE; pass++){
        // loop to control the number of comparisons per pass 
        for (size_t i = 0; i < SIZE-1; i++){
            if (a[i] > a[i+1]){
                // swap elements if out of order
                int hold = a[i];
                a[i] = a[i+1];
                a[i+1] = hold;
            }
        }    
    }
}

// output array contents (20 values per row)
void printArray(const int a[]){
    // output array contents
    for (size_t j = 0; j < SIZE; j++){

        if (j % 20 == 0){
            puts(""); // begin newline every 20 values
        }

        printf("%2d", a[j]);
    }
}