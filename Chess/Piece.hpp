#include"common.hpp"
class Spot;
class Board;

class Piece
{
    bool Killed         = false;
    bool white         = false;
    bool isWhitePiece   = false;
    bool isPieceKilled  = false;

public:
    Piece(bool white);
    bool isWhite();
    void setWhite(bool white);
    bool isKilled();
    void setKilled(bool Killed);
    virtual bool canMove(Board* board, Spot* start, Spot* end) = 0;
    virtual string getSymbol() = 0;
    virtual void move(Board* board, Spot* start, Spot* end) = 0;
};