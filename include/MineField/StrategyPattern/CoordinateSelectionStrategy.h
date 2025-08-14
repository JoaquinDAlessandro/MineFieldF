#pragma once
#include <MineField/Coordinate.h>
#include <functional>

class Game;

class CoordinateSelectionStrategy
{
    public:
        virtual ~CoordinateSelectionStrategy() = default;
        virtual Coordinate const* chooseCoordinate(const Game& game, unsigned int num) = 0;
        
};
