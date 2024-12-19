#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include "Cell.h"

class Board {
private:
    int rows;                     // Number of rows on the board
    int cols;                     // Number of columns on the board
    int mineCount;                // Total number of mines
    Cell** grid;                  // 2D array of Cell objects

    bool isValidPosition(int row, int col) const;
    int countAdjacentMines(int row, int col) const;

public:
    // Constructor
    Board(int r, int c, int mines) : rows(r), cols(c), mineCount(mines) {
        // Allocate memory for the 2D array
        grid = new Cell*[rows];
        for (int i = 0; i < rows; ++i) {
            grid[i] = new Cell[cols];
        }

        // Randomly place mines
        srand(static_cast<unsigned>(time(0)));
        int placedMines = 0;
        while (placedMines < mineCount) {
            int row = rand() % rows;
            int col = rand() % cols;
            if (!grid[row][col].hasMine()) {
                grid[row][col].setMine();
                placedMines++;
            }
        }

        // Calculate adjacent mines for each cell
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (!grid[r][c].hasMine()) {
                    grid[r][c].setAdjacentMines(countAdjacentMines(r, c));
                }
            }
        }
    }

    // Destructor
    ~Board() {
        for (int i = 0; i < rows; ++i) {
            delete[] grid[i];
        }
        delete[] grid;
    }

    void display(bool revealAll = false) const;
    bool revealCell(int row, int col);
    // Toggles a flag on a cell
    void toggleFlag(int row, int col);
    // Checks if all non-mine cells are revealed
    bool isCleared() const;


};
