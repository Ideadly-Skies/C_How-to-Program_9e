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

int main(void) {
    // initialize deck array
    int deck[SUITS][FACES] = {0};

    srand(time(NULL)); // seed the random-number generator
    shuffle(deck);     // shuffle the deck

    // initialize the suit array
    // 
    // each element is actually pointer to string's first character!
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    // initialize the face array
    const char *face[FACES] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    // create a 5-hand card suit 
    int hand_suits1[HANDS];
    int hand_faces1[HANDS];

    puts("Deck 1:");
    deal(deck, face, suit, hand_suits1, hand_faces1);
    for(size_t i = 0; i < HANDS; i++){
        printf("%s of %s\n", suit[hand_suits1[i]], face[hand_faces1[i]]);
    }

    // find pairs and store it in unique_pair for deck1 
    int unique_pair1[HANDS]; 
    find_pairs(hand_faces1, unique_pair1);

    puts("");
    puts("");

    // create a 5-hand card suit 
    int deck2[SUITS][FACES] = {0};
    shuffle(deck2);

    int hand_suits2[HANDS];
    int hand_faces2[HANDS];

    puts("Deck 2:");
    deal(deck2, face, suit, hand_suits2, hand_faces2);
    for(size_t i = 0; i < HANDS; i++){
        printf("%s of %s\n", suit[hand_suits2[i]], face[hand_faces2[i]]);
    }
    puts(""); // default newline character before dect power verdict 

    // find pairs and store it in unique_pair for deck2 
    int unique_pair2[HANDS];
    find_pairs(hand_faces2, unique_pair2);

    /*
    ============================================
        
        Calculate Point For Each Deck  
    
    ============================================
    */
    // calculate point for deck1
    int deck1_points = calculatePoint(unique_pair1, hand_suits1, hand_faces1);
    int deck2_points = calculatePoint(unique_pair2, hand_suits2, hand_faces2);

    // output which deck is the stronger deck
    if (deck1_points > deck2_points){
        printf("Deck 1 is the stronger deck!\n");
    }else if (deck2_points > deck1_points){
        printf("Deck 2 is the stronger deck!\n");
    } else {
        printf("Both are equally powerful!\n");
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