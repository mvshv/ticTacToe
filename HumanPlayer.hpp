#include "Player.hpp"

class HumanPlayer : public Player{
public:
    HumanPlayer(std::string name, char symbol);

    Move doMove() override;
};