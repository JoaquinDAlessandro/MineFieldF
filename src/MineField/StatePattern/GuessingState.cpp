#include <iostream>
#include <MineField/StatePattern/GuessingState.h>
#include <MineField/StatePattern/ProcessingState.h>
#include <MineField/Utils/gameFunctions.h>
#include <thread>

//each player gets a number of guesses equal to the number of oponent's active mines
void GuessingState::update(Game& game)
{
    std::cout << "Time to guess the mines!";
    Player& p1 = game.getPlayerAt(0);
    Player& p2 = game.getPlayerAt(1);
    //each player gets as many guesses as the number of enemy mines
    if(p1.getPlayerType() == PlayerType::CPU && p2.getPlayerType() == PlayerType::CPU)
    {
        std::thread t1(gameFunctions::logic, std::ref(game), std::ref(p1), gameFunctions::ProcessingType::Guessing, p2.getMinesCount());
        std::thread t2(gameFunctions::logic, std::ref(game), std::ref(p2), gameFunctions::ProcessingType::Guessing, p1.getMinesCount());
        t1.join();
        t2.join();
    }
    else
    {
        gameFunctions::logic(game,p1, gameFunctions::ProcessingType::Guessing, p2.getMinesCount());
        gameFunctions::logic(game,p2, gameFunctions::ProcessingType::Guessing, p1.getMinesCount());
    }
    std::cout << " All guesses processed! "<< std::endl;
    game.changeState(std::make_unique<ProcessingState>());
}