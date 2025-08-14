#include <MineField/StatePattern/SetupState.h>
#include <MineField/Game.h>
#include <iostream>
#include <MineField/StatePattern/PlacingMinesState.h>
#include <MineField/PlayerInitializers/PlayerInitializers.h>


void SetupState::update(Game& game)
{
    std::cout << "Welcome to Minefield!" << std::endl;
    unsigned int rows = 0;
    unsigned int columns = 0;
    int mines;

    do
    {
        std::cout << "Enter number of rows (10-50): ";
        std::cin >> rows;
    } while (rows < 10 || rows > 50);
    
    do
    {
        std::cout << "Enter number of columns (10-50): ";
        std::cin >> columns;
    } while (columns < 10 || columns > 50);

    do
    {
        std::cout << "Enter number of mines (3-8): ";
        std::cin >>mines;
    }while(mines < 3 || mines >8);

    game.setBoardSize(rows, columns);
    game.setMineCount(mines);
    int mode = 0;
    do
    {
        std::cout <<"select game mode: "<<std::endl<<"1. Human vs Human" <<std::endl << "2. Human vs CPU"<<std::endl<<"3. CPU vs CPU"<<std::endl;
        std::cin>>mode;
    } while (mode != 1 && mode != 2 && mode != 3);
    switch(mode)
    {
        case 1:
            game.setPlayerInitializer(&PlayerInitializers::classicMode);
            break;
        case 2:
            game.setPlayerInitializer(&PlayerInitializers::soloMode);
            break;
        case 3:
            game.setPlayerInitializer(&PlayerInitializers::cpuVScpu);
            break;
    }
    game.runPlayerInitialization();

    std::cout <<"LET'S START PLAYING!!!"<<std::endl;

    game.changeState(std::make_unique<PlacingMinesState>());
}
