#pragma once
#include "Board.h"
#include "Player.h"
#include "Mine.h"
#include "Coordinate.h"
#include "StatePattern/GameState.h"
#include <vector>
#include <iostream>
#include <functional>
#include <memory>

enum class GameResult 
{ 
    InProgress,
    Player1Wins,
    Player2Wins,
    Draw 
};
class Game
{
public:
    using PlayerInitFunc = std::function<void(Game&)>;
    Game();
    const std::vector<std::unique_ptr<Player>>& getPlayers() const ;
    Player& getPlayerAt(int i);
    Board& getBoard();
    const Board& getConstBoard() const;
    GameResult getResult() const;
    int getMinesCount() const;
    void setMineCount(int mines);
    void setResult(GameResult result);
    void changeState(std::unique_ptr<GameState> newState);
    void addPlayer(std::unique_ptr<Player> player);
    void setPlayerInitializer(PlayerInitFunc func);
    void runPlayerInitialization();
    void placeMines();
    void makeGuesses();
    void processTurn();
    void printBoard() const;
    void setBoardSize(unsigned int rows, unsigned int columns);
    void nextStep();
    void markGameAsOver();
    bool isGameActive() const;
private:
    Board mBoard;
    int mMineCount;
    std::vector<std::unique_ptr<Player>> mPlayers;
    std::unique_ptr<GameState> mCurrentState;
    GameResult mResult = GameResult::InProgress;
    PlayerInitFunc mPlayerInitFunc;
    bool mIsGameActive;
};