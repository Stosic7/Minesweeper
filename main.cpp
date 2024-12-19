#include "Game.h"
#include <iostream>

int main() {
    // Set the game parameters
    int rows = 8;       // Number of rows
    int cols = 8;       // Number of columns
    int mines = 10;     // Number of mines

    std::cout << "Welcome to Minesweeper!\n";
    std::cout << "Starting a game with " << rows << " rows, " << cols << " columns, and " << mines << " mines.\n";

    // Create and start the game
    Game game(rows, cols, mines);
    game.start();

    return 0;
}
