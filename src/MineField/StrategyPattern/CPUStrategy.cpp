#include <MineField/StrategyPattern/CPUStrategy.h>
#include <MineField/StrategyPattern/CoordinateSelectionStrategy.h>
#include <MineField/Utils/intFunctions.h>
#include <iostream>


CPUStrategy::CPUStrategy(RandomIntFunction randomFunc)
:mRandomFunc(randomFunc)
{
        
}

Coordinate const* CPUStrategy::chooseCoordinate (const Game& game, unsigned int num)
{
        const Board& board = game.getConstBoard();
        unsigned int row = 0;
        unsigned int column = 0;
        row = mRandomFunc(0,board.getRows());
        column = mRandomFunc(0,board.getColumns());
        return board.getCoordinate(row,column);
}