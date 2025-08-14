#include <iostream>
#include <MineField/StatePattern/PlacingMinesState.h>
#include <vector>
#include <MineField/StatePattern/GuessingState.h>
#include <MineField/Utils/gameFunctions.h>
#include <thread>

void PlacingMinesState::update(Game& game)
{
    std::cout << "Time to place the mines!" << std::endl;
    Player& player1 = game.getPlayerAt(0);
    Player& player2 = game.getPlayerAt(1);
    if(player1.getPlayerType() == PlayerType::CPU && player2.getPlayerType() == PlayerType::CPU)
    {
        std::thread t1(gameFunctions::logic, std::ref(game), std::ref(player2), gameFunctions::ProcessingType::Placing, 0);
        std::thread t2(gameFunctions::logic, std::ref(game), std::ref(player1), gameFunctions::ProcessingType::Placing, 0);
        t1.join();
        t2.join();
    }else
    {
        gameFunctions::logic(game, player1, gameFunctions::ProcessingType::Placing);
        gameFunctions::logic(game, player2, gameFunctions::ProcessingType::Placing);
    }
    
    
    
    std::cout << "The mines were placed!!\n";
    game.changeState(std::make_unique<GuessingState>());
} 