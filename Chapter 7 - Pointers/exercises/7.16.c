// fig07_16.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

// prototypes
void shuffle(int deck[][FACES]);
void deal(int deck[][FACES], const char *face[], const char *suit[]);

int main(void) {
    // initialize deck array
    int deck[SUITS][FACES] = {0};
    int card = 1;
    for(size_t row = 0; row < SUITS; row++){
        for(size_t col = 0; col < FACES; col++){
            deck[row][col] = card;
            card++; 
        }
    }

    srand(time(NULL)); // seed the random-number generator
    shuffle(deck);     // shuffle the deck

    // initialize the suit array
    // 
    // each element is actually pointer to string's first character! (mind-blown)
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    // initialize the face array
    const char *face[FACES] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    deal(deck, face, suit);

    return (0);
}

// shuffle cards in deck
void shuffle(int deck[][FACES]) {
    for(size_t row = 0; row < SUITS; row++){
        for(size_t col = 0; col < FACES; col++){
            // generate new row and col 
            size_t new_row = rand() % SUITS;
            size_t new_col = rand() % FACES;;

            // swap entries
            int temp = deck[row][col];            
            deck[row][col] = deck[new_row][new_col];
            deck[new_row][new_col] = temp;
        }
    }     
}

// deal cards in deck
void deal(int deck[][FACES], const char *face[], const char *suit[]) {
    int count = 0; 
    for (size_t row = 0; row < SUITS; row++) {
        for (size_t col = 0; col < FACES; col++) {
            int card = deck[row][col];

            // Convert card number (1–52) into suit/face index
            int suit_index = card / FACES;
            int face_index = card % FACES;

            // Fix edge case: multiples of 13 (i.e., 13, 26, 39, 52)
            if (face_index == 0) {
                // 13 % 13 = 12
                face_index = 12;       
                suit_index -= 1;
            } else {
                // 12 % 13 = 12 (decrement by one)
                face_index -= 1;       
            }

            printf("%5s of %-8s\t", face[face_index], suit[suit_index]);
            if (++count % 4 == 0) printf("\n");
        }
    }
}