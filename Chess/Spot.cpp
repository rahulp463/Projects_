#include"Spot.hpp"

Spot::Spot(int x, int y, Piece* p):x(x),y(y),piece(p){}

Piece* Spot::getPiece()
{
    return piece;
}

void Spot::SetPiece(Piece* p)
{
    this->piece = p;
}

void Spot::setX(int x)
{
    this->x = x;
}

int Spot::getX()
{
    return x;
}

void Spot::setY(int y)
{
    this->y = y;
}

int Spot::getY()
{
    return y;
}