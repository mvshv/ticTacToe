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
        std::shared_ptr<Player> player1 = std::make_unique<Player>("XXX", 'X');
        std::shared_ptr<Player> player2 = std::make_unique<Player>("YYY", '0');       

        std::shared_ptr<Player> currentPlayer = player1;

        int x = 0;
        int y = 0;

        while (!board.checkWinner()){
            std::cout << currentPlayer->getName() << " make move: \n";

            std::cin >> x >> y;

            board.doMove(x, y);
            board.display();

            currentPlayer = (currentPlayer == player1) ? player2 : player1;
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