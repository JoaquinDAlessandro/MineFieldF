#include <iostream>
#include <vector>
#include <Minefield/Board.h>
#include <Minefield/Coordinate.h>
#include <iomanip> 

Board::Board(unsigned int rows, unsigned int columns)
:mRows(rows)
, mColumns(columns)
{
    for(unsigned int i = 0 ; i < mRows ; i++)
    {
        for(unsigned int j = 0 ; j<mColumns ; j++)
        {
            mCoordinates.push_back(Coordinate{i,j,CoordinateStatus::Available});
            
        }
    }
        
}

Coordinate const* Board::getCoordinate(int row, int column) const 
{
    for (Coordinate const& coord : mCoordinates) 
    {
        if (coord.Row == row && coord.Column == column) 
        {
            return &coord;
        }
    }
    return nullptr;
}

int Board::getRows() const
{
    return mRows;
}

int Board::getColumns() const
{
    return mColumns;
}

void Board::changeCoordinateStatus(int row, int column, CoordinateStatus newStatus)
{
    std::lock_guard<std::mutex> lock(mtx);
    for (Coordinate& coordinate : mCoordinates) 
    {
        if (coordinate.Column == column && coordinate.Row == row) 
        {
            coordinate.Status = newStatus; 
            return;
        }
    }
}
//prints the board using a custom symbol function to determine how each cell is printed
void Board::printMapFormatted(CoordinateToStringFunc symbolFunc) const 
{
    if (symbolFunc != nullptr)
    {
        std::cout << "    ";
        for (int c = 0; c < mColumns; ++c) 
        {
            std::cout << std::setw(3) << c;
        }
        std::cout << std::endl;

        for (int r = 0; r < mRows; ++r) 
        {
            std::cout << std::setw(3) << r << ' '; 

            for (int c = 0; c < mColumns; ++c) 
            {
                for (const auto& coord : mCoordinates) 
                {
                    if (coord.Row == r && coord.Column == c) 
                    {
                        std::cout << std::setw(3) << symbolFunc(coord);
                        break;
                    }
                }
            }
            std::cout << std::endl;
        }
    }
}

Board& Board::operator=(Board&& otherBoard) noexcept
{
    if (this != &otherBoard)
    {
        std::lock(mtx, otherBoard.mtx);
        std::lock_guard<std::mutex> lock1(mtx, std::adopt_lock);
        std::lock_guard<std::mutex> lock2(otherBoard.mtx, std::adopt_lock);

        mRows = otherBoard.mRows;
        mColumns = otherBoard.mColumns;
        mCoordinates = std::move(otherBoard.mCoordinates);
    }
    return *this;
}

Board::Board(Board&& otherBoard) noexcept
{
    std::lock(mtx, otherBoard.mtx);
    std::lock_guard<std::mutex> lock1(mtx, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(otherBoard.mtx, std::adopt_lock);

    mRows = otherBoard.mRows;
    mColumns = otherBoard.mColumns;
    mCoordinates = std::move(otherBoard.mCoordinates);
}
