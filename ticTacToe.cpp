#include "GameBoard.hpp"
#include "Player.hpp"

#include <iostream>
#include <string>
#include <sstream>

int main()
{

    bool playAgain = true;

    while (playAgain) {
        GameBoard board(3);
        Player player1("XXX", 'X');
        Player player2("YYY", '0');
        Player *currentPlayer = &player1;

        int x = 0;
        int y = 0;

        while (!board.checkWinner()){
            std::cout << currentPlayer->getName() << " make move: \n";

            std::cin >> x >> y;

            board.doMove(x, y);
            board.display();

            currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
        }
        std::cout << "Winner! " << currentPlayer->getName();

        std::string choice;
        std::cout << "Do you want to play again? (Y/N) ";
        std::cin >> choice;
        if (choice != "Y" && choice != "y")
            playAgain = false;
    }

    return 0;
}