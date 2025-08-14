
#include <MineField/Coordinate.h>
#include <vector>
#include <MineField/Mine.h>
#include <MineField/Player.h>
#include <iostream>

Player::Player(const std::string& name ,PlayerType playerType, std::unique_ptr<CoordinateSelectionStrategy> selectionStrategy )
:mName(name)
,mPlayerType(playerType)
,mMinesPlanted()
,mCurrentGuesses()
,mSelectionStrategy(std::move(selectionStrategy))
{

}

Player::Player() = default;

const std::string& Player::getName() const
{
    return mName;
}

PlayerType& Player::getPlayerType()
{
    return mPlayerType;
}

std::vector<Mine>& Player::getMinesPlanted()
{
    return mMinesPlanted;
}

const std::vector<Coordinate>& Player::getCurrentGuesses() const
{
    return mCurrentGuesses;
}

void Player::setName(const std::string& name) 
{
    mName = name;
}

void Player::setPlayerType(PlayerType& playerType)
{
    mPlayerType = playerType;
}

void Player::setFakeMines(const int& amount)
{
    for(int i = 0 ; i<amount ; i++)
    {
        mMinesPlanted.push_back(Mine{true, Coordinate{0,0,CoordinateStatus::Disabled}});
    };
}

void Player::addGuess(const Coordinate& coordinate)
{
    mCurrentGuesses.push_back(coordinate);
}

void Player::addMine(const Mine& mine)
{
    mMinesPlanted.push_back(mine);
}

void Player::clearMines()
{
    mMinesPlanted.clear();
    
}

void Player::clearCurrentGuesses()
{
    mCurrentGuesses.clear();
}

unsigned int Player::getMinesCount() const
{
    unsigned int activeMines = 0;
    for (const Mine& m : mMinesPlanted)
    {
        if (m.Active)
        {
            activeMines++;
        }
    }
    return activeMines;
}

void Player::setSelectionStrategy(std::unique_ptr<CoordinateSelectionStrategy> selectionStrategy)
{
    mSelectionStrategy = std::move(selectionStrategy);
}

CoordinateSelectionStrategy* Player::getSelectionStrategy() const
{
    return mSelectionStrategy.get();
}