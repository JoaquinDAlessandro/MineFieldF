#pragma once
#include <MineField/Game.h>
#include <iostream>

class SetupState : public GameState
{
public:
     void update(Game& game) override;
private:
     void setBoardSize(int rows, int columns, GameContext& context);
     void setPlayerInitializer(PlayerInitFunc& playerInitFunc, GameContext& context);

};
