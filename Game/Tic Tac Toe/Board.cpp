#include "Board.hpp"
#include <iostream>

Board::Board() {
    grid.resize(3, std::vector<char>(3, '_'));
}

bool Board::makeMove(int row, int col, char symbol) {
    if (row < 0 || col < 0 || row >= 3 || col >= 3) return false;
    if (grid[row][col] != '_') return false;

    grid[row][col] = symbol;
    return true;
}

bool Board::hasWinner(char s) const {
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == s && grid[i][1] == s && grid[i][2] == s) return true;
        if (grid[0][i] == s && grid[1][i] == s && grid[2][i] == s) return true;
    }

    if (grid[0][0] == s && grid[1][1] == s && grid[2][2] == s) return true;
    if (grid[0][2] == s && grid[1][1] == s && grid[2][0] == s) return true;

    return false;
}

bool Board::isFull() const {
    for (auto& row : grid)
        for (char c : row)
            if (c == '_') return false;
    return true;
}

void Board::print() const {
    for (auto& row : grid) {
        for (char c : row)
            std::cout << c << " ";
        std::cout << "\n";
    }
}