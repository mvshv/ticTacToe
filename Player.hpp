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
    ~Player();

private:
    std::string name;
    char symbol;
};