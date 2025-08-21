#include <MineField/Board.h>
#include <MineField/Game.h>
#include <MineField/Player.h>
#include <MineField/StatePattern/GameState.h>

struct GameContext
{
    using PlayerInitFunc = std::function<void(GameContext&)>;
    std::reference_wrapper<Board> board;
    std::vector<std::unique_ptr<Player>> players;
    std::reference_wrapper<GameResult> gameResult;
    PlayerInitFunc playerInitFunc;
    std::unique_ptr<GameState> currentState;

    GameContext(Board& b, std::vector<std::unique_ptr<Player>>& players, GameResult& result, PlayerInitFunc initFunc, std::unique_ptr<GameState> currentState)
    : board(b)
    , players(std::move(players))
    , gameResult(result)
    , playerInitFunc(initFunc)
    , currentState(std::move(currentState))
    {
    }

    void runPlayerInitialization()
    {
        if (playerInitFunc)
        {
            playerInitFunc(*this);
        }
    }
};