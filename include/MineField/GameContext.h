#include <MineField/Board.h>
#include <MineField/Game.h>
#include <MineField/Player.h>

using PlayerInitFunc = std::function<void(Game&)>;

struct GameContext
{
    Board& board;                                 
    std::vector<std::unique_ptr<Player>>& players; 
    GameResult& gameResult;                        
    PlayerInitFunc playerInitFunc;    

    GameContext(Board& b, std::vector<std::unique_ptr<Player>>& p, GameResult& result, PlayerInitFunc initFunc)
    : board(b)
    , players(p)
    , gameResult(result)
    , playerInitFunc(initFunc)
    {
    }
};