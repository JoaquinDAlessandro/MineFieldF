#pragma once
#include "Coordinate.h"
#include <vector>
#include "Mine.h"
#include <iostream>
#include "StrategyPattern/CoordinateSelectionStrategy.h"
#include <memory>

enum class PlayerType
{
    Human,
    CPU
};

class Player
{
public:
    Player(const std::string& name, PlayerType playerType, std::unique_ptr<CoordinateSelectionStrategy> selectionStrategy);
    Player();
    Player(Player&&) noexcept = default;
    Player& operator=(Player&&) noexcept = default;
    const std::string& getName() const;
    PlayerType& getPlayerType() ;
    std::vector<Mine>& getMinesPlanted();
    const std::vector<Coordinate>& getCurrentGuesses() const;
    void setName(const std::string& name);
    void setPlayerType(PlayerType& playerType);
    void setFakeMines(const int& amount);
    void addGuess(const Coordinate& coordinate);
    void addMine(const Mine& mine);
    void clearMines();
    void clearCurrentGuesses();
    unsigned int getMinesCount() const;
    CoordinateSelectionStrategy* getSelectionStrategy() const;
    void setSelectionStrategy(const std::unique_ptr<CoordinateSelectionStrategy> selectionStrategy);
private:
    std::string mName;
    PlayerType mPlayerType;
    std::vector<Mine> mMinesPlanted;
    std::vector<Coordinate> mCurrentGuesses;
    std::unique_ptr<CoordinateSelectionStrategy> mSelectionStrategy;
};