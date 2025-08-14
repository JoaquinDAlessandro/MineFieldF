#pragma once
#include <MineField/StrategyPattern/CoordinateSelectionStrategy.h>
#include <MineField/Game.h>

class CPUStrategy : public CoordinateSelectionStrategy
{
    public:
        using RandomIntFunction = int(*)(unsigned int, unsigned int);
        CPUStrategy(RandomIntFunction randomFunc);
        Coordinate const* chooseCoordinate(const Game& game, unsigned int num) override;
    private:
        RandomIntFunction mRandomFunc;
};