#include <MineField/Utils/gameFunctions.h>
#include <MineField/Utils/intFunctions.h>

namespace gameFunctions
{
    void logic(Game& game, Player& player, ProcessingType type, unsigned const int  amount)
    {
        std::cout << player.getName() << "'s turn!" << std::endl;
        unsigned int limit = 0;
        unsigned int n = 0;
        Board& board = game.getBoard();

        if (type == ProcessingType::Guessing)
        {
            if ( amount == 0)
            {
                std::cout << "You have no guesses left!"  << std::endl;
                return;
            }
            limit = amount;
            player.clearCurrentGuesses();
        }
        if (type == ProcessingType::Placing)
        {
            limit = player.getMinesCount();
            player.clearMines();

            if(limit == 0)
            {
                std::cout << "You have no mines left!" << std::endl;
                return;
            }
        }
            while (n < limit)
            {
                Coordinate const* coordPtr = player.getSelectionStrategy()->chooseCoordinate(game, n+1);
                if (coordPtr == nullptr) 
                {
                    std::cout << "Invalid coordinate. Try again."<< std::endl;
                }
                else
                {
                    if(type == ProcessingType::Placing)
                    {
                        player.addMine(Mine{true, *coordPtr});
                        board.changeCoordinateStatus(coordPtr->Row, coordPtr->Column, CoordinateStatus::HasMines);
                    }
                    else
                    {
                        player.addGuess(*coordPtr);
                        board.changeCoordinateStatus(coordPtr->Row, coordPtr->Column, CoordinateStatus::Disabled);
                    }
                    n++;
                } 

            }
    }
};
