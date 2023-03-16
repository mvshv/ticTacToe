#include <iostream>
#include <string>
#include <random>
#include "GameBoard.hpp"

struct Move {
    int x;
    int y;
};

enum class PlayerType {
    Human,
    Computer
};
class Player {

public:
    void setName(std::string name);
    std::string getName() const;
    void setSymbol(char symbol);
    char getSymbol() const;
    PlayerType getTypeOfPlayer() const;
    virtual Move doMove() = 0;
    Player();
    Player(std::string name, char symbol, PlayerType type);
    Player(const Player& other) : 
        name(other.name), symbol(other.symbol), type(PlayerType::Human) {}
    ~Player();

    Player& operator=(Player&& other) noexcept {
        if(this != &other) {
            name = std::move(other.name);
            symbol = other.symbol;
            type = other.type;
        }
        return *this;
    }

private:
    std::string name;
    char symbol;
    PlayerType type;
};

class HumanPlayer : public Player{
public:
    HumanPlayer(std::string name, char symbol) : Player(name, symbol, PlayerType::Human) {}

    Move doMove() override {
        Move move;
        std::cin >> move.x >> move.y;
        return move;
    }
};

class ComputerPlayer : public Player{
public:
    ComputerPlayer(std::string name, char symbol, GameBoard& board) : 
                    Player(name, symbol, PlayerType::Computer), gameBoard(board) {}

    Move doMove() override {

        std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> dist(0, 2);
        int x = dist(rng);
        int y = dist(rng);

        Move move {x, y};
        std::cout << getName() << " makes move: " << x << ", " << y << std::endl;

        return move;
    }

    Move doMoveHeuristic() {
        int bestScore = -std::numeric_limits<int>::max();
        Move bestMove;

        // Evaluate each possible move using the heuristic function
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(gameBoard.board[i][j] == ' ') {
                    int score = evaluateMove(i, j);
                    if(score > bestScore) {
                        bestScore = score;
                        bestMove.x = i;
                        bestMove.y = j;
                    }
                }
            }
        }

        return bestMove;
    }

private:
    GameBoard &gameBoard;
    int evaluateMove(int x, int y) {
        int score = 0;

        // Check each row and column for potential wins
        for(int i = 0; i < 3; ++i) {
            if(gameBoard.board[x][i] == gameBoard.currentSymbol) {
                score += 10;
            } else if(gameBoard.board[x][i] != ' ') {
                score -= 5;
            }

            if(gameBoard.board[i][y] == gameBoard.currentSymbol) {
                score += 10;
            } else if(gameBoard.board[i][y] != ' ') {
                score -= 5;
            }
        }

        // Check the two diagonals for potential wins
        if(x == y) {
            for(int i = 0; i < 3; ++i) {
                if(gameBoard.board[i][i] == gameBoard.currentSymbol) {
                    score += 10;
                } else if(gameBoard.board[i][i] != ' ') {
                    score -= 5;
                }
            }
        }

        if(x + y == 2) {
            for(int i = 0; i < 3; ++i) {
                if(gameBoard.board[i][2-i] == gameBoard.currentSymbol) {
                    score += 10;
                } else if(gameBoard.board[i][2-i] != ' ') {
                    score -= 5;
                }
            }
        }

        return score;
    }

};