// reverse string using recursion
#include <stdio.h>

void stringReverse(char *str);

int main(void) {
    char s[] = "hello world";
    stringReverse(s);
    puts("");

    return (0);
}

void stringReverse(char *str){
    if (*str == '\0') return;
    
    stringReverse(str+1);
    printf("%c",*str);
}