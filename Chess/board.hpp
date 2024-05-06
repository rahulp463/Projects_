#pragma once
#include "Spot.hpp"

class Board
{
    Spot* boxes[8][8];

public:
    Board();
    Spot* getSpot(int x, int y);
    void displayBoard();
    void resetBoard();
};