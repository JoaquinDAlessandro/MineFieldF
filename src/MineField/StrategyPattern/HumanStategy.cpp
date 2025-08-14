#include <MineField/StrategyPattern/HumanStrategy.h>
#include <MineField/StrategyPattern/CoordinateSelectionStrategy.h>

Coordinate const* HumanStrategy::chooseCoordinate (const Game& game, unsigned int num)
{
        Board const& board = game.getConstBoard();
        unsigned int row = 0;
        unsigned int column = 0;
        game.printBoard();
        std::cout << "Enter row for #" << num << ": " << std::endl;
        std::cin >> row;
        std::cout << "Enter column for #" << num << ": " << std::endl;
        std::cin >> column;
        Coordinate const* coordPtr = board.getCoordinate(row, column);
        return coordPtr;

}