#pragma once
#include <MineField/Game.h>

struct PlayerInitializers
{
    static void classicMode(GameContext& game);
    static void soloMode(GameContext& game);
    static void cpuVScpu(GameContext& game);
};