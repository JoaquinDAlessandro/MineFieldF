#include <gtest/gtest.h>

#include <MineField/Board.h>
#include <MineField/Coordinate.h>
#include <MineField/Game.h>

namespace board::tests
{
TEST(Board, should_return_true_if_board_is_set_correctly)
{
    Game game;
    unsigned int rows = 10;
    unsigned int columns = 15;
    game.setBoardSize(10, 15);
    EXPECT_EQ(game.getBoard().getRows(), rows);
    EXPECT_EQ(game.getBoard().getColumns(), columns);
}

TEST(Board, should_return_nullptr_when_accesing_coordinate_if_board_is_not_initialized)
{
    Game game;
    Board board;
    int row = 10;
    int column = 10;
    Coordinate const* coord = board.getCoordinate(row, column);
    EXPECT_EQ(coord, nullptr);
}

} // namespace board::tests