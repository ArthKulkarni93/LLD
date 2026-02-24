#include <vector>

class Board {
public:
    Board();

    bool makeMove(int row, int col, char symbol);
    bool hasWinner(char symbol) const;
    bool isFull() const;
    void print() const;

private:
    std::vector<std::vector<char>> grid;
};

