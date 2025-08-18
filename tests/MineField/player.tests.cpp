#include <gtest/gtest.h>
#include <MineField/Player.h>
#include <MineField/Board.h>
#include <MineField/Game.h>

namespace player::tests
{
TEST(Player, should_return_true_if_set_player_type)
{
    Player player;
    PlayerType type = PlayerType::Human;
    player.setPlayerType(type);
    EXPECT_EQ(player.getPlayerType(), type);
}

TEST(Player, should_return_1_if_guess_was_added)
{
    Game game;
    
    Board board;
    game.setBoardSize(10, 10);
   
    Player player;
    
    Coordinate coordinate;
    coordinate.Row = 5;
    coordinate.Column = 2;
    
    player.addGuess(coordinate);

    EXPECT_EQ(player.getCurrentGuesses().size(), 1);
}

TEST(Player, should_return_1_if_mine_was_added)
{
    Game game;

    Board board;
    game.setBoardSize(10, 10);

    Player player;

    Coordinate coordinate;
    coordinate.Row = 5;
    coordinate.Column = 2;

    Mine mine;
    mine.Coordinate = coordinate;

    player.addMine(mine);

    EXPECT_EQ(player.getMinesPlanted().size(), 1);
    EXPECT_EQ(player.getMinesCount(), 1);
}

TEST(Player, should_return_0_if_player_has_no_mines_and_no_guesses)
{
    Game game;

    Board board;
    game.setBoardSize(10, 10);

    Player player;

    player.clearMines();
    EXPECT_EQ(player.getMinesCount(), 0);

    player.clearCurrentGuesses();
    EXPECT_EQ(player.getCurrentGuesses().size(), 0);
}

}