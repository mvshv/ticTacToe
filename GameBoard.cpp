#include "GameBoard.hpp"
#include <stdlib.h>

GameBoard::GameBoard(int size) {
    this->currentSymbol = 'O';
    this->board = std::vector<std::vector<char>>(size, std::vector<char>(size, ' '));
}

GameBoard::~GameBoard() {
    std::cout << "thanks for the game! \n";
}

void GameBoard::display() {

    system("clear");
    for(int i = 0; i < board[0].size(); ++i) {
        for(int j = 0; j < board.size(); ++j) {
            std::cout << " | " << board[i][j] << " | ";

            if(j == board.size() - 1){
                std::cout << "\n";
                std::cout << "---------------------\n";
            }
        }
    }
}

void GameBoard::doMove(int x, int y) {
    if (checkMoveValid(x, y)) {
        this->board[x][y] = currentSymbol;
        changeSymbol();
    }
}

bool GameBoard::checkMoveValid(int x, int y) {
    if(board[x][y] != ' ')
        return false;
    return true;
}

bool GameBoard::checkWinner() const {

    for(int i = 0; i < board[0].size(); ++i) {
        for(int j = 0; j < board.size(); ++j) {

            if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return true;
            if(board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
                return true;
        }
    }
    return false;
}

void GameBoard::changeSymbol() {

    if(currentSymbol == 'O')
        currentSymbol = 'X';
    else currentSymbol = 'O';
}