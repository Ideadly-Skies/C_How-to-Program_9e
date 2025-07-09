// fig07_07.c
// Printing a string one character at a time using
// a non-constant pointer to a constant data

#include <stdio.h>

void printCharacters(const char *sPtr);

int main(void) {
    // initialize char array
    char string[] = "print characters of a string";

    puts("The string is:");
    printCharacters(string);
    // default newline character
    puts("");

    return (0);
}

void printCharacters(const char *sPtr) {
    // while sPtr does not point to
    // null terminating character
    while (*sPtr != '\0'){
        printf("%c", *sPtr);
        sPtr++; // increment pointer 
    }
}