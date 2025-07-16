#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 12
#define COLS 13

// starting X and Y values of maze
int startX = 1, startY = 1;

// ending X and Y values of
int endX = 10;
int endY = 11;

// constants to generate maze
#define WALL_CHAR '#'
#define EMPTY_CHAR '.'
#define DIRECTION_UP 0
#define DIRECTION_LEFT 1
#define DIRECTION_RIGHT 2
#define DIRECTION_DOWN 3

// generate map
void depth_first_search(int current_row, int current_col, int rows, int cols, char maze[ROWS][COLS+1]);
void get_available_direction(int current_row, int current_col, int rows, int cols, char maze[ROWS][COLS+1], int available_directions[4]);

void printMaze(char maze[ROWS][COLS+1]); // print current maze 
int recursiveSolve(int x, int y, char maze[ROWS][COLS+1], char wasHere[ROWS][COLS+1], char correctPath[ROWS][COLS+1]); // prototype

// https://humbertowoody.xyz/posts/maze-generator-game-in-c#main-function
int main(void){
    srand(time(NULL));

    // allocate one more space for null 
    // terminating character
    // char maze[ROWS][COLS+1] = {
    //     "############",
    //     "#...#......#",
    //     "..#.#.####.#",
    //     "###.#....#.#",
    //     "#....###.#..",
    //     "####.#.#.#.#",
    //     "#..#.#.#.#.#",
    //     "##.#.#.#.#.#",
    //     "#........#.#",
    //     "######.###.#",
    //     "#......#...#",
    //     "############"
    // };

    // init maze
    char maze[ROWS][COLS+1];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = WALL_CHAR;
        }
        maze[i][COLS] = '\0'; // null-terminate each row
    }

    depth_first_search(1, 1, ROWS, COLS, maze);

    // set starting pos of maze
    maze[1][1] = EMPTY_CHAR;

    // set ending pos of maze
    maze[10][11] = EMPTY_CHAR;

    // maze variables
    char wasHere[ROWS][COLS+1]; 
    char correctPath[ROWS][COLS+1];

    // init was here and correct path
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS + 1; j++) {
            wasHere[i][j] = maze[i][j];
            correctPath[i][j] = maze[i][j];
        }
    }

    // print original maze
    puts("Unsolved Maze:\n");
    printMaze(maze);

    // print maze solved
    puts("\nMaze Solved:\n"); 

    // recursively solve the maze
    if (recursiveSolve(startX, startY, maze, wasHere, correctPath)){
        printMaze(correctPath);
    } else {
        printf("No solution found!\n");
    }

    return (0);
}

void depth_first_search(int current_row, int current_col, int rows, int cols, char maze[ROWS][COLS+1]){
    int available_directions[4] = {0, 0, 0, 0}, // array for storing all of the available directions for each cell
        direction;                              // the selected direction 

    do {
        maze[current_row][current_col] = EMPTY_CHAR;

        // get the updated and available directions for the current cell
        get_available_direction(current_row, current_col, rows, cols, maze, available_directions);        

        // check for the base case for our recursion: no available directions.
        if (!available_directions[DIRECTION_UP] && !available_directions[DIRECTION_DOWN] && !available_directions[DIRECTION_LEFT] && !available_directions[DIRECTION_RIGHT]){
            return;
        } 

        do {
            // Random value between 0 and 3
            direction = rand() % 4;
        } while (available_directions[direction] == 0);

        switch (direction) {
            case DIRECTION_UP:
                // Carve wall
                maze[current_row - 1][current_col] = EMPTY_CHAR;

                // Move to next cell
                depth_first_search(current_row - 2, current_col, rows, cols, maze);
                break;

            case DIRECTION_LEFT:
                maze[current_row][current_col - 1] = EMPTY_CHAR;
                depth_first_search(current_row, current_col - 2, rows, cols, maze);
                break;

            case DIRECTION_RIGHT:
                maze[current_row][current_col + 1] = EMPTY_CHAR;
                depth_first_search(current_row, current_col + 2, rows, cols, maze);
                break;

            case DIRECTION_DOWN:
                maze[current_row + 1][current_col] = EMPTY_CHAR;
                depth_first_search(current_row + 2, current_col, rows, cols, maze);
                break;
        }

    } while (available_directions[DIRECTION_UP] || available_directions[DIRECTION_DOWN] || available_directions[DIRECTION_LEFT] || available_directions[DIRECTION_RIGHT]);
}

void get_available_direction(int current_row, int current_col, int rows, int cols, char maze[ROWS][COLS+1], int available_directions[4]){
    // DIRECTION_UP
    if ((current_row - 2) >= 1 && maze[current_row - 2][current_col] == WALL_CHAR)
    {
        available_directions[DIRECTION_UP] = 1;
    }
    else
    {
        available_directions[DIRECTION_UP] = 0;
    }

    // DIRECTION_DOWN
    if ((current_row + 2) <= (rows - 2) && maze[current_row + 2][current_col] == WALL_CHAR)
    {
        available_directions[DIRECTION_DOWN] = 1;
    }
    else
    {
        available_directions[DIRECTION_DOWN] = 0;
    }

    // DIRECTION_RIGHT
    if ((current_col + 2) <= (cols - 2) && maze[current_row][current_col + 2] == WALL_CHAR)
    {
        available_directions[DIRECTION_RIGHT] = 1;
    }
    else
    {
        available_directions[DIRECTION_RIGHT] = 0;
    }

    // DIRECTION_LEFT
    if ((current_col - 2) >= 1 && maze[current_row][current_col - 2] == WALL_CHAR)
    {
        available_directions[DIRECTION_LEFT] = 1;
    }
    else
    {
        available_directions[DIRECTION_LEFT] = 0;
    }
}

int recursiveSolve(int x, int y, char maze[ROWS][COLS+1], char wasHere[ROWS][COLS+1], char correctPath[ROWS][COLS+1]){
    if (x == endX && y == endY) {
        // mark correct path and return
        correctPath[endX][endY] = 'X';
        return 1;   
    }   
    if (maze[x][y] == '#' || wasHere[x][y] == 'X') return 0;

    // if you are on a wall or already were here
    wasHere[x][y] = 'X';
    if (x != 0) { // checks if not on left edge
        if (recursiveSolve(x-1, y, maze, wasHere, correctPath)) {
            correctPath[x][y] = 'X';
            return 1;
        }
    }

    if (x != ROWS - 1) { // checks if not on right edge
        if (recursiveSolve(x+1, y, maze, wasHere, correctPath)) {
            correctPath[x][y] = 'X';
            return 1;
        }
    }

    if (y != 0){        // checks if not on top edge
        if (recursiveSolve(x, y-1, maze, wasHere, correctPath)) { 
            correctPath[x][y] = 'X';
            return 1;
        }
    }

    if (y != COLS - 1) { // checks if not on bottom edge
        if (recursiveSolve(x, y+1, maze, wasHere, correctPath)) { 
            correctPath[x][y] = 'X';
            return 1;
        }
    }

    return 0;
}

// print maze to the screen
void printMaze(char maze[ROWS][COLS+1]){
    for(size_t row = 0; row < ROWS; row++){
        for(size_t col = 0; col < COLS; col++){
            printf("%c ", maze[row][col]);
        }
        puts("");
    }
}