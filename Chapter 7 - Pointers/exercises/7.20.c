#include <stdio.h>
#include <stdlib.h>

#define ROWS 12
#define COLS 13

// starting X and Y values of maze
int startX = 2, startY = 0;

// ending X and Y values of
int endX = 4;
int endY = 11;     

void printMaze(char maze[ROWS][COLS+1]); // print current maze 
int recursiveSolve(int x, int y, char maze[ROWS][COLS+1], char wasHere[ROWS][COLS+1], char correctPath[ROWS][COLS+1]); // prototype

int main(void){
    // allocate one more space for null 
    // terminating character
    char maze[ROWS][COLS+1] = {
        "############",
        "#...#......#",
        "..#.#.####.#",
        "###.#....#.#",
        "#....###.#..",
        "####.#.#.#.#",
        "#..#.#.#.#.#",
        "##.#.#.#.#.#",
        "#........#.#",
        "######.###.#",
        "#......#...#",
        "############"
    };

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