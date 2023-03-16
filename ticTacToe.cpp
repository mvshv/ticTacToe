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
        std::shared_ptr<Player> player1 = std::make_unique<HumanPlayer>("XXX", 'X');
        std::shared_ptr<Player> player2 = std::make_unique<ComputerPlayer>("YYY", '0');       

        std::shared_ptr<Player> currentPlayer = player1;

        int x = 0;
        int y = 0;
        board.display();

        while (!board.checkWinner() && !board.checkDraw()){
            
            bool correctMove = false;
            
            while(!correctMove) {
                std::cout << currentPlayer->getName() << " make move: \n";

                Move move = currentPlayer->doMove();
                board.display();
                if(board.doMove(move.x, move.y))
                    correctMove = true;
            }

            board.display();

            currentPlayer = (currentPlayer == player1) ? player2 : player1;

            if(currentPlayer->getTypeOfPlayer() == PlayerType::Human)
                std::cout << "NOW ITS HUMAN MOVE\n";
        }

        if(board.checkWinner())
            std::cout << "Winner! " << currentPlayer->getName();
        else
            std::cout << "DRAW!\n";

        std::string choice;
        std::cout << "Do you want to play again? (Y/N) ";
        std::cin >> choice;
        if (choice != "Y" && choice != "y")
            playAgain = false;
    }

    return 0;
}