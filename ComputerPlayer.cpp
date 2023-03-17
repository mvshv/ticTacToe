#include "ComputerPlayer.hpp"

Move ComputerPlayer::doMove() {

    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(0, 2);
    int x = dist(rng);
    int y = dist(rng);

    Move move{x, y};
    std::cout << getName() << " makes move: " << x << ", " << y << std::endl;

    return move;
}

Move ComputerPlayer::doMoveHeuristic()
{
    int bestScore = -std::numeric_limits<int>::max();
    Move bestMove;

    // Evaluate each possible move using the heuristic function
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (gameBoard.board[i][j] == ' ')
            {
                int score = evaluateMove(i, j);
                if (score > bestScore)
                {
                    bestScore = score;
                    bestMove.x = i;
                    bestMove.y = j;
                }
            }
        }
    }
    return bestMove;
}

int ComputerPlayer::evaluateMove(int x, int y)
{
    int score = 0;

    // Check each row and column for potential wins
    for (int i = 0; i < 3; ++i)
    {
        if (gameBoard.board[x][i] == gameBoard.currentSymbol)
            score += 10;

        else if (gameBoard.board[x][i] != ' ')
            score -= 5;

        if (gameBoard.board[i][y] == gameBoard.currentSymbol)
            score += 10;

        else if (gameBoard.board[i][y] != ' ')
            score -= 5;
    }

    // Check the two diagonals for potential wins
    if (x == y)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (gameBoard.board[i][i] == gameBoard.currentSymbol)
                score += 10;

            else if (gameBoard.board[i][i] != ' ')
                score -= 5;
        }
    }

    if (x + y == 2)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (gameBoard.board[i][2 - i] == gameBoard.currentSymbol)
                score += 10;

            else if (gameBoard.board[i][2 - i] != ' ')
                score -= 5;
        }
    }

    return score;
}