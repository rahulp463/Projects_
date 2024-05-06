#include"board.hpp"
#include"spot.hpp"

Board::Board()
{
    for(int i=0; i<8;i++)
    {
        for(int j=0; j<8;j++)
        {
            boxes[i][j] = nullptr;
        }
    }
    resetBoard();
}

Spot* Board::getSpot(int row, int col)
{
    if(row < 0 || row >= 8 || col < 0 || col >= 8)
    {
        cerr<<"Error: Index out of error"<<endl;
        return nullptr;
    }
    return boxes[row][col];
}

void Board::resetBoard()
{
    //Initialize White pieces
    boxes[0][0] = new Spot(0,0, new Rook(true));
    boxes[0][1] = new Spot(0,1, new Knight(true));
    boxes[0][2] = new Spot(0,2, new Bishop(true));
    boxes[0][3] = new Spot(0,3, new Queen(true));
    boxes[0][4] = new Spot(0,4, new King(true));
    boxes[0][5] = new Spot(0,5, new Bishop(true));
    boxes[0][6] = new Spot(0,6, new Knight(true));
    boxes[0][7] = new Spot(0,7, new Rook(true));
    for(int i=0; i<8; i++)
    {
        boxes[1][i] = new Spot(1,i, new Pawn(true));
    }

    boxes[7][0] = new Spot(7,0, new Rook(false));
    boxes[7][1] = new Spot(1,0, new Knight(false));
    boxes[7][2] = new Spot(2,0, new Bishop(false));
    boxes[7][3] = new Spot(3,0, new Queen(false));
    boxes[7][4] = new Spot(4,0, new King(false));
    boxes[7][5] = new Spot(5,0, new Bishop(false));
    boxes[7][6] = new Spot(6,0, new Knight(false));
    boxes[7][7] = new Spot(7,0, new Rook(false));
    for(int i=0; i<8; i++)
    {
        boxes[6][i] = new Spot(1,i, new Pawn(false));
    }

    for(int i=2; i<6;i++)
    {
        for(int j=0; j<8;j++)
        {
            boxes[i][j] = new Spot(i,j,nullptr);
        }
    }
}