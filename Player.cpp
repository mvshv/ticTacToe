#include "Player.hpp"

Player::Player() {
    name = "XYZ";
    symbol = 'N';
    type = PlayerType::Human;
}

Player::Player(std::string setName, char symbol, PlayerType type) : 
    name(setName), symbol(symbol), type(PlayerType::Human) { }

Player::~Player() {
    std::cout << "delete player\n";
}

void Player::setName(std::string name) {
    this->name = name;
}

std::string Player::getName() const {
    return name;
}

void Player::setSymbol(char symbol) {
    this->symbol = symbol;
}

char Player::getSymbol() const {
    return symbol;
}

PlayerType Player::getTypeOfPlayer() const {
    return type;
}
