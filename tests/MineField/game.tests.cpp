#include <gtest/gtest.h>
#include <MineField/Game.h>
#include <MineField/Player.h>
#include <MineField/StatePattern/PlacingMinesState.h>

namespace game::tests
{
TEST(Game, player_count_should_be_1_after_adding)
{
    Game game;
    std::unique_ptr<Player> player = std::make_unique<Player>();
    game.addPlayer(std::move(player));
    unsigned int size = game.getPlayers().size();
    EXPECT_EQ(size, 1);
}

TEST(Game, isGameActive_should_return_false_if_game_is_marked_as_over)
{
    Game game;
    game.markGameAsOver();
    EXPECT_EQ(game.isGameActive(), false);
}

TEST(Game, should_return_true_if_result_was_set)
{
    Game game;
    game.setResult(GameResult::Player1Wins);
    EXPECT_EQ(game.getResult(), GameResult::Player1Wins);
}


}
