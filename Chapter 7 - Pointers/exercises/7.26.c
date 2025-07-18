#include <stdio.h>
#include <stdlib.h>

// banner prototype
void introMessage(void);
void exitMessage(void);
void selectOption(int *option);

// calculator prototype
double add(double num1, double num2); 
double subtract(double num1, double num2); 
double multiply(double num1, double num2); 
double divide(double num1, double num2); 

int main(void){

    // output intro message 
    introMessage();
    puts("");

    // input two numbers
    double num1, num2;
    printf("please key in a number: ");
    scanf("%lf", &num1);
    printf("please key in another number: ");
    scanf("%lf", &num2);

    // function prototype
    void *options[4] = {&add, &subtract, &multiply, &divide};

    // init prompt
    int option;
    selectOption(&option);

    while (option != 5){
       while (option < 1 || option > 5){
            puts("You have dialed an invalid option!");
            selectOption(&option);
        }

        if (option == 1){
            // add two number together
            double sum = ( ( double (*)(double, double) ) options[0] )(num1, num2);
            printf("\nThe sum of the two numbers are: %.2f\n", sum);
        }
        else if (option == 2){
            // sub two number together
            double sub = ( ( double (*)(double, double) ) options[1] )(num1, num2);
            printf("\nThe sub of the two numbers are: %.2f\n", sub);
        }
        else if (option == 3){
            // mul two numbers together
            double mul = ( ( double (*)(double, double) ) options[2] )(num1, num2);
            printf("\nThe mul of the two numbers are: %.2f\n", mul);
        } 
        else if (option == 4){
            // div two number together
            double div = ( ( double (*)(double, double) ) options[  3] )(num1, num2);
            printf("\nThe div of the two numbers are: %.2f\n", div);
        }

        selectOption(&option);
    }
    
    // exit message
    puts("");
    exitMessage();
    
    return (0);
}

/*******************************************************************
 *                      BANNERS FUNCTION                           *
 *******************************************************************/
void introMessage(void){ 
    puts("====================================================================================");
    puts("            WELCOME TO THE CALCULATOR PROGRAM MAKE YOURSELF AT HOME                 ");
    puts("====================================================================================");
}

void exitMessage(void){
    puts("====================================================================================");
    puts("           THANK YOU FOR USING THE CALCULATOR PROGRAM HAVE A NICE DAY               ");
    puts("====================================================================================");
}

void selectOption(int *option) {
    printf("\n%s:\n  %s  %s  %s  %s  %s\n","Enter a choice", " 1  Add Two Numbers\n", " 2  Subtract Two Numbers\n", " 3  Multiply Two Numbers\n", " 4  Divide Two Numbers\n", " 5  Exit\n");
    printf("select option: ");
    scanf("%d", option); 
}


/*******************************************************************
 *                      CALCULATOR FUNCTION                        *
 *******************************************************************/
double add(double num1, double num2){
    return num1 + num2;
}

double subtract(double num1, double num2){
    return num1 - num2;
}

double multiply(double num1, double num2){
    return num1 * num2;
}

double divide(double num1, double num2){
    return num1 / num2;
}