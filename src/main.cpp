#include <iostream>
#include <MineField/Game.h>
#include <cstdlib>
int main() 
{
    Game game;
    while (game.isGameActive()) 
    { 
        game.nextStep();
    }
    return 0;
}