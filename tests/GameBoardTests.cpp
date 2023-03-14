#include "../GameBoard.hpp"
#include <gtest/gtest.h>

TEST(GameBoardTest, CheckMoveValid) {
    GameBoard board(3);
    EXPECT_TRUE(board.checkMoveValid(0, 0));
    EXPECT_TRUE(board.checkMoveValid(0, 1));
    EXPECT_FALSE(board.checkMoveValid(10, 10));
    EXPECT_FALSE(board.checkMoveValid(-1, 1));
}

TEST(GameBoardTest, CheckWinner) {
    GameBoard board(3);
    board.doMove(0 ,0);
    board.doMove(1, 0);
    board.doMove(0, 1);
    board.doMove(1, 1);
    board.doMove(0, 2);
    EXPECT_TRUE(board.checkWinner());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}