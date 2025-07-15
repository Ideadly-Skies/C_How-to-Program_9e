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
#define ROUNDS 20

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

// manual replace human (improve this later)
int manualReplace(int deck[][FACES], int hand_suits[], int hand_faces[], const char** suit, const char** face);

int main(void) {
    // initialize deck array
    int deck[SUITS][FACES];
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *face[FACES] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int round = 1;
    
    // accumulated points
    int human_points_total = 0;
    int robot_points_total = 0;
    
    while (round <= ROUNDS) {
        // initialize deck for this round 
        int deck[SUITS][FACES] = {0};
        
        // shuffle deck
        srand(time(NULL));
        shuffle(deck);

        printf("%s\n", "================================================================");
        printf("\nBeginning round %d, humans total points %d, robot total points %d\n", round, human_points_total, robot_points_total);
        printf("\n%s\n", "================================================================");        

        /****************************************** 
         *                                        *     
         *     Human's Deck w/ Manual Draw        *                                                         
         *                                        *  
         ******************************************   
        */
        int hand_suits_humans[HANDS];
        int hand_faces_humans[HANDS];
        
        // initial deal (human) 
        deal(deck, face, suit, hand_suits_humans, hand_faces_humans); 
    
        // call manual_replace in here
        int isManualReplace = manualReplace(deck, hand_suits_humans, hand_faces_humans, suit, face);
    
        // after without replacement
        printf("\nHuman Deck:\n");
        for(size_t i = 0; i < HANDS; i++){
            printf("Card %zu: %s of %s\n", i+1, face[hand_faces_humans[i]], suit[hand_suits_humans[i]]);
        }
    
        /****************************************** 
         *                                        *     
         *     Computer's Deck w/ Automatic Draw  *                                                         
         *                                        *  
         ******************************************   
        */
        int hand_suits_robots[HANDS];
        int hand_faces_robots[HANDS];
        
        // initial deal (robot) 
        deal(deck, face, suit, hand_suits_robots, hand_faces_robots); 
    
        // evaluate + possibly replace cards (advantage robot)
        replaceCards(deck, hand_suits_robots, hand_faces_robots); 
    
        // after replacement
        printf("\nRobot Deck:\n");
        for(size_t i = 0; i < HANDS; i++){
            printf("Card %zu: %s of %s\n", i+1, face[hand_faces_robots[i]], suit[hand_suits_robots[i]]);
        }
    
        /****************************************** 
         *                                        *     
         *    Calculate Player Points             *                                                
         *                                        *  
         ******************************************   
        */
        
        // verdict banner
        printf("\n%s\n", "******************************************");
        printf("%s\n", "*            Round Verdict               *");
        printf("%s\n", "******************************************");

        // human points
        int human_pairs[HANDS];
        find_pairs(hand_faces_humans, human_pairs);

        int human_points = calculatePoint(human_pairs, hand_suits_humans, hand_faces_humans);
        if (isManualReplace) 
            printf("\nhuman points (with replacement): %d", human_points);
        else
            printf("\nhuman points (without replacement): %d", human_points);
    
        // robot points
        int robot_pairs[HANDS];
        find_pairs(hand_faces_robots, robot_pairs);
    
        int robot_points = calculatePoint(robot_pairs, hand_suits_robots, hand_faces_robots);
        printf("\nRobot points (with replacement): %d\n", robot_points);
        puts(""); // newline for new banner
        
        // increment points accordingly
        if (human_points > robot_points){
            human_points_total += human_points;
        } else if (robot_points > human_points) {
            robot_points_total += robot_points;
        } else {
            human_points_total++;
            robot_points_total++;
        }

        // increment round
        round++;
    }

    // display win / lose banner
    if (human_points_total > robot_points_total){
        printf("Human Win!\n"); 
    } else if (robot_points_total > human_points_total) {
        printf("Robot Win!\n");
    } else {
        printf("It's a draw!\n"); 
    }

    // thanks for playing our game!
    printf("Thanks for playing our game, see you next time!");

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

// manually replace the card (only applicable to humans)
int manualReplace(int deck[][FACES], int hand_suits[], int hand_faces[], const char** suit, const char** face){ 
    // display deck to user
    puts("\ndisplaying cards for human:\n"); 
    for(size_t i = 0; i < HANDS; i++){
        printf("%zu. %s of %s\n", i+1, face[hand_faces[i]], suit[hand_suits[i]]); 
    }

    // choose a choice
    int choice;
    printf("\ndo you wish to replace your deck of cards? (1 for yes -1 for no): ");
    scanf("%d", &choice);
    
    // replace card
    if (choice == 1){
        while (choice == 1){
            // choose choice 
            int choose;
            printf("\nselect a card to replace (-1 to quit): ");
            scanf("%d", &choose);
    
            // manual replace logic in here ... 
            int break_from_inner = -1;            
            while (choose < 1 || choose > HANDS) {
                if (choose == -1) {
                    break_from_inner = 1;
                    break;         
                }

                printf("choice %d out of bounds! please choose a valid selection (-1 to quit): ", choose);
                scanf("%d", &choose);
            }

            // escape while (choice == 1) loop 
            if (break_from_inner == 1)
                break;
            
            // draw new card for the card he/she wishes to replace
            int new_row = rand() % SUITS;
            int new_col = rand() % FACES; 
    
            while (new_row == hand_suits[choose-1] || new_col == hand_faces[choose-1]){
                new_row = rand() % SUITS;
                new_col = rand() % FACES; 
            }
    
            // printf("card %d was %s of %s.\n", choose-1, face[hand_faces[choose-1]], suit[hand_suits[choose-1]]);
    
            // assign hand_faces and hand_suits new row and col value
            hand_suits[choose-1] = new_row; 
            hand_faces[choose-1] = new_col;
    
            // printf("card %d is now %s of %s.\n", choose-1, face[hand_faces[choose-1]], suit[hand_suits[choose-1]]);
    
            // display deck after the change
            puts("\ndisplaying cards for human:\n"); 
            for(size_t i = 0; i < HANDS; i++){
                printf("%zu. %s of %s\n", i+1, face[hand_faces[i]], suit[hand_suits[i]]); 
            }
    
            // re-prompt user for choice
            printf("\ndo you wish to replace your deck of cards? (1 for yes -1 for no): ");
            scanf("%d", &choice);  
        }

        // exit out of manual card selection...
        printf("\nFinishing up manual card selection...\n");

        return 1;
    }
    
    return 0;
}