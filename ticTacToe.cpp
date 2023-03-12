#include "GameBoard.hpp"
#include "Player.hpp"

#include <iostream>
#include <string>
int main() {
    GameBoard board(3);

    Player player1("Kuba");
    Player player2("Ola");
    Player* currentPlayer = &player1;
    int x = 0;
    int y = 0;

    while(!board.checkWinner()) {
    
    std::cout << "make move: \n";
    std::cin >> x >> y;
    board.doMove(x, y);
    board.display();

    currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
    }

    std::cout << "Winner! " << currentPlayer->getName();
    std::cout << "\n";
    return 0;
}