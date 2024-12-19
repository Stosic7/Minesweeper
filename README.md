# Minesweeper Console Game 🎮

A console-based implementation of the classic **Minesweeper** game, developed in **C++** with an object-oriented approach.

## How to Play
- The game starts with a grid containing hidden cells. Some cells contain mines.
- The objective is to reveal all cells that do not contain mines.
- If you reveal a cell with a mine, the game ends.
- Numbers indicate how many mines are adjacent to a revealed cell.

### Commands
1. **Reveal a cell**: `R <row> <col>`  
   - Example: `R 1 2` reveals the cell in the 1st row and 2nd column.
2. **Flag/Unflag a cell**: `F <row> <col>`  
   - Example: `F 3 4` flags the cell in the 3rd row and 4th column (or removes the flag if already flagged).
3. **Quit the game**: `Q`  
   - Example: `Q` exits the game.

### Notes
- **Rows and columns start from 0.**
- Use flags to mark suspected mines and avoid accidentally revealing them.

---

## Installation
### Requirements
- A C++ compiler (e.g., g++, Clang).
- CMake (optional for building the project).

### Author
Luka Stosic

### Gameplay Example
# Starting grid:
# # # #
# # # #
# # # #
# # # #

Enter your move: R 0 1

# Grid after revealing (0, 1):
#   1 #
# # # #
# # # #
# # # #

Enter your move: F 2 3

# Grid with a flag at (2, 3):
#   1 #
# # # #
# # # F
