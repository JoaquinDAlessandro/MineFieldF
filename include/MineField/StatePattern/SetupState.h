#pragma once
#include <MineField/Game.h>
#include <iostream>
#include <MineField/PlayerInitializers/PlayerInitializers.h>

void setPlayerInitializer(PlayerInitFunc playerInitFunc, GameContext& context);
void setBoardSize(int rows, int columns, GameContext& context);
void setPlayerInitializer(PlayerInitFunc playerInitFunc, GameContext& context);

class SetupState : public GameState
{
public:
     void update(Game& game) override;
};
