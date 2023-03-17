cmake_minimum_required(VERSION 3.19)

project(TicTacToe)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(TicTacToe
    ticTacToe.cpp
    GameBoard.cpp
    Player.cpp
    ComputerPlayer.cpp
    HumanPlayer.cpp
)

add_subdirectory(tests)