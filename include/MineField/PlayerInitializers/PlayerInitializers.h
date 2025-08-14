#pragma once
#include <MineField/Game.h>

struct PlayerInitializers
{
    static void classicMode(Game& game);
    static void soloMode(Game& game);
    static void cpuVScpu(Game& game);
};