/*#include <iostream>
#include <vector>
#include <cstdlib>

const int ROWS = 10;
const int COLS = 10;
const int MINES = 15;

// Represents a cell on the Minesweeper board
struct Cell {
    bool isMine;
    bool isRevealed;
    bool isFlagged;
    int surroundingMines;
};

// Represents the entire Minesweeper board
class MinesweeperBoard {
private:
    std::vector<std::vector<Cell>> board;
    int minesRemaining;

public:
    MinesweeperBoard() {
        // Initialize the board to all unrevealed cells
        board.resize(ROWS, std::vector<Cell>(COLS));
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                board[i][j] = { false, false, false, 0 };
            }
        }

        // Place MINES mines randomly on the board
        minesRemaining = MINES;
        while (minesRemaining > 0) {
            int row = rand() % ROWS;
            int col = rand() % COLS;
            if (!board[row][col].isMine) {
                board[row][col].isMine = true;
                minesRemaining--;
            }
        }

        // Calculate the number of surrounding mines for each cell
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (!board[i][j].isMine) {
                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            int ni = i + di;
                            int nj = j + dj;
                            if (ni >= 0 && ni < ROWS && nj >= 0 && nj < COLS && board[ni][nj].isMine) {
                                board[i][j].surroundingMines++;
                            }
                        }
                    }
                }
            }
        }
    }
}
// Reveals the cell at the given row and column, and returns
// true if the cell contained a mine, false otherwise
bool revealCell(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        // Invalid cell
        return false;
    }

    Cell& cell = board[row][col];
    if (cell.isRevealed || cell.isFlagged) {
        // Cell has already been revealed or flagged, do nothing
        return false;
    }

    cell.isRevealed = true;
    if (cell.isMine) {
        // Cell contained a mine
        return true;
    }

    // Cell did not contain a mine, reveal surrounding cells
    if (cell.surroundingMines == 0) {
        revealSurroundingCells(row, col);
    }
    return false
        // Flags the cell at the given row and column
        void flagCell(int row, int col) {
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            // Invalid cell
            return;
        }

        Cell& cell = board[row][col];
        if (cell.isRevealed) {
            // Cannot flag a revealed cell
            return;
        }

        cell.isFlagged = !cell.isFlagged;
   }

    // Reveals all the cells around the given cell that do not contain mines
    void revealSurroundingCells(int row, int col) {
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                int ni = row + di;
                int nj = col + dj;
                if (ni >= 0 && ni < ROWS && nj >= 0 && nj < COLS) {
                    revealCell(ni, nj);
                }
            }
        }
    }

    // Returns true if the game is won (all non-mine cells are revealed), false otherwise
    bool isWon() {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (!board[i][j].isMine && !board[i][j].isRevealed) {
                    return false;
                }
            }
        }
        return true;
    }

    // Prints the Minesweeper board to the console
    void print() {
        std::cout << "  ";
        for (int j = 0; j < COLS; j++) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
        for (int i = 0; i < ROWS; i++) {
            std::cout << i << " ";
            for (int j = 0; j < COLS; j++) {
                Cell& cell = board[i][j];
                if (cell.isFlagged) {
                    std::cout << "F ";
                }
                else if (!cell.isRevealed) {
                    std::cout << ". ";
                }
                else if (cell.isMine) {
                    std::cout << "X ";
                }
                else {
                    std::cout << cell.surroundingMines << " ";
                }
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    MinesweeperBoard board;

    while (true) {
        std::cout << "Enter command (r row col/f row col/q): ";
        char cmd;
        int row, col;
        std::cin >> cmd >> row >> col;
        if (cmd == 'r') {
            if (board.revealCell(row, col)) {
                std::cout << "You hit a mine!" << std::endl;
                break;
            }
            if (board.isWon()) {
                std::cout << "You win!" << std::endl;
                break;
            }
        }
        else if (cmd == 'f') {
            board.flagCell(row, col);
        }
        else if (cmd == 'q') {
            break;
        }
        board.print();
    }

    return 0;
}*/

