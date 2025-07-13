// fig07_15.c
// Copying a string array notation and pointer notation.
#include <stdio.h>
#define SIZE 10

void copy1(char * const s1, const char * const s2); // prototype
void copy2(char *s1, const char *s2);

int main(void) {
    char string1[SIZE];             // create array string1
    char *string2 = "Hello";        // create a pointer to a string

    copy1(string1, string2); 
    printf("string1 = %s\n", string1);

    char string3[SIZE];             // create array string3
    char string4[] = "Good Bye";    // create a pointer to a string

    copy2(string3, string4);
    printf("String3 = %s\n", string3);

    return (0);
}

// copy s2 to s1 using array subscript notation
// 
// s1 is a constant pointer to a character while
// s2 is a constant pointer to a constant character
void copy1(char * const s1, const char * const s2){
    // loop through until null character 
    for (size_t i = 0; (s1[i] = s2[i]) != '\0'; i++){
        ; // don't do anything in the function body
    } 
}

// copy s4 to s3 using pointer notation and arithmetic
// 
// s3 is a non-constant pointer to non-constant character
// s4 is a non-constant pointer to constant character
void copy2(char *s1, const char *s2){
    // loop through until null character
    for (size_t i = 0; (*s1 = *s2) != '\0'; s1++, s2++){
        ; // don't do anything in the function body
    }
}