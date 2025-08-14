#include <iostream>
#include <MineField/StatePattern/ProcessingState.h>
#include <vector>
#include <MineField/StatePattern/GameOverState.h>
#include <MineField/StatePattern/PlacingMinesState.h>
#include <MineField/Player.h>

void disableOverlappingMines(std::vector<Mine>& mines1,std::vector<Mine>& mines2,Board& board) 
{
    for (Mine& m1 : mines1) 
    {
        for (Mine& m2 : mines2) 
        {
            if (m1.Active && m2.Active &&
                m1.Coordinate == m2.Coordinate) 
            {
                m1.Active = false;
                m2.Active = false;
                board.changeCoordinateStatus(m1.Coordinate.Row,m1.Coordinate.Column,CoordinateStatus::Disabled);
                std::cout << "OVERLAPPING MINES AT [" << m1.Coordinate.Row << "][" << m1.Coordinate.Column << "] ... BOTH DISABLED!\n";
            }
            else if (m1.Active)
            {
                board.changeCoordinateStatus(m1.Coordinate.Row,m1.Coordinate.Column,CoordinateStatus::Disabled);  
            }
            else if (m2.Active)
            {
                board.changeCoordinateStatus(m2.Coordinate.Row,m2.Coordinate.Column,CoordinateStatus::Disabled);
            }
        }
    }
}

enum class MineHitResult
{
     None,
     Own,
     Enemy
};

void processGuesses(const std::vector<Coordinate>& guesses, std::vector<Mine>& ownMines, std::vector<Mine>& enemyMines, Board& board) 
{
    for (const Coordinate& guess : guesses)
    {
        int row = guess.Row;
        int column = guess.Column;
        MineHitResult mineHitResult= MineHitResult::None;
        //check if the guess hits own mines
        for (Mine& m : ownMines) 
        {
            if (m.Active && m.Coordinate.Row == row && m.Coordinate.Column == column) 
            {
                m.Active = false;
                mineHitResult = MineHitResult::Own;
            }
        }
        //check if the guess hits enemy mines
        for (Mine& m : enemyMines) 
        {
            if (m.Active && m.Coordinate.Row == row && m.Coordinate.Column == column)
            {
                m.Active = false;
                mineHitResult = MineHitResult::Enemy;
            }
        }
        switch (mineHitResult)
        {
        case MineHitResult::Own:
            std::cout << "GUESS [" << row << "][" << column << "] ..... BOOM'T!! YOU HIT YOUR OWN MINE!\n";
            break;
        case MineHitResult::Enemy:
            std::cout << "GUESS [" << row << "][" << column << "] ..... BOOM!!\n";
            break;
            
        default:
            std::cout << "GUESS [" << row << "][" << column << "] .... NOTHING FOUND\n";
            break;
        }

    }
}

enum class HasActiveMines
{
    No,
    Yes
};

HasActiveMines hasActiveMines(std::vector<Mine>& mines) 
{
    for (Mine const& m : mines) 
    {
        if (m.Active)
        {
            return HasActiveMines::Yes;
        } 
    }
    return HasActiveMines::No;
}

void ProcessingState::update(Game& game) 
{
    std::cout << "Processing inputs...\n";
    Board& board = game.getBoard();
    Player& p1 = game.getPlayerAt(0);
    Player& p2 = game.getPlayerAt(1);
    std::vector<Mine>& minesP1 = p1.getMinesPlanted();
    std::vector<Mine>& minesP2 = p2.getMinesPlanted();
    const std::vector<Coordinate>& guessesP1 = p1.getCurrentGuesses();
    const std::vector<Coordinate>& guessesP2 = p2.getCurrentGuesses();
    //disable mines placed on same coordinate
    disableOverlappingMines(minesP1, minesP2, board);
    std::cout << "----" << p1.getName() << "----" << std::endl;
    //process each player's guesses
    processGuesses(guessesP1, minesP1, minesP2, board);
    std::cout << "----" << p2.getName() << "----" << std::endl;
    processGuesses(guessesP2, minesP2, minesP1, board);
    //check win conditions
    HasActiveMines p1HAM = hasActiveMines(minesP1);
    HasActiveMines p2HAM = hasActiveMines(minesP2);
    if (p1HAM == HasActiveMines::No && p2HAM == HasActiveMines::No)
    {
        game.setResult(GameResult::Draw);
        game.changeState(std::make_unique<GameOverState>());
    } 
    else if (p2HAM == HasActiveMines::No) 
    {
        game.setResult(GameResult::Player1Wins);
        game.changeState(std::make_unique<GameOverState>());
    } 
    else if (p1HAM == HasActiveMines::No) 
    {
        game.setResult(GameResult::Player2Wins);
        game.changeState(std::make_unique<GameOverState>());
    } 
    else 
    {
        //no one won yet - next round
        game.changeState(std::make_unique<PlacingMinesState>()); 
    }
}