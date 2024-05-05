#include "Piece.hpp"

Piece::Piece(bool white): isWhitePiece(white)
{
    isPieceKilled = false;
}

bool Piece::isWhite()
{
    return isWhitePiece;
}

void Piece::setWhite(bool pIswhite)
{
    isWhitePiece = pIswhite;
}

bool Piece::isKilled()
{
    return isPieceKilled;
}
void Piece::setKilled(bool Killed)
{
    isPieceKilled = Killed;
}



