#pragma once
#include <MineField/Game.h>
#include <iostream>

class GameOverState : public GameState
{
public:
     void update(Game& game) override;
};
