#include "Player.hpp"

class ComputerPlayer : public Player{
public:
    ComputerPlayer(std::string name, char symbol, GameBoard& board) : 
                    Player(name, symbol, PlayerType::Computer), gameBoard(board) {}

    Move doMove() override;
    Move doMoveHeuristic();

private:
    GameBoard &gameBoard;
    int evaluateMove(int x, int y);
};