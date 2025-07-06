#include <stdio.h>
#define FREQUENCY_SIZE 9 

// sales commission
int main(void){
    // init variables for sales commission
    int base_salary = 200;
    double rate = 0.09;
    double grossSale, salary;
    
    // init double array of counters 
    int freq[FREQUENCY_SIZE] = {0};  
    
    // prompt user to input gross sales
    printf("Enter a gross sales (-1 to quit): $");     
    scanf("%lf", &grossSale);

    // sentinel controlled loop
    while (grossSale != -1){
        int salary = base_salary + (int) (rate * grossSale); // truncate    
        printf("salary: $%d\n", salary);

        // calculate the index of the array in which
        // the salary is classified onto and increment freq array 
        int index = (salary - 200) / 100;
        printf("index: %d\n", index); 
        
        freq[index]++;

        // re-prompt user
        printf("Enter a gross sales (-1 to quit): $");     
        scanf("%lf", &grossSale); 
    }

    // display result
    printf("%4s%8s%12s\n", "Start ($)", "End ($)", "Frequency");
    size_t index = 0;

    // output the frequency in a tabular format
    for(size_t start = 200; start <= 1000; start += 100){
        printf("%8u%9u%11d\n", start, start+99, freq[index++]);
    }

    return (0);
}