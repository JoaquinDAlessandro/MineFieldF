#pragma once

enum class CoordinateStatus
{
    Available,
    Disabled,
    HasMines,
    DetectedMine
};

struct Coordinate
{
    bool operator==(Coordinate otherC) const
    {
        if (Row == otherC.Row && Column == otherC.Column)
        {
            return true;
        }
        return false;
    }
    unsigned int Row;
    unsigned int Column;
    CoordinateStatus Status;

};