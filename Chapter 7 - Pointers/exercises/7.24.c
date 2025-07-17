// rewritting the program in fig06_17.c to use function pointer
// fig06_17.c = two dimensional array manipulations.
#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

// function prototype
int minimum(const int grades[][EXAMS], size_t pupils, size_t tests);
int maximum(const int grades[][EXAMS], size_t pupils, size_t tests);
double average(const int setOfGrades[], size_t tests);
void printArray(const int grades[][EXAMS], size_t pupils, size_t tests);

// prototypes
void printBanner(void);
void selectChoice(int *option);
void exitMessage(void);

// function main begins program execution
int main(void){
    // initialize students grades for three students (rows)
    int studentGrades[STUDENTS][EXAMS] = {
        {77, 68, 86, 73},
        {96, 87, 89, 78},
        {70, 90, 86, 81},
    };

    // assign each element to the corresponding
    // function
    // interface[0] = printArray;
    // interface[1] = minimum;
    // interface[2] = maximum;
    // interface[3] = average;

    // display school banner
    printBanner();

    int option;
    selectChoice(&option); 

    // function pointers
    void *options[4] = {&minimum, &maximum, &average, &printArray};

    // happy case - assuming user did not input 4
    while (option != 4){
        while (option < 1 || option > 4){
            printf("\nYou have dialed an invalid option!");
            selectChoice(&option);
        }

        // break out of the loop
        if (option == 1){
            int min = ( ( int (*)(const int grades[][EXAMS],size_t,size_t) ) options[0] )(studentGrades, STUDENTS, EXAMS);
            printf("\n\nLowest Grade: %d\n", min);    
        }
        
        else if (option == 2){
            int max = ( ( int (*)(const int grades[][EXAMS],size_t,size_t) ) options[1] )(studentGrades, STUDENTS, EXAMS);
            printf("\n\nHighest Grade: %d\n", max);
        } 

        else if (option == 3) {
            puts("\n");
            for (size_t student = 0; student < STUDENTS; ++student) {
                double average = ( ( double (*)(const int setOfGrades[], size_t tests) ) options[2] )(studentGrades[student], EXAMS); 
                printf("The average grade for student %zu is %.2f\n", student, average);
            }
        } 
        
        // reprompt the user again
        selectChoice(&option);  
    }

    // exit message
    puts("");
    exitMessage();
    puts("");
}

void printBanner(void){ 
    puts("====================================================================================");
    puts("            WELCOME TO BINUS INTERNATIONAL SCHOOL SERPONG MS/HS SYS                 ");
    puts("====================================================================================");
}

void selectChoice(int *option){
    printf("\n%s:\n  %s  %s  %s  %s\n","Enter a choice", " 1  Find the minimum grade\n", " 2  Find the maximum grade\n", " 3  Print the average on all tests for each student\n", " 4  End program\n");
    printf("select option: "); 
    scanf("%d", option); 
}

void exitMessage(void){
    puts("====================================================================================");
    puts("           THANK YOU FOR USING THE BINUS INTERNATIONAL SCHOOL PROGRAM               ");
    puts("====================================================================================");
}

// Find the minimum value
int minimum(const int grades[][EXAMS], size_t pupils, size_t tests){
    int lowGrade = 100; // initialize to highest possible grade

    // loop through row of grades
    for(size_t row = 0; row < pupils; ++row){
        // loop through columns of grades
        for(size_t col = 0; col < pupils; ++col){
            if (grades[row][col] < lowGrade) {
                lowGrade = grades[row][col];
            }
        }
    }

    // return lowGrade
    return lowGrade;
}

int maximum(const int grades[][EXAMS], size_t pupils, size_t tests){
    int highGrade = 0; // initialize to lowest possible grade

    // loop through row of grades
    for(size_t row = 0; row < pupils; ++row){
        // loop through columns of grades
        for(size_t col = 0; col < tests; ++col){
            if (grades[row][col] > highGrade) {
                highGrade = grades[row][col];
            }
        }
    }

    return highGrade;
}

// Determine the average grade for a particular student
double average(const int setOfGrades[], size_t tests) {
    int total = 0;
    // total all grades for one student
    for (size_t test = 0; test < tests; ++test) {
        total += setOfGrades[test];
}
    return (double) total / tests; // average
}

// Print the array
void printArray(const int grades[][EXAMS], size_t pupils, size_t tests) { // output column heads
    printf("%s", "                 [0] [1] [2] [3]");

    // output grades in tabular format
    for (size_t row = 0; row < pupils; ++row){
        // output label for row
        printf("\nstudentGrades[%zu] ", row);

        // output grades for one student
        for (size_t col = 0; col < tests; ++col) {
            printf("%-5d", grades[row][col]);
        }
    }
}