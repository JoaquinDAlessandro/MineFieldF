#include <MineField/PlayerInitializers/PlayerInitializers.h>
#include <iostream>
#include <MineField/StrategyPattern/CPUStrategy.h>
#include <MineField/StrategyPattern/HumanStrategy.h>
#include <MineField/Utils/intFunctions.h>

void PlayerInitializers::classicMode(Game& game)
{
    std::string name1;
    std::string name2;
    std::cout << "enter name for player 1: ";
    std::cin >> name1;
    std::cout << "enter name for player 2: ";
    std::cin>>name2;
    int mines = game.getMinesCount();

    Player p1(name1,PlayerType::Human, std::make_unique<HumanStrategy>());
    Player p2(name2,PlayerType::Human, std::make_unique<HumanStrategy>());
    p1.setFakeMines(mines);
    p2.setFakeMines(mines);
    game.addPlayer(std::make_unique<Player>(std::move(p1)));
    game.addPlayer(std::make_unique<Player>(std::move(p2)));
}

void PlayerInitializers::soloMode(Game& game)
{
    std::string name;
    std::cout<<"enter your name: ";
    std::cin>>name;
    int mines= game.getMinesCount();
    Player player(name,PlayerType::Human, std::make_unique<HumanStrategy>());
    Player cpu("cpu", PlayerType::CPU, std::make_unique<CPUStrategy>(intFunctions::getRandomInt));
    player.setFakeMines(mines);
    cpu.setFakeMines(mines);
    game.addPlayer(std::make_unique<Player>(std::move(player)));
    game.addPlayer(std::make_unique<Player>(std::move(cpu)));
}

void PlayerInitializers::cpuVScpu(Game& game)
{
    Player cpu1("cpu 1", PlayerType::CPU, std::make_unique<CPUStrategy>(intFunctions::getRandomInt));
    Player cpu2("cpu 2", PlayerType::CPU, std::make_unique<CPUStrategy>(intFunctions::getRandomInt));
    cpu1.setFakeMines(game.getMinesCount());
    cpu2.setFakeMines(game.getMinesCount());
    game.addPlayer(std::make_unique<Player>(std::move(cpu1)));
    game.addPlayer(std::make_unique<Player>(std::move(cpu2)));
}