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

    srand(time(NULL)); // seed the random-number generator
    shuffle(deck);     // shuffle the deck

    // initialize the suit array
    // 
    // each element is actually pointer to string's first character! (mind-blown)
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    // initialize the face array
    const char *face[FACES] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    deal(deck, face, suit);

    return (0);
}

// shuffle cards in deck
void shuffle(int deck[][FACES]) {
    // for each of the cards, choose slot of deck randomly
    for (size_t card = 1; card <= CARDS; ++card) {
        size_t row = 0;         // row number
        size_t column = 0;      // column number

        // choose new random location until unoccupied slot found
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