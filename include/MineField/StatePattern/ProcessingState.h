#pragma once
#include <MineField/Game.h>
#include <iostream>

class ProcessingState : public GameState
{
public:
     void update(Game& game) override;
};