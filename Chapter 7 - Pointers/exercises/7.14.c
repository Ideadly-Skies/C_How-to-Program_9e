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
void deal(int deck[][FACES], const char *face[], const char *suit[], int hand_suits[], int hand_faces[]);
void find_pairs(int hand_faces[], int unique_pair[]); 
// award points based on function               // points
int contains_pair(int unique_pair[]);           // 1
int contains_two_pairs(int unique_pair[]);      // 2
int contains_three_pairs(int unique_pair[]);    // 3
int four_of_a_kind(int unique_pair[]);          // 4
int flush(int hand_suits[]);                    // 5
int straight(int hand_faces[]);                 // 6

// calculate points for deck
int calculatePoint(int unique_pair[], int hand_suits[], int hand_faces[]);

// mark deck entry as unvisited other than hand_suits and hand_faces
void drawNewCard(int deck[][FACES], int *suit, int *face);
void replaceCards(int deck[][FACES], int hand_suits[], int hand_faces[]);

int main(void) {
    // initialize deck array
    int deck[SUITS][FACES] = {0};
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *face[FACES] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int hand_suits[HANDS];
    int hand_faces[HANDS];

    srand(time(NULL)); // seed the random-number generator
    shuffle(deck);
    
    // initial deal
    deal(deck, face, suit, hand_suits, hand_faces); 

    printf("Initial Hand:\n");
    for(size_t i = 0; i < HANDS; i++){
        printf("Card %zu: %s of %s\n", i+1, face[hand_faces[i]], suit[hand_suits[i]]);
    }

    // store unique pairs in pairs 
    int pairs[HANDS];
    find_pairs(hand_faces, pairs); 
    
    // calculate points of initial deck
    int points = calculatePoint(pairs, hand_suits, hand_faces);
    printf("\noriginal deck points: %d\n", points);
   
    // evaluate + possible replace cards
    replaceCards(deck, hand_suits, hand_faces); 

    // after replacement
    printf("\nAfter Replacement:\n");
    for(size_t i = 0; i < HANDS; i++){
        printf("Card %zu: %s of %s\n", i+1, face[hand_faces[i]], suit[hand_suits[i]]);
    }

    // store unique pairs in pairs
    int new_pairs[HANDS]; 
    find_pairs(hand_faces, new_pairs);

    // calculate points of modified deck
    points = calculatePoint(new_pairs, hand_suits, hand_faces);
    printf("\nModified deck points: %d\n", points);
    
    puts("\npairs:");     
    for (size_t i = 0; i < HANDS; i++){
        if (pairs[i] != -1) printf("pair %zu: %s\n", i+1, face[new_pairs[i]]);
    }

    return (0);
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
void deal(int deck[][FACES], const char *face[], const char *suit[], int hand_suits[], int hand_faces[]) {
    // deal each of the cards
    for (size_t card = 1; card <= 5 ; card++) {
        for (size_t row = 0; row < SUITS; row++) {
            for (size_t col = 0; col < FACES; col++) {
                if (deck[row][col] == card) {
                    hand_suits[card-1] = row;   
                    hand_faces[card-1] = col;
                }
            }
        }
    }
}

void find_pairs(int hand_faces[], int unique_pair[]){
    int k = 0;
    int last_element = -1;

    for(size_t i = 0; i < HANDS; i++) {
        for(size_t j = i + 1; j < HANDS; j++) {
            if (hand_faces[i] == hand_faces[j]) {
                if (hand_faces[i] != last_element) {
                    unique_pair[k++] = hand_faces[i];
                    last_element = hand_faces[i];
                }
            }
        }
    }

    // fill remaining with -1 (optional)
    for (; k < HANDS; k++) {
        unique_pair[k] = -1;
    }
}

// this is bad practice... am i right?
int contains_pair(int unique_pair[]){
    int count = 0;
    for(size_t i = 0; i < HANDS; i++){
        if (unique_pair[i] != -1) count++;
    }
    return count == 1;
}

int contains_two_pairs(int unique_pair[]){
    int count = 0;
    for(size_t i = 0; i < HANDS; i++){
        if (unique_pair[i] != -1) count++;
    }
    return count == 2;
}

int contains_three_pairs(int unique_pair[]){
    int count = 0;
    for(size_t i = 0; i < HANDS; i++){
        if (unique_pair[i] != -1) count++;
    }
    return count == 3; 
}

int four_of_a_kind(int unique_pair[]){
    int count = 0;
    for(size_t i = 0; i < HANDS; i++){
        if (unique_pair[i] != -1) count++;
    }
    return count == 4; 
}

int flush(int hand_suit[]){
    int last_hand = hand_suit[0];
    int count = 1;

    for(size_t i = 1; i < HANDS; i++){
        if (hand_suit[i] == last_hand) count++;
    }
    return count == HANDS;
}

int straight(int hand_face[]){
    int temp[HANDS];
    
    // copy to temp array to avoid modifying the original
    for(int i = 0; i < HANDS; i++){
        temp[i] = hand_face[i];
    }

    // sort the array (simple bubble sort)
    for(int i = 0; i < HANDS-1; i++){
        for(int j = 0; j < HANDS - i - 1; j++){
            if (temp[j] > temp[j+1]){
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            } 
        }
    }

    // check if values are consecutive
    for(int i = 0; i < HANDS-1; i++){
        if(temp[i+1] != temp[i]+1) return 0;
    }

    // valid straight
    return 1;
}

int calculatePoint(int unique_pair[], int hand_suits[], int hand_faces[]){
    int points = 0; 
    if (contains_pair(unique_pair)){
        points += 1;
    }
    else if (contains_two_pairs(unique_pair)){
        points += 2;
    }
    else if (contains_three_pairs(unique_pair)) {
        points += 3;
    }
    else if (four_of_a_kind(unique_pair)){
        points += 4;
    }
    else if (flush(hand_suits)){
        points += 5;
    }
    else if (straight(hand_faces)){
        points += 6;
    }
    return points;
}

void drawNewCard(int deck[][FACES], int *suit, int *face){
    for(size_t row = 0; row < SUITS; row++){
        for(size_t col = 0; col < FACES; col++){
            if (deck[row][col] > 5) {
                *suit = row;
                *face = col;
                deck[row][col] = 0; 
                return;
            }
        }
    } 
}

void replaceCards(int deck[][FACES], int hand_suits[], int hand_faces[]){
    int unique_pair[HANDS];
    find_pairs(hand_faces, unique_pair);

    int points = calculatePoint(unique_pair, hand_suits, hand_faces);
    int keep[HANDS] = {0}; // 1 = keep, 0 = replace    

    if (points >= 3) {
        return; // strong hand - keep all
    }

    else if (contains_two_pairs(unique_pair)){
        for (int i = 0; i < HANDS; i++){
            for (int j = 0; j < HANDS; j++){
                if (hand_faces[i] == unique_pair[i]) keep[i] = 1;
            }
        }
    }

    else if (contains_pair(unique_pair)){
        for (int i = 0; i < HANDS; i++){
            if (hand_faces[i] == unique_pair[0]) keep[i] = 1;
        }
    }

    // else points == 0 -> replace all (default keep[i] = 0)

    for(int i = 0; i < HANDS; i++){
        if (!keep[i]){
            drawNewCard(deck, &hand_suits[i], &hand_faces[i]);
        }
    }
}