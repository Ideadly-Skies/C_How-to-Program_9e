// fig06_17.c
// two dimensional array manipulation
#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4 

// function prototypes
int minimum(const int grades[][EXAMS], size_t pupils, size_t tests);
int maximum(const int grades[][EXAMS], size_t pupils, size_t tests);
double average(const int setOfGrades[], size_t tests);
void printArray(const int grades[][EXAMS], size_t pupils, size_t tests);

// function main begins program execution
int main(void){
    // initialize student grades for three students (rows)
    int studentGrades[STUDENTS][EXAMS] = {
       {77, 68, 86, 73},
       {96, 87, 89, 78},
       {70, 90, 86, 81}
    };
    
    // output array student grades
    puts("The array is:");
    printArray(studentGrades, STUDENTS, EXAMS);

    // determine the smallest and largest grade values
    printf("\n\nLowest grade: %d\nHighest grade: %d\n",
      minimum(studentGrades, STUDENTS, EXAMS),
      maximum(studentGrades, STUDENTS, EXAMS));
    
    // calculate the average grade for each students
    for (size_t student = 0; student < STUDENTS; ++student){
        printf("The average grade for student %zu is %.2f\n", student, average(studentGrades[student], EXAMS));
    }
}

// find the minimum grade
int minimum(const int grades[][EXAMS], size_t pupils, size_t tests){
    int lowGrade = 100; // initialize to highest possible grade  
    for (size_t pupil = 0; pupil < pupils; ++pupil){
        for (size_t test = 0; test < tests; ++test){
            if (grades[pupil][test] < lowGrade){
                lowGrade = grades[pupil][test];
            }
        }
    } 
    return lowGrade; // return minimum grade
}

// find the maximum grade
int maximum(const int grades[][EXAMS], size_t pupils, size_t tests){
    int highGrade = 0; // initialize to lowest possible grade
    for (size_t pupil = 0; pupil < pupils; ++pupil){
        for (size_t test = 0; test < tests; ++test){
            if (grades[pupil][test] > highGrade){
                highGrade = grades[pupil][test];
            }
        }
    }
    return highGrade; // return maximum grade
}

// determine the average grade for a particular student
double average(const int setOfGrades[], size_t tests){
    int total = 0;
    for (size_t i = 0; i < tests; ++i){
        total += setOfGrades[i];
    }
    return (double) total / tests; 
}

// print array
void printArray(const int grades[][EXAMS], size_t pupils, size_t tests){
    // output column heads
    printf("%s", "                [0]  [1]  [2]  [3]"); 
    
    // output grades in tabular format
    for (size_t row = 0; row < pupils; ++row){
        // output label for row
        printf("\nstudentGrades[%zu] ", row);

        // output grades for one student
        for (size_t column = 0; column < tests; ++column) {
            printf("%-5d", grades[row][column]);
        }
    }
}