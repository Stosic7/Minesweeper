// Game.h
#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include <iostream>

class Game {
private:
    Board* board;  // Pointer to the game board
    int rows;
    int cols;
    int mineCount;
    bool gameOver;

public:
    // Constructor
    Game(int rows, int cols, int mines);

    // Destructor
    ~Game();

    // Function to start the game loop
    void start();

private:
    // Function to process player input
    void processInput();

    // Function to display game instructions
    void displayInstructions() const;
};

#endif // GAME_H
