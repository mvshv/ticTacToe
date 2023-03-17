#include "HumanPlayer.hpp"

HumanPlayer::HumanPlayer(std::string name, char symbol) :
    Player(name, symbol, PlayerType::Human) {}

    Move HumanPlayer::doMove() {
        Move move;
        std::cin >> move.x >> move.y;
        return move;
    }