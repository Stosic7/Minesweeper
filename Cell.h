#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Cell {
private:
    bool isMine;       // True if the cell contains a mine
    bool isRevealed;   // True if the cell is revealed
    bool isFlagged;    // True if the cell is flagged
    int adjacentMines; // Number of mines in adjacent cells
public:
    //Constructors
    Cell() : isMine(false), isRevealed(false), isFlagged(false), adjacentMines(0) {}
    ~Cell() {}
    //Setters
    void setMine() {isMine = true;}
    void setAdjacentMines(int count) {adjacentMines = count;}
    void reveal() {isRevealed = true;}
    void toggleFlag() {isFlagged = !isFlagged;}

    //Getters
    bool hasMine() const {return isMine;}
    bool hasRevealed() const {return isRevealed;}
    bool hasFlagged() const {return isFlagged;}
    int getAdjacentMines() const {return adjacentMines;}

    //Display the cell
    char display() const {
        if (isRevealed) {
            if (isMine) {
                return '*'; // The cell contains a mine
            } else if (adjacentMines > 0) {
                return '0' + adjacentMines; // Display the number of adjacent mines
            } else {
                return ' '; // Empty cell with no adjacent mines
            }
        } else {
            if (isFlagged) {
                return 'F'; // The cell is flagged
            } else {
                return '#'; // Unrevealed cell
            }
        }
    }
};
