#pragma once
#include <MineField/StrategyPattern/CoordinateSelectionStrategy.h>
#include <MineField/Game.h>

class HumanStrategy : public CoordinateSelectionStrategy
{
    public:
        Coordinate const* chooseCoordinate(const Game& game, unsigned int num) override;
};