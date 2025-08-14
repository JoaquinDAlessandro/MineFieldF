#pragma once
#include <MineField/Game.h>
#include <iostream>

class PlacingMinesState : public GameState
{
public:
     void update(Game& game) override;
};