#pragma once
#include <MineField/Game.h>
#include <iostream>

class SetupState : public GameState
{
public:
     void update(Game& game) override;
};
