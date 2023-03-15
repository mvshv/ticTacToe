#include <iostream>
#include <string>

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


    ComputerPlayer (std::string name, char symbol) : Player(name, symbol, PlayerType::Computer) {}
    Move doMove() override {
        // logic to generate a computer move
        Move move;
        move.x = 1; // example move
        move.y = 2; // example move
        return move;
    }

};