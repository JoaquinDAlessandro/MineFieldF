#include "MineField/Coordinate.h"
#include <MineField/StatePattern/GameState.h>
#include <MineField/StatePattern/GameOverState.h>
#include <MineField/StatePattern/SetupState.h>
#include <iostream>
#include "MineField/Game.h"

Game::Game()
    : mBoard()
    , mMineCount(0)
    , mPlayers()
    , mCurrentState(std::make_unique<SetupState>())
    , mResult(GameResult::InProgress) 
    , mPlayerInitFunc(nullptr)
    , mIsGameActive(true)
    , gameContext(mBoard, mPlayers, mPlayerInitFunc)
{
}

 const std::vector<std::unique_ptr<Player>>& Game::getPlayers() const
{
    return mPlayers;
}

Player& Game::getPlayerAt(int i)
{
    if (i < 0 || i >= mPlayers.size()) {
        throw std::out_of_range("Index is out of range");
    }
    Player* playerPtr = mPlayers.at(i).get();
    if (playerPtr == nullptr) {
        throw std::runtime_error("Player pointer is null");
    }
    return *playerPtr; 
}

Board& Game::getBoard()
{
    return mBoard;
}

const Board& Game::getConstBoard() const
{
    return mBoard;
}

GameResult Game::getResult() const
{
    return mResult;
}

int Game::getMinesCount() const
{
    return mMineCount;
}

void Game::setMineCount(int mines)
{
    this->mMineCount = mines;
}

void Game::setResult(GameResult result) 
{
    mResult = result;
}

void Game::setPlayerInitializer(PlayerInitFunc func)
{
    mPlayerInitFunc = func;
}

void Game::runPlayerInitialization()
{
    if (mPlayerInitFunc)
    {
        mPlayerInitFunc(gameContext);
    }
}

void Game::addPlayer(std::unique_ptr<Player> player)
{
    if(player!= nullptr)
    {
        mPlayers.push_back(std::move(player));
    }

}

static char const* toString(CoordinateStatus status)
{
    switch (status)
    {
        case CoordinateStatus::Available:
            return "O";
        case CoordinateStatus::HasMines:
            return "O";
        case CoordinateStatus::DetectedMine:
            return "X";
        case CoordinateStatus::Disabled:
            return "X";
        default:
            return "?";
    }
}

void Game::printBoard() const 
{
    mBoard.printMapFormatted([](const Coordinate& coord) -> char const*
    {
        return toString(coord.Status);
    });
}

void Game::changeState(std::unique_ptr<GameState> newState) {
    mCurrentState = std::move(newState);
}

void Game::setBoardSize(unsigned int rows, unsigned int columns)
{
    mBoard = Board(rows,columns);
}

void Game::nextStep()
{
    mCurrentState->update(*this);
}

void Game::markGameAsOver()
{
    mIsGameActive = false;

}

bool Game::isGameActive() const
{
    return mIsGameActive;
}

GameContext& Game::getGameContext()
{
    return gameContext;
}
