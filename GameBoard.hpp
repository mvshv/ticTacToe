#include <iostream>
#include <string>
#include <vector>

class GameBoard {

    public:

    void display() const;
    void doMove(int x, int y);
    bool checkWinner() const;
    bool checkMoveValid(int x, int y) const;
    GameBoard(int size);
    ~GameBoard();

    private:
    std::vector<std::vector<char>> board;
    char currentSymbol;
    int boardSize;
    void changeSymbol();
};