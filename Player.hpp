#ifndef PLAYER_HPP
#define PLAYER_HPP

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

#endif //PLAYER_HPP