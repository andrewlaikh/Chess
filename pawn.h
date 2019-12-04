#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include "constants.h"
#include <iostream>

//check whether this is necessary.
using namespace std;

class Pawn: public Piece
{
public:
  Pawn(int pieceName, string identifier, bool firstMove):
  Piece(pieceName, identifier), firstMove(firstMove)
  {
    if (pieceName == WHITE_PAWN)
    {
      uniCode = "♙";
    }
    if (pieceName == BLACK_PAWN)
    {
      uniCode = "♟";
    }
  }
  bool makeMove (Piece* Board[8][8], string source_square,
    string destination_square) override;
protected:
private:
  bool firstMoveWithinRange(int sourceSquare, int destinationSquare);
  bool moveWithinRange(int sourceSquare, int destinationSquare);
  bool noObstructingPieces(Piece* Board[8][8], int sourceSquare,
    int destinationSquare);
  bool firstMove;
};

#endif
