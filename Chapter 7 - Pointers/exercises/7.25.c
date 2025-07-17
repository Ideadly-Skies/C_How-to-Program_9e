#include <stdio.h>
#include <stdlib.h>

// define PI constant
#define PI 3.14159265358979323846

// interface prototype
void introMessage(void);
void promptRadius(double *radius);
void selectOption(int *option);
void exitMessage(void);

// functionality prototype
double calculateCircumference(double radius);
double calculateArea(double radius);
double calculateVolume(double radius);

int main(void){
    // greet banner 
    introMessage();

    // init radius variable
    puts("");
    double radius;
    
    // initial radius prompting 
    promptRadius(&radius);
    
    // keep prompting radius until sensible
    // answer matches
    while (radius < 0) {
        puts("Invalid radius specified! value must be positive.\n");
        promptRadius(&radius);
    }

    // prompt user for option 
    int option;
    selectOption(&option);

    // define function pointers in here
    void *options[3] = {&calculateCircumference, &calculateArea, &calculateVolume};

    while (option != 4){
        while (option < 1 || option > 4){
            printf("\nYou have dialed an invalid option!");
            selectOption(&option);
        }

        // calculate circumference
        if (option == 1){
            double circumference = ( ( double (*)(double) ) options[0] )(radius);
            printf("\n\nThe circumference is %.2f.\n", circumference);
        } 

        // calculate area
        else if (option == 2){
            double area = ( ( double (*)(double) ) options[1] )(radius);
            printf("\n\nThe area is %.2f.\n", area);
        } 

        // calculate volume
        else if (option == 3){
            double volume = ( ( double (*)(double) ) options[2] )(radius);
            printf("\n\nThe volume is %.2f.\n", volume);
        }

        // prompt the user again
        selectOption(&option);
    }

    // exit banner
    puts("");
    exitMessage();
    
    return (0);
}

/*******************************************************************
 *                      BANNERS FUNCTION                           *
 *******************************************************************/
void introMessage(void){ 
    puts("====================================================================================");
    puts("            WELCOME TO CIRCLE CIRCUMFERENCE, VOLUME, AREA CALCULATOR                ");
    puts("====================================================================================");
}

void exitMessage(void){
    puts("====================================================================================");
    puts("           THANKS FOR USING TO CIRCLE CIRCUMFERENCE, VOLUME, AREA CALCULATOR        ");
    puts("====================================================================================");
}

void selectOption(int *option) {
    printf("\n%s:\n  %s  %s  %s  %s\n","Enter a choice", " 1  Calculate Circumference\n", " 2  Calculate Area\n", " 3  Calculate Spehere Volume\n", " 4  End program\n");
    printf("select option: "); 
    scanf("%d", option); 
}

/*******************************************************************
 *                CIRCLE CALCULATOR FUNCTION                       *
*******************************************************************/
void promptRadius(double *radius){
    printf("please enter radius: ");
    scanf("%lf", radius);
}

double calculateCircumference(double radius){
    return 2 * PI * radius; 
}

double calculateArea(double radius){
    return PI * radius * radius; 
}

double calculateVolume(double radius){
    return 4 * PI * radius * radius * radius;
}