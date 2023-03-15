#include "Player.hpp"

Player::Player() {
    name = "XYZ";
    symbol = 'N';
    
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



    // Move doMove() override {
    //     // Use a random number generator to select a move
    //     std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    //     std::uniform_int_distribution<int> dist(0, 2);
    //     int x = dist(rng);
    //     int y = dist(rng);

    //     Move move = {x, y};
    //     std::cout << getName() << " makes move: " << x << ", " << y << std::endl;
    //     return move;
    // }