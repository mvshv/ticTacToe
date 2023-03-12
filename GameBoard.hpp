#include <iostream>
#include <string>
#include <vector>

class GameBoard {

    public:
    std::vector<std::vector<char>> board;
    char currentSymbol;

    void display();
    void doMove(int x, int y);
    bool checkWinner() const;
    GameBoard(int size);
    ~GameBoard();

    private:
    void changeSymbol();
    bool checkMoveValid(int x, int y);
};