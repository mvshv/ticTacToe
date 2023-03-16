#include "GameBoard.hpp"
#include <stdlib.h>

GameBoard::GameBoard(int size) : 
    board(size, std::vector<char>(size, ' ')),
    currentSymbol('X'),
    boardSize(size) {

    }

GameBoard::~GameBoard() {
    std::cout << "thanks for playing \n";
}

void GameBoard::display() const{

    system("clear");
    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < boardSize; ++j) {
            std::cout << " | " << board[i][j] << " | ";
        }
        std::cout << "\n\n";
    }
}

bool GameBoard::doMove(int x, int y) {
    if(checkMoveValid(x, y)) {
        this->board[x][y] = currentSymbol;
        changeSymbol();
        std::cout << "draw: " << checkDraw() << "\n";
        return true;
    }
    else
        std::cout << "Entered incorrect values\n";
    return false;
        
}

bool GameBoard::checkMoveValid(int x, int y) const{
    if(x > boardSize || x < 0 || y > boardSize || y < 0) {
        std::cout << "out of the board \n";
        return false;
    }
    if(board[x][y] != ' ') {
        std::cout << "in use \n";
        return false;
    }
    return true;
}

bool GameBoard::checkWinner() const {

    //check horizontal
    for(int i = 0; i < board[0].size(); ++i)
        if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
    //check vertical
    for(int j = 0; j < board.size(); ++j)
        if(board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return true;

    // horizontal from left top to right bottom
    for(int i = 0; i < board.size() - 2; ++i)
        if(board[i][i] != ' ' && board[i][i] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 2][i + 2])
            return true;
    // horizontal from right top to left bottom
    for(int i = 0; i < board.size() - 2; ++i)
        if(board[i][board.size() - 1] != ' ' && board[i][board.size() - 1] == board[i + 1][board.size() - 2] && board[i + 1][board.size() - 2] == board[i + 2][board.size() - 3])
            return true;


    return false;
}

bool GameBoard::checkDraw() const {
    for(int i = 0; i < board.size(); ++i)
        for(int j = 0; j < board[i].size(); ++j)
            if(board[i][j] == ' ') 
                return false;
    return true;
}

void GameBoard::changeSymbol() {
    currentSymbol = (currentSymbol == 'O') ? 'X' : 'O';
}
