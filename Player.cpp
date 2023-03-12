#include "Player.hpp"

Player::Player(std::string setName) {
    this->name = setName;
}

Player::~Player() {
    std::cout << "delete player\n";
}

std::string Player::getName() {
    return name;
}