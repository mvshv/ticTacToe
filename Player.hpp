#include <iostream>
#include <string>

class Player {

public:
    void setName(std::string name);
    std::string getName() const;
    void setSymbol(char symbol);
    char getSymbol() const;

    Player();
    Player(std::string name, char symbol);
    Player(const Player& other) : name(other.name), symbol(other.symbol) {}
    ~Player();

    Player& operator=(Player&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
        symbol = other.symbol;
    }
    return *this;
    }

private:
    std::string name;
    char symbol;
};