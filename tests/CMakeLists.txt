include_directories(${GTEST_INCLUDE_DIRS})

set(GameBoardTests GameBoardTests)

add_executable(${GameBoardTests}
    GameBoardTests.cpp
    ../GameBoard.cpp
)

target_link_libraries(${GameBoardTests} GTest::GTest GTest::Main)

add_test(NAME ${GameBoardTests} COMMAND ${GameBoardTests})