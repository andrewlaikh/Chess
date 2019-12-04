#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include "rook.h"
#include "constants.h"

//credit on multiple inheritance:
//https://www.youtube.com/watch?v=3XUXSiC-hPE
//get common ancestors.
class Queen: public Rook
{
public:
  Queen(int pieceName, string identifier):Rook(pieceName, identifier),
  Piece(pieceName, identifier)
  {
    if (pieceName == WHITE_QUEEN)
    {
      uniCode = "♕";
    }
    if (pieceName == BLACK_QUEEN)
    {
      uniCode = "♛";
    }
  };
  //appears that you are overwriting function.
  virtual bool makeMove (Piece* Board[8][8], string source_square,
    string destination_square) override;
private:
  bool bishopNoObstructingPieces(Piece* Board[8][8], int sourceSquare,
  int destinationSquare);
  bool bishopMoveWithinRange(int sourceSquare, int destinationSquare);
protected:
  bool noObstructingPieces(Piece* Board[8][8],int sourceSquare,
    int destinationSquare);

};


#endif
