// Game.cpp
#include "Game.h"
#include <iostream>
using namespace std;

// Constructor
Game::Game(int r, int c, int mines) : rows(r), cols(c), mineCount(mines), gameOver(false) {
    board = new Board(rows, cols, mineCount);
}

// Destructor
Game::~Game() {
    delete board;
}

// Function to display game instructions
void Game::displayInstructions() const {
    cout << "Welcome to Minesweeper!" << endl;
    cout << "Commands:" << endl;
    cout << " - Reveal a cell: R <row> <col>" << endl;
    cout << " - Flag a cell: F <row> <col>" << endl;
    cout << " - Quit: Q" << endl;
}

// Function to process player input
void Game::processInput() {
    char command;
    int row, col;

    cout << "Enter your move: ";
    cin >> command;

    if (command == 'R' || command == 'r') {
        cin >> row >> col;
        if (board->revealCell(row, col)) {
            gameOver = true;
            cout << "BOOM! You hit a mine!" << endl;
            board->display(true); // Reveal the entire board
        }
    } else if (command == 'F' || command == 'f') {
        cin >> row >> col;
        board->toggleFlag(row, col);
    } else if (command == 'Q' || command == 'q') {
        gameOver = true;
    } else {
        cout << "Invalid command. Try again." << endl;
    }
}

// Function to start the game loop
void Game::start() {
    displayInstructions();

    while (!gameOver) {
        board->display();
        processInput();

        if (board->isCleared() && !gameOver) {
            cout << "Congratulations! You cleared the board!" << endl;
            board->display(true);
            gameOver = true;
        }
    }

    cout << "Thanks for playing!" << endl;
}
