#pragma once
#include <MineField/Coordinate.h>
#include <MineField/Board.h>
#include <MineField/Player.h>
#include <MineField/Game.h>

namespace gameFunctions
{
    enum class ProcessingType
    {
        Guessing,
        Placing
    };
    void logic(Game& game, Player& player, ProcessingType type, unsigned const int amount = 0);
};