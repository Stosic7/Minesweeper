#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board.h"
#include "Cell.h"

using namespace std;

bool Board::isValidPosition(int row, int col) const {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

int Board::countAdjacentMines(int row, int col) const {
    int count = 0;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            int newRow = row + dr;
            int newCol = col + dc;
            if (isValidPosition(newRow, newCol) && grid[newRow][newCol].hasMine()) {
                count++;
            }
        }
    }
    return count;
}

void Board::display(bool revealAll) const {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (revealAll) {
                cout << grid[r][c].display() << ' ';
            } else {
                cout << grid[r][c].display() << ' ';
            }
        }
        cout << '\n';
    }
}

// Toggles a flag on a cell
void Board::toggleFlag(int row, int col) {
    if (isValidPosition(row, col) && !grid[row][col].hasRevealed()) {
        grid[row][col].toggleFlag();
    }
}

// Checks if all non-mine cells are revealed
bool Board::isCleared() const {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (!grid[r][c].hasMine() && !grid[r][c].hasRevealed()) {
                return false;
            }
        }
    }
    return true;
}

bool Board::revealCell(int row, int col) {
    if (!isValidPosition(row, col) || grid[row][col].hasRevealed() || grid[row][col].hasFlagged()) {
        return false;
    }

    grid[row][col].reveal();

    if (grid[row][col].hasMine()) {
        return true;
    }

    if (grid[row][col].getAdjacentMines() == 0) {
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                int newRow = row + dr;
                int newCol = col + dc;
                if (isValidPosition(newRow, newCol)) {
                    revealCell(newRow, newCol);
                }
            }
        }
    }
}
