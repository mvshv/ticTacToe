#include "Player.hpp"

Player::Player() {
    name = "XYZ";
    symbol = 'N';
}

Player::Player(std::string setName, char symbol) : 
    name(setName), symbol(symbol) { }

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

char Player::getSymbol() const{
    return symbol;
}