
#include "Board.hpp"

class Game {
public:
    Game();
    void play();

private:
    Board board;
    char current;  // 'X' or 'O'
    void switchTurn();
};
