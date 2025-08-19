#include <MineField/PlayerInitializers/PlayerInitializers.h>
#include <iostream>
#include <MineField/StrategyPattern/CPUStrategy.h>
#include <MineField/StrategyPattern/HumanStrategy.h>
#include <MineField/Utils/intFunctions.h>

void PlayerInitializers::classicMode(GameContext& context)
{
    std::string name1;
    std::string name2;
    int m1 = 0;
    int m2 = 0;

    std::cout << "enter name for player 1: ";
    std::cin >> name1;
    std::cout << "enter number of mines for player 1: ";
    std::cin >> m1;

    std::cout << "enter name for player 2: ";
    std::cin>>name2;
    std::cout << "enter number of mines for player 2: ";
    std::cin >> m2;


    Player p1(name1,PlayerType::Human, std::make_unique<HumanStrategy>());
    Player p2(name2,PlayerType::Human, std::make_unique<HumanStrategy>());
    p1.setFakeMines(m1);
    p2.setFakeMines(m2);
    context.players.push_back(std::make_unique<Player>(std::move(p1)));
    context.players.push_back(std::make_unique<Player>(std::move(p2)));
}

void PlayerInitializers::soloMode(GameContext& context)
{
    std::string name;
    int m1;
    int m2;

    std::cout<<"enter your name: ";
    std::cin>>name;
    std::cout << "enter the number for" << name << ": ";
    std::cin >> m1;

    std::cout << "enter the number of mines for cpu:  ";
    std::cin >> m2;


    Player player(name,PlayerType::Human, std::make_unique<HumanStrategy>());
    Player cpu("cpu", PlayerType::CPU, std::make_unique<CPUStrategy>(intFunctions::getRandomInt));
    player.setFakeMines(m1);
    cpu.setFakeMines(m2);
    context.players.push_back(std::make_unique<Player>(std::move(player)));
    context.players.push_back(std::make_unique<Player>(std::move(cpu)));
}

void PlayerInitializers::cpuVScpu(GameContext& context)
{
    Player cpu1("cpu 1", PlayerType::CPU, std::make_unique<CPUStrategy>(intFunctions::getRandomInt));
    Player cpu2("cpu 2", PlayerType::CPU, std::make_unique<CPUStrategy>(intFunctions::getRandomInt));
    cpu1.setFakeMines(5);
    cpu2.setFakeMines(5);
    context.players.push_back(std::make_unique<Player>(std::move(cpu1)));
    context.players.push_back(std::make_unique<Player>(std::move(cpu2)));
}