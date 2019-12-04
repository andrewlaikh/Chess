#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include "constants.h"

//virtual base class for double inheritance in queen
class Rook:virtual public Piece
{
public:
  Rook(int pieceName, string identifier):Piece(pieceName, identifier)
  {
    if (pieceName == WHITE_ROOK)
    {
      uniCode = "♖";
    }
    if (pieceName == BLACK_ROOK)
    {
      uniCode = "♜";
    }
  }
  virtual bool makeMove (Piece* Board[8][8], string source_square,
    string destination_square) override;
private:
  //determine IF move within range should be a virtual function
protected:
  bool moveWithinRange(int sourceSquare, int destinationSquare);
  bool noObstructingPieces(Piece* Board[8][8], int sourceSquare, int destinationSquare);

};

#endif
