#include <iostream>
#include <string>

class Player {

public:
    std::string name;
    char symbol;
    std::string getName();

    Player(std::string setName);
    ~Player();
};