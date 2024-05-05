#pragma once
#include "Piece.hpp"

class Spot
{
    Piece* piece;
    int x;
    int y;

public:
    Spot(int x, int y, Piece* piece);
    Piece* getPiece();
    void SetPiece(Piece* p);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
};