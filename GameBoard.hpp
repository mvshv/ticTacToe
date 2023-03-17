#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include <iostream>
#include <string>
#include <vector>

class GameBoard {

    public:

    void display() const;
    bool doMove(int x, int y);
    bool checkWinner() const;
    bool checkDraw() const;
    bool checkMoveValid(int x, int y) const;
    GameBoard(int size);
    ~GameBoard();
    std::vector<std::vector<char>> board;
    char currentSymbol;
    private:


    int boardSize;
    void changeSymbol();
};

#endif //GAMEBOARD_HPP