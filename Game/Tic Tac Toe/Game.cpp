#include "Game.hpp"
#include <iostream>

Game::Game() : current('X') {}

void Game::switchTurn() {
    current = (current == 'X') ? 'O' : 'X';
}

void Game::play() {
    while (true) {
        board.print();
        std::cout << "Player " << current << " move (row col): ";

        int r, c;
        std::cin >> r >> c;

        if (!board.makeMove(r, c, current)) {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        if (board.hasWinner(current)) {
            board.print();
            std::cout << "Player " << current << " wins \n";
            break;
        }

        if (board.isFull()) {
            board.print();
            std::cout << "Draw \n";
            break;
        }

        switchTurn();
    }
}