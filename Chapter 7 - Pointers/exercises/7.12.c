// fig07_16.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
#define HANDS 5

// prototypes
void shuffle(int deck[][FACES]);
void deal(int deck[][FACES], const char *face[], const char *suit[]);
void draw(char *hand[], int deck[][FACES], const char *face[], const char *suit[], int SIZE);
void copy(const char * const s1, char * const s2);

int main(void) {
    // initialize deck array
    int deck[SUITS][FACES] = {0};

    srand(time(NULL)); // seed the random-number generator
    shuffle(deck);     // shuffle the deck

    // initialize the suit array
    // 
    // each element is actually pointer to string's first character! (mind-blown)
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    // initialize the face array
    const char *face[FACES] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    // deal(deck, face, suit);
    
    // declare a char string array
    char default_string1[18];
    char default_string2[18];
    char default_string3[18];
    char default_string4[18];
    char default_string5[18];

    char *hand[HANDS] = {default_string1, default_string2, default_string3, default_string4, default_string5};
    draw(hand, deck, face, suit, HANDS);

    for(size_t i = 0; i < HANDS; i++){
        printf("%s ", hand[i]);
    }
    puts("");

    return (0);
}

// populate hand with the cards
void draw(char *hand[], int deck[][FACES], const char *face[], const char *suit[], int SIZE){ 
    char last_string[18]; 
    char constructed_string[18];

    for(size_t i = 0; i < SIZE; i++){
        size_t row = 0;     // row number
        size_t column = 0;  // column number 

        do {
            // empty the string first in new run
            constructed_string[0] = '\0';
            row = rand() % SUITS;   
            column = rand() % FACES;

            // construct the card and store in constructed_string 
            sprintf(constructed_string, "%5s of %-8s", face[column], suit[row]);

        } while (strcmp(last_string, constructed_string) == 0);
        
        // debugging print statement 
        // printf("constructed string: %s\n", constructed_string);        
        // printf("last string: %s\n", last_string);

        // update last string with newly constructed string
        copy(constructed_string, last_string); 
        copy(constructed_string, hand[i]);
    }
}

// copy s2 to s1 using array subscript notation
// 
// s1 is a constant pointer to a character while
// s2 is a constant pointer to a constant character
void copy(const char * const s1, char * const s2){
    // loop through until null character 
    for (size_t i = 0; (s2[i] = s1[i]) != '\0'; i++){
        ; // don't do anything in the function body
    } 
}

// shuffle cards in deck
void shuffle(int deck[][FACES]) {
    // for each of the cards, choose slot of deck randomly
    for (size_t card = 1; card <= CARDS; ++card) {
        size_t row = 0;         // row number
        size_t column = 0;      // column number

        // choose new random location until unoccupied slot found
        // indefinite shufflement may occur in here 
        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while (deck[row][column] != 0);
        
        deck[row][column] = card; // place card number in chosen slot
    }
}

// deal cards in deck
void deal(int deck[][FACES], const char *face[], const char *suit[]) {
    // deal each of the cards
    for (size_t card = 1; card <= CARDS; card++) {
        for (size_t row = 0; row < SUITS; row++) {
            for (size_t col = 0; col < FACES; col++) {
                if (deck[row][col] == card) {
                    if (card % 4 == 0) {
                        printf("%5s of %-8s  \n", face[col], suit[row]); // newline after every 4th card
                    } else {
                        printf("%5s of %-8s  \t", face[col], suit[row]); // tab otherwise
                    }
                }
            }
        }
    }
}