#include <MineField/StatePattern/GameOverState.h>
#include <iostream>

void GameOverState::update(Game& game) 
{
    std::cout << "\n===== GAME OVER ====="<<std::endl;
    GameResult result = game.getResult();
    if (result == GameResult::Player1Wins) {
        std::cout << game.getPlayerAt(0).getName() << " WINS!"<<std::endl;
    } else if (result == GameResult::Player2Wins) {
        std::cout << game.getPlayerAt(1).getName() << " WINS!"<<std::endl;
    } else if (result == GameResult::Draw) {
        std::cout << "It's a draw!" <<std::endl;
    }
    game.markGameAsOver();
}