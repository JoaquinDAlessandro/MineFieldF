#pragma once
#include <vector>
#include "Coordinate.h"
#include <functional>
#include <iostream>
#include <mutex>

using CoordinateToStringFunc = std::function<std::string(const Coordinate&)>;

class Board
{
public:
    //constructs a rowsXcolumns board
    Board(unsigned int rows = 0, unsigned int columns = 0);
    Coordinate const* getCoordinate(int row, int column) const;
    int getRows() const;
    int getColumns() const;
    void changeCoordinateStatus(int row, int column,CoordinateStatus newStatus);
    void printMapFormatted(CoordinateToStringFunc coordinateToStringFunc) const;
    Board(Board&& otherBoard) noexcept;
    Board& operator=(Board&& otherBoard) noexcept;
    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;
private:
    int mRows;
    int mColumns;
    std::vector<Coordinate> mCoordinates;
    mutable std::mutex mtx;
};